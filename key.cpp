#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> changeRotate(vector<vector<int> key)
{
	int sx = -1;
	int sy = -1;

	vector<pair<int, int>> relKey;

	for(int y = 0; y < key.size(); ++y)
	{
		for(int x = 0; x < key[y].size(); ++x)
		{
			if(key[y][x] == 1)
			{
				if(sx == -1)
				{
					sy = y;
					sx = x;
				}

				relKey.push_back(make_pair(y - sy, x - sx));
			}
		}
	}

	return relKey;
}

vector<vector<pair<int, int>>> changeKey(vector<vector<int>> key)
{
	vector<vector<int>> change(key.size(), vector<int>(key.size(), 0));
	
	int rx = 0;
	for(int y = 0; y < key.size(); ++y)
	{
		for(int x = 0; x < key[y].size(); ++x)
		{
			change[x][key.size() - y -1] = key[y][x];
		}
	}

	return relPoint;
}

int outRange(int x, int y, int mx, int my)
{
	if(x < 0 || x >= mx)
		return 0;
	if(y < 0 || y >= my)
		return 0;

	return 1;
}
int search(vector<vector<int>> map, vector<vector<pair<int, int>>> keys)
{
	int pointX = -1;
	int pointY = -1;
	int blankCount = 0;

	for(int y = 0; y < map.size(); ++y)
	{
		for(int x= 0; x < map.size(); ++x)
		{
			if(map[y][x] == 0)
			{
				if(pointX == -1)
				{
					pointX = x;
					pointY = y;
				}

				++blankCount;
			}
		}
	}

	if(pointY == -1)
		return true;

	for(int rt = 0; rt < 4; ++rt)
	{
		vector<pair<int, int>> relPoint = roateChange(keys);
		int count = 0;
		int flag = 1;

		for(int i = 0; i < relPoint.size(); ++i)
		{
			int my = pointY + relPoint[i].first;
			int mx = pointX + relPoint[j].second;

			if(outRange(mx, my, map.size(), map.size()) == 1)
			{
				if(map[my][mx] == 1)
				{
					flag = 0;
					break;
				}
				else
					++count;
			}
		}

		if(flag == 1 && count == blankCount)
			return true;

		key = changeMap(key)
	}
				
	return false;
}
int main(void)
{
	int tc;
	tc = 1;

	for(int test = 0; test < tc; ++test)
	{
		int m, n;
		cin >> m >> n;
		vector<vector<int>> key;
		vector<vector<int>> map;

		for(int i = 0; i < n; ++i) //keys
		{
			vector<int> s;
			for(int j = 0; j < n; ++j)
			{
				int e; 
				cin >> e;
				s.push_back(e);
			}

			key.push_back(s);
		}

		for(int i = 0; i < m; ++i)
		{
			vector<int> s;	//lock

			for(int j = 0; j < m; ++j)
			{
				int e;
				cin >> e;

				s.push_back(e);
			}

			map.push_back(s);
		}

		vector<vector<pair<int, int>>> rel = changeroate(key);
		cout << search(map, rel);
	}
}
