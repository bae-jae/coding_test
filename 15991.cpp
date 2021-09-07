#include <iostream>
#include <cstring>

using namespace std;

int ans;
int cache[100000];

int find(int now)
{
	if(now == 0)
	{
		return 1;
	}
	
	int &ret = cache[now];
	
	if(ret != -1)
	{
		return ret;
	}
	
	ret = 0;
	
	for(int i = 1; i <= 3; ++i)
	{
		int left = now - i * 2;
		
		if(left >= 0)
		{
			ret += find(left);
		}
		else if(now - i == 0)
		{
			ret += find(0);
		}
		
		ret = (ret % 1000000009);
	}
	
	return ret;
}

int main(void)
{
	int tc;
	cin >> tc;
		
	
	for(int i = 0; i < tc; ++i)
	{
		int n;
		cin >> n;

		memset(cache, -1, sizeof(cache));
		cout << find(n) << "\n";
	}
}