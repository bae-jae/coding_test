#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int person[1005];
int parent[1005];

vector<pair<int, pair<int, int>>> list;

void init()
{
	for(int i = 0; i < 1005; ++i)
	{
		parent[i] = i;
	}
}

int find(int node)
{
	if(parent[node] == node)
		return node;
	
	return parent[node] = find(parent[node]);
}

int merge(int s, int e)
{
	s = find(s);
	e = find(e);
	
	if(s == e)
		return 0;
	
	parent[e] = s;
	
	return 1;
}

int main(void)
{
	int n, m;
	cin >> n >> m;
	
	init();
	
	for(int i = 1; i <= n; ++i)
	{
		string s;
		cin >> s;
		
		if(s == "M")
			person[i] = 0;
		else
			person[i] = 1;
	}
	
	for(int i = 0; i < m; ++i)
	{
		int s, e, c;
		cin >> s >> e >> c;
		
		list.push_back({c, {s, e}});
	}
	
	sort(list.begin(), list.end());
	
	int ans = 0;
	
	for(int i = 0; i < list.size(); ++i)
	{
		int cost = list[i].first;
		int start = list[i].second.first;
		int end = list[i].second.second;
		
		if(person[start] == person[end])
			continue;
		else{
			if(merge(start, end) == 1)
			{
				ans += cost;
			}
		}
	}
	
	for(int i = 2; i <= n; ++i)
	{
		if(merge(i, 1) == 1)
			ans = -1;
	}
	
	cout << ans;
}