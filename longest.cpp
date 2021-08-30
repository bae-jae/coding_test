#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

vector<int> v;

int cache[1005];
int nextIdx[1005];

int find(int idx)
{
	if(idx == v.size())
		return 0;

	int& ret = cache[idx];

	if(ret != -1)
		return ret;

	nextIdx[idx] = idx;
	ret = 1;

	for(int i = idx + 1; i < v.size(); ++i)
	{
		if(v[idx] < v[i])
		{
			int cand = find(i) + 1;

			if(ret < cand)
			{
				ret = cand;
				nextIdx[idx] = i;
			}
		}
	}

	//cout << idx << " " << nextIdx[idx] << " " << ret <<endl;
	return ret;
}

void printAns(int idx)
{
	if(idx == nextIdx[idx])
	{
		cout << v[idx];
		return;
	}

	cout << v[idx] << " ";
	printAns(nextIdx[idx]);
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

	int ans = 0;
	int startIdx = 0;

	for(int i = 0; i < v.size(); ++i)
	{
		if(ans < find(i))
		{
			startIdx = i;
			ans = find(i);
		}
	}

	cout << ans << "\n";
	printAns(startIdx);

}
