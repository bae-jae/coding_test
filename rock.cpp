#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int max(int n1, int n2)
{
	if(n1 > n2)
		return n1;

	return n2;
}

int main(void)
{
	int n, b, w;
	cin >> n >> b >> w;

	string s;
	cin >> s;

	queue<int> q;

	int black = 0;
	int white = 0;
	int start = 0;
	int end = 0;
	int answer = 0;

	for(int i = 0; i < s.size(); ++i)
	{
		int rock = 1;

		if(s[i] == 'W')
		{
			++white;
			rock = 0;
		}
		else
		{
			++black;
		}

		q.push(rock);

		if(black > b)
		{
			while(!q.empty())
			{
				int n = q.front();
				q.pop();

				if(n == 1)
				{
					--black;
					break;
				}
				else
					--white;
			}
		}

		if(white >= w)
			answer = max(answer, q.size());
	}

	cout << answer;
}
