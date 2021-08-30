#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;
vector<pair<int, int>> dis;

int main(void)
{
	int w, k, d;
	cin >> w >> k >> d;

	for(int i = 0; i < k; ++i)
	{
		int s;
		cin >> s;

		v.push_back(s);
	}


	for(int i = 0; i < v.size() - 1; ++i)
		dis.push_back(make_pair(-(v[i + 1] - v[i] - 1), 2));

	if(d % 2 == 1)
	{
		dis.push_back(make_pair(-(v[0] - 1),1));
		dis.push_back(make_pair(-(w - v[v.size() - 1]), 1));
	}
	else
	{
		dis.push_back(make_pair(-((v[0] - 1) + w - v[v.size() - 1]), 2));
	}

	sort(dis.begin(), dis.end());

	int ans = 0;

	for(int i = 0; i < dis.size(); ++i)
	{
		int need = dis[i].second;
		int cost = dis[i].first;

		if(d == 0)
			break;


		if(d >= need)
		{
			ans += -cost;
			d -= need;
		}
	}

	cout << ans;

}
