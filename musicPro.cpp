#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> map[1001];
vector<int> ans;

int finish[1001];
int visited[1001];

void dfs(int node)
{
	visited[node] = 1;

	for(int i = 0; i < map[node].size(); ++i)
	{
		int next = map[node][i];

		if(visited[next] == 0)
			dfs(next);
		else
		{
			if(finish[next] == 0)
				ans.push_back(node);
		}
	}

	ans.push_back(node);
	finish[node] = 1;
}

int main(void)
{
	int n, m;
	cin >> n >> m;

	for(int i = 0; i < m; ++i)
	{
		int human;
		cin >> human;

		vector<int> makeMap;

		for(int j = 0; j < human; ++j)
		{
			int s;
			cin >> s;

			makeMap.push_back(s);
		}

		for(int j = 0; j < makeMap.size() - 1; ++j)
			map[makeMap[j]].push_back(makeMap[j+1]);
	}

	for(int i = 1; i <= n; ++i)
	{
		if(visited[i] == 0)
			dfs(i);
	}

	reverse(ans.begin(), ans.end());

	cout << ans.size() << endl;

	if(ans.size() >= n + 1)
		cout << 0 << "\n";
	else{
		for(int i = 0; i < ans.size(); ++i)
			cout << ans[i] << "\n";
	}

}
