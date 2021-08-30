#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int map[501][501];
int maxDrunk[501][501];

vector<int> drunkScore;
vector<pair<int, int>> queryList;

void init(void)
{
	for(int i = 0; i < 501; ++i)
	{
		for(int j = 0; j < 501; ++j)
		{
			map[i][j] = 987654321;
			maxDrunk[i][j] = 0;
		}

		map[i][i] = 0;
	}
}

int min(int n1, int n2)
{
	if(n1 < n2)
		return n1;

	return n2;
}

void search(int ve)
{
	vector<int> v(3);
	for(int k = 0; k < ve; ++k)
	{
		for(int i = 0; i < ve; ++i)
		{
			for(int j = 0; j < ve; ++j)
			{
				int crossDist = map[i][k] + map[k][j];

				v[0] = maxDrunk[i][k];
				v[1] = maxDrunk[k][j];
				v[2] = drunkScore[k];

				sort(v.begin(), v.end());

				int maxDrink = v[2];

				cout << v[0] << " " << v[1] << " " << v[2] << " " << k << endl;

				if(maxDrink == maxDrunk[i][k])
				{
					crossDist = crossDist - maxDrunk[k][j];
				}
				else if(maxDrink == maxDrunk[k][j])
				{
					crossDist = crossDist - maxDrunk[i][k];
				}
				else
					crossDist = maxDrunk[i][k] - maxDrunk[k][j] + v[2];

				if(map[i][j] > crossDist)
				{
					map[i][j] = crossDist;
					maxDrunk[i][j] = maxDrink;
				}
			}
		}
	}
}

int main(void)
{

	for(int test = 0; test < 1; ++test)
	{
		int v, e;
		cin >> v >> e;

		for(int i = 0; i < v; ++i)
		{
			int s;
			cin >> s;

			drunkScore.push_back(s);
		}

		init();

		for(int i = 0; i < e; ++i)
		{
			int s, e, num;
			cin >> s >> e >> num;

			map[s][e] = num;
			map[e][s] = num;
		}

		int tc;

		cin >> tc;

		for(int i = 0; i < tc; ++i)
		{
			int a, b;
			cin >> a >> b;

			queryList.push_back(make_pair(a, b));
		}

		search(v);

		for(int i = 0; i < queryList.size(); ++i)
		{
			int f = queryList[i].first;
			int s = queryList[i].second;

			cout << map[f][s] << "\n";
		}

		return 0;
	}
}
