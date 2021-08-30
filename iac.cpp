#include <iostream>

using namespace std;

int min(int n1, int n2)
{
	if(n1 < n2)
		return n1;

	return n2;
}

int main(void)
{
	int tc;
	cin >> tc;

	for(int test = 0; test < tc; ++test)
	{
		int n;
		cin >> n;

		long long left = 0;
		long long right = 1e9;
		long long ans = right;

		for(int i = 1; i <= 1000000 && i <= n; ++i)
		{
			ans = min(ans, (i - 1) + ((n - 1) / i));
		}
		cout << ans <<  endl;

	}
}
