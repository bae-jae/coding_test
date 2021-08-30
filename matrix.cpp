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
		int n , m;
		cin >> n >> m;

		vector<pair<int, int>> v;

		for(int i = 0; i < n * 2; ++i)
		{
			int x ,y ;
			cin >> x >> y;

			v.push_back(make_pair(x, y));
		}

		int ans = 0;

		for(int i = 0; i < v.size(); i+=2)
		{
			if(v[i].second == v[i + 1].first)
			{
				ans = 1;
				break;
			}
		}

		if(m % 2 != 0)
			cout << "NO" << endl;
		else
			if(ans == 1)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
	}
}
