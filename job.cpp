#include <iostream>
#include <vector>

using namespace std;

int timeList[102];
vector<int> list[102];
int finished[102];


int maxTime(int idx)
{
	int ans = 0;

	for(int i = 0; i < list[idx].size(); ++i)
	{
		ans = max(ans, finished[list[idx][i]]);
	}

	return ans;
}

int find(int n)
{
	for(int i = 1; i <= n; ++i)
	{
		finished[i] = maxTime(i) + timeList[i];

		cout << i << " " << finished[i] << endl;
	}

	int ans = 0;

	for(int i = 1; i <= n; ++i)
		ans = max(ans, finished[i]);

	return ans;
}

int main(void)
{
	int n;
	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		int needtime;
		int num;

		cin >> needtime;
		cin >> num;

		timeList[i] = needtime;

		for(int j = 0; j < num; ++j)
		{
			int s;
			cin >> s;

			list[i].push_back(s);
		}
	}

	cout << find(n) << endl;
}
