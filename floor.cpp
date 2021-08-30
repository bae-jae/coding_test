#include <iostream>

using namespace std;

int main(void)
{
	int tc;
	cin >> tc;

	for(int test = 0; test < tc; ++test)
	{
		int n, x;
		cin >> n >> x;

		int ans = 0;
		if(n == 1 || n == 2)
			ans = 1;
		else
		{
			for(int i = 1; i <= n; ++i)
			{
				long long sub = i * x + 2;

				if(n <= sub)
				{
					ans = i + 1;
					break;
				}
			}
		}

		cout << ans << "\n";
	}
}
