#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

int map[27][27];
int visited[27];

vector<int> answerList;
vector<string> query;

int can;

void dfs(int here)
{
	visited[here] = 1;

	for(int i = 0; i < 26; ++i)
	{
		if(map[here][i] == 1)
		{	
			if(visited[i] == 0)
				dfs(i);
			else
				can = 0;
		}
	}

	answerList.push_back(here);
}

void dfsAll(void)
{
	for(int i = 0; i < 26; ++i)
	{
		if(visited[i] == 0)
			dfs(i);
	}

	reverse(answerList.begin(), answerList.end());

	for(int i = 0; i < answerList.size(); ++i)
	{
		for(int j = i + 1; j < answerList.size(); ++j)
		{
			if(map[answerList[j]][answerList[i]] == 1)
			{
				answerList.clear();
				return;
			}
		}
	}
}

int min(int n1, int n2)
{
	if(n1 < n2)
		return n1;

	return n2;
}

void findAnswer()
{
	for(int i = 0; i < query.size() - 1; ++i)
	{
		int len = min(query[i].size(), query[i + 1].size());

		for(int j = 0; j < len; ++j)
		{
			if(query[i][j] != query[i + 1][j])
			{
				int x = query[i][j] - 'a';
				int y = query[i + 1][j] - 'a';

				map[x][y] = 1;

				break;
			}
		}
	}
}

int main(void)
{
	int n;
	cin >> n;

	for(int test = 0; test < n; ++test)
	{
		int wordN;
		string s;

		cin >> wordN;

		can = 0;

		query.clear();
		answerList.clear();

		memset(map, 0, sizeof(map));
		memset(visited, 0 ,sizeof(visited));

		for(int i = 0; i < wordN; ++i)
		{
			cin >> s;
			query.push_back(s);
		}

		findAnswer();
		dfsAll();

		if(answerList.size() == 0)
		{
			cout << "INVALID HYPOTHESIS";
		}
		else
		{
			for(int i = 0; i < answerList.size(); ++i)
				cout << char(answerList[i] + 'a');
		}

		cout << "\n";
	}
}
