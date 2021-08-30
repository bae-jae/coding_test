#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

vector<int> v;
int cache[51][51];

int max(int n1, int n2)
{
	if(n1 > n2)
		return n1;

	return n2;
}

int search(int left, int right)
{
	if(left > right)
		return 0;
	
	int&ret = cache[left][right];

	if(ret != -1)
		return ret;
	
	if(left == right)
		return ret = v[left];

	ret = 0;

	int n1 =  v[left] - search(left + 1, right);
	int n2 = v[right] - search(left, right - 1);
	int n3 =  search(left + 2, right);
	int n4 = search(left, right - 2);

	vector<int> cand(4, 0);
	cand[0] = n1;
	cand[1] = n2;
	cand[2] = n3;
	cand[3] = n4;

	sort(cand.begin(), cand.end());
	return ret = cand[3];
}

int main(void)
{
	int tc;
	cin >> tc;

	for(int test =0; test < tc; ++test)
	{
		int n;
		cin >> n;

		v.clear();
		memset(cache, -1, sizeof(cache));

		for(int i = 0; i < n; ++i)
		{
			int s;
			cin >> s;

			v.push_back(s);
		}

		cout << search(0, n - 1) << endl;
	}
}
