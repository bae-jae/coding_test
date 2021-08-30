#include <iostream>
#include <queue>
#include <vector>

using namespace std;
vector<vector<int>> v;
int visited[50005];

int bfs(void)
{
	queue<pair<int, int>> q;

	q.push(make_pair(1, 1));

	while(!q.empty())
	{
		int arrive = q.front().first;
		int ord = q.front().second;
		q.pop();

		if(visited[arrive] != 0)
			continue;

		visited[arrive] = ord;

		for(int i = 0; i < v[arrive].size(); ++i)
			q.push(make_pair(v[arrive][i], ord + 1));
	}
}

int main(void)
{
	int n;
	cin >> n;

	v.resize(n + 1);

	for(int i = 1; i <= n - 1; ++i)
	{
		int s, e;
		cin >> s >> e;

		v[s].push_back(e);
		v[e].push_back(s);
	}

	bfs();

	cin >> n;

	for(int i = 0; i < n; ++i)
	{

		int s, e;
		cin >> s >> e;


		if(visited[s] > visited[e])
		{
			int swap = s;
			s = e;
			e = swap;
		}

		while(visited[s] != visited[e])
		{
			for(int i = 0; i < v[e].size(); ++i)
			{
				if(visited[e] - 1 == visited[v[e][i]])
				{
					e = v[e][i];
					break;
				}
			}
		}

		while(s != e)
		{
			for(int i = 0; i < v[s].size(); ++i)
			{
				if(visited[s] -1 == visited[v[s][i]])
				{
					s = v[s][i];
					break;
				}
			}

			for(int i = 0; i < v[e].size(); ++i)
			{
				if(visited[e] -1 == visited[v[e][i]])
				{
					e = v[e][i];
					break;
				}
			}
		}

		cout << s << "\n";
	}
}
