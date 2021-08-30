#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<vector<pair<int, double>>> map;

double search(int v)
{
	priority_queue<pair<double, int>> pq;
	vector<double> dist(v + 1, 0.0);
	
	dist[0] = 1.0;
	pq.push(make_pair(-1, 0));

	while(!pq.empty())
	{
		int here = pq.top().second;
		double cost = -pq.top().first;

		pq.pop();

		if(dist[here] < cost)
			continue;

		for(int i = 0; i < map[here].size(); ++i)
		{
			int there = map[here][i].first;
			double candcost = cost * map[here][i].second;

			if(candcost < dist[there] || dist[there] == 0.0)
			{
					dist[there] = candcost;
					pq.push(make_pair(-candcost, there));
			}
		}
	}

	return dist[v-1];
}

int main(void)
{
	int tc;
	cin >> tc;

	for(int test = 0; test < tc; ++test)
	{
		int v, e;
		cin >> v >> e;

		map.clear();
		map.resize(v + 1);

		for(int i = 0; i < e; ++i)
		{
			int h, t;
			double cost;

			cin >> h >> t >> cost;

			map[h].push_back(make_pair(t, cost));
			map[t].push_back(make_pair(h, cost));
		}

		printf("%.10f\n", search(v));
	}
}
