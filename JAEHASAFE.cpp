#include <iostream>
#include <string>
#include <string.h>

using namespace std;

string s[110];
int n;
int pi[1005];

void makeLinked(int idx)
{
	memset(pi, 0, sizeof(pi));

	int len = s[idx].size();
	int begin = 1;
	int matched = 0;

	while(begin + matched < len)
	{
		if(s[idx][begin + matched] == s[idx][matched])
		{
			++matched;
			pi[begin + matched - 1] = matched;
		}
		else
		{
			if(matched == 0)
				++begin;
			else
			{
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
}
int find(int first,int secd)
{
	makeLinked(secd);

	string target = s[first] + s[first];  //문자열 연걸 
	int begin = 0;
	int matched = 0;

	while(begin + matched < target.size())
	{
		if(target[begin + matched] == s[secd][matched])
		{
			++matched;

			if(matched == s[secd].size())
				return begin;
		}
		else
		{
			if(matched == 0)
				++begin;
			else
			{
				begin += matched - pi[matched-1];
				matched = pi[matched - 1];
			}
		}
	}
}
int search(void)
{
	int clockMove = 0;
	int answer = 0;

	for(int i = 0; i < n; ++i)
	{
		if(clockMove == 0)
		{
			clockMove = 1;
			answer += find(i + 1, i);
		}
		else
		{
			clockMove = 0;
			answer += find(i, i + 1);
		}
	}

	return answer;
}

int main(void)
{
	int tc;
	cin >> tc;

	for(int test = 0; test < tc; ++test)
	{
		cin >> n;
		cin >> s[0];

		for(int i = 1; i <= n; ++i)
		{
			cin >> s[i];
		}

		cout << search() << "\n";
	
	}

	return 0;
}
