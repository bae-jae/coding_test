#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> list;

int main(void)
{
	int k, n;
	cin >> k >> n;

	for(int i = 0; i < k; ++i)
	{
		int s;
		cin >> s;

		list.push_back(s);
	}

	sort(list.begin(), list.end());

	int startLen = 1;
	int endLen = list[list.size() - 1] + 1;

	while(startLen + 1 < endLen)
	{
		int mid = (startLen + endLen) / 2;
		int count = 0;

		for(int i = 0; i < list.size(); ++i)
			count += list[i] / mid;

		cout << count << " " << mid << " " << startLen << " " << endLen << endl;

		if(count >= n)
			startLen = mid;
		else
			endLen = mid;

	}
	cout << startLen << endl;
}
