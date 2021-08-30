#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int cache[205];
vector<int> v;

int search(int start)
{
	int& ret = cache[start + 1];

	if(ret != -1)
		return ret;

	ret = 1;

	for(int i = start + 1; i < v.size(); ++i)
	{
		if(start == -1 || v[start] < v[i])
			ret = max(ret, search(i) + 1);
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
		int s;
		cin >> s;

		v.push_back(s);
	}


	cout << n - (search(-1) - 1);
}
