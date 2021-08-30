#include <iostream>
#include <string>
#include <string.h>
#include <vector>

using namespace std;
int mx[] = {1, 1, 0};
int my[] = {0, 1, 1};

int boolBoard[31][31];
int notUsed[31];

int boardCount(void)
{
	int count = 0;

	for(int i = 0; i < 31; ++i)
	{
		for(int j = 0; j < 31; ++j)
		{
			if(boolBoard[i][j] == 0)
				++count;
		}
	}

	return count;
}

int search(void)
{
	memset(notUsed, -1, sizeof(notUsed));
	memset(boolBoard, -1, sizeof(notUsed));

	while(1)
	{
		for(int y = 0; y < board.size() - 1; ++y)
		{
			for(int x = 0; x < board.size() - 1; ++x)
			{
				if(notUsed[x] < y)
				{
					int in = 1;

					for(int routin = 0; routin < 3; ++i)
					{
						int my = y + my[routin];
						int mx = x + mx[routin];

						if(board[y][x] != board[my][mx])
							in = 0;
					}

					if(in == 1)		//all same
					{
						boolBoard[y][x] = 0;
	
						for(int routin = 0; routin < 3; ++i)
						{
							int my = y + my[routin];
							int mx = x + mx[routin];
	
							boolBoard[my][mx] = 0;
						}
					}
				}	
			}
		}

		//delete need
		int lastAnswer = answer;
		for(int y = 0; y < board.size(); ++y)
		{
			for(int x = 0; x < board.size(); ++x)
			{
				if(boolBoard[y][x] == 0)
				{
					++answer;
					if(y == 0)
					{
						notUsed[x] = 0;
						continue;
					}
					else
					{
						notUsed[x] = notUsed[x] + 1;

						for(int my = y; my >= 1; --my)
						{
							board[my][x] = board[my-1][x];
						}
					}

					boolBoard[y][x] = -1;
				}
			}
		}

		if(lastAnswer == answer)
			break;
	}
}

int main(void)
{
	int tc;
	cin >> tc;

	for(int i = 0; i < tc; ++i)
	{
		int m, n;
		cin >> m >> n;

		vector<string> v;

		for(int i = 0; i < n; ++i)
		{
			string s;
			cin >> s;

			v.push_back(s);
		}


	}
}
