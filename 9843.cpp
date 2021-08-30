#include <iostream>

using namespace std;

int main(void)
{
	int tc;
	cin >> tc;

	for(int test = 0; test < tc; ++test)
	{
		long long int n;
		cin >> n;

		long long int org = n * 2;
		long long int answer = 0;

		if(n == 1)
		{
			cout <<"#" <<test << " " <<  1 << "\n";
			continue;
		}
		n = org;


		while(n >= 1)
		{
			n /= 2;

			if(n == 1)
			{
				break;
			}

			if(n % 2 != 0)
			{
				if(org % (n - 1) == 0)
				{
					answer = n - 1;
					break;
				}
			}
			else 
			{
				if(org % (n + 1) == 0)
				{
					answer = n;
					break;
				}
			}
		}

		if(answer == 0)
			cout << "#" << test + 1 << " " << -1 << "\n";
		else
			cout << "#"<< test << " " << answer << "\n";
	}
}
