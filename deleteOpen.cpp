#include <iostream>
#include <stack>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

stack<int> list;
map<string, int> m;
string s;

vector<string> ansList;

int visited[2005];
int check[2005];

int countC;

void find(int idx)
{
	if(idx == countC)
	{
		string ans;

		for(int i = 0; i < s.size(); ++i)
		{
			if(visited[i] == -1)
			{
				ans += s[i];
				continue;
			}

			if(check[visited[i]] == 0)
			{
				ans += s[i];
			}
		}

		if(m[ans] == 0)
		{
			ansList.push_back(ans);
			m[ans] = 1;
		}


		return;
	}

	find(idx + 1);	//그냥

	check[idx] = 1;
	find(idx + 1);
	check[idx] = 0;
}

int main(void)
{
	cin >> s;

	m[s] = 1;

	memset(visited, -1, sizeof(visited));

	for(int i = 0; i < s.size(); ++i)
	{
		if(s[i] == '(')
		{
			visited[i] = countC;
			list.push(countC);

			++countC;
		}

		if(s[i] == ')')
		{
			int pos = list.top();
			list.pop();

			visited[i] = pos;
		}
	}

	find(0);

	sort(ansList.begin(), ansList.end());

	for(int i = 0; i < ansList.size(); ++i)
		cout << ansList[i] << "\n";
}
