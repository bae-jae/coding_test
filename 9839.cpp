#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

int search(int target)
{
	int prev = target % 10;
	target /= 10;
	int div = 10;

	while(target > 0)
	{
		int cand = target % 10;

		if(prev != cand + 1)
			return 0;

		prev = cand;
		target /= div;
	}

	return 1;
}

int main(void)
{
	int tc;
	cin >> tc;

	for(int test = 0; test < tc; ++test)
	{
		int n;
		cin >> n;

		vector<int> board;

		for(int i = 0; i < n; ++i)
		{
			int s;
			cin >> s;

			board.push_back(s * -1);
		}

		int answer = -1;

		sort(board.begin(), board.end());

		for(int i = 0; i < n; ++i)
		{
			for(int j = i + 1; j <n; ++j)
			{
				 int target = board[i] * board[j];
				 int canAnswer = search(target);

				 if(canAnswer == 1)
				 {
					 answer = target;
					 break;
				 }
			}

			if(answer != -1)
				break;
		}

		cout << "#" << test + 1 << " " << answer << "\n";
	}
}
