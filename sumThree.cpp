#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> v;
long long ans = 0;

long long max(long long n1, long long n2)
{
	if(n1 > n2)
		return n1;

	return n2;
}

int main(void)
{
	int n;
	cin >> n;

	for(int i = 0; i < n; ++i)
	{
		int s;
		cin >> s;

		v.push_back(s);
	}

	vector<int> left;
	vector<pair<int, int>> right;

	for(int i = 0; i < v.size(); ++i)
	{
		for(int j = 0; j < v.size(); ++j)
		{
			left.push_back(v[i] + v[j]);
			right.push_back(make_pair(v[i] - v[j], v[i]));
		}
	}

	sort(left.begin(), left.end());
	sort(right.begin(), right.end());

	int l = 0;
	int r = 0;

	while(l < left.size() && r < right.size())
	{
		if(left[l] < right[r].first)
			++l;
		else if(left[l] > right[r].first)
			++r;
		else
		{
			ans = max(ans, right[r].second);
			l++;
			r++;
		}
	}

	cout << ans;
}
