#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int map[55][55];
int answer = 987654321;
int bound;

vector<pair<int, int>> chickPos;

int min(int n1, int n2)
{
	if(n1 < n2)
		return n1;

	return n2;
}

int getDis(int y1, int x1, int y2, int x2)
{
	return abs(y1- y2) + abs(x2 - x1);
}

int search(vector<pair<int, int>>& market, int pos, int n)
{
	if(market.size() == n)
	{
		int sub = 0;

		for(int y = 0; y < bound; ++y)
		{
			for(int x = 0; x < bound; ++x)
			{
				if(map[y][x] == 1)
				{
					int getMin = 98765421;
					
					for(int i = 0; i < market.size(); ++i)
						getMin = min(getMin, getDis(y, x, market[i].first, market[i].second));

					sub += getMin;
				}
			}
		}

		answer = min(answer, sub);
		return;
	}

	for(int i = pos + 1; i < chickPos.size(); ++i)
	{
		market.push_back(chickPos[i]);
		search(market, i, n);
		market.pop_back();
	}
}

int main(void)
{
	int n;
	cin >> bound >> n;
	
	for(int r = 0; r < bound; ++r)
	{
		for(int c = 0; c < bound; ++c)
		{
			int s;
			cin >> s;

			map[r][c] = s;

			if(s == 2)
			{
				chickPos.push_back(make_pair(r, c));
			}
		}
	}

	vector<pair<int, int>> list;

	for(int i = 0; i < chickPos.size(); ++i)
	{
		list.push_back(chickPos[i]);
		search(list, i, n);
		list.pop_back();
	}

	cout << answer << endl;
}

