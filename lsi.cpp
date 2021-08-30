#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int downCache[1005];
int upCache[1005];

vector<int> v;
int n;
int answer;

int searchDown(int start)
{
	int&ret = downCache[start];

	if(ret != -1)
		return ret;

	ret = 1;

	for(int i = start + 1; i < n; ++i)
	{
		if(v[start] > v[i])
			ret = max(ret, searchDown(i) + 1);
	}

	return ret;
}

int searchUp(int start)
{
	int&ret = upCache[start];

	if(ret != -1)
		return ret;

	ret = 1;
	
	for(int i = start  - 1; i >= 0; --i)
	{
		if(v[start] > v[i])
			ret = max(ret, searchUp(i) + 1);
	}

	return ret;
}

int main(void)
{
	memset(downCache, -1, sizeof(downCache));
	memset(upCache, -1, sizeof(upCache));

	cin >> n;

	for(int i = 0; i < n; ++i)
	{
		int s;
		cin >> s;

		v.push_back(s);
	}

	for(int start = 0; start < n; ++start)
	{
		searchDown(start);
		searchUp(start);
	}

	cout << "downMax result" << endl;

	for(int start = 0; start < n; ++start)
	{
		cout << upCache[start] << " ";
	}

	cout << endl;
	for(int i = 0; i < n; ++i)
	{
		answer = max(answer , upCache[i] + downCache[i] - 1);
	}

	cout << answer;
}
