#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int min(int n1, int n2)
{
	if(n1 < n2)
		return n1;
	return n2;

}
int search(vector<pair<int, int>>& routes)
{
	sort(routes.begin(), routes.end());
	int answer = 0;
	int lastCamera = 300001;

	for(int i = routes.size() - 1; i >= 0; --i)
	{
		if(lastCamera > routes[i].second)
		{
			++answer;
			lastCamera = routes[i].first;
		}

		cout <<routes[i].first << " " << lastCamera << endl;
	}

	return answer;
}

int main(void)
{
	int tc;
	cin >> tc;

	for(int test = 0; test < tc; ++test)
	{
		int n;
		cin >> n;
		
		vector<pair<int, int>> routes;

		for(int i = 0; i < n; ++i)
		{
			int f, s;
			cin >> f >> s;

			routes.push_back(make_pair(f, s));
		}

		cout << search(routes);
	}
}
