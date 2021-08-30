#include <iostream>
#include <queue>
#include <string>

using namespace std;

int map[1005][1005];
int visited[1005][1005][11];

int dy[4] = { -1, 0, 1,  0};
int dx[4] = {  0, 1,  0, -1};

int n, m, k;

int outRange(int y, int x)
{
	if(x < 1 || x >= (m + 1))
		return 0;
	
	if(y < 1 || y >= (n + 1))
		return 0;
	
	return 1;
}

int main(void)
{
	cin >> n >> m >> k;
	
	for(int i = 1; i <= n; ++i)
	{
		string s;
		cin >> s;
		
		for(int j = 0; j < s.size(); ++j)
			map[i][j + 1] = s[j] - '0';
	}
	
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push({{1, 1}, {k, 1}});
	
	while(!q.empty())
	{
		int my = q.front().first.first;
		int mx = q.front().first.second;
			
		int broke = q.front().second.first;
		int cost = q.front().second.second;
		
		q.pop();
		
		if(visited[my][mx][broke] == 1)
			continue;
		
		visited[my][mx][broke] = 1;
		
		if(mx == m && my == n)
		{
			cout << cost;
			return 0;
		}
			
		for(int i = 0; i < 4; ++i)
		{	
			int ry = my + dy[i];
			int rx = mx + dx[i];
			
			if(outRange(ry, rx) == 1)
			{
				if(visited[ry][rx][broke] == 1)
					continue;
				
				if(map[ry][rx] == 1)
				{
					if(broke >= 1)
					{
						q.push({{ry, rx}, {broke - 1, cost + 1}});
					}
					else
						continue;
				}
				else{
					q.push({{ry, rx}, {broke, cost + 1}});
				}
				
			}
		}
	}
	cout << -1;
}