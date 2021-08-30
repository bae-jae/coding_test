#include <iostream>
#include <vector>

using namespace std;

int cnt[100005][2];
int dp[100005][2];

int main(void)
{
	int n, k;
	int first;

	cin >> n >> k;

	for(int i = 0; i < n; ++i)
	{
		int s;
		cin >> s;

		if(i == 0)
			first  = s;

		++cnt[i % k][s % 2];
	}

	dp[0][0] =  cnt[0][1];
	dp[0][1] =  cnt[0][0];

	for(int i = 1; i < k; ++i)
	{
		dp[i][0] = min(dp[i-1][0] + cnt[i][1], dp[i-1][1] + cnt[i][0]);
		dp[i][1] = min(dp[i-1][0] + cnt[i][0], dp[i-1][1] + cnt[i][1]);
	}

	cout << dp[k - 1][0];
}
