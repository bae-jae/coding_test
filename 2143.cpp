#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<long long> nPsum;
vector<long long> mPsum;

vector<long long> nList;
vector<long long> mList;

int main(void)
{
	int t;
	int n, m;
	
	cin >> t;
	cin >> n;
	
	for(int i = 0; i < n; ++i)
	{
		long long s;
		cin >> s;
		
		nList.push_back(s);
	}
	
	cin >> m;
	for(int i = 0; i < m; ++i)
	{
		long long s;
		cin >> s;
		
		mList.push_back(s);
	}
	
	nPsum.push_back(0);
	mPsum.push_back(0);
	
	
	for(int i = 0; i < nList.size(); ++i)
	{
		nPsum.push_back(nPsum[i] + nList[i]);
	}
	
	for(int i = 0; i < mList.size(); ++i)
		mPsum.push_back(mPsum[i] + mList[i]);
	
	long long ans = 0;
	
	map<long long, long long> st;
	
	for(int i = 0; i < mPsum.size(); ++i)
	{
		for(int j = i + 1  ; j < mPsum.size(); ++j)
		{
			st[mPsum[j] - mPsum[i]] += 1; 
		}
		
	}
	
	for(int i = 0; i < nPsum.size(); ++i)
	{
		for(int j = i + 1; j < nPsum.size(); ++j)
		{
			ans += st[t - (nPsum[j] - nPsum[i])];
		}
	}
	
	cout << ans;
}