#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


vector<pair<int, pair<int, int>>> board;
int parent[1005];

void init(void)
{
	for(int i = 0; i < 1005; ++i)
		parent[i] = i;
}

int find(int node)
{
	if(parent[node] == node)
		return node;
	
	return parent[node] = find(parent[node]);
}

int makeUnion(int n1, int n2)
{
	n1 = find(n1);
	n2 = find(n2);
	
	if(n1 == n2)
		return 0;
	
	parent[n1] = n2;
	
	return 1;
}

int cut(int n)
{
	int top = find(n);
	
	for(int i = 1; i <= n; ++i)
	{
		if(top != find(i))
			return 0;
	}
	
	return 1;
}

int main(void)
{
	int n, m, k;
	cin >> n >> m >> k;
	
	init();
	
	for(int i = 0; i < m; ++i)
	{
		int start, end;
		cin >> start >> end;
		
		board.push_back({i + 1, {start, end}});
	}
	
	sort(board.begin(), board.end());
	int ans = 0;
	
	for(int i = 0; i < board.size(); ++i)
	{
		int s = find(board[i].second.first);
		int e = find(board[i].second.second);
		
		if(s != e)
			ans += board[i].first;
		
		makeUnion(s, e);
	}
	
	
	for(int i = 0; i < k; ++i)
	{
		if(cut(n) == 0)
			cout << 0 << " ";
		else
			cout << ans << " ";
		
		init();
		
		ans = 0;
		
		for(int j = i + 1; j < board.size(); ++j)
		{
			int s = find(board[j].second.first);
			int e = find(board[j].second.second);
		
			if(s != e)
				ans += board[j].first;
			
			makeUnion(s, e);
		}
		
	}
}