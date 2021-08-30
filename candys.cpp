#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n, m;
int map[305][305];
int cache[305][305];

int main(void)
{
	cin >> n >> m;

	for(int i = 0; i < n; ++i)
	{
		int y, x;
		cin >> x >> y;

		map[x][y] = 1;
	}

	int sec = m;

	for(int i = 1; i < 301; ++i)
	{
		--sec;

		if(map[0][i] == 1)
		{
			cache[0][i] = cache[0][i - 1] + sec;
		}
		else
			cache[0][i] = cache[0][i-1];

		if(map[i][0] == 1)
		{
			cache[i][0] = cache[i - 1][0] + sec;
		}
		else
			cache[i][0] = cache[i-1][0];
	}

	for(int y = 1; y < 301; ++y)
	{
		--m;
		m = max(m, 0);
		
		int rowSec = m;
		
		for(int x = 1; x < 301; ++x)
		{
			--rowSec;
			rowSec = max(0, rowSec);

			if(map[y][x] == 1)
			{
				int total = max(cache[y - 1][x], cache[y][x - 1]);
				cache[y][x] =  rowSec + total;
			}
			else
				cache[y][x] = max(cache[y-1][x], cache[y][x-1]);
		}
	}

	cout << cache[300][300];
	return 0;
}
