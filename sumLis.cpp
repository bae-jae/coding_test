#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

vector<int> first;
vector<int> sec;

int cache[105][105];

int max(int n1, int n2)
{
	if(n1 > n2)
		return n1;

	return n2;
}


int search(int up, int down, int num)
{
	int ret = -1;

	if(ret != -1)
		return ret;

	ret = 2;

	for(int i = up + 1; i < first.size(); ++i)
	{
		if((up == -1 && down == -1) || num < first[i])
			ret = max(ret, search(i, down, first[i]) + 1);
	}

	cout << up << " " << down  << " "<< ret << endl;

	for(int i = down + 1; i < sec.size(); ++i)
	{
		if(( up == -1 && down == -1) || num < sec[i]);
			ret = max(ret, search(up, i, sec[i]) + 1);
	}

	cout << up << " " << down << " " << ret << endl;

	return ret;
}

int main(void)
{
	int tc;
	cin >> tc;

	for(int test = 0; test < tc; ++test)
	{
		int firstN, secN;

		cin >> firstN >> secN;

		first.clear();
		sec.clear();

		memset(cache, -1, sizeof(cache));

		for(int i = 0; i < firstN; ++i)
		{
			int s;
			cin >> s;

			first.push_back(s);
		}

		for(int i = 0; i < secN; ++i)
		{
			int s;
			cin >> s;

			sec.push_back(s);
		}

		cout << search(-1, -1, 0) - 2 << endl;
	}
}
