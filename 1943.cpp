#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int cache[105][100010];
vector<pair<int, int>> v;
int sum;

int search(int idx, int me)
{
	if(sum <= me * 2)
	{
		if(sum == me * 2)
			return 1;
		
		return 0;
	}
	
	if(idx == v.size())
		return 0;
	
	
	int &ret = cache[idx][me];
	
	if(ret != -1)
		return ret;
	
	ret = search(idx + 1, me);
	
	for(int i = 1; i <= v[idx].second; ++i)
	{
		ret = max(ret, search(idx + 1, me + v[idx].first * i));
	}
	
	return ret;
}

int main(void)
{
	for(int i = 0; i < 3; ++i)
	{
		int n;
		cin >> n;
		
		sum = 0;
		
		memset(cache, -1, sizeof(cache));
		
		for(int j = 0; j < n; ++j)
		{
			int cost, count;
			cin >> cost >> count;
			
			sum += (cost * count);
			
			v.push_back({cost, count});
		}
		
		cout << search(0, 0) << "\n";
		
		v.clear();
	}
}