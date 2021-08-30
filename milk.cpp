#include <iostream>
#include <string.h>

using namespace std;

int map[1005][1005];

int cache[1005][1005][4];

int milk[4] = {1, 2, 0, 0};
int n;

int dy[2] = {1, 0};
int dx[2] = {0, 1};

int outRange(int y, int x)
{
	if(y < 0 || y >= n)
		return 0;

	if(x < 0 || x >= n)
		return 0;

	return 1;
}
int dfs(int y, int x, int target)
{
	if(outRange(y, x) == 0)
		return 0;

	int& ret = cache[y][x][target];

	if(ret != -1)
		return ret;

	ret = 0;

	for(int i = 0; i < 2; ++i)
	{
		int my = y + dy[i];
		int mx = x + dx[i];

		if(outRange(my, mx) == 0)
			continue;

		if(map[my][mx] == milk[target])
		{
			ret = max(ret, dfs(my, mx, milk[target]) + 1);
		}

		ret = max(ret, dfs(my, mx, target));
	}

	return ret;
}


int main(void)
{
	cin >> n;

	memset(cache, -1, sizeof(cache));

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			cin >> map[i][j];
		}
	}

	if(map[0][0] == 0)
		cout << dfs(0, 0, 0) + 1;
	else
		cout << dfs(0, 0, 3);
}
