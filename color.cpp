#include <iostream>
#include <cstring>

using namespace std;

int cache[1005][1005];
int n, last;
int mod = 1000000003;

void find(void)
{
	for(int i = 1; i <= n; ++i)
	{
		cache[i][1] = i;
		cache[i][0] = 1;
	}

	for(int i = 2; i <= n; ++i)
	{
		for(int j = 2; j <= last; ++j)
		{
			cache[i][j]  = (cache[i-1][j] + cache[i - 2][j - 1]) % mod;
		}
	}

	cout << cache[n-3][last-1] + cache[n-1][last] << endl;
}

int main(void)
{
	cin >> n;
	cin >> last;

	int ans = 0;

	find();

}
