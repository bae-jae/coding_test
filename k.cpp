#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
	int n;
	cin >> n;

	int idx;
	cin >> idx;

	int left = 0;
	int right = n * n;

	while(left + 1 < right)
	{
		int mid = (left + right) / 2;

		int cnt = 0;
		
		for(int i = 1; i <= n; ++i)
			cnt += min(mid / i, n);

		if(cnt < idx)
			left = mid;
		else
			right = mid;
	}

	cout << right<< endl;
}
