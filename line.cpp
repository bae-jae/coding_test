#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> map[32005];
int visited[32005];
vector<int> answer;

void dfs(int node)
{
	if(visited[node] == 1)
		return;

	visited[node] = 1;

	for(int i = 0; i < map[node].size(); ++i)
	{
		int next = map[node][i];

		if(visited[next] == 0)
			dfs(next);
	}

	answer.push_back(node);
}

int main(void)
{
	int n, m;
	cin >> n >> m;

	for(int i = 0; i < m; ++i)
	{
		int v, next;
		cin >> v >> next;

		map[v].push_back(next);
	}

	for(int i = 1; i <= n; ++i)
	{
		if(visited[i] == 0)
		{
			cout << " 허출도ㅓㅣㅁ " << i << endl;
			dfs(i);
		}
	}

	reverse(answer.begin(), answer.end());

	for(int i = 0; i < answer.size(); ++i)
	{
		cout << answer[i] << " ";
	}


}
