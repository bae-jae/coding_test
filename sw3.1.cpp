#include <iostream>
#include <algorithm>

using namespace std;

int board[1000005];
int cache[1000005];

int search(int start)
{
	int &ret = cache[start];

	if(ret != -1)
		return ret;
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
			cache[s] = 1;
		}

		sort(board, board + n);

		int answer = 0;

		for(int i = 0; i < board.size(); ++i)
			answer = max(answer, search(i));
	}
}
