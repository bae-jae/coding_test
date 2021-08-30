#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int tc;
	cin >> tc;

	for(int test = 0; test < tc; ++test)
	{
		int n, k;
		cin >> n >> k;

		vector<int> v;
		for(int i = 0; i < n; ++i)
		{
			int s;
			cin >> s;

			v.push_back(s);
		}

		sort(v.begin(), v.end());

		int answer = 0;
		for(int i = 1; i < v.size(); ++i)
		{
			int div = k - v[i];
			answer += (div / v[0]);
		}

		cout << answer << endl;
	}
}
