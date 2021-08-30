#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>
using namespace std;

double n, w;
int visited[500005];
vector<int> m[500005];

double bfs(int start)
{
	queue<int> q;

	q.push(start);
	int leaf = 0;

	while(!q.empty())
	{
		int node = q.front();
		q.pop();

		if(visited[node] == 1)
			continue;

		visited[node] = 1;

		int in = 0;
		for(int i = 0; i < m[node].size(); ++i)
		{
			int next = m[node][i];

			if(visited[next] == 0)
			{
				q.push(next);
				in = 1;
			}
		}

		if(in == 0)
			++leaf;
	}

	return leaf;
}


int main(void)
{
	cin >> n >> w;

	for(int i = 0; i < n-1; ++i)
	{
		int s, e;
		cin >>s >> e;

		m[s].push_back(e);
		m[e].push_back(s);
	}

	int leaf = bfs(1);

	printf("%.11f", (w / leaf));
}
