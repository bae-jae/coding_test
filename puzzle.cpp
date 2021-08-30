#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;

string s;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0,  1, 0, -1};

string f = "123456789";
map<string ,int> visited;


int outRange(int y, int x)
{
	if(y < 0 || y >= 3 || x < 0 || x >= 3)
		return 0;

	return 1;
}

int swap(int idx1, int idx2)
{
	char sub = s[idx1];
	s[idx1] = s[idx2];
	s[idx2] = sub;
}

int main(void)
{
	for(int y= 0; y < 3; ++y)
	{
		for(int x = 0; x < 3; ++x)
		{
			int t;
			cin >> t;

			if(t == 0)
				t = 9;

			s += to_string(t);
		}
	}

	queue<pair<string, int>> q;
	q.push(make_pair(s, 0));

	while(!q.empty())
	{
		s = q.front().first;
		int ans = q.front().second;

		q.pop();

		if(s == f)
		{
			cout << ans;
			return 0;
		}

		visited[s] = 1;

		int idx = s.find('9');

		int y = idx / 3;
		int x = idx % 3;

		for(int i = 0; i < 4; ++i)
		{
			int nextY = y + dy[i];
			int nextX = x + dx[i];

			if(outRange(nextY, nextX) == 1)
			{
				int idx1 = nextY*3 + nextX;

				swap(idx1, idx);

				if(visited[s] == 0)
					q.push(make_pair(s, ans + 1));

				swap(idx1, idx);
			}
		}
	}

	cout << -1;
}
