#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>> map;

int indegree[32001];
int visited[32001];


int main(void)
{
	int n, m;
	cin >> n >> m;

	map.resize(n + 1);
	priority_queue<int> pq;

	for(int i = 0; i < m; ++i)
	{
		int s, e;
		cin >> s >> e;

		indegree[e]++;
		map[s].push_back(e);
	}


	for(int i = 1; i <= n; ++i)
	{
		if(indegree[i] == 0)
		{
			pq.push(-i);
		}
	}

	while(!pq.empty())
	{
		int next = -pq.top();
		pq.pop();

		cout << next << " ";
		for(int i = 0; i < map[next].size(); ++i)
		{
			--indegree[map[next][i]];

			if(indegree[map[next][i]] == 0)
				pq.push(-map[next][i]);
		}
	}
}
