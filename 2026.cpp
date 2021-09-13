#include <iostream>
#include <vector>

using namespace std;

int map[905][905];
int fcount[901];
int visited[901];
int FIND;
int k;

vector<int> ans;

int search(int node)
{
	for(int i = 0; i < 901; ++i)
	{
		if(visited[i] == 1)
		{
			if(map[node][i] == 0)
				return 0;
		}	
	}
	
	return 1;
}

void dfs(int node)
{
	ans.push_back(node);
	
	if(FIND == 1)
		return;
	
	if(ans.size() == k)
	{
		for(int i = 0; i < ans.size(); ++i)
			cout << ans[i] << "\n";
		
		FIND = 1;
		
		return;
	}
	
	for(int i = 1; i < 901; ++i)
	{
		int next = i;
		
		if(visited[next] == 0 && map[node][next] == 1)
		{
			if(search(next) == 0)
				continue;
			
			visited[next] = 1;
			dfs(next);
			visited[next] = 0;
		}
	}
	
	ans.pop_back();
}

int main(void)
{
	int n, f;
	cin >> k >> n >> f;
	
	for(int i = 0; i < f; ++i)
	{
		int s1, s2;
		cin >> s1 >> s2;
		
		map[s1][s2] = 1;
		map[s2][s1] = 1;
		
		++fcount[s1];
		++fcount[s2];
	}
	
	for(int i = 1; i <= n; ++i)
	{
		
		if(fcount[i] + 1 < k)
			continue;
		
		visited[i] = 1;
		dfs(i);
		visited[i] = 0;
	}
	
	if(FIND == 0)
		cout << -1 << endl;
}