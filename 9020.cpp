#include <iostream>
#include <cmath>
using namespace std;

int arr[10004];

void find(void)
{
	for(int i = 2; i <= 10000; ++i)
	{
		if(arr[i] != -1)
		{
			arr[i] = 1;
		}

		int sub = i;
		int maxNum = i;

		while(maxNum <= 10000)
		{
			maxNum += sub;

			if(maxNum > 10000)
				break;

			arr[maxNum] = -1;
		}
	}
}

int main(void)
{
	int tc;
	cin >> tc;

	find();


	for(int test = 0; test < tc; ++test)
	{

		int qury;
		cin >> qury;

		int minans = 987321;
		int ans[2];

		for(int i = 2; i <= qury; ++i)
		{
			if(arr[i] == 1)
			{
				if(arr[qury - i] == 1)
				{
					if(minans > abs(((qury - i) - i)))
					{
						ans[0] = i;
						ans[1] = qury - i;

						minans = ans[1] - ans[0];
					}
				}
			}
		}

		cout << ans[0] << " " << ans[1] << "\n";
	}
}
