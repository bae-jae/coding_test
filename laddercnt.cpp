#include<iostream>

using namespace std;

int map[15][35];
int n, h;
int answer = 987654321;

int drawMap(void)
{
	for(int i = 1; i <= h; ++i)
	{
		for(int j = 1; j <= n; ++j)
		{
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int allclear(void)
{
	for(int i = 1; i < n; ++i)
	{
		int start = i;

		for(int j = 1; j <= h; ++j)
		{
			if(map[j][start] == 1)
			{
				if(map[j][start + 1] == 1)
					++start;	//오른쪽 이동
				else
					--start;

			}
		}

		if(start != i)
		{
			return i;
		}
	}

	return 0;
}

void search(int idx, int next)
{
	int go = allclear();
	int answer = 987654321;

	if(go == 0)
	{
		answer = min(answer, next);
		return;
	}

	if(next == 3)
		return;
	
	for(int i = 1; i < n; ++i)
	{
		for(int j = idx; j <= h; ++j)
		{
			if(map[j][i] == 0 && map[j][i + 1] == 0)
			{
				map[j][i] = 1;
				map[j][i + 1] = 1;

				search(j, next + 1);

				map[j][i] = 0;
				map[j][i + 1] = 0;
			}
		}
	}
}

int main(void)
{
	int m;
	cin >> n >> m >> h;

	for(int i = 0; i < m; ++i)
	{
		int floor, pos;
		cin >> floor >> pos;

		map[floor][pos] = 1;
		map[floor][pos + 1] = 1;
	}

	search(1, 0);

	cout << answer << endl;
}
