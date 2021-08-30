#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

//bfs로 풀어야함 

int map[20005][20005];

void changeVToA(vector<pair<int, int>> edge)
{
	memset(map, 0, sizeof(map));

	for(int i = 0; i < edge.size(); ++i)
	{
		int start = edge[i].first;
		int end = edge[i].second;

		map[start][end] = 1;
		map[end][start] = 1;
	}
}

int max(int n1, int n2){
	if(n1 > n2)
		return n1;

	return n2;
}

int search(int n)
{
	queue<pair<int, int>> q;
	q.push(make_pair(1, 0));

	vector<int> dist(n + 1, 987654321);

	while(!q.empty())
	{
		int node = q.front().first;
		int len = q.front().second;

		q.pop();

		if(len >= dist[node])
			continue;
		dist[node] = len;

		for(int i = 1; i <= n; ++i)
		{
			if(len + 1 < dist[i] && map[node][i] == 1)
			{
				q.push(make_pair(i, len + 1));
			}
		}
	}

	int answer = 0;
	int maxLen = 0;

	for(int i = 1; i <= n; ++i)
	{
		cout << dist[i] << " ";
		if(maxLen < dist[i])
		{
			maxLen = dist[i];
			answer = 1;
		}
		else if(maxLen == dist[i])
			++answer;
	}

	return answer;
}

int main(void)
{
	int tc;
	cin >> tc;

	for(int test = 0; test < tc; ++test)
	{
		int nodeCount = 0;
		cin >> nodeCount;

		int vertexCount = 0;
		cin >> vertexCount;

		vector<pair<int, int>> list;

		for(int i = 0; i < vertexCount; ++i)
		{
			int a,b;
			cin >> a >> b;

			list.push_back(make_pair(a,b));
		}

		changeVToA(list);
		cout << search(nodeCount) << endl;
		
	}
}
