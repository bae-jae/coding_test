#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

int board[100005];
int cache[100005];

int max(int n1, int n2)
{
	if(n1 > n2)
		return n1;

	return n2;
}

int main(void)
{
	int tc;
	cin >> tc;

	for(int test = 0; test < tc; ++test)
	{
		int n;
		cin >> n;

		memset(cache, 0, sizeof(cache));

		for(int i = 0; i < n; ++i)
		{
			int s;
			cin >> s;

			board[i] = s;
		}

		sort(board, board + n);

		for(int i = 0; i < n; ++i)
		{
			cache[board[i]] = 1;
		}

		for(int i = 0; i < n; ++i)
		{
			for(int j = board[i] + board[i]; j <= board[n-1]; j += board[i])
			{
				if(cache[j] > 0)
				{
					cache[j] = max(cache[j], cache[board[i]] + 1);
				}
			}
		}

		int answer = 0;
		for(int i = 0; i < n; ++i)
			answer = max(answer, cache[board[i]]);

		cout << "#" << test + 1 << " " << answer << "\n";
	}
}
