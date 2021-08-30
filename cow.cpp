#include <iostream>
#include <queue>

using namespace std;

int dist[105][105];
int map[105][105];
int n;

int my[16] = {0,  0,  1, -1, 3, 2, 1, 0, -1, -2, -3, -2, -1, 0, 1, 2};
int mx[16] = {1, -1,  0,  0, 0, 1, 2, 3, 2, 1, 0, -1, -2, -3, -2, -1};

int outRange(int y, int x)
{
	if(y < 0 || y >= n)
		return 0;

	if(x < 0 || x >=n)
		return 0;

	return 1;
}

int search(int t)
{
	priority_queue<pair<int, pair<int, int>>> q;
	
	q.push(make_pair(0, make_pair(0,0)));
	dist[0][0] = 0;

	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			dist[i][j] = 987654321;

	while(!q.empty())
	{
		int y = q.top().second.first;
		int x = q.top().second.second;
		int cost = -q.top().first;
		q.pop();

		if(dist[y][x] < cost)
			continue;

		int tob = (n - y -1 ) + (n - x - 1);

		if(tob <= 2)
		{
			dist[n-1][n-1] = min(dist[n-1][n-1], cost + tob * t);
		}


		for(int i = 0; i < 16; ++i)
		{
			int xx = x + mx[i];
			int yy = y + my[i];

			if(outRange(yy, xx) == 0)
				continue;

			int nxtcost = cost + 3 * t + map[yy][xx];

			if(dist[yy][xx] < nxtcost)
				continue;

			dist[yy][xx] = nxtcost;
			q.push(make_pair(-nxtcost, make_pair(yy, xx)));
		}
	}

	return dist[n-1][n-1];
}

int main(void)
{
	int t;

	cin >> n >> t;

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			cin >> map[i][j];
		}
	}

	cout << search(t);
}
