#include <iostream>
#include <vector>

using namespace std;

int price[123460];
vector<int> map[123460];
int visited[123460];

int dfs(int node)
{
	visited[node] = 1;
	int ans = price[node];

	for(int i = 0; i < map[node].size(); ++i)
	{
		int next = map[node][i];

		if(visited[next] == 0)
		{
			ans += dfs(next);
		}
	}

	if(ans < 0)
		ans = 0;

	return ans;

}

int main(void)
{
	int n;
	cin >> n;

	int start = 2;

	for(int i = 0; i < n - 1; ++i)
	{
		char animal;
		int p;
		int to;
		cin >> animal >> p >> to;

		if(animal == 'S')
			price[start] = p;
		else
			price[start] = -p;

		map[to].push_back(start);
		map[start].push_back(to);

		++start;
		cout << i << endl;
	}

	cout << dfs(1);
}
