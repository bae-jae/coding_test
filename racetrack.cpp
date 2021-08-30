#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> map;

int n;
int my[4] = {-1, 0, 1, 0};
int mx[4] = {0, 1, 0, -1};

int outRange(int y, int x)
{
	if(y < 0 || y >= n)
		return 0;
	if(x < 0 || x >= n)
		return 0;

	return 1;
}

int min(int n1, int n2)
{
	if(n1 < n2)
		return n1;

	return n2;
}

void bfs(vector<vector<int>> map)
{
	priority_queue<pair<pair<int, int>, pair<int, int>>> pq;
	pq.push(make_pair(make_pair(0, -1), make_pair(0, 0)));

	vector<vector<int>> scoreBoard;

	for(int i = 0; i < map.size(); ++i)
	{
		vector<int> v;
		for(int j = 0; j < map.size(); ++j)
		{
			v.push_back(987654321);
		}
		scoreBoard.push_back(v);
	}

	scoreBoard[0][0] = 0;

	while(!pq.empty())
	{
		int y = pq.top().second.first;
		int x = pq.top().second.second;
		int dir = pq.top().first. second;
		int score = pq.top().first.first * -1;

		pq.pop();

		for(int i = 0; i < 4; ++i)
		{
			int ry = y + my[i];
			int rx = x + mx[i];
			int makeMoney = 100;

			if(dir != -1)
			{
				if(dir != i)
					makeMoney = 600;
			}

			if(outRange(ry, rx) == 1 && map[ry][rx] == 0)
			{
				int lastScore = score + makeMoney;

				if(scoreBoard[ry][rx] > lastScore)
				{
					scoreBoard[ry][rx] = lastScore;
					cout << x << " " << y << " " << rx << " " << ry << " " << score << " " << makeMoney << endl;
					pq.push(make_pair(make_pair(lastScore * -1, i), make_pair(ry, rx)));
				}
				else
					continue;
			}
		}
	}

	cout << scoreBoard[map.size() -1][map.size() - 1] << endl;
}

int main(void)
{
	int tc;
	cin >> tc;

	for(int test = 0; test < tc; ++ test)
	{
		
		cin >> n;
		vector<vector<int>> map;

		for(int i = 0; i < n; ++i)
		{
			vector<int> v;

			for(int j = 0; j < n; ++j)
			{
				int s;
				cin >> s;

				v.push_back(s);
			}
			map.push_back(v);
		}

		bfs(map);
	}
}
