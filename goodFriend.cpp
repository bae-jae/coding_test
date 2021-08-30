#include <iostream>
#include <vector>
#include <string>
#include <string.h>

using namespace std;

int visited[300000];
vector<string> v;
int answer;

int max(int n1, int n2)
{
	if(n1 > n2)
		return n1;

	return n2;
}

void search(int ans, int k)
{
	int start = -1;

	for(int i = 0; i < v.size(); ++i)
	{
		if(visited[i] == 0)
		{
			start = i;
			break;
		}
	}

	if(start == -1)
	{
		answer = max(answer, ans);
		return;
	}

	cout << start << endl;

	for(int i = start + 1; i < v.size(); ++i)
	{
		if(i - start <= k && visited[i] == 0)
		{
			if(v[start].size() == v[i].size())
			{
				visited[i] = 1;
				search(ans + 1, k);
				visited[i] = 0;
			}
		}
		else
			break;
	}
}

int main(void)
{
	int n;
	int k;

	cin >> n >> k;

	memset(visited, 0, sizeof(visited));

	for(int i = 0; i < n; ++i)
	{
		string s;
		cin >> s;

		v.push_back(s);
	}

	search(0, k);
	cout << answer;
}
