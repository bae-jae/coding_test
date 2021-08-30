#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> list;
int used[29];
int answer;
string sub;

void search(int idx, int k)
{
	if(idx >= sub.size())
	{
		int canAns = 0;

		for(int i = 0; i < list.size(); ++i)
		{
			int canCount = 1;

			for(int j = 0; j < list[i].size(); ++j)
			{
				if(used[list[i][j] - 'a'] != 1)
				{
					canCount = 0;
					break;
				}
			}

			if(canCount == 1)
				++canAns;
		}

		answer = max(answer, canAns);
		return;
	}

	int visited = sub[idx] - 'a';

	if(k >= 1 && used[visited] == 0)
	{
		used[visited] = 1;
		search(idx + 1, k - 1);
		used[visited] = 0;
	}
	search(idx + 1, k);
}

int main(void)
{
	int n, k;
	cin >> n >> k;

	for(int i = 0; i < n; ++i)
	{
		string s;
		cin >> s;

		list.push_back(s);
	}

	if(k < 5)
		cout << 0;
	else if(k == 26)
		cout << n;
	else
	{
		for(int i = 0; i < list.size(); ++i)
		{
			for(int start = 4; start < list[i].size() - 4; ++start)
			{
				int idx = list[i][start] - 'a';

				if(used[idx] == 0)
				{
					sub += list[i][start];
					used[idx] = 1;
				}
			}
		}


		search(0, k);

		cout << answer;
	}
}
