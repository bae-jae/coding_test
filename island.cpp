#include <iostream>
#include <string>
#include <queue>
#include <string.h>
#include <algorithm>

using namespace std;

int map[51][51];
int visited[51][51];
int result[51][51];

int r, w;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = { 0, 1, 0, -1};

int outRange(int y, int x)
{
	if(y < 0 || y >= r)
		return 0;

	if(x < 0 || x >= w)
		return 0;

	return 1;
}

int bfs(int y, int x)
{
	queue<pair<int, pair<int, int>>> q;

	q.push(make_pair(0, make_pair(y, x)));

	visited[y][x] = 1;

	int ans = -1;
	int ry = y;
	int rx = x;

	while(!q.empty())
	{
		int cost = q.front().first;
		int ny = q.front().second.first;
		int nx = q.front().second.second;

		q.pop();

		if(ans < cost)
		{
			ans = cost;
			ry = ny;
			rx = nx;
		}


		for(int i = 0; i < 4; ++i)
		{
			int ry = ny + dy[i];
			int rx = nx + dx[i];

			if(outRange(ry, rx) == 1 && visited[ry][rx] == 0 && map[ry][rx] == 1)
			{
				q.push(make_pair(cost + 1, make_pair(ry, rx)));
				visited[ry][rx] = 1;
			}
		}
	}


	return ans;
}

int main(void)
{
	cin >> r >> w;

	for(int i = 0; i < r; ++i)
	{
		string s;
		cin >> s;

		for(int j = 0; j < s.size(); ++j)
		{
			if(s[j] == 'W')
				map[i][j] = 0;
			else
				map[i][j] = 1;
		}
	}

	int ans = 0;

	for(int i = 0; i < r; ++i)
	{
		for(int j = 0; j < w; ++j)
		{
			if(map[i][j] == 1)
			{
				ans = max(ans, bfs(i, j));

				memset(visited, 0, sizeof(visited));
			}
		}
	}

	cout << ans;
}
