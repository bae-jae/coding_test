#include <iostream>
#include <vector>

using namespace std;

vector<vector<pair<int, int>>> map; //0 가격 1 src


vector<int> searchDist(int v)		//최단거리 과거나
{
	vector<int> upper(v + 1, 987654321);

	upper[0] = 0;	//지구 시작점은 0dla 
	bool update;

	for(int iter = 0; iter < v; ++iter)
	{
		update = false;

		for(int here = 0; here < v; ++here)
		{
			for(int i = 0; i < map[here].size(); ++i)
			{
				int there = map[here][i].second;
				int cost = map[here][i].first;

				if(upper[there] > cost + upper[here])
				{
					update = true;
					upper[there] = cost + upper[here];
				}
			}
		}

		if(update == false)
			break;
	}

	if(update == true)
		upper.clear();

	return upper;
}

vector<int> searchMaxDist(int v)		//최단거리 과거나
{
	vector<int> upper(v + 1, -987654321);

	upper[0] = 0;	//지구 시작점은 0dla 
	bool update;

	for(int iter = 0; iter < v; ++iter)
	{
		update = false;

		for(int here = 0; here < v; ++here)
		{
			for(int i = 0; i < map[here].size(); ++i)
			{
				int there = map[here][i].second;
				int cost = map[here][i].first;

				if(upper[there] < cost + upper[here])
				{
					update = true;
					upper[there] = cost + upper[here];
				}
			}
		}

		if(update == false)
			break;
	}

	if(update == true)
		upper.clear();

	return upper;
}

int main(void)
{
	int tc;
	cin >> tc;

	for(int test = 0; test < tc; ++test)
	{
		int v, w;
		cin >> v >> w;

		map.clear();
		map.resize(v + 1);

		for(int i = 0; i < w; ++i)
		{
			int a, b, d;
			cin >> a >> b >> d;

			map[a].push_back(make_pair(d, b));
		}

		vector<int> dist = searchDist(v);
		vector<int> dist1 = searchMaxDist(v);

		if(dist[1] < 987654321 - 100000000)
		{
			if(dist.size() == 0)
				cout << "INFINITY" << " ";
			else
				cout << dist[1] << " ";

			if(dist1.size() == 0)
				cout << "INFINITY" << endl;
			else
				cout << dist1[1] << endl;
		}
		else
			cout << "UNREACHABLE" << endl;
	}
}
