#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int cache[51][880][880];
int sum;
vector<int> v;

int min(vector<int> list)
{
	int ans  = 987654321;

	for(int i = 0; i < 3; ++i)
	{
		if(ans > list[i])
		{
			ans = list[i];
		}
	}

	return ans;
}

int search(int idx, int n1, int n2)
{
	if(idx == v.size())
		return min({n1, n2, sum - n1 - n2});

	int &ret = cache[idx][n1][n2];

	if(ret != -1)
		return ret;

	ret = search(idx + 1, n1, n2);

	if(n1 + v[idx] <= 880)
		ret = max(ret, search(idx + 1, n1 + v[idx], n2));
	
	if(n2 + v[idx] <= 880)
		ret = max(ret, search(idx + 1, n1, n2 + v[idx]));

	return ret;
	
}


int main(void)
{
	int n;
	cin >> n;

	memset(cache, -1, sizeof(cache));

	for(int i =0; i < n; ++i)
	{
		int s;
		cin >> s;

		sum += s;

		v.push_back(s);
	}
	
	cout << search(0, 0, 0);

}
