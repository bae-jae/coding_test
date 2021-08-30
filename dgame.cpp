#include <iostream>
#include <string>

using namespace std;

int search(int n, string s)
{
	int answer = -1;
		if(n % 2 == 0)	//b의 홀수자 중요한 부분
		{
			for(int i = 0; i < s.size(); ++i)
			{
				if((i+1) % 2 == 0)
				{
					int cand = s[i] - '0';

					if(cand % 2 == 0)
					{
						return 2;
					}
				}
			}

			return 1;
		}
		else
		{
			for(int i = 0; i < s.size(); ++i)
			{
				if((i+1) % 2 != 0)
				{
					int cand = s[i] - '0';

					if(cand % 2 != 0)
					{
						return 1;
					}
				}
			}
			
			return 2;
		}
}

int main(void)
{
	int tc;
	cin >> tc;

	for(int test =0; test < tc; ++test)
	{
		int n;
		string s;

		cin >> n;
		cin >> s;

		cout << search(n, s) << endl;
	}
}
