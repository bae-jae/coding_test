#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

vector<int> m;
vector<int> t;

int cache[101][10001];

int search(int idx, int time)
{
	if(idx >= m.size())
		return 0;

	int &ret = cache[idx][time];

	if(ret != -1)
		return ret;

	ret = 0;

	if(time - t[idx] >= 0)
		ret = search(idx + 1, time - t[idx]) + m[idx];
	
	ret = max(ret, search(idx + 1, time));

	return ret;
}

int main(void)
{
	int n, need;

	cin >> n >> need;

	memset(cache, -1 ,sizeof(cache));

	for(int i = 0 ; i < n; ++i)
	{
		int s;
		cin >> s;


		m.push_back(s);
	}

	for(int i = 0; i < n; ++i)
	{
		int s;
		cin >> s;

		t.push_back(s);
	}

	int time = 1;

	while(1)
	{
		if(search(0, time) >= need)
		{
			cout << time;
			break;///
		}
		++time;
	}
}
