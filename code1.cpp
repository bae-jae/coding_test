#include <iostream>
#include <string.h>

using namespace std;

int map[51][51];
int n, m;

int check(int y, int x)
{
	for(int i = 0; i < m; ++i)
	{
		if(map[y][i] == 1)
			return 0;
	}

	for(int i = 0; i < n; ++i)
	{
		if(map[i][x] == 1)
			return 0;
	}

	return 1;
}

void print(void)
{
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
			cout << map[i][j] << " ";

		cout  << "\n";
	}
}

int main(void)
{
	int tc;
	cin >> tc;

	for(int test = 0; test < tc; ++test)
	{
		cin >> n >> m;

		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < m; ++j)
			{
				int s;
				cin >> s;

				map[i][j] = s;
			}
		}

		int count = 0;

		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < m; ++j)
			{
				if(map[i][j] == 0)
				{
					if(check(i, j) == 1)
					{
						++count;
						break;
					}

				}
			}
		}


		if(count % 2 == 0)
			cout << "Vivek";
		else
			cout << "Ashish";

		cout << "\n";

	}
}
