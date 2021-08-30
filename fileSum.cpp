#include <iostream>
#include <vector>
#include <cstring>

using namespace std;


vector<int> map;
vector<int> psum;

int cache[501][501];
int come[501][501];

int search(int left, int right)
{
	if(left == right)
	{
		cache[left][right] = 0;
		return 0;
	}

	if(left + 1 == right)
	{
		return cache[left][right] = map[left] + map[right];
	}


	int &ret = cache[left][right];
	int mid = -1;
	if(ret != -1)
		return ret;

	ret = 987654321;

	for(int i = left; i < right; ++i)
	{
		int leftCost = search(left, i);
		int rightCost = search(i + 1, right);

		int total = leftCost + rightCost;

		if(ret > total)
		{
			ret = total;
			mid = i;
		}
	}

	for(int i = left; i <= right; ++i)
		ret += map[i];

	return ret;
}

int main(void)
{
	int tc;
	cin >> tc;

	for(int i = 0; i < tc; ++i)
	{
		int n;
		cin >> n;

		map.clear();
		memset(cache, -1, sizeof(cache));

		for(int j = 0; j < n; ++j)
		{
			int s;
			cin >> s;

			map.push_back(s);
		}

		cout << search(0, n - 1) << endl;;

	}
}
