#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int map[205][205];
int undo[205][205];


void init(void)
{
	for(int i = 0; i < 205; ++i)
	{
		for(int j = 0; j < 205; ++j)
		{
			map[i][j] = 987654321;
			undo[i][j] = j;
		}
	}
}

int find(int s, int e)
{
	if(undo[s][e] == e)
	{
		return e;
	}

	return undo[s][e] = find(s, undo[s][e]);
}

int min(vector<int> v)
{
	sort(v.begin(), v.end());
	return v[0];
}

void search(void)
{
	for(int k = 1; k <= n; ++k)
	{
		for(int i = 1; i <= n; ++i)
		{
			for(int j = 1; j <= n; ++j)
			{
				if(map[i][j] > map[i][k] + map[k][j])
				{
					undo[i][j] = k;
					map[i][j] = map[i][k] + map[k][j];
				}
			}
		}
	}

	for(int i =1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
		{
			if(i == j)
			{
				cout << '-' << " ";
				continue;
			}

			cout << find(i, j) << " ";
		}
		cout << "\n";
	}
}

int main(void)
{
	cin >> n >> m;
	init();

	for(int i = 0; i < m; ++i)
	{
		int s, e , c;
		cin >> s >> e >> c;

		map[s][e] = min({map[s][e], map[e][s], c});
		map[e][s] = map[s][e];
	}

	search();
}
