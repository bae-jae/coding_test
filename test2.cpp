#include <iostream>
#include <string>

using namespace std;

int map[4][4];
int boolmap[4][4];

int dy = [-1, 0, 1, 0];
int dx = [0, 1, 0, -1];

int minMvCount;

int outRange(int y, int x)
{
	if(y < 0 || y >= 4)
		return 0;
	if(x < 0 || x >= 4)
		return 0;

	return 1;
}

//y, x 
pair<int, int> cntmove(int my, int mx, int dir)
{
	if(dir == 0)
	{
		for(int y = my -1; y >= 0; --y)
		{
			if(map[y][mx] != 0)
				return make_pair(y, mx);
		}

		return make_pair(0, mx);
	}
	else if(dir == 1)
	{
		for(int x = mx + 1; x < 4; ++x)
		{
			if(map[my][x] != 0)
				return make_pair(my, x);
		}

		return make_pair(my, 3);
	}
	else if(dir == 2)
	{
		for(int y = my + 1; y < 4; ++y)
		{
			if(map[y][x] != 0)
				return make_pair(y, mx);
		}

		return make_pair(3, mx);
	}
	else
	{
		for(int x = mx - 1; x >= 0; --x)
		{
			if(map[my][x] != 0)
				return make_pair(my, x);
		}

		return make_pair(my, 0);
	}
}

void eraseMap(int target)
{
	for(int y = 0; y < 4; ++y)
	{
		for(int x = 0; x < 4; ++x)
		{
			if(map[y][x] == target)
				map[y][x] = 0;
		}
	}
}

int min(int n1, int n2)
{
	if(n1 < n2)
		return n1;

	return n2;
}

void search(int y, int x. int target, int moveCnt)
{
	if(outRange(y, x) == 0)
		return;

	if(boolMap[y][x] == 1)
		return;

	boolMap[y][x] = 1;

	if(map[y][x] == target)
	{
		moveCnt += 1;
		minMvCount = min(moveCnt, minMvCount);
	}

	for(int i = 0; i <4; ++i)
	{
		search(y + dy[i] , x + dx[i] , target, moveCnt + 1);

		pair<int, int> pos = cntMove(y, x, i);
		search(pos.first, pos.second, target, moveCnt + 1);
	}
}

int findCard(int y, int x. int target, int moveCnt)
{
	if(outRange(y, x) == 0)
		return;

	if(boolMap[y][x] == 1)
		return;

	boolMap[y][x] = 1;

	if(map[y][x] != 0)
	{
		minMvCount = min(moveCnt, minMvCount);
		return map[y][x];
	}

	for(int i = 0; i <4; ++i)
	{
		search(y + dy[i] , x + dx[i] , target, moveCnt + 1);

		pair<int, int> pos = cntMove(y, x, i);
		search(pos.first, pos.second, target, moveCnt + 1);
	}
}

void init()
{
	memset(boolMap, 0, sizeof(boolMap));	//초기화 
	minMvCount = 987654321;
}

void answerSearch(int y, int x, int n)
{
	int answer = 0;

	for(int i = 0; i < n; ++i)
	{
		init();

		answer += search(y, x);	//움직임 최소 구함
		eraseMap(map[y][x]);

		init();
		answer += findCard(y, x);
	}
}

int main(void)
{
	int tc;
	cin >> tc;

	for(int test = 0; test < tc; ++test)
	{
		int candN;

		for(int y = 0; y < 4; ++y)
		{
			for(int x = 0; x < 4; ++x)
			{
				int cand; 
				cin >> cand;

				map[y][x] = cand;

				if(cand != 0)
					++candN;
			}
		}

		int r, c;
		cin >> r >> c;

		answerSearch(r, c, candN / 2);
	}
}
