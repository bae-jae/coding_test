#include <iostream>

using namespace std;

int main(void)
{
	int tc;
	cin >> tc;

	for(int test = 0; test < tc; ++test)
	{
		long long x;
		cin >> x;

		long long height = 1;

		while(1)
		{
			long long sub = ((height * height) - height) / 2 + height;

			if(sub > x)
				break;

			++height;			//최대 높이 나옴 
		}

		cout << height << endl;

		int ans = 0;
		for(int i = height - 1; i >= 1; --i)
		{
			int blockNum = (i * i - i) / 2 + i; //블럭 개수 

			if(x >= blockNum)
			{
				++ans;
				x -= blockNum;
			}
		}

		cout << ans << endl;
	}
}
