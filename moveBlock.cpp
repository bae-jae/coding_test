#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int outRange(int x, int y, int n)
{
	if(y < 0 || y >= n)
		return 0;

	if(x < 0 || x >= n)
		return 0;

	return 1;
}

int mvRight(int y1, int x1, int y2, int x2, int n)
{
	if(outRange(y1, x1 + 1, y2, x2 + 1, n))
		return 1;

	return 0;
}

int mvLeft(int y1, int x1, int y2, int x2, int n)
{
	if(outRange(y1, x1 - 1, y2, x2 - 1, n))
		return 1;

	return 0;
}

int search(vector<vector<int>> board)
{
	priority_queue<pair<int, pair<pair<int, int>, pair<int, int>> pq;

	pq.push_back(make_pair(0, make_piar(make_pair(0, 0), make_pair(0, 1))));


	vector<vector<int>> time;

	for(int i = 0; i < board.size(); ++i)
	{
		vector<int> v(board.size(), 987654321);
		time.push_back(v);
	}

	while(!pq.empty())
	{
		int price = pq.top().first;
		int y1 = pq.top().second.first.frist;
		int x1 = pq.top().second.first.second;

		int y2 = pq.top().second.second.first;
		int x2 = pq.top().second.second.second;
		
		pq.pop();

		if(y1 == y2)
		{
			if(mvRight(y1, x1, y2, x2, board.size()))
			{
			}
			if(mvLeft(y1, x1, y2, x2, board.size()))
			{
			}
		}
	}
}
int main(void)
{
	int tc;
	cin >> tc;

	for(int test = 0; test < tc; ++test)
	{
		int n;
		cin >> n;

		vector<vector<int>> board;

		for(int i = 0; i < n; ++i)
		{
			vector<int> v;

			for(int j = 0; j < n; ++j)
			{
				int s;
				cin >> s;

				v.push_back(s);
			}

			board.push_back(v);
		}


	}
}
