#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int map[402][402];

int main(void)
{
	int v, e;
	cin >> v >> e;

	for(int i = 0; i < 402; ++i)
	{
		for(int j = 0; j < 402; ++j)
		{
			map[i][j] = 987654321;
		}
	}

	for(int i = 0; i < e; ++i)
	{
		int start, end, cost;
		cin >> start >> end >> cost;

		map[start][end] = cost;

	}

	for(int k = 1; k <= v; ++k)
	{
		for(int i = 1; i <= v; ++i)
			for(int j = 1; j <= v; ++j)
				map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
	}

	int ans = 987654321;

	for(int i = 1; i <= v; ++i)
		ans = min(ans, map[i][i]);

	if(ans == 987654321)
		ans = -1;

	cout << ans << endl;



}
