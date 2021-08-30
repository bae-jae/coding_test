#include<iostream>
#include<vector>
#include <algorithm>
#include <queue>

using namespace std;

int order[100005];
vector<pair<int, int>> v;

int dy[5] = {0,  -1, 0 , 1 , 0};
int dx[5] = {0,  0,  1,  0, -1};

int d[2][5];

int outRange(int y, int x)
{
	if(y < 0 || y >= 100000 || x < 0 || x >= 100000)
		return 0;

	return 1;
}


void init(int startx, int starty)
{
	for(int i = 0; i < 5; ++i)
	{
		int rx = v[0].first + dx[i];
		int ry = v[0].second + dy[i];

		if(outRange(ry, rx) == 0)
			continue;

		int diffx = rx - startx;
		int diffy = ry - starty;

		int sum = abs(diffx) + abs(diffy);

		d[0][i] = sum;
		d[1][i] = 987654321;
	}
}

void find(int idx)
{
	for(int i = 0; i < 5; ++i)
	{
		int startx = v[idx - 1].first + dx[i];
		int starty = v[idx - 1].second + dy[i];
		
		for(int j = 0; j < 5; ++j)
		{
			int rx = v[idx].first + dx[j];
			int ry = v[idx].second + dy[j];

			if(outRange(ry, rx) == 0)
				continue;

			int diffx = rx - startx;
			int diffy = ry - starty;

			int sum = abs(diffx) + abs(diffy);

			d[1][j] = min(d[1][j] , d[0][i] + sum);
		}
	}

	for(int i = 0 ; i < 5; ++i)
	{
		d[0][i] = d[1][i];
		d[1][i] = 987654321;
	}
}


int main(void)
{
	int n;
	cin >> n;

	int startx, starty;
	cin >> startx >> starty;

	for(int i = 0; i < n; ++i)
	{
		int s, e;
		cin >> s >> e;

		v.push_back(make_pair(s, e));
	}

	init(startx, starty);

	int ans = 987654321;

	for(int i = 1; i < v.size(); ++i)
		find(i);

	for(int i = 0; i < 5; ++i)
	{
		ans = min(ans, d[0][i]);
	}

	cout << ans << endl;
}
