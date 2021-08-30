#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int max(int n1, int n2)
{
	if(n1 > n2)
		return n1;

	return n2;
}

int min(int n1, int n2)
{
	if(n1 < n2)
		return n1;

	return n2;
}
int main(void)
{
	vector<int> stone;

	for(int i = 0; i < 10; ++i)
	{
		int s;
		cin >> s;

		stone.push_back(s);
	}

	int k;
	cin >> k;

	vector<int> clone = stone;
		
	int low = 0;
	int high = 200000005;


	while(low < high)
	{
		int mid = (low + high) / 2;

		int count = 0;
		int len = 0;

		for(int i = 0; i < stone.size(); ++i)
		{
			if(stone[i] <= mid)
				++count;
			else
			{
				count = 0;
			}

			len = max(len, count);
		
		}

		if(len >= k)
			high = mid - 1;
		else
			low = mid + 1;

	}
	
	cout << low << endl;

	return 0;
}
