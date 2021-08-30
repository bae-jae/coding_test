#include <iostream>
#include <cstring>

using namespace std;

int map[505][505];

int dy[4] = {-1, 0, 1,  0};
int dx[4] = {0,  1, 0, -1};
int cache[505][505];

int n;

int outRange(int y,int x)
{
	if(y < 0 || y >= n)
		return 0;

	if(x < 0 || x >= n)
		return 0;

	return 1;
}

int dfs(int y, int x)
{
	int nowBamboo = map[y][x];

	int &ret = cache[y][x];

	if(ret != -1)
		return ret;

	ret = 0;

	for(int i = 0; i < 4; ++i)
	{
		int ry = y + dy[i];
		int rx = x + dx[i];

		if(outRange(ry, rx) == 1)
		{
			int next = map[ry][rx];

			if(nowBamboo < next)
				ret = max(ret , dfs(ry, rx));
		}
	}

	return ret = ret + 1 ;
}

int main(void)
{
	cin >> n;

	memset(cache, -1 , sizeof(cache));

	for(int i = 0; i < n; ++i)
	{
		for(int j= 0; j < n; ++j)
		{
			int s;
			cin >> s;

			map[i][j] = s;
		}
	}

	int ans = 0;

	for(int i = 0 ; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			cout << i << "  " << j << " " << dfs(i, j) << endl;
			ans = max(ans, dfs(i, j));
		}
	}

	cout << ans;
}
