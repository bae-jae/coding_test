#include <iostream>
#include <cstring>

using namespace std;

int h, w;

int map[502][502];
int cache[502][502][10000];
int visited[502][502];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};


int outRange(int y, int x)
{
	if(y < 0 || y >= h)
		return 0;

	if(x < 0 || x >= w)
		return 0;

	return 1;
}

int dfs(int y, int x, int r)
{
	if(y == h - 1 && x == w - 1)
		return 1;

	visited[y][x] = 1;
	int &ret = cache[y][x][r];

	if(ret != -1)
		return ret;

	ret = 0;

	for(int i = 0; i < 4; ++i)
	{
		int mx = x + dx[i];
		int my = y + dy[i];

		if(outRange(my, mx) == 1 && visited[my][mx] == 0)
		{
			if(map[my][mx] < map[y][x])
			{
				ret += dfs(my, mx, i);
			}
		}
	}

	visited[y][x] = 0;

	return ret;
}



int main(void)
{
	cin >> h >> w;

	memset(cache, -1 ,sizeof(cache));

	for(int i = 0; i < h; ++i)
	{
		for(int j = 0; j < w; ++j)
		{
			int s;
			cin >> s;

			map[i][j] = s;
		}
	}

	cout << dfs(0, 0, 0);

}
