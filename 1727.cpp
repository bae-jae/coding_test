#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

long long range = 0;

vector<long long> man;
vector<long long> girl;

long long cache[1005][1005];

//이럴경우 테스트 코드 어떻게 작성할건가 생각해보기 
//		항상 작고,  항상 크고 
long long search(int midx, int gidx)
{
	if(midx == range)
		return 0;
	
	long long &ret = cache[midx][gidx];
	
	if(ret != -1)
		return ret;
	
	ret = 987654321;
	
	for(int i = gidx; i < girl.size(); ++i)
		ret = min(ret, search(midx + 1, i + 1) + abs(man[midx] - girl[i]));
	
	return ret;
}


int main(void)
{
	int n, m;
	cin >> n >> m;
	
	range = min(n, m);
	
	for(int i = 0; i < n; ++i)
	{
		int s;
		cin >> s;
		
		man.push_back(s);
	}
	
	sort(man.begin(), man.end());
	
	for(int j = 0; j < m; ++j)
	{
		int s;
		cin >> s;
		
		girl.push_back(s);
	}
	
	sort(girl.begin(), girl.end());
	
	if(man.size() > girl.size())
	{
		vector<long long> v = man;
		man = girl;
		girl = v;
	}
	
	memset(cache, -1, sizeof(cache));
	
	cout << search(0, 0);
}