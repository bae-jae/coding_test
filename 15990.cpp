#include <iostream>
#include <cstring>

using namespace std;

int ans;
int cache[100000][5];

int find(int now, int whatUse)
{
	if(now == 0)
		return 1;
	
	int &ret = cache[now][whatUse + 1];
	
	if(ret != -1)
	{
		return ret;
	}
	
	ret = 0;
	
	for(int i = 1; i <= 3; ++i)
	{
		int left = now - i;
		
		if(i != whatUse && now >= 0)
		{
			ret += find(left, i);
		}
		
		ret = (ret % 1000000009);
	}
	
	return ret;
}

int main(void)
{
	int tc;
	cin >> tc;
	
	memset(cache, -1, sizeof(cache));
	
	for(int i = 0; i < tc; ++i)
	{
		int n;
		cin >> n;
		
		cout << find(n, -1) << "\n";
	}
}