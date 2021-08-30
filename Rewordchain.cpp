#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

int map[27][27];
int visited[101];
int in[27];
int out[27];

vector<int> list;
vector<string> v;

void init(void)
{
	memset(map, 0, sizeof(map));
	memset(visited, 0, sizeof(visited));
	memset(in, 0, sizeof(in));
	memset(out, 0, sizeof(out));

	list.clear();
	v.clear();
}

int getCircuit(int here)
{
	for(int there = 0; there < 26; ++there)
	{
		while(map[here][there] > 0)
		{
			map[here][there]--;
			getCircuit(there);
		}
	}

	list.push_back(here);
}

void search(int here)
{

	for(int i = 0; i < 26; ++i)
	{
		if(out[i] == in[i] + 1)
		{
			here = i;
			break;
		}
	}
	getCircuit(here);
	reverse(list.begin(), list.end());

	vector<string> answer;

	for(int i = 0; i < list.size() - 1; ++i)
	{
		int s = list[i];
		int e = list[i + 1];

		for(int j = 0; j < v.size(); ++j)
		{
			int start = v[j][0] - 'a';
			int end = v[j][v[j].size() - 1] - 'a';

			if(visited[j] == 0 && s == start && e == end)
			{
				visited[j] = 1;
				answer.push_back(v[j]);
				break;
			}
		}
	}

	for(int i = 0; i < v.size(); ++i)
	{
		if(visited[i] == 0)
		{
			cout << "IMPOSSIBLE" << endl;
			return;
		}
	}

	for(int i = 0; i < answer.size(); ++i)
		cout << answer[i] << " ";

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

		init();

		for(int i = 0; i < n; ++i)
		{
			string s;
			cin >> s;

			int start = s[0] -'a';
			int end = s[s.size() - 1] - 'a';

			++map[start][end];
			v.push_back(s);

			out[start]++;
			in[end]++;
		}

		search(v[0][0]- 'a');
	}
}
