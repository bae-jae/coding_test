#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

vector<int> list;

int map[27][27];
int visited[27];

void init(void)
{
	list.clear();

	memset(map, 0, sizeof(map));
	memset(visited, 0, sizeof(visited));
}

void dfs(int n)
{
	if(visited[n] == 1)
		return;

	visited[n] = 1;

	for(int j = 0; j < 26; ++j)
	{
		if(map[n][j] == 1)
			dfs(j);
	}

	list.push_back(n);
}

void dfsAll(void)
{
	for(int i = 0; i < 26; ++i)
	{
		if(visited[i] == 0)
			dfs(i);
	}

	reverse(list.begin(), list.end());

	for(int i = 0; i < list.size(); ++i)
	{
		for(int j = i + 1; j < list.size(); ++j)
			if(map[list[j]][list[i]] == 1)
			{
				cout << char(list[j] +'a') << " " << char(list[i] + 'a') << endl;
				cout << "INVALID HYPOTHESIS" << endl;
				return;
			}
	}

	for(int i = 0; i < list.size(); ++i)
		cout << (char)(list[i] + 'a');

	cout << endl;
}

int main(void)
{
	int tc;
	cin >> tc;

	for(int test = 0; test < tc; ++test)
	{
		int n;
		cin >> n;

		vector<string> v;
		init();

		for(int i = 0; i < n; ++i)
		{
			string s;
			cin >> s;

			v.push_back(s);
		}

		//string to map
		for(int i = 0; i < v.size() - 1; ++i)
		{
			for(int j = 0; j < min(v[i + 1].size(), v[i].size()); ++j)
			{
				if(v[i][j] != v[i + 1][j])
				{
					int start = v[i][j] - 'a';
					int end =  v[i + 1][j] - 'a';

					map[start][end] = 1;
					break;
				}
			}
		}

		dfsAll();
	}
}
