#include <iostream>

using namespace std;

int visited[21][21];
int use[30];
char map[21][21];

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int r, c;
int answer;

int outRange(int y, int x)
{
	if(y < 0 || y >= r)
		return 0;
	if(x < 0 || x >= c)
		return 0;

	return 1;
}

int dfs(int y, int x, int ans)
{
	answer = max(ans, answer);

	int idx = map[y][x] - 'A';

	use[idx] = 1;
	visited[y][x] = 1;
	

	for(int i = 0; i < 4; ++i)
	{
		int mx = x + dx[i];
		int my = y + dy[i];

		if(outRange(my, mx) == 1)
		{
			int idx = map[my][mx] - 'A';

			if(use[idx] == 0 && visited[my][mx] == 0)
				dfs(my, mx, ans + 1);
		}
	}

	visited[y][x] = 0;
	use[idx] = 0;

	return ans;
}

int main(void)
{
	cin >> r >> c;

	for(int i = 0; i < r; ++i)
	{
		string s;
		cin >> s;

		for(int j = 0; j < s.size(); ++j)
			map[i][j] = s[j];
	}

	dfs(0, 0, 1);

	cout << answer;
}
