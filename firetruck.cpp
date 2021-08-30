#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<pair<int, int>>> map; // first는 cost second는 정점
vector<int> firePlace;
vector<int> fireTruck;

int min(int n1, int n2)
{
	if(n1 < n2)
		return n1;

	return n2;
}

vector<int> search(int start, int v)
{
	vector<int> dist(v + 1, 987654321);
	vector<int> visited(v + 1, 0);
	priority_queue<pair<int, int>> pq;    //fist 코스트 sec 정점 

	pq.push(make_pair(0, start));
	
	while(!pq.empty())
	{
		int cost = -pq.top().first;
		int here = pq.top().second;

		visited[here] = 1;
		int judge = 1;

		for(int i = 0; i < firePlace.size(); ++i)
		{
			if(visited[firePlace[i]] == 0)
			{
				judge = 0;
				break;
			}
		}

		if(judge == 1)
			break;

		pq.pop();

		if(dist[here] < cost)
			continue;

		for(int i = 0; i < map[here].size(); ++i)
		{
			int nextCost = map[here][i].first + cost;
			int there = map[here][i].second;

			if(dist[there] > nextCost)
			{
				dist[there] = nextCost;
				pq.push(make_pair(-nextCost, there));
			}
		}
	}

	return dist;
}

int main(void)
{
	int tc;
	cin >> tc;

	for(int test = 0; test < tc; ++test)
	{
		// n은 화재장소 
		int v, e, n, m;
		cin >> v >> e >> n >> m;

		fireTruck.clear();
		firePlace.clear();
		map.clear();

		map.resize(v + 1);

		vector<int> fireTime(v + 1, 987654321);

		for(int i = 0; i < e; ++i)		//e
		{
			int a, b, price;
			cin >> a >> b >> price;

			map[a].push_back(make_pair(price, b));
			map[b].push_back(make_pair(price, a));
		}//map 받는거

		for(int i = 0; i < n; ++i)
		{
			int place;
			cin >> place;

			firePlace.push_back(place);
		}

		for(int i = 0; i < m; ++i)
		{
			int place;
			cin >> place;

			fireTruck.push_back(place);
		}

		for(int i = 0; i < fireTruck.size(); ++i)
		{
			vector<int> dist = search(fireTruck[i], v);

			for(int j = 0; j < firePlace.size(); ++j)
			{
				fireTime[firePlace[j]] = min(dist[firePlace[j]], fireTime[firePlace[j]]);  
			}
		}

		int sum = 0;


		for(int i = 0; i < firePlace.size(); ++i)
			sum += fireTime[firePlace[i]];

		cout << sum << endl;
	}
}
