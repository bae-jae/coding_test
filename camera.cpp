#include <iostream>
#include <string.h>

using namespace std;

int map[1005][1005];
int visited[1005];
int answer, n;

void init(void)
{
	answer = 0;

	memset(visited, 0, sizeof(visited));
	memset(map, 0, sizeof(map));
}

int dfs(int here)
{
	int child[3] = {0, 0, 0};
	visited[here] = 1;

	for(int i = 0; i < n; ++i)
	{
		if(map[here][i] == 1 && visited[i] == 0)
			++child[dfs(i)];
	}

	if(child[0] != 0)
	{
		++answer;
		return 2;
	}

	if(child[2] != 0)
		return 1;

	return 0;
}

int main(void)
{
	int tc;
	cin >> tc;

	for(int test = 0; test < tc; ++test)
	{
		int k;
		cin >> n >> k;

		init();

		for(int i = 0; i < k; ++i)
		{
			int here, there;
			cin >> here >> there;

			map[here][there] = 1;
			map[there][here] = 1;
		}

		for(int i = 0; i < n; ++i)
		{
			if(!visited[i] && dfs(i) == 0)
				++answer;

		}

		cout << answer << "\n";
	}
}
