#include <iostream>
#include <vector>
using namespace std;

vector<int> query;
vector<pair<int, int>> map;
vector<int> xList;
vector<int> answer;

const int DIV = 998244353;

void search(void)
{
	vector<int> memory;

	for(int i = 0; i < xList.size(); ++i)
	{
		memory.clear();

		memory.push_back(1);
		memory.push_back(xList[i]);

		for(int j = 0; j < query.size(); ++j)
		{
			int q = query[j];
			int fa = map[j].first;
			int fb = map[j].second;
			int result;

			if(q == 1)
			{
				result = (memory[fa] + memory[fb]);
			}
			else if(q == 2)
			{
				result = (fa * memory[fb]);
			}
			else if(q == 3)
			{
				result = (memory[fa] * memory[fb]);
			}
			memory.push_back(result % DIV);
		}

		answer.push_back(memory[memory.size() - 1] % DIV);
	}
}
int main(void)
{
	int tc;
	cin >> tc;

	for(int test = 0; test < tc; ++test)
	{
		int n;
		cin >> n;

		query.clear();
		answer.clear();
		map.clear();

		for(int i = 2; i <= n; ++i)
		{
			int t, a, b;
			cin >> t >> a >> b;
			
			query.push_back(t);
			map.push_back(make_pair(a,b));
		}

		int m;
		cin >> m;

		xList.clear();
		for(int i = 0; i < m; ++i)
		{
			int x;
			cin >> x;

			xList.push_back(x);
		}

		search();

		cout << "#" << test + 1 << " ";

		for(int i = 0; i < answer.size(); ++i)
		{
			cout << answer[i] << " ";
		}

		cout << endl;
	}
}
