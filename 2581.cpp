#include <iostream>

using namespace std;

int arr[10000];

void check(void)
{
	arr[0] = 1;
	arr[1] = 1;
	
	for(int i = 2; i <= 10000; ++i)
	{
		if(arr[i] == 0)
		{
			for(int j = i * 2; j <= 10000; j = j + i)
			{
				arr[j] = 1;
			}
		}
	}
}
int main(void)
{
	int m, n;
	
	cin >> m >> n;
	check();
	
	int minAns = 987654321;
	int ans = 0;
	
	for(int i = m; i <= n; ++i)
	{
		if(arr[i] == 0)
		{
			minAns = min(minAns, i);
			ans += i;
		}
	}
	
	if(ans == 0)
		cout << -1;
	else
	{
		cout << ans << "\n";
		cout << minAns << "\n"	;
	}
	
}