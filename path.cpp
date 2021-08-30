#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> path[1010];

int pay[1010];
int visited[1010];



int main(void)
{
	int n, m;
	cin >> n >> m;

	for(int i = 0; i < m; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;

		path[a].push_back({b, c});
	}
}
