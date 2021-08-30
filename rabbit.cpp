#include <iostream>
#include <string.h>

using namespace std;

int n, m;

string map[1005];

int visited[1005][1005];
int cache[1005][1005];

int my[3] = {-1,  1, 0};
int mx[3] = {-1, -1, -1};

int in = 0;

int outRange(int y, int x)
{
	if(y < 0 || y >= n)
		return 0;

	if(x < 0 || x >= m)
		return 0;

	return 1;
}

int dfs(int y, int x)
{
	if(map[y][x] == 'R')
	{
		in = 1;
		return 1;
	}

	int &ret = cache[y][x];

	if(ret != -1)
		return ret;

	ret = 0;
	int cost = 0;

	if(map[y][x] == 'C')
		++cost;

	for(int i = 0; i < 3; ++i)
	{
		int ry = y + my[i];
		int rx = x + mx[i];

		if(outRange(ry, rx) == 1 && map[ry][rx] != '#')
		{
			int cango = dfs(ry, rx);

			if(cango >= 1)
			{
				ret = max(ret, cango  + cost);
			}
		}
	}

	cout << y << " "  << x << " " << ret << endl;

	return ret;
}

int main(void)
{
	cin >> n >> m;

	int sy, sx;
	memset(cache, -1, sizeof(cache));

	for(int i = 0; i < n; ++i)
	{
		string s;
		cin >> s;

		map[i] = s;
	}

	int ans = 0;

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < map[i].size(); ++j)
		{
			if(map[i][j] == 'O')
			{
				ans = max(ans, dfs(i, j));
			}
		}
	}

	if(in == 0)
		ans = 0;

	cout << ans - 1;
}
