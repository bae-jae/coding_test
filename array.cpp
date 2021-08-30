#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

string s;
string s1;
string s2;
int cache[3000][3000];

void makeAns(int y, int x)
{
	if(cache[y][x] == 0)
		return;
	
	s.push_back(s1[y]);
	
	makeAns(y - 1, x - 1);
}

int main(void)
{
	cin >> s1;
	cin >> s2;
	
	int maxRow = min(s1.size(), s2.size());
	
	for(int i = 0; i < s2.size(); ++i)
	{
		if(s1[0] == s2[i])
		{
			cache[0][i] = 1;
		}
	}
	
	
	for(int i = 0; i < s1.size(); ++i)
	{
		if(s1[i] == s2[0])
		{
			cache[i][0] = 1;
		}
	}
	/////////init
	
	for(int i = 1; i < s1.size(); ++i)
	{
		for(int j = 1; j < s2.size(); ++j)
		{
			if(s1[i] == s2[j])
			{
				cache[i][j] = cache[i - 1][j - 1] + 1; 
				cout << cache[i][j] << endl;
			}
		}
	}
	
	int ans = 0;
	int x = -1;
	int y = -1;
	
	for(int i = 0; i < s1.size(); ++i)
	{
		for(int j = 0; j < s2.size(); ++j)
		{
			if(cache[i][j] > ans)
			{
				ans = cache[i][j];
				
				y = i;
				x = j;
			}
		}
	}
	
	cout << ans << "\n";
	makeAns(y, x);
	reverse(s.begin(), s.end());
	cout << s;
}