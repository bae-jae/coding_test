#include <iostream>

using namespace std;

int main(void)
{
	long long n1, n2;
	cin >> n1 >> n2;


	if(!n1 && !n2)
		cout << 0;

	else
	{
		long long k = 1;

		while(1)
		{
			if(n1 + n2 == ((k * (k + 1)) / 2))
				break;
			else if(n1 + n2 < ((k * (k + 1)) / 2))
			{
				cout << -1;
				return 0;
			}
			++k;
		}

		long long ans = 0;

		for(long long i = k; i >= 1; --i)
		{

			if(n1 == 0)
				break;

			n1 -= min(n1, i);
			++ans;
		}

		cout << ans;
	}

	return 0;
}
