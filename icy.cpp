#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0,  1,  0,  -1};

int map[305][305];
int n,m;
int visited[305][305];

int outRange(int y, int x)
{
	if(y < 0 || y >= n)
		return 0;

	if(x < 0 || x >= m)
		return 0;

	return 1;
}

int count(int y, int x)
{
	int ans = 0;

	for(int i = 0; i < 4; ++i)
	{
		int ry = y + dy[i];
		int rx = x + dx[i];

		if(outRange(ry, rx) == 1 && map[ry][rx] == 0)
			++ans;
	}

	return ans;
}

void dfs(int y, int x)
{
	visited[y][x] = 1;

	for(int i = 0; i < 4; ++i)
	{
		int ry = y + dy[i];
		int rx = x + dx[i];

		if(outRange(ry, rx) == 1)
		{
			if(visited[ry][rx] == 0 && map[ry][rx] != 0)
				dfs(ry, rx);
		}
	}
}

int checkMap(void)
{
	memset(visited, 0, sizeof(visited));
	int in = 0;

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			if(map[i][j] != 0 && visited[i][j] == 0)
			{
				dfs(i, j);
				++in;
			}
		}
	}

	return in;
}

int find(void)
{
	int ans = 0;

	while(1)
	{
		int deleted = 0;
		int findWay = 0;
		
		++ans;

		for(int y = 0; y < n; ++y)
		{
			for(int x = 0; x < m; ++x)
			{
				if(map[y][x] != 0)
				{
					int minus = count(y, x);

					if(minus == 0)
						continue;


					if(map[y][x] - minus <= 0)
					{
						findWay = 1;
						map[y][x] = -1;
					}
					else
						map[y][x] -= minus;

					deleted = 1;

				}
			}
		}

		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < m; ++j)
			{

				if(map[i][j] == -1)
					map[i][j] = 0;

				cout << map[i][j] << " ";
			}

			cout << endl;
		}

		cout << endl;

		if(checkMap() >= 2)
			return ans;

		if(deleted == 0)
			break;

	}

	return 0;
}

int main(void)
{
	cin >> n >> m;

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			int s;
			cin >> s;

			map[i][j] = s;
		}
	}

	cout << find();

}
