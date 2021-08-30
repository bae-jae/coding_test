#include <iostream>
#include <queue>

using namespace std;


int map[51][51];
int boolmap[51][51];

int movey[4] = {-1, 0, 1, 0};
int movex[4] = {0, 1, 0, -1};

int outRange(int y, int x, int my, int mx)
{
	if(y < 0 || y >= my)
		return 0;

	if(x < 0 || x >= mx)
		return 0;

	return 1;
}

void floorWater(int y, int x)
{
	for(int i = 0; i < y; ++ i)
	{
		for(int j = 0; j < x; ++j)
		{
			if(map[i][j] == 2)
			{
				for(int m = 0; m < 4; ++ m)
				{
					int my = i + movey[m];
					int mx = j + movex[m];

					if((outRange(my, mx, y, x) == 1) && map[my][mx] != 2 && map[my][mx] != 1 && map[my][mx] != 4)
						map[my][mx] = -1;
				}
			}
		}
	}

	for(int i = 0; i < y; ++ i)
	{
		for(int j = 0; j < x; ++j)
		{
			if(map[i][j] == -1)
				map[i][j] = 2;
		}
	}
}
int main(void)
{
	int y, x;
	int sx, sy;
	cin >> y >> x;

	queue<pair<int, pair<int, int>>> q;

	for(int i = 0; i < y; ++i)
	{
		for(int j = 0; j < x; ++j)
		{
			char c;
			cin >> c;

			if(c == 'D')
				map[i][j] = 1;	//탈출지점
			else if(c == '.')
				map[i][j] = 0;	//통과가
			else if(c == '*')
				map[i][j] = 2; 	//물임 
			else if(c == 'X')
				map[i][j] = 4;	//돌
			else
			{
				sy = i;
				sx = j;
				map[i][j] = 3;
			}
		}
	}


	q.push(make_pair(0, make_pair(sy, sx)));
	int undowaterLevel = -1;
	int answer = -1;

	while(!q.empty())
	{
		int waterLevel = q.front().first;
		int my = q.front().second.first;
		int mx = q.front().second.second;

		q.pop();

		if(boolmap[my][mx] == 1)
			continue;
		else
			boolmap[my][mx] = 1;


		if(map[my][mx] == 1)
		{
			answer = waterLevel;
			break;
		}

		if(undowaterLevel != waterLevel)
		{
			undowaterLevel = waterLevel;
			floorWater(y, x);
		}

		for(int i = 0; i < 4; ++i)
		{
			int ry = my + movey[i];
			int rx = mx + movex[i];

			if(outRange(ry, rx, y, x) == 1)
			{
				if(boolmap[ry][rx] == 0 && map[ry][rx] != 2 && map[ry][rx] != 4)
				{
					q.push(make_pair(waterLevel + 1, make_pair(ry, rx)));
				}
			}
		}
	}

	if(answer != -1)
		cout << answer;
	else
		cout << "KAKTUS";
}
