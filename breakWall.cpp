#include <iostream>
#include <queue>
#include <algorithm>
#include <string>


using namespace std;

int map[1002][1002];
int cache[2][1002][1002];

int dy[4] = {-1,  0, 1,   0};
int dx[4] = {0,   1, 0,  -1};

typedef struct{
	int y;
	int x;
	int count;
}Dir;

int outRange(int h, int w, int y, int x)
{
	if(y < 0 || y >= h)
		return 0;
	
	if(x < 0 || x >= w)
		return 0;

	return 1;
}

int findDist(int h, int w)
{
	queue<pair<Dir, int>> q;

	q.push(make_pair(Dir{0,0,0}, 0));

	while(!q.empty())
	{
		int y = q.front().first.y;
		int x = q.front().first.x;
		int ans = q.front().first.count;
		int canBreak = q.front().second;

		
		q.pop();


		if((y == (h - 1)) && (x == (w - 1)))
		{
			return ans;
		}

		if(cache[canBreak][y][x] == 1)
		{
			continue;
		}

		cache[canBreak][y][x] = 1;

		for(int i = 0; i < 4; ++i)
		{
			int mx = x + dx[i];
			int my = y + dy[i];


			if(outRange(h,w,my, mx) == 1)
			{

				if(map[my][mx] == 0)
				{
					q.push(make_pair(Dir{my, mx, ans + 1}, canBreak));
				}
				else
				{
					if(canBreak == 0)
						q.push(make_pair(Dir{my, mx, ans + 1}, 1));
				}
			}
		}
	}
	return -1;
}

int main(void)
{
	int h, w;
	cin >> h >> w;


	for(int i = 0; i < h; ++i)
	{
		string s;
		cin >> s;

		for(int j = 0; j < s.size(); ++j)
			map[i][j] = s[j] - '0';
	}


	cout << findDist(h, w) << endl;
}
