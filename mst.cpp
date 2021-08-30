#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int visited[10005];
int score[10005];
vector<pair<int, int>> map[10005];


void init(void)
{
	for(int i = 0; i < 10005; ++i)
	{
		map[i].clear();
		visited[i] = 0;
		score[i] = 0;
	}
}

int mst(int node)
{
	int ans = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	pq.push(make_pair(0, node));

	while(!pq.empty())
	{
		int cost = pq.top().first;
		node = pq.top().second;

		pq.pop();

		if(visited[node] == 1)
			continue;

		ans += cost;
		visited[node] = 1;

		for(int i = 0; i < map[node].size(); ++i)
		{
			int nextNode = map[node][i].first;
			int needCost = map[node][i].second;

			if(visited[nextNode] == 0)
				pq.push(make_pair(needCost, nextNode));
		}
	}

	return ans;
}
int main(void)
{
	int n, e;
	cin >> n >> e;

	for(int i = 0; i < e; ++i)
	{
		init();

		int start, end, cost;
		cin >> start >> end >> cost;

		map[start].push_back(make_pair(end, cost));
		map[end].push_back(make_pair(start, cost));
	}

	cout << mst(1);
}
