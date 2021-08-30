#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

vector<pair<int, int>> list;
int cache[3000];

int find(int idx, int k)
{
	int &ret = cache[idx];

	if(ret != -1)
		return ret;

	ret = 1;

	for(int i = idx + 1; i < list.size(); ++i)
	{
		int h = list[i].first;
		int w = list[i].second;

		if(list[idx].second <= w)
		{
			cout << list[idx].first << " " << list[idx].second << " " << h << " " << w << " " << k << endl;
			ret = max(ret, find(i, k + 1) + 1);
		}

	}


	return ret;
}

int main(void)
{
	int n;
	cin >> n;

	memset(cache, -1, sizeof(cache));

	for(int i = 0; i < n; ++i)
	{
		int s1, s2;
		cin >> s1 >> s2;

		if(s2 > s1)
		{
			int s = s1;

			s1 = s2;
			s2 = s;
		}

		list.push_back(make_pair(s1, s2));
	}

	sort(list.begin(), list.end());

	int ans = 0;

	for(int i = 0; i < list.size(); ++i)
	{
		ans = max(ans, find(i, 0));
	}

	cout << ans << endl;
}

