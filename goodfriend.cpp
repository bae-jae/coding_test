#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main(void)
{
	int n, k;

	cin >> n >> k;

	vector<int> v;
	queue<int> q[21];

	for(int i = 0; i < n; ++i)
	{
		string s;
		cin >> s;

		v.push_back(s.size());
	}

	int answer = 0;

	for(int i = 0; i < n; ++i)
	{
		int len = v[i];

		if(q[len].size() == 0)
			q[len].push(i);
		else
		{
			q[len].push(i);

			while(!q[len].empty())
			{
				int idx = q[len].front();

				if(i - idx > k)
					q[len].pop();
				else
					break;
			}

			answer += (q[len].size() - 1);
		}
	}

	cout << answer;
}
