#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

int map[27][27];
int use[101];

int comeNode[27];
int outNode[27];

vector<string> list;
vector<int> answerList;

void make_map(int n)
{
	for(int i = 0; i < n; ++i)
	{
		int start = list[i][0] - 'a';
		int end = list[i][list[i].size() - 1] - 'a';

		++outNode[start];
		++comeNode[end];
		
		++map[start][end];
	}
}

void dfs(int here)
{
	for(int there = 0; there < 27; ++there)
	{
		while(map[here][there] > 0)
		{
			--map[here][there];
			dfs(there);
		}
	}
	answerList.push_back(here);
}

vector<string> changeAnswer()
{
	vector<string> answer;

	for(int i = 0; i < answerList.size() - 1; ++i)
	{
		char s = answerList[i] + 'a';
		char e = answerList[i + 1] + 'a';


		for(int j = 0; j < list.size(); ++j)
		{
			if(use[j] == 0 && (list[j][0] == s) && (list[j][list[j].size() - 1] == e))
			{
				answer.push_back(list[j]);
				use[j] = 1;
				break;
			}
		}
	}

	return answer;
}

int checkImpossible()
{
	int outNum = 0;
	int comeNum = 0;

	for(int i = 0; i < 27; ++i)
	{
		int come = comeNode[i];
		int out = outNode[i];

		int sub = out - come;

		if(sub < -1 || 1 < sub)
			return -1;

		if(sub == 1)
		{
			outNum++;
		}
		if(sub == -1)
		{
			comeNum++;
		}
	}

	if((comeNum == 1 && outNum == 1) || (comeNum == 0 && outNum == 0))
		return 1;

	return -1;
}

vector<string> search(void)
{
	vector<string> answer;

	for(int i = 0; i < 27; ++i)
	{
		if(outNode[i] == comeNode[i] + 1)
		{
			dfs(i);
			break;
		}
	}

	if(answerList.size() != 0)
	{
		reverse(answerList.begin(), answerList.end());
		answer = changeAnswer();
		return answer;
	}

	for(int i = 0; i < 27; ++i)
	{
		if(outNode[i] >=1)
		{
			dfs(i);
			break;
		}
	}

	reverse(answerList.begin(), answerList.end());
	answer = changeAnswer();
	return answer;
}
int main(void)
{
	int tc;
	cin >> tc;

	string s;

	for(int test = 0; test < tc; ++test)
	{
		int n;
		cin >> n;

		for(int i = 0; i < n; ++i)
		{
			cin >> s;
			list.push_back(s);
		}

		memset(map,0, sizeof(map));
		memset(comeNode, 0 , sizeof(comeNode));
		memset(outNode, 0, sizeof(outNode));
		memset(use, 0 , sizeof(use));

		make_map(n);

		int can = checkImpossible();

		if(can == -1)
			cout << "IMPOSSIBLE";
		else
		{
			vector<string> answer = search();

			if(answer.size() != n)
				cout << "IMPOSSIBLE";
			else
				for(int i = 0; i < answer.size() - 1; ++i)
					cout << answer[i] << " ";

			cout << answer[answer.size() -1];
		}

		cout << "\n";

		list.clear();
		answerList.clear();
	}
	return 0;
}
