#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> map[10002];
int visited[101];

void dfs(int node, int cost)
{
	visited[node] = cost;


	for(int i = 0; i < map[node].size(); ++i)
	{
		int next = map[node][i].first;
		int nextCost = map[node][i].second + cost;

		if(visited[next] == 0)
			dfs(next, nextCost);
	}
}

int main(void)
{
	int n;
	cin >> n;

	for(int i = 0; i < n - 1; ++i)
	{
		int start, end, cost;
		cin >> start >> end >> cost;

		map[start].push_back(make_pair(end, cost));
		map[end].push_back(make_pair(start, cost));
	}

	dfs(1, 0);

	int nextNode = 0;
	int maxDist = 0;

	for(int i = 1; i <= n; ++i)
	{
		if(maxDist < visited[i])
		{
			maxDist = visited[i];
			nextNode = i;
		}

		visited[i] = 0;
	}

	dfs(nextNode, 0);

	nextNode = 0;
	maxDist = 0;

	for(int i = 1; i <= n; ++i)
	{
		if(maxDist < visited[i])
		{
			maxDist = visited[i];
			nextNode = i;
		}

		visited[i] = 0;
	}

	cout << maxDist << endl;

}
