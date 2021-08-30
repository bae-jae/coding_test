#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;

vector<pair<int, int>> v;

int cache[1005][1005];
int who[1005];
int w;

void track(int p1, int p2)
{
	int idx =  max(p1, p2) + 1;
	
	if(idx == v.size())
		return;
	
	int ny = v[idx].first;
	int nx = v[idx].second;
	
	int p1x = 1;
	int p1y = 1;
	int p2x = w;
	int p2y = w;
	
	if(p1 != -1)
	{
		p1y = v[p1].first;
		p1x = v[p1].second;
	}
	
	if(p2 != -1)
	{
		p2y = v[p2].first;
		p2x = v[p2].second;
	}
	
	int dist1 = abs(ny - p1y) + abs(nx - p1x);
	int dist2 = abs(ny - p2y) + abs(nx - p2x);
	
	// cout << cache[p1 + 1][p2 + 1] - dist1 << " " <<  cache[idx + 1][p2 + 1] << endl;
	// cout << cache[p1 + 1][p2 + 1] - dist2 << " " <<  cache[p1 + 1][idx + 1] << endl;
	
	if(cache[p1 + 1][p2 + 1] - dist1 == cache[idx + 1][p2 + 1])
	{
		cout << 1 << "\n";
		track(idx, p2);
		return;
	}
	else
	{
		cout << 2 << "\n";
		track(p1, idx);
		return;
	}
}

//			나의 위치를 알려줌 
int search(int p1, int p2)
{
	int idx = max(p1, p2) + 1;	//다음 거리 위치 
	int& ret = cache[p1 + 1][p2 + 1];
	
	if(idx == v.size())
		return ret = 0;
	
	if(ret != -1)
		return ret;
	
	int ny = v[idx].first;
	int nx = v[idx].second;
	
	int p1x = 1;
	int p1y = 1;
	int p2x = w;
	int p2y = w;
	
	if(p1 != -1)
	{
		p1y = v[p1].first;
		p1x = v[p1].second;
	}
	
	if(p2 != -1)
	{
		p2y = v[p2].first;
		p2x = v[p2].second;
	}
	
	int dist1 = abs(ny - p1y) + abs(nx - p1x);
	int dist2 = abs(ny - p2y) + abs(nx - p2x);
	
	int cand1 = search(idx, p2) + dist1;
	int cand2 = search(p1, idx) + dist2;
	
	// if(cand1 < cand2)
	// 	who[idx] = 1;
	// else
	// 	who[idx] = 2;
	
	return ret = min(search(idx, p2) + dist1, search(p1, idx) + dist2);
}

int main(void)
{
	cin >> w;
	
	int n;
	cin >> n;
	
	for(int i = 0; i < n; ++i)
	{
		int s, e;
		cin >> s >> e;
		
		v.push_back({s, e});
	}
	
	memset(cache, -1, sizeof(cache));
	
	cout << search(-1, -1) << "\n";
	
	track(-1, -1);
}