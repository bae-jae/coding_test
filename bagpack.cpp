#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

vector<pair<int, int>> list;
long long cache[105][100005];

int max(int n1, int n2)
{
	if(n1 > n2)
		return n1;

	return n2;
}

long long search(int pick, long long weight)
{
	long long &ret = cache[pick + 1][weight];

	if(weight < 0 || pick >= list.size())
	{
		if(weight < 0)
			return ret = 0;
	}

	if(ret != -1)
		return ret;

	ret = 0;

	for(int i = pick + 1; i < list.size(); ++i)
		ret = max(ret, search(i, weight - list[i].first));

	return ret = ret + list[pick].second;
}

int main(void)
{
	int n, k;
	cin >> n >> k;
	memset(cache, -1, sizeof(cache));

	for(int i = 0; i < n; ++i)
	{
		int w, v;
		cin >> w >> v;

		list.push_back(make_pair(w,v));
	}

	cout << search(-1, k);
}
