#include <iostream>
#include <string>

using namespace std;

int r, c;
int map[10001][10001];
int visited[10001][10001];

int dy[4] = {-1, 0, 1};
int dx[4] = {1,  1, 1};


int outRange(int y, int x)
{
	if(y < 0 || y >= r)
		return 0;

	if(x < 0 || x >= c)
		return 0;

	return 1;
}

int dfs(int y, int x)
{
	if(x == c - 1)
		return 1;

	visited[y][x] = 1;

	for(int i = 0; i < 3; ++i)
	{
		int my = dy[i] + y;
		int mx = dx[i] + x;

		if(outRange(my, mx) == 1 && map[my][mx] == 0 && visited[my][mx] == 0)
		{
			int check = dfs(my, mx);

			if(check == 1)
				return 1;
		}
	}

	return 0;
}


int main(void)
{
	cin >> r >> c;


	for(int i = 0; i < r; ++i)
	{
		string s;
		cin >> s;

		for(int j = 0; j < s.size(); ++j)
		{
			if(s[j] == '.')
			{
				map[i][j] = 0;
			}
			else
				map[i][j] = 1;
		}
	}

	int ans = 0;

	for(int i = 0; i < r; ++i)
	{
		ans += dfs(i, 0);
	}

	cout << ans;
}

