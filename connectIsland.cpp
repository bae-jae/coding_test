#include <iostream>
#include <queue>
#include <string.h>

using namespace std;
int parent[101];
int len[101];

void init(void)
{
	for(int i = 0; i < 101; ++i)
	{
		parent[i] = i;
		len[i] = 1;
	}
}

int find(int n)
{
	if(n == parent[n])
		return n;

	return parent[n] = find(parent[n]);
}

void union_set(int here, int there)
{
	int f = find(here);
	int s = find(there);
	
	if(len[s] > len[f])
	{
		int swap = s;
		f = s;
		s = swap;
	}
	
	if(len[f] == len[s])
		++len[f];

	parent[s] = f;
}
int search(int n, vector<vector<int>> cost)
{
	priority_queue<vector<int>> pq;
	
	int answer = 0;
	int visited[105];

	init();
	for(int i = 0; i < cost.size(); ++i)
	{
		vector<int> v(3, 0);

		v[0] = -cost[i][2];
		v[1] = cost[i][0];
		v[2] = cost[i][1];

		pq.push(v);
	}

	while(!pq.empty())
	{
		int price = -pq.top()[0];
		int here = pq.top()[1];
		int there = pq.top()[2];

		pq.pop();

		int f = find(here);
		int s = find(there);

		if(f == s)
			continue;

		union_set(f, s);
		answer += price;

	}

	return answer;
}

int main(void)
{
	int tc;
	cin >> tc;

	for(int test = 0; test < tc; ++test)
	{
		int n;
		cin >> n;

		int costN;
		cin >> costN;

		vector<vector<int>> costs;

		for(int i = 0; i < costN; ++i)
		{
			vector<int> v(3, 0);

			int s, e, c;
			cin >> s >> e >> c;
		}
	}
}
