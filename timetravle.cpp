#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, k;
int visited[100005];
int come[100005];
vector<int> path;

int find(int target)
{
	queue<pair<int, int>> q;

	q.push(make_pair(n,0));

	for(int i = 0; i < 100005; ++i)
		come[i] = 987654321;

	while(!q.empty())
	{
		int cand = q.front().first;
		int ans = q.front().second;

		q.pop();

		if(visited[cand] == 1)
			continue;

		if(come[target] > ans)
			come[target] = ans;

		visited[cand] = 1;
	
		if(cand == target)
		{
			return ans;
		}

		q.push(make_pair(cand + 1, ans + 1));
		come[cand + 1] = cand;
		
		if(cand > 0)
		{
			come[cand - 1] = cand;
			q.push(make_pair(cand - 1, ans + 1));
		}

		if(cand * 2 <= 100000)
		{
			come[cand * 2] = cand;
			q.push(make_pair(cand * 2, ans + 1));
		}
	}
}

int main(void)
{
	cin >> n >> k;

	int t = k;

	cout << find(t);
}
