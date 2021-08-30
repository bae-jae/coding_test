#include <iostream>

using namespace std;

int map[1005][1005];
int cache[1005][1005];

int dy[4] = {-1, -1, 0};
int dx[4] = {-1,  0, -1};

int side;

int getBoard(int y, int x)
{
	int maxB = 987654321;

	for(int i = 0; i < 3; ++i)
	{
		int my = y + dy[i];
		int mx = x + dx[i];

		if(cache[my][mx] < maxB)
		{
			maxB = cache[my][mx];
		}
	}

	return maxB;
}

int main(void)
{
	int w, h;
	cin >> w >> h;


	for(int y = 0; y < h; ++y)
	{
		for(int x = 0; x < w; ++x)
		{
			cin >> map[y][x];
		}
	}

	for(int i = 0; i < h; ++i)
	{
		if(map[i][0] == 0)
		{
			side = 1;
			cache[i][0] = 1;
		}
	}

	for(int i = 0; i < w; ++i)
	{
		if(map[0][i] == 0)
		{
			side = 1;
			cache[0][i] = 1;
		}
	}

	for(int y = 1; y < h; ++y)
	{
		for(int x = 1; x < w; ++x)
		{
			if(map[y][x] == 0)
			{
				cache[y][x] = getBoard(y, x) + 1;

				side = max(cache[y][x], side);
			}
		}
	}

	cout << side;

}
