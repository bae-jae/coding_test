#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> makePI(string s)
{
	int m = s.size();
	vector<int> pi(m, 0);
	
	int begin = 1;
	int matched = 0;
	
	while(begin + matched < s.size())
	{
		if(s[matched] == s[begin + matched])
		{
			++matched;
			pi[begin + matched - 1] = matched;
		}
		else
		{
			if(matched == 0)
			{
				++begin;
			}else{
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	
	return pi;
}

int main(void)
{
	string s;
	cin >> s;
	
	int ans = 0;
	
	for(int i = 0; i < s.size() / 2 + 1; ++i)
	{
		vector<int> pi = makePI(s.substr(i, s.size()));

		for(int i = 0; i < pi.size(); ++i)
		{
			ans = max(ans, pi[i]);
		}
	}
	
	cout << ans;
}