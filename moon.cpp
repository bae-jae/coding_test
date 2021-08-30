#include <iostream>
#include <string>
#include <ctype.h>
#include <queue>

using namespace std;

int r, c;

string map[51];

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0,  1, 0, -1};
int visited[1 << 7][51][51];


int outRange(int y, int x)
{
	if(y < 0 || y >= r)
		return 0;
	if(x < 0 || x >= c)
		return 0;

	return 1;
}

int bfs(int startY, int startX)
{
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push({{startY, startX}, {0, 0}});

	visited[0][startY][startX] = 1;
	

	while(!q.empty())
	{
		int y = q.front().first.first;
		int x = q.front().first.second;

		int cost = q.front().second.first;
		int key = q.front().second.second;

		q.pop();

		if(map[y][x] == '1')
			return cost;

		for(int i = 0; i < 4; ++i)
		{
			int my = y + dy[i];
			int mx = x + dx[i];

			if(outRange(my, mx) == 1 && map[my][mx] != '#' && visited[key][my][mx] == 0)
			{

				if(map[my][mx] == '.' || map[my][mx] == '1')
				{
					visited[key][my][mx] = 1;
					q.push({{my, mx}, {cost + 1, key}});
				}
				else if('a' <= map[my][mx] && map[my][mx] <= 'f')
				{
					int make_key = key | (1 << (map[my][mx] - 'a')); 

					visited[make_key][my][mx] = 1;
					q.push({{my, mx}, {cost + 1, make_key}});
				}
				else
				{
					int temp = key & (1 << (map[my][mx] - 'A'));

					if(temp != 0) 
					{
						visited[temp][my][mx] = 1;
						q.push({{my, mx}, {cost+ 1, key}});
					}
				}
			}
		}
	}

	return -1;
	
}

int main(void)
{
	cin >> r >> c;
	int startY, startX;

	for(int i = 0; i < r; ++i)
	{
		string s;
		cin >> s;


		for(int j = 0; j < s.size(); ++j)
		{
			if(s[j] == '0')
			{
				startY = i;
				startX = j;
				s[j] = '.';
			}
		}

		map[i] = s;
	}

	cout << bfs(startY, startX);


}
