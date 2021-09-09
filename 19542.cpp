#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> map[100005];
int visited[100005];
int len[100005];

int answer = 0;
int s, n, d;

int getLength(int node)
{
	visited[node] = 1;
	
	int last = 1;
	int maxLen = 0;
	
	for(int i = 0; i < map[node].size(); ++i)
	{
		int next = map[node][i];
		
		if(visited[next] == 0)
		{
			last = 0;
			maxLen = max(maxLen, getLength(next) + 1);
		}
	}
	
	if(last == 1)
		return 0;
	
	return len[node] = maxLen;
}


void dfs(int node)
{
	visited[node] = 1;
	int last = 1;
	
	for(int i = 0; i < map[node].size(); ++i)
	{
		int next = map[node][i];
		
		if(visited[next] == 0 && len[next] >= d)
		{
			++answer;
			dfs(next);
			++answer;
			
			last = 0;
		}
	}
	
	return;
}

int main(void)
{
	cin >> n >> s >> d;
	
	for(int i = 1; i < n; ++i)
	{
		int sn, en;
		cin >> sn >> en;
		
		map[sn].push_back(en);
		map[en].push_back(sn);
		
	}
	
	int len = getLength(s);
	
	memset(visited, 0, sizeof(visited));
	dfs(s);
	
	cout << answer;
	
	
}