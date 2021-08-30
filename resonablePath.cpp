#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> map[1005];
int visited[1005];
int checkDist[1005];

void bfs(int node)
{
	queue<pair<int, int>> pq;

	pq.push(make_pair(1, 1));

	while(!pq.empty())
	{
		int node = pq.front().first;
		int cost = pq.front().second;

		pq.pop();

		if(node == 2)
		{
			checkDist[cost]++;
			continue;
		}

		visited[node] = 1;

		for(int i = 0; i < map[node].size(); ++i)
		{
			int next = map[node][i];

			if(visited[next] == 0)
				pq.push(make_pair(next, cost + 1));
		}
	}
}

int main(void)
{
	int n, m;
	cin >> n >> m;

	for(int i = 0; i < m; ++i)
	{
		int s, e, c;
		cin >> s >> e >> c;

		map[s].push_back(e);
		map[e].push_back(s);
	}

	bfs(1);

	for(int i = 0; i < 1005; ++i)
	{
		if(checkDist[i] >= 1)
		{
			cout << checkDist[i];
			break;
		}
	}


	return 0;
}
