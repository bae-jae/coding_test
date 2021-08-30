#include <iostream>
#include <vector>

using namespace std;

double answer = 0;
int n;

int mx[4] = {0, 0, 1, -1};
int my[4] = {1, -1, 0, 0};
int map[40][40];
double prob[4];

void dfs(int count, int x, int y, double p)
{
	if(count == n)
	{
		answer += p;
		return;
	}

	map[y][x] = 1;

	for(int i = 0; i < 4; ++i)
	{
		if(map[y + my[i]][x + mx[i]] == 0)
		{
			dfs(count + 1, x + mx[i], y + my[i], p * prob[i]);
		}
	}

	map[y][x] = 0;
}

int main(void)
{
	cin >> n;

	for(int i = 0; i < 4; ++i)
	{
		cin >> prob[i];
		prob[i] = prob[i] / 100;
	}

	vector<int> pos;
	
	int x = 0;
	int y = 0;

	dfs(0, 20, 20, 1.0);

	cout.precision(10);
	cout << fixed << answer;
}
