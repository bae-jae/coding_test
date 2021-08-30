#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int visited[10];
int answer = - 1;

string s;
string cand;

void search(int n, int end)
{
	if(n == s.size())
	{
		if(stoi(cand) <= end)
		{
			answer = max(stoi(cand), answer);
		}
		return;
	}
	else
	{
		for(int i = 0; i < s.size(); ++i)
		{
			if(visited[i] == 0)
			{
				if(n == 0 && s[i] == '0')
					continue;

				visited[i] = 1;

				cand.push_back(s[i]);
				search(n + 1, end);
				cand.pop_back();
				
				visited[i] = 0;
			}
		}
	}
}

int main(void)
{
	int n, m;
	cin >> n >> m;

	s = to_string(n);

	search(0, m);

	cout << answer;
}
