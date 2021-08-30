#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<pair<int, int>>> map;
int maxDist[101];
int minDist[101];

void init()
{
	for(int i = 0; i < 101; ++i)
	{
		minDist[i] = -987654321;
		maxDist[i] = 98764321;
	}
}

int vel(int v)
{
	maxDist[0] = 0;	//출발점 추기
	bool change = false;

	for(int i = 0; i < v; ++i)
	{
		change = false;

		for(int here = 0; here < v; ++here)
		{
			for(int j = 0; j < map[here].size(); ++j)
			{
				int there = map[here][j].first;
				int cost = map[here][j].second + maxDist[here];

				if(maxDist[there] > cost)
				{
					maxDist[there] = cost;
					change = true;
				}
			}
		}
	}

	if(change == true)
		return 987654321;
	else
		return maxDist[1];
}

int maxvel(int v)
{
	minDist[0] = 0;	//출발점 추기
	bool change = false;

	for(int i = 0; i < v; ++i)
	{
		change = false;

		for(int here = 0; here < v; ++here)
		{
			for(int j = 0; j < map[here].size(); ++j)
			{
				int there = map[here][j].first;
				int cost = map[here][j].second + minDist[here];

				if(minDist[there] < cost)
				{
					minDist[there] = cost;
					change = true;
				}
			}
		}
	}

	if(change == true)
		return 987654321;
	else
		return minDist[1];
}

int main(void)
{
	int tc;
	cin >> tc;

	for(int test =0; test < tc; ++test)
	{
		int v, w;
		cin >> v >> w;

		init();
		map.clear();
		map.resize(v);

		for(int i = 0; i < w; ++i)
		{
			int s, e, p;
			cin >> s >> e >> p;

			map[s].push_back(make_pair(e, p));
		}

		int ans1 = vel(v);

		if(ans1 == 98764321)
			cout << 
	}
}
