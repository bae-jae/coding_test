#include <iostream>
#include <vector>
#include <cstring>

using namespace std;


vector<vector<int>> returnList;

int cache[22][301];

void reconstruct(vector<int> & ans, int pick, int money)
{
	if(pick == returnList[0].size())
		return;

	if(cache[pick][money] == cache[pick + 1][money])
	{
		ans.push_back(0);
		reconstruct(ans, pick + 1, money);
	}
	else
	{
		for(int i = 0; i < returnList.size(); ++i)
		{
			int earn = returnList[i][pick];
			int cost = returnList[i][0];

			if(cost <= money)
			{
				if(cache[pick][money] == (cache[pick + 1][money - cost] + earn)){
					ans.push_back(cost);
					reconstruct(ans, pick + 1, money - cost);
					return;
				}
			}
		}
	}
}
int search(int pick, int money)
{
	if(pick == returnList[0].size())
		return cache[pick][money] = 0;

	int& ret = cache[pick][money];

	if(ret != -1)
		return ret;

	ret = 0;

	ret = search(pick + 1, money);

	for(int i = 0; i < returnList.size(); ++i)
	{
		int cost = returnList[i][0];
		int earn = returnList[i][pick];
		int cand = 0;

		if(cost <= money)
		{
			ret = max(ret, search(pick + 1, money - cost) + earn);
		}
	}

	return ret;
}

int main(void)
{
	int n, m;
	cin >> n >> m;

	memset(cache, -1, sizeof(cache));

	for(int i = 0; i < n; ++i)
	{
		vector<int> v;

		int funding;
		cin >> funding;

		v.push_back(funding);

		for(int j = 0; j < m; ++j)
		{
			int s;
			cin >> s;

			v.push_back(s);
		}

		returnList.push_back(v);
	}

	vector<int> ans;

	cout << search(1, n) << "\n";

	reconstruct(ans, 1, n);

	for(int i = 0; i < ans.size(); ++i)
		cout << ans[i] << " ";
	
	cout << "\n";
}
