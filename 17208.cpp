#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m, k;
int cache[105][305][305];

vector<pair<int, int>> v;

int find(int idx, int c, int f)
{
	if(idx == v.size())
		return 0;
	
	int &ret = cache[idx][c][f];
	
	if(ret != -1)
		return ret;
	
	ret = find(idx + 1, c, f);
	
	int uc = v[idx].first;	//남은 치즈
	int uf = v[idx].second; //남은 프렌치
	
	if(c - uc >= 0 && f - uf >= 0)
		ret = max(ret, find(idx + 1, c - uc, f - uf) + 1);
	
	return ret;
}
int main(void)
{
	memset(cache, -1, sizeof(cache));
	
	cin >> n >> m >> k;
	
	for(int i = 0; i < n; ++i)
	{
		int c, f;
		cin >> c >> f;
		
		v.push_back({c, f});
	}
	
	cout << find(0, m, k);
}