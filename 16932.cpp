#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int map[1005][1005];
int labelMap[1005][1005];
int labelCount[100000];

int n, m;


int dy[4] = {-1, 0, 1,  0};
int dx[4] = { 0, 1, 0, -1};


int outRange(int y, int x)
{
	if(y < 0 || y >= n)
		return 0;
	
	if(x < 0 || x >= m)
		return 0;
	
	return 1;
}

int dfs(int y, int x, int label)
{
	int count = 0;
	
	labelMap[y][x] = label;
	
	for(int i = 0; i < 4; ++i)
	{
		int ry = y + dy[i];
		int rx = x + dx[i];
		
		if(outRange(ry, rx) == 0 || labelMap[ry][rx] != -1)
			continue;
		
		if(map[ry][rx] == 1)
			count += dfs(ry, rx, label);
	}
	return count + 1;	//자기자신 
}

int getScore(int y, int x)
{
	vector<int> v;
	int ans = 0;
	for(int i = 0; i < 4; ++i)
	{
		int ry = y + dy[i];
		int rx = x + dx[i];
		
		if(outRange(ry, rx) == 0 || labelMap[ry][rx] == -1)
			continue;
		
		v.push_back(labelMap[ry][rx]);
	}
	
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(),v.end()), v.end());
	
	
	for(int i = 0; i < v.size(); ++i)
		ans += labelCount[v[i]];
	
	return ans;	//자기자신 
}

int main(void)
{
	cin >> n >> m;
	
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			cin >> map[i][j];
		}
	}
	
	int label = 1;
	memset(labelMap, -1 ,sizeof(labelMap));
	
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			if(labelMap[i][j] == -1 && map[i][j] == 1)
			{
				labelCount[label] = dfs(i, j, label);
				++label;
			}
		}
	}
	
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			cout << labelMap[i][j] << " ";
		}
		cout << endl;
	}
	
	int ans= 0;
	
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			if(map[i][j] == 0)
			{
				ans = max(ans, getScore(i, j) + 1);
			}
		}
	}
	
	
	cout << ans << endl;
}