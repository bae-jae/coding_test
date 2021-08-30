#include <iostream>
#include <queue>
#include <cstring>
#include <unordered_set>

using namespace std;

vector<int> map[200005];
int n, q;

int f[200005];
int visited[200005];
int backward[200005];
int from, last;
unordered_set<int> cycle;


void dfs(int cur, int undo)
{
	visited[cur] = 1;

	for(int i = 0; i < map[cur].size(); ++i)
	{
		int next = map[cur][i];

		if(visited[next] == 0)
		{
			backward[next] = cur;
			dfs(next, cur);
		}
		else if(f[next] == 0 && next != undo)
		{
			from = next;
			last = cur;
		}
	}

	f[cur] = 1;
}

void bfs(int node)
{
	int ans = 0;

	queue<int> q;

	q.push(node);

	while(!q.empty())
	{
		int now = q.front();

		q.pop();
		
		if(visited[now] != -1)
			continue;

		visited[now] = node;

		for(int i = 0; i < map[now].size(); ++i)
		{
			int next = map[now][i];

			if(visited[next] == -1 && cycle.count(next) > 0)
				q.push(next);
		}
	}
}

int main(void)
{
	cin >> n >> q;

	for(int i = 0; i < n; ++i)
	{
		int s, e;
		cin >> s >> e;

		map[s].push_back(e);
		map[e].push_back(s);
	}

	while(1)
	{
		cycle.insert(last);

		if(last == from)
			break;

		last = backward[last];
	}

	memset(visited, -1, sizeof(visited));

	for(int v: cycle)
	{
		bfs(v);
	}



	for(int i = 0; i < q; ++i)
	{
		int s, e;
		cin >> s >> e;

		if(cycle.count(s) && cycle.count(e))
			cout << "2\n";
		else if(visited[s] != visited[e])
			cout << "2\n";
		else
			cout << "1\n";
	}
}
