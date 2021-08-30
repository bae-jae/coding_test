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
		cin >> n;

		string target;
		cin >> target;

		string ans = "";
		int want = 0;

		for(int i = 0; i < n; ++i)
		{
			string sub = target.substr(i, i + n);
			ans += sub[i];
		}

		cout << ans << endl;
	}
}
