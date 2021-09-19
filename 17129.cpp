#include <iostream>
#include <queue>
#include <string>

#define MAX 3005;

using namespace std;

int map[3005][3005];
int visited[3005][3005];

int dy[4] = {-1, 0, 1,  0};
int dx[4] = { 0, 1, 0, -1};

int n , m;

int outRange(int y, int x)
{
	if(y < 0 || y >= n)
		return 0;
	
	if(x < 0 || x >= m)
		return 0;
	
	return 1;
}

int bfs(int y, int x)
{
	queue<pair<int, pair<int, int>>> q;
	
	q.push({0, {y, x}});
	visited[y][x] = 1;
	
	
	while(!q.empty())
	{
		int cost = q.front().first;
		
		int ry = q.front().second.first;
		int rx = q.front().second.second;
		
		q.pop();
		
		if(map[ry][rx] >= 3)
			return cost;
		
		cout << ry << " " << rx << endl;
			
		for(int i = 0; i < 4; ++i)
		{
			int my = ry + dy[i];
			int mx = rx + dx[i];
			
			if(outRange(my, mx) == 0 || visited[my][mx] == 1 || map[my][mx] == 1)
				continue;
			
			cout << "변경도니 " << my << " " << mx << endl;
			visited[my][mx] = 1;
			q.push({cost + 1, {my, mx}});
		}
	}
	
	return -1;
}
int main(void)
{
	int sy, sx;
	cin >> n >> m;
	
	for(int i= 0; i < n; ++i)
	{
		string s;
		cin >> s;
		for(int k = 0; k < s.size(); ++k)
		{
			map[i][k] = s[k] - '0';
			
			if(map[i][k] == 2)
			{
				sy = i;
				sx = k;
			}
		}
	}
	
	int ans = bfs(sy, sx);
	
	if(ans == -1)
	{
		cout << "NIE";
	}
	else
	{
		cout << "TAK" << "\n";
		cout << ans;
	}
	
	return 0;
}