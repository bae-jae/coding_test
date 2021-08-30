#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<pair<int, int>> map[1010];
priority_queue<int> store[1010];

void dk(int n, int k)
{
	priority_queue<pair<int, int>> pq;
	
	pq.push({0,1});
	store[1].push(0);
	
	cout << n << " " << k << endl;
	
	while(!pq.empty())
	{
		int cost = -pq.top().first;
		int node = pq.top().second;
		
		pq.pop();
		
		
		for(int i = 0; i < map[node].size(); ++i)
		{
			int nextCost = map[node][i].second + cost;
			int nextNode = map[node][i].first;
			
			if(store[nextNode].size() < k)
			{
				store[nextNode].push(nextCost);
				pq.push({-nextCost, nextNode});
			}
			else
			{
				if(nextCost < store[nextNode].top())
				{
					store[nextNode].pop();
					store[nextNode].push(nextCost);	
					pq.push({-nextCost, nextNode});
				}
				
			}
			
		}
	}
	
	for(int i = 1; i <= n; ++i)
	{
		int len = store[i].size();
		
		if(store[i].size() < k)
			cout << -1 << "\n";
		else{
			cout << store[i].top() << "\n";
		}
	}
}

int main(void)
{
	int n , m ,k;
	cin >> n >> m >> k;
	
	for(int i = 0; i < m; ++i)
	{
		int s,e,c;
		cin >> s >> e >> c;
		
		map[s].push_back({e, c});
	}
	
	dk(n, k);
}