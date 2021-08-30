#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> timeList;

long long n, k;
long long ans = (long long)1000000 * 1000010;

long long binary(void)
{
	long long start = -1;
	long long end = (long long)1000000 * 1000010;
	
	while(start + 1 < end)
	{
		long long mid = (start + end) / 2;
		long long make = 0;
		
		for(int i = 0; i < timeList.size(); ++i)
			make += mid / timeList[i];
		
		if(make < k)
			start = mid;
		else
			end = mid;
	}
	
	return end;
}

void search(int idx, int c)
{
	if(idx == timeList.size() || c == 0)
	{
		for(int i = 0; i < timeList.size(); ++i)
			cout << timeList[i] << " ";
		cout << endl;
		
		ans = min(ans, binary());
		return;
	}
	
	for(int i = 1; i <= c; ++i)
	{
		if(timeList[idx] - i < 1)
			break;
		
		timeList[idx] -= i;
		search(idx + 1, c - i);
		timeList[idx] += i;
	}
	
	search(idx + 1, c);
}

int main(void)
{
	long long c;
	
	cin >> n >> k >> c;
	
	for(int i = 0; i < n; ++i)
	{
		long long s;
		cin >> s;
		
		timeList.push_back(s);
	}
	
	search(0, c);
	
	cout << ans;
}