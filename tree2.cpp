#include <iostream>
#include <vector>

using namespace std;

vector<int> map[505];
int visited[505];
int nodeNum;
int edgeNum;

void dfs(int node)
{
	visited[node] = 1;

	for(int i = 0; i < map[node].size(); ++i)
	{
		int next = map[node][i];

		if(visited[next] == 0)
		{
			++nodeNum;
			dfs(next);
		}

		++edgeNum;
	}

}

int main(void)
{
	int n, m;

	while(1)
	{
		cin >> n >> m;
		
		if(n == 0  && m == 0)
			break;

		for(int i = 0; i < 505; ++i)
		{
			map[i].clear();
			visited[i] = 0;
		}

		for(int i = 0; i < m; ++i)
		{
			int start, end;
			cin >> start >> end;

			map[start].push_back(end);
			map[end].push_back(start);
		}

		int treeCount = 0;

		for(int i = 1; i <= n; ++i)
		{
			if(visited[i] == 0)
			{
				dfs(i);

				if(nodeNum == edgeNum / 2)
					++treeCount;
			}

			nodeNum = 0;
			edgeNum = 0;
		}

		cout << treeCount;
	}

	return 0;
}
