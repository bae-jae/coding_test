#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> map;

int cache[10001][4];

int max(int n1, int n2)
{
	if(n1 > n2)
		return n1;

	return n2;
}


int search(int pos, int count, int ans)
{
	cout << pos << " " << count << " " << ans << endl;
	if(pos == map.size())
		return 0;

	int &ret = cache[pos][count];

	if(ret != -1)
	{
		cout <<"cache " << pos << " " << count << " " << cache[pos][count] << endl;
		return ret;
	}

	ret = 0;

	if(count < 2)
		ret = search(pos + 1, count + 1, ans + map[pos]) + map[pos];

	ret = max(search(pos + 1, 0, ans), ret);

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

		map.push_back(s);
	}

	cout << search(0, 0, 0) << endl;
}
