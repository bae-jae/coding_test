#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int r, c;
int cache[1501][1501];

int apple[1501][1501];
int banana[1501][1501];

int dy[3] = {0, -1, -1};
int dx[3] = {-1, -1, 0};

int find(void)
{

	for(int x = 0; x < c; ++x)
	{
		cache[0][x] = banana[0][x + 1];
	}

	for(int y = 1; y < r; ++y)
	{
		cache[y][0] = cache[y-1][0] + banana[y][1];
	}

	for(int y = 1; y < r; ++y)
	{
		for(int x = 1; x < c; ++x)
		{
			cache[y][x] = max(cache[y- 1][x- 1], cache[y -1][x]) + apple[y][x - 1] + banana[y][x + 1];
			cache[y][x] = max(cache[y][x], cache[y][x - 1] - banana[y][x] + banana[y][x+1]);
		}
	}

	return cache[r-1][c-1];
}


int main(void)
{
	cin >> r >> c;


	for(int i = 0; i < r; ++i)
	{
		for(int j = 0; j < c; ++j)
		{
			char s;
			int n;
			cin >> s >> n;

			if(s == 'B')
			{

				banana[i][j] = n;
			}
			else
			{
				apple[i][j] = n;
			}
		}
	}

	for(int i = 0; i < r; ++i)
	{
		for(int j = 0; j < c; ++j)
		{
			apple[i][j] += apple[i][j - 1];
			banana[i][c - j - 1] += banana[i][c - j];
		}
	}

	cout << find();
}
