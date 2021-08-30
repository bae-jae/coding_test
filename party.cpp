#include <iostream>
#include <queue>

using namespace std;

int n, m, x;

vector<pair<int, int>> map[1002];
vector<pair<int, int>> reverseMap[1002];


priority_queue<pair<int, int>> pq;
int ans[1002];
int homeCost[1002];

void dk(int home, vector<pair<int, int>> m[1002])
{
	for(int i = 0; i < 1002; ++i)
		homeCost[i] = 987654321;

	pq.push(make_pair(0, home));
	
	while(!pq.empty())
	{
		int cost = -pq.top().first;
		int node = pq.top().second;

		pq.pop();

		if(homeCost[node] < cost)
			continue;

		homeCost[node] = cost;

		for(int i = 0; i < m[node].size(); ++i)
		{
			int next = m[node][i].first;
			int nextCost = cost + m[node][i].second;

			if(homeCost[next] > nextCost)
			{
				homeCost[next] = nextCost;
				pq.push(make_pair(-nextCost, next));
			}
		}
	}

	for(int i = 1; i <= n; ++i)
		ans[i] += homeCost[i];
}

int main(void)
{
	cin >> n >> m >> x;

	for(int i = 0; i < m; ++i)
	{
		int s, e, c;
		cin >> s >> e >> c;

		map[s].push_back(make_pair(e ,c));
		reverseMap[e].push_back(make_pair(s, c));
	}

	int fans = 0;

	dk(x, map);
	dk(x, reverseMap);
	for(int i = 1; i <= n; ++i)
	{
		fans = max(fans, ans[i]);
	}

	cout << fans;
}
