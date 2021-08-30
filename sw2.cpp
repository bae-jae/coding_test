#include <iostream>
#include <map>

using namespace std;

int board[4][4];

int mx[4] = {0, 1, 0, -1};
int my[4] = {-1, 0, 1, 0};
int cache[4][4][9] = 0;

map<vector<int>, int> m;

int outRange(int x, int y)
{
	if(x < 0 || x >= 4)
		return 0;
	if(y < 0 || y >= 4)
		return 0;

	return 1;
}

int search(int x, int y, int count, vector<int>& v)
{
	if(outRange(x, y) == 0)
		return 0;

	int& ret = cache[y][x][count];

	if(count == 6) //종료 했는경
	{
		return board[y][x];
	}

	for(int i = 0; i <4; ++i)
	{
		ret += search(x + mx[i], y + my[i], count + 1);
	}

	return ret;
}

int main(void)
{
	int tc;
	cin >> tc;

	for(int test = 0; test < tc; ++test)
	{
		map.clear();

		for(int i = 0; i < 4; ++i)
		{
			for(int j = 0; j < 4; ++j)
			{
				int num = 0;
				cin >> num;

				board[i][j] = num;
			}
		}

		cout << search()


	}
}
