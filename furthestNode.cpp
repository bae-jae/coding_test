#include <iostream>
#include <string.h>

using namespace std;

int map[20005][20005];
int visited[20005];

void changeVToA(vector<pair<int, int>> map)
{
	memset(map, 0, sizeof(map));
	memset(visited, 0, sizeof(visited));

	for(int i = 0; i < map.size(); ++i)
	{
		int start = map[i].first;
		int end = map[i].second;

		map[start][end] = 1;
		map[end][start] = 1
	}
}

int max(int n1, int n2){
	if(n1 > n2)
		return n1;

	return n2;
}

int search(int n, int start, int len)
{
	visited[start] = 1;

	int answer = -1;

	for(int i = 1; i <= n; ++i)
	{
		if(visited[i] == 0 && map[start][i] == 1)
		{
			answer = max(answer, search(n, i, len + 1));
		}
	}

	visited[start] = 0;

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
		visited[1] = 1;
		
		int maxLen = -1;
		int answer = 0;

		for(int i = 0; i < n; ++i)
		{
			if(map[1][i] == 1)
			{
				int cand = search(n, i , 0);

				if(maxLen == cand)
					++answer;
				else if(maxLen < cand)
				{
					answer = 0;
					maxLen = cand;
				}
			}
		}
		cout << answer << endl;
	}
}
