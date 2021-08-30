#include <iostream>

using namespace std;

int map[105][105];

void init(void)
{
	int max = 105;
	int num = 987654321;

	for(int i = 0; i < 105; ++i)
	{
		for(int j = 0; j < max; ++j)
		{
			if(i == j)
				map[i][j] = 0;
			else
				map[i][j] = num;
		}
	}

}

void floyd(int n)
{
	for(int k = 1; k <= n; ++k)
	{
		for(int i = 1; i <= n; ++i)
		{
			for(int j = 1; j <= n; ++j)
			{
				map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
			}
		}
	}
}

int main(void)
{
	int n;
	cin >> n;

	int m;
	cin >> m; 	//bust info

	init();

	for(int i = 0; i < m; ++i)
	{
		int node, next , p;

		cin >> node >> next >> p;

		map[node][next] = min(map[node][next], p);
	}

	floyd(n);

	for(int i = 1; i <=n; ++i)
	{
		for(int j = 1; j <= n; ++j)
		{
			if(map[i][j] >= 987654321)
				cout << 0;
			else
				cout << map[i][j];

			cout << " ";
		}
		cout << endl;
	}
}
