#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;


int visited[1005];
vector<pair<int, int>> map[1005];
int n, m;

int dfs(int start, int c)
{
	int flag = 0;
	int ans = 0;
	
	for(int i = 0; i < map[start].size(); ++i)
	{
		int next = map[start][i].first;
		int cost = map[start][i].second;
		
		if(visited[next] == 0)
		{
			flag = 1;
			visited[next] = 1;
			ans += dfs(next, cost);
		}
	}
	
	if(flag == 0)
		return c;
	else
		return min(ans, c);
}

int main(void)
{
	int tc;
	cin >> tc;
	
	for(int test =0 ; test < tc; ++ test)
	{
		cin >> n >> m;
		memset(visited, 0, sizeof(visited));
		
		for(int i = 0; i < 1005; ++i)
			map[i].clear()
		
		
		for(int i = 0; i < m; ++i)
		{
			int s , e, c;
			cin >> s >> e >> c;

			map[s].push_back({e, c});
			map[e].push_back({s, c});
		}
		
		visited[1] = 1;
		cout << dfs(1, 987654321);
	}
}