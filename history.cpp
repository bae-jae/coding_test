#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

vector<int> map[401];
int visited[401];
int arrive[401][401];
int differ[401];
int row = 1;

void dfs(int node, int now)
{
	visited[now] = 1;

	for(int i = 0; i < map[now].size(); ++i)
	{
		int next = map[now][i];

		if(visited[next] == 0)
		{
			arrive[node][next] = -1;
			arrive[next][node] = 1;
			
			dfs(node, next);
		}
	}

}

int main(void)
{
	int n, k;
	cin >> n >> k;

	for(int i = 0; i < k; ++i)
	{
		int s, e;
		cin >> s >> e;

		map[s].push_back(e);
		
		arrive[s][e] = -1;
		arrive[e][s] = 1;

	}

	for(int i = 1; i <= n; ++i)
	{
		dfs(i, i);
		memset(visited, 0, sizeof(visited));
	}

	int q;
	cin >> q;

	for(int i = 0; i < q; ++i)
	{
		int s, e;
		cin >> s >> e;

		cout << arrive[s][e];
		cout <<"\n";
	}
}
