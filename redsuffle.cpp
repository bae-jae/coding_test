#include <iostream>
#include <string>

using namespace std;


int main(void)
{
	int tc;
	cin >> tc;

	for(int test = 0; test < tc; ++test)
	{
		int n;


		string s1, s2;

		cin >> n;
		cin >> s1 >> s2;

		int red = 0;
		int blue = 0;


		for(int i = 0; i < s1.size(); ++i)
		{
			int a = s1[i] - '0';
			int b = s2[i] - '0';

			if(a == b)
				continue;

			if(a > b)
				red++;
			else
				blue++;
		}

		string ans = "EQUAL";

		if(red > blue)
			ans = "RED";
		else if(red < blue)
			ans = "BLUE";

		cout << ans << "\n";
	}
}
