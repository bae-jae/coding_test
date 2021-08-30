#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n;
vector<int> list;
int pick;

int cache[50001][4];

int find(int idx, int remain)
{
	if(idx >= list.size())
		return 0;

	if(remain == 0)
		return 0;

	int &ret = cache[idx][remain];

	if(ret != -1)
		return ret;

	int sub = 0;

	for(int i = idx; i < idx + pick; ++i)
	{
		if(i == list.size())
			break;

		sub += list[i];
	}

	ret = max(find(idx + 1, remain), find(idx + pick, remain - 1) + sub);

	return ret;
}


int main(void)
{
	int n;
	cin >> n;

	memset(cache, -1, sizeof(cache));

	for(int i = 0 ; i < n; ++i)
	{
		int s;
		cin >> s;

		list.push_back(s);
	}
	
	cin >> pick;

	cout << find(0, 3);
}
