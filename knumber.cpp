#include<iostream>
#include<vector>
#include<map>
#include<string.h>

using namespace std;

int cache[300005];
int m[300005];

int min(int n1, int n2)
{
	if(n1 < n2)
		return n1;

	return n2;
}

int main(void)
{
	int tc;
	cin >> tc;

	for(int test =0; test < tc; ++test)
	{
		int n;
		cin >> n;

		vector<int> v;


		memset(cache, 0, sizeof(cache));
		memset(m, -1, sizeof(m));

		for(int i = 0;i < n; ++i)
		{
			int s;
			cin >> s;

			v.push_back(s);
		}

		//1은 집입 초기에 처리
		for(int i = 1; i <= n; ++i)
		{
			for(int j = 0; j < n; ++j)
			{
				int idx = j % i;
				int pos = m[idx];

				m[idx] = j;

				if(pos == -1)		//없을경우
					++cache[v[j]];
				else
				{
					if(v[j] != v[pos])
						cache[v[pos]]--;
				}
			}

			int answer = 987654321;

			for(int j = 0; j < n; ++j)
			{
				if(cache[v[j]] >= 1)
					answer = min(answer, v[j]);

				cache[v[j]] = 0;
				m[j] = -1;
			}


			if(answer == 987654321)
				cout << "-1" << " ";
			else
				cout << answer << " ";
		}

		cout << endl;
	}
}
