#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int visited[500001];
int finished[500001];


vector<int> map[500000];
vector<pair<int, int>> list;
vector<pair<int, int>> sub;

void dfs(int node)
{
	visited[node] = 1;

	for(int i = 0; i < map[node].size(); ++i)
	{
		int next = map[node][i];

		if(visited[next] == 0)
			dfs(next);
		else if(finish[next] == 0)
			sub.push_back(make_pair(node, next));
	}

	finished[node] = 1;
}


int main(void)
{
	int n, m;

	cin >> n >> m;

	for(int i = 0; i < m; ++i)
	{
		int start, end;
		cin >> start >> end;

		map[start].push_back(end);

		list.push_back(make_pair(start, end));
	}

	for(int i = 0; i < n; ++i)
	{
		if(visited[i] == 0)
			dfs(i);

		if(
	}

	for(int i = list.size() - 1; i >= 0; --i)
	{
		int start = list[i].first;
		int end = list[i].second;


	}
}
