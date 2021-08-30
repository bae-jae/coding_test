#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int N;
int M;

int linkMap[202][202];
vector<int> map[202];

int bfs(int start, int end)
{
	int v[202];
	memset(v, 0, sizeof(v));

	if(linkMap[start][end] == 1)
		return 1;

	queue<int> q;

	q.push(start);

	while(!q.empty())
	{
		int node = q.front();
		q.pop();

		if(v[node] == 1)
			continue;

		v[node] = 1;
		linkMap[start][node] = 1;
		linkMap[node][start] = 1;

		if(node == end)
			return 1;

		for(int i = 0; i < map[node].size(); ++i)
			q.push(map[node][i]);
	}

	return 0;
}

int main(void)
{
	cin >> N;
	cin >> M;

	for(int i = 1; i <= N; ++i)
	{
		for(int j = 1; j <= N; ++j)
		{
			int s;
			cin >> s;

			if(s == 1)
			{
				map[j].push_back(i);
				map[i].push_back(j);

				linkMap[i][j] = 1;
				linkMap[j][i] = 1;
			}
		}
	}

	vector<int> list;

	for(int i = 0; i < M; ++i)
	{
		int s;
		cin >> s;

		list.push_back(s);
	}

	int Can = 1;

	for(int i = 0; i < list.size() - 1; ++i)
	{
		if(bfs(list[i], list[i + 1]) == 0)
		{
			Can = 0;
			break;
		}
	}

	if(Can == 1)
		cout << "YES";
	else
		cout << "NO";
}
