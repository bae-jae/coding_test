#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> list;
int n, maxDay;
int dp[11][500001];

int main(void)
{
	int asset;

	cin >> n >> maxDay >> asset;

	list.resize(n);

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < maxDay; ++j)
		{
			int p;
			cin >> p;

			list[i].push_back(p);
		}
	}

		for(int day = 0; day < maxDay - 1; ++day)
		{
			for(int buget = 1; buget <= 500000; ++buget)
			{
				for(int sl = 0; sl < list.size(); ++sl)
				{
					int nd = buget - list[sl][day];
					int gd = list[sl][day + 1] - list[sl][day];

					if(nd >= 0)
					{
						dp[day][buget] = max(dp[day][buget], dp[day][nd] + gd);
					}

					//cout << day << " " << sl << " " << buget << " " << dp[day][buget] << endl;
				}
			}

		}


		for(int i = 0; i < maxDay - 1; ++i)
		{
			//cout << asset << endl;
			asset += dp[i][asset];
		}

		cout << asset << endl;
}
