#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int map[101][101];

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int visited[105][105];
int island[105][105];
int n;

int outRange(int y, int x)
{
	if(y < 0 || y >= n)
		return 0;

	if(x < 0 || x >= n)
		return 0;

	return 1;
}

int findIsland(int y, int x, int color)
{
	queue<pair<pair<int, int>, int>> q;

	q.push(make_pair(make_pair(y, x), 0));
	
	while(!q.empty())
	{
		int cy = q.front().first.first;
		int cx = q.front().first.second;
		int count = q.front().second;

		q.pop();

		if(island[cy][cx] == 1)
			continue;

		if(map[cy][cx] != 0 && visited[cy][cx] != color)
			return count - 1;

		island[cy][cx] = 1;

		for(int i = 0; i < 4; ++i)
		{
			int ry = cy + dy[i];
			int rx = cx + dx[i];

			if(outRange(ry, rx) == 1)
			{
				if(map[cy][cx] != color)
					q.push(make_pair(make_pair(ry, rx), count + 1));
			}
		}
	}

	return 987654321;
}

int dfs(int y, int x, int color)
{
	visited[y][x] = color;

	for(int i = 0; i < 4; ++i)
	{
		int ry = y + dy[i];
		int rx = x + dx[i];

		if(outRange(ry, rx) == 1)
		{
			if(visited[ry][rx] == 0 && map[ry][rx] == 1)
			{
				dfs(ry, rx, color);
			}
		}
	}
}

int outWave(int y, int x)
{
	for(int i = 0; i < 4; ++i)
	{
		int ry = y + dy[i];
		int rx = x + dx[i];

		if(outRange(ry, rx) == 1)
		{
			if(map[ry][rx] == 0)
				return 1; //진출가능 
		}
	}

	return 0;
}

int main(void)
{
	cin >> n;

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			int s;
			cin >> s;

			map[i][j] = s;
		}
	}

	int color = 1;

	for(int y = 0; y < n; ++y)
	{
		for(int x = 0; x < n; ++x)
		{
			if(map[y][x] == 1 && visited[y][x] == 0)
			{
				dfs(y, x, color);
				++color;
			}
		}
	}

	cout << endl;

	for(int y = 0; y < n; ++y)
	{
		for(int x= 0 ; x < n ; ++x)
		{
			cout << visited[y][x] << " ";
		}
		cout << endl;
	}

	cout << endl;

	int ans = 987654321;

	for(int y = 0; y < n; ++y)
	{
		for(int x = 0; x < n; ++x)
		{
			if(outWave(y, x) == 1)
			{
				memset(island, 0, sizeof(island));
				ans = min(ans, findIsland(y, x, visited[y][x]));
			}
		}
	}

	cout << ans;
}
