#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int visited[100001];

int main(void)
{
	int n;
	cin >> n;

	vector<int> v;
	queue<int> q;

	for(int i = 0; i < n; ++i)
	{
		int s;
		cin >> s;

		v.push_back(s);
	}

	int answer = 0;

	for(int i = 0; i < v.size(); ++i)
	{
		if(visited[v[i]] == 1)
		{
			while(!q.empty())
			{
				int t = q.front();
				answer += q.size();
				
				q.pop();
				visited[t] = 0;

				if(t == v[i])
					break;

			}
		}

		q.push(v[i]);
		visited[v[i]] = 1;
	}

	while(!q.empty())
	{
		answer += q.size();
		q.pop();
	}

	cout << answer << endl;
}
