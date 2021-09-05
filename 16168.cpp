#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

vector<int> board[1000005];
int visited[1000005];
int ans = 0;

int dfs(int node)
{
	int pick = 0;
	int last = 1;
	
	visited[node] = 1;

	for(int i = 0; i < board[node].size(); ++i)
	{
		int next = board[node][i];
		
		if(visited[next] == 1)
			continue;
		
		last = 0;
		
		if(dfs(next) == 0)
			pick = 1;
	}
	
	if(pick == 1)
		++ans;
	
	return pick;
}
int main(void)
{
	int n;
	cin >> n;
	
	for(int i = 0; i < n - 1; ++i)
	{
		int s, e;
		cin >> s >> e;
		
		board[s].push_back(e);
		board[e].push_back(s);
	}
	
	dfs(1);
	
	cout <<  ans;
}