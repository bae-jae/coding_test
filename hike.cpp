#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int n, m;

vector<int> high;
vector<int> map[5002];

int visited[5002];
int cache[5002];

int dfs(int node)
{
	visited[node] = 1;

	int &ret = cache[node];

	if(ret != -1)
	{
		visited[node] = 0;
		return ret;
	}

	ret = 0;

	for(int i = 0; i < map[node].size(); ++i)
	{
		int next = map[node][i];

		if(visited[next] == 0 && high[next - 1] > high[node - 1])
		{
			ret = max(ret, dfs(next));
		}
	}

	visited[node] = 0;

	return ret = ret + 1;
}

int main(void)
{
	cin >> n >> m;

	for(int i = 0; i < n; ++i)
	{
		int s;
		cin >> s;

		high.push_back(s);
	}

	for(int i = 0; i < m; ++i)
	{
		int s, e;
		cin >> s >> e;

		map[s].push_back(e);
		map[e].push_back(s);
	}

	memset(cache, -1, sizeof(cache));

	int start = 0;
	int h = 987654321;

	for(int i = 0; i < high.size(); ++i)
	{
		if(h > high[i])
		{
			start = i;
			h = high[i];
		}
	}

	//dfs(start);

	for(int i = 1; i <= n; ++i)
	{
		cout << dfs(i) << "\n";
	}
}
