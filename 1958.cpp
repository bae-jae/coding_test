#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> cand;

int cache[210][210][210];

int main(void)
{
	string s1, s2, s3;
	
	cin >> s1;
	cin >> s2;
	cin >> s3;
	
	int ans = 0;
	
	for(int i = 1; i <= s1.size(); ++i)
	{
		for(int j = 1; j <= s2.size(); ++j)
		{
			for(int k = 1; k <= s3.size(); ++k)
			{
				if(s1[i-1] == s2[j-1] && s2[j-1] == s3[k-1])
				{
					cache[i][j][k] = cache[i-1][j-1][k-1] + 1;
					ans = max(ans, cache[i][j][k]);	
				}
				else
				{
					cache[i][j][k] = max(cache[i-1][j][k], max(cache[i][j-1][k], cache[i][j][k-1]));
					ans = max(ans, cache[i][j][k]);	
				}
			}
		}
	}
	
	cout << ans << " ";
}