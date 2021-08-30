#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int candArr[105];

int main(void)
{
	int n, cand;
	cin >> n >> cand;

	vector<int> v;

	for(int i = 0; i < cand; ++i)
	{
		int s;
		cin >> s;

		v.push_back(s);
	}

	queue<int> q;
	queue<int> sub;

	for(int i = 0; i < v.size(); ++i)
	{
		if(candArr[v[i]] != 0)
		{
			candArr[v[i]]++;
		}
		else
		{
			q.push(v[i]);

			if(q.size() <= n)
			{
				candArr[v[i]]++;
				continue;
			}

			int count = 987654321;

			for(int j = 1; j <= 100; ++j)
				if(candArr[j] >= 1)
					count = min(count, candArr[j]);

			candArr[v[i]]++;

			while(!q.empty())
			{
				int tar = q.front();
				q.pop();

				if(candArr[tar] == count)
				{
					candArr[tar] = 0;
					count = 0;
				}
				else
					sub.push(tar);
			}

			q = sub;
			
			while(!sub.empty())
				sub.pop();
		}
	}

	v.clear();

	while(!q.empty())
	{
		int tar = q.front();
		v.push_back(tar);
		q.pop();
	}

	sort(v.begin(), v.end());

	for(int i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
}
