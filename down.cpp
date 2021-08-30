#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n;
vector<int> map;


int main(void)
{
	cin >> n;

	int cache[2][3];
	int mincache[2][3];

	for(int i = 0; i < n; ++i)
	{
		map.clear();

		for(int j = 0; j < 3; ++j)
		{
			int s;
			cin >> s;

			map.push_back(s);
		}

		if(i == 0)
		{
			for(int k = 0; k < 3; ++k)
			{
				cache[0][k] = map[k];
				mincache[0][k] = map[k];
			}
		}
		else
		{
			{
				cout << cache[0][0] << " " << cache[0][1] << " " << cache[0][2] << endl;
				
				cache[1][0] = max(cache[0][0] + map[0], cache[0][1] + map[0]);

		
				cache[1][1] = max(cache[0][0] + map[1], cache[0][1] + map[1]);
				cache[1][1] = max(cache[1][1], cache[0][2] + map[1]);

				cache[1][2] = max(cache[0][1] + map[2], cache[0][2] + map[2]);

				cache[0][0] = cache[1][0];
				cache[0][1] = cache[1][1];
				cache[0][2] = cache[1][2];

				cout << cache[0][0] << " " << cache[0][1] << " " << cache[0][2] << endl;
			}

			{
				mincache[1][0] = min(mincache[0][0] + map[0], mincache[0][1] + map[0]);
		
				mincache[1][1] = min(mincache[0][0] + map[1], mincache[0][1] + map[1]);
				mincache[1][1] = min(mincache[1][1], mincache[0][2] + map[1]);

				mincache[1][2] = min(mincache[0][1] + map[2], mincache[0][2] + map[2]);

				mincache[0][0] = mincache[1][0];
				mincache[0][1] = mincache[1][1];
				mincache[0][2] = mincache[1][2];
			}
		}
	}

	int ans = 0;
	int minans = 987654321;

	for(int i = 0; i < 3; ++i)
		ans = max(cache[0][i], ans);

	for(int i = 0; i < 3; ++i)
		minans = min(minans, mincache[0][i]);

	cout << ans << " " << minans << endl;
}
