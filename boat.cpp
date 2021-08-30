#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

vector<int> board;
int check[50005];
int lim;
int answer;

int min(int n1, int n2)
{
	if(n1 < n2)
		return n1;

	return n2;
}

void search(int weight, int boat)
{
	int end = 1;
	
	for(int i = 0; i < board.size(); ++i)
	{
		if(check[i] == 0)
		{
			end = 0;
			break;
		}
	}

	if(end == 1)
	{
		answer = min(boat, answer);
		return;
	}

	for(int i = 0; i < board.size(); ++i)
	{
		if(check[i] == 0)
		{
			check[i] = 1;

			if((weight + board[i] <= lim))
			{
				search(weight + board[i], boat);
			}
			else
			{
				search(board[i], boat + 1);
			}

			check[i] = 1;
		}
	}
}
int main(void)
{
	int tc;
	cin >> tc;

	for(int test = 0; test < tc; ++test)
	{
		int n;
		cin >> n;

		board.clear();
		memset(check, 0, sizeof(check));
		answer = 987654321;

		for(int i = 0; i < n; ++i)
		{
			int s;
			cin >> s;

			board.push_back(s);
		}

		cin >> lim;

		search(0, 0);
		cout << answer + 1;
	}
}
