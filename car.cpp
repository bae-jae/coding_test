#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<pair<int, int>> map[1005];
pair<int, int> cache[1005];

void dfs(int go, int cost, int idx)
{
	if(go == 1 && idx == 1)
		return;
	
	for(int i = 0; i < map[go].size(); ++i)
	{
		int nextnode = map[go][i].first;
		int nextcost = map[go][i].second + cost;

		if(nextcost > cache[nextnode].second)
		{
			cache[nextnode].second = nextcost;
			cache[nextnode].first = go;

			dfs(nextnode, nextcost, 1);
		}
	}
}

void print_path(int node, int idx)
{
	if(node == 1 && idx == 1)
	{
		cout << 1 << " ";
		return ;
	}

	print_path(cache[node].first, 1);
	cout << node << " ";
}

int main(void)
{
	int m, n;
	cin >> n;
	cin >> m;

	for(int i = 0; i < m; ++i)
	{
		int s, e, p;

		cin >> s >> e >> p;
		map[s].push_back({e, p});
	}

	dfs(1, 0, 0);
	cout << cache[1].second << "\n";
	print_path(1, 0);

}
