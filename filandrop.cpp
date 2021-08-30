#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int cache[2001][2001];
vector<int> v;

int find(int s, int e)
{
	if(s == e)
		return cache[s][e] = 1;

	if(s + 1 == e)
	{
		if(v[s] == v[e])
			return 1;

		return 0;
	}

	int &ret = cache[s][e];

	if(ret != -1)
		return ret;

	if(v[s] == v[e])
	{
		return ret = find(s + 1, e - 1);
	}
	else
		return ret = 0;
}


int main(void)
{
	int n;
	memset(cache, - 1, sizeof(cache));

	cin >> n;
	
	v.push_back(0);

	for(int i = 0; i < n; ++i)
	{
		int s;
		cin >> s;

		v.push_back(s);
	}

	cin >> n;

	for(int i = 0; i < n; ++i)
	{
		int start, end;
		cin >> start >> end;

		cout << find(start, end) << "\n";

	}

}
