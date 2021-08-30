#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

int n, m;

int cache[2345][12345];
vector<pair<int, int>> bag;


int find(int idx, int left)
{
	if(idx == bag.size())
		return 0;


	int weight = bag[idx].first;
	int happy = bag[idx].second;

	int ret = 0;


	ret = find(idx + 1, left); //사용  ㅌ

	if(weight <= left)
	{
		ret = max(ret, find(idx + 1, left - weight) + happy);
	}

	return ret;
}

int main(void)
{
	cin >> n >> m;

	memset(cache, -1, sizeof(cache));

	for(int i = 0; i < n; ++i)
	{
		int v, c, k;
		cin >> v >> c >> k;

		for(int j = 0; k > 0; ++j)
		{
			int tmp = min(1 << j, k);
			
			bag.push_back({tmp * v, tmp * c});
			k -= tmp;
		}

	}

	for(int i =0; i < bag.size(); ++i)
	{
		cout << bag[i].first << " " << bag[i].second << endl;
	}
	cout << find(0, m);
}
