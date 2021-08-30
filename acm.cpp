#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> map[1005];
vector<int> cost;
vector<int> load;
vector<int> indegree[1005];

int visited[1005];
int mapCost[1005];

void init(void)
{
	cost.clear();
	load.clear();

	for(int i = 0; i < 1005; ++i)
	{
		mapCost[i] = -1;
		visited[i] = 0;
		indegree[i].clear();
	}
}

void bfs(int node)
{
	for(int i = 0; i < map[node].size(); ++i)
	{
		int next = map[node][i];
		int nCost = mapCost[node] + cost[next];

		if(mapCost[next] < nCost)
		{
			mapCost[next] = nCost;
		}
	}
}

void dfs(int node)
{
	visited[node] = 1;

	for(int i = 0; i < map[node].size(); ++i)
	{
		int next = map[node][i];

		if(visited[next] == 0)
		{
			dfs(next);
		}
	}

	load.push_back(node);
}


int main(void)
{
	int tc;
	cin >> tc;

	for(int test = 0; test < tc; ++test)
	{
		init();
		int n, k;
		cin >> n >> k;

		cost.push_back(0); //
		
		for(int i = 0; i < n; ++i)
		{
			int s;
			cin >> s;

			cost.push_back(s);
		}


		for(int i = 0; i < k; ++i)
		{
			int s, e;
			cin >> s >> e;

			map[s].push_back(e);
			indegree[e].push_back(s);
		}

		for(int i = 1; i <= n; ++i)
		{
			if(visited[i] == 0)
				dfs(i);
		}

		reverse(load.begin(), load.end());

		for(int i = 0; i < load.size(); ++i)
		{
			cout << load[i] << " ";
			if(indegree[load[i]].size() == 0)
			{
				mapCost[load[i]] = cost[load[i]];
				bfs(load[i]);
			}
			else
				bfs(load[i]);
		}

		int target;
		cin >> target;

		cout << mapCost[target] << endl;
	}
}
