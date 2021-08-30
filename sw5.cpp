#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> board;
int k;

int max(int n1, int n2)
{
	if(n1 > n2)
		return n1;

	return n2;
}

int search(int start)
{
	int left = start;
	int right = board.size() - 1;

	while(left < right)
	{
		int mid = (left + right) / 2;
		cout << left << " " << right << " "<< mid << " " << board[left] << " " << board[right] << endl;
		//cout << left << " " << right << endl;

		if(board[mid] - board[start] <= k)
		{
			if(board[mid + 1] - board[start] > k) // 탐색 공각 안나옴 
			{
				left = mid;
				break;
			}

			left = mid + 1;
		}
		else
			right = mid - 1;
	}

	return left;
}

int main(void)
{
	int tc;
	cin >> tc;

	for(int test = 0; test < tc; ++test)
	{
		int n;
		cin >> n >> k;

		board.clear();

		for(int i = 0; i < n; ++i)
		{
			int s;
			cin >> s;

			board.push_back(s);
		}

		sort(board.begin(), board.end());

		int answer = -1;

		for(int i = 0; i < board.size(); ++i)
		{
			cout << "진입 " <<i << endl;
			int left = search(i);

			answer = max(answer, left - i + 1);
		}

		cout << "#" << test + 1 << " " << answer << "\n";
	}
}
