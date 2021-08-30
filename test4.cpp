#include <iostream>
#include <string>

using namespace std;

int map[300][300];

void init()
{
	for(int i = 0; i < 300; ++i)
	{
		for(int j = 0; j < 300; ++j)
		{
			map[i][j] = 987654321;
			map[j][i] = 987654321;
		}
	}
}

int min(int n1, int n2)
{
	if(n1 < n2)
		return n1;

	return n2;
}

void shortPair(int n)
{
	for(int i = 0; i < n; ++i)
		map[i][i] = 0;

	for(int k = 0; k < n; ++k)
	{
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < n; ++j)
			{
				if(map[i][j] > map[i][k] + map[k][j])
				{
					map[i][j] = map[i][k] + map[k][j];
				}
			}
		}
	}
}

int solution(int s, int a, int b, int n)
{
	shortPair(n);

	int answer = 0;
	//합석안할경우
	int total = map[s][a] + map[s][b];

	cout << total << map[s][a] << " " << map[s][b] << endl;

	for(int i = 0; i < n; ++i)
	{
		answer = map[s][n];
		answer += map[n][a] + map[n][b];

		total = min(answer, total);
	}

	cout << total << endl;
	return total;
}
int main(void)
{
	int tc;
	cin >> tc;

	for(int test = 0; test < tc; ++test)
	{
		int n, s, a, b;
		cin >> n >> s >> a >> b;

		init();
		//a start b end
		int edge;
		cin >> edge;

		for(int i= 0; i < edge; ++i)
		{
			int s1, e1, price;
			cin >> s1 >> e1 >> price;

			map[s1][e1] = price;
			map[e1][s1] = price;
		}

		solution(s, a, b, n);
	}
}
