#include <iostream>
#include <queue>

using namespace std;

int map[1005][1005];
int visited[1005][1005][2];
int startX, startY;
int exitX, exitY;
int endX, endY;

int dy[4] = { -1, 0, 1,  0};
int dx[4] = {  0, 1,  0, -1};

int outRange(int x, int y)
{
	if(x < 1 || x >= (endX + 1))
		return 0;
	
	if(y < 1 || y >= (endY + 1))
		return 0;
	
	return 1;
}
int main(void)
{
	cin >> endX >> endY;
	cin >> startX >> startY;
	cin >> exitX >> exitY;
	
	for(int i = 1; i <= endX; ++i)
	{
		for(int j = 1; j <= endY; ++j)
		{
			int s;
			cin >> s;
			
			map[i][j] = s;
		}
	}
	
	
	//			    행	열      벽부슨 움직인 횟수
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push({{startX, startY}, {1, 0}});
	
	while(!q.empty())
	{
		int mx = q.front().first.first;
		int my = q.front().first.second;
			
		int broke = q.front().second.first;
		int cost = q.front().second.second;
		
		q.pop();
		
		if(visited[mx][my][broke] == 1)
			continue;
		
		visited[mx][my][broke] = 1;
		
		if(mx == exitX && my == exitY)
		{
			cout << cost;
			return 0;
		}
			
		for(int i = 0; i < 4; ++i)
		{	
			int rx = mx + dy[i];
			int ry = my + dx[i];
			
			if(outRange(rx, ry) == 1)
			{
				if(visited[rx][ry][broke] == 1)
					continue;
				
				if(map[rx][ry] == 1)
				{
					if(broke == 1)
					{
						q.push({{rx, ry}, {0, cost + 1}});
					}
					else
						continue;
				}
				else{
					q.push({{rx, ry}, {broke, cost + 1}});
				}
				
			}
		}
	}
	cout << -1;
}