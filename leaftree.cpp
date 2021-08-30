#include <iostream>
#include <vector>

using namespace std;

vector<int> map[51];
int visited[51];


void dfs(int node)
{
	visited[node] = 1;
	int delNode = 0;

	for(int i = 0; i < map[node].size(); ++i)
	{
		int next = map[node][i];

		if(visited[next] == 0 && next != -1)
			dfs(next);
	}
}

int main(void)
{
	int n;
	cin >> n;

	for(int i = 0; i < n; ++i)
	{
		int go;
		cin >> go;

		if(go != -1)
			map[go].push_back(i);
	}

	int delNode;
	cin >> delNode;
	
	dfs(delNode);

	int leafCount = 0;

	for(int i = 0; i < n; ++i)
	{
		int leaf = 1;

		if(visited[i] == 0)
		{
			for(int j = 0; j < map[i].size(); ++j)
			{
				int next = map[i][j];

				if(visited[next] == 0)
				{
					leaf = 0;
					break;
				}
			}
		}
		else
			leaf = 0;

		if(leaf == 1)
			++leafCount;
	}

	cout << leafCount;

}
