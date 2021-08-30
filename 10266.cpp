#include<iostream>
#include<vector>
#include <map>
#include<string>
#include<cmath>

using namespace std;

vector<int> c1;
vector<int> c2;
map<int, int> m;

vector<int> makePi(string s)
{
	int n = s.size();
	int begin = 1;
	int mathched = 0;
	
	vector<int> pi(s.size(), 0);
	
	while(begin + mathched < n)
	{
		if(s[mathched] == s[begin + mathched])
		{
			++mathched;
			pi[begin + mathched - 1] = mathched;
		}
		else{
			if(mathched == 0)
			{
				++begin;
				continue;
			}
			
			begin += mathched - pi[mathched - 1];
			mathched = pi[mathched - 1];
		}
	}
	
	return pi;
}

int getMatch(vector<int> pi, string h, string n)
{
	int begin = 0;
	int mathched = 0;
	
	
	while(begin <= h.size() - n.size())
	{
		if(mathched < n.size() && h[begin + mathched] == n[mathched])
		{
			mathched++;
			
			if(mathched == n.size())
				return 1;
		}
		else{
			if(mathched == 0)
			{
				++begin;
				continue;
			}
			
			begin += mathched - pi[mathched - 1];
			mathched = pi[mathched - 1];
		}
	}
	
	return 0;
}

int main(void)
{
	int n;
	cin >> n;
	
	string niddle;
	string huddle;
	
	for(int i = 0; i < 360000; ++i)
	{
		niddle += "0";
		huddle += "0";
	}
	
	for(int i = 0; i < n; ++i)
	{
		int s;
		cin >> s;
		
		niddle[s] = 1;
	}
	
	for(int i = 0; i < n; ++i)
	{
		int s;
		cin >> s;
		
		huddle[s] = 1;
	}
	
	vector<int> pi = makePi(niddle);
	
	int ans = 0;
		
	ans = getMatch(pi, huddle + huddle, niddle);
	
	
	if(ans == 0)
	{
		cout << "impossible";
	}else
		cout << "possible";
}