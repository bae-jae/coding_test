#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> orders;
vector<int> course;
map<string, int> m;

vector<string> list;

void split(string s, int start, string cand, int n)
{
	if(cand.size() == n)
	{
		list.push_back(cand);
		m[cand]++;
		return;
	}

	if(s.size() <= start)
		return;

	split(s, start + 1, cand + s[start], n);
	split(s, start + 1, cand, n);

}

void ready()
{
	for(int i = 0; i < orders.size(); ++i)
	{
		for(int j = 0; j < course.size(); ++j)
		{
			split(orders[i], 0, "", course[j]);
		}
	}
}

int max(int n1, int n2)
{
	if(n1 > n2)
		return n1;

	return n2;
}

void search2()
{
	vector<int> board(11, 0);
	vector<string> answer;

	sort(list.begin(), list.end());
	list.erase(unique(list.begin(), list.end()), list.end());

	for(int k = 0; k < course.size(); ++k)
	{
		int maxN = 0;
		for(int i = 0; i < list.size(); ++i)
		{
			if(list[i].size() == course[k])
			{
				maxN = max(maxN, m[list[i]]);
			}
		}

		if(maxN < 2)
			continue;

		for(int i = 0; i < list.size(); ++i)
		{
			if(list[i].size() == course[k])
			{
				if(m[list[i]] == maxN)
				{
					answer.push_back(list[i]);
				}
			}
		}
	}

	sort(answer.begin(), answer.end());

}
int main(void)
{
	int tc;
	cin >> tc;

	for(int test = 0; test < tc; ++test)
	{
		int orderN;
		cin >> orderN;

		m.clear();
		orders.clear();

		for(int i = 0; i < orderN; ++i)
		{
			string s;
			cin >> s;

			sort(s.begin(), s.end());
			orders.push_back(s);
		}

		int courseN;
		cin >> courseN;

		course.clear();
		for(int i = 0; i < courseN; ++i)
		{
			int cand;
			cin >> cand;

			course.push_back(cand);
		}

		ready();
		search2();
	}
}
