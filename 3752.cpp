#include <iostream>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;

vector<int> board;

int scoreBoard[10005];
int scoreMin[10005];
int count = 0;

void init()
{
	for(int i = 0; i < 10005; ++i)
		scoreMin[i] = 987654321;
}

void search(int pick, int score)
{
	if(scoreBoard[score] == 0)
		++count;

	scoreBoard[score] = 1;

	for(int i = pick; i < board.size(); ++i)
	{
		int idx = score + board[i];	

		if(scoreBoard[idx] == 0 || scoreMin[idx] > i)
		{
			scoreMin[idx] = i;
			search(i + 1, score + board[i]);
		}
	}
}

int search2(int pick, int score)
{
	if(pick >= board.size())
	{
		if(scoreBoard[score] == 0)
		{
			cout << score << " ";
			scoreBoard[score] = 1;
			return 1;
		}

		return 0;
	}

	int ret = 0;

	ret = search2(pick + 1, score);
	ret += search2(pick + 1, score + board[pick]);

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

		board.clear();
		count = 0;

		memset(scoreBoard, 0, sizeof(scoreBoard));

		for(int i = 0; i < n; ++i)
		{
			int s;
			cin >> s;

			board.push_back(s);
		}

		init();
		memset(scoreBoard, 0, sizeof(scoreBoard));
		search(0, 0);

		cout << "#" << test + 1 << " " << count << "\n";
	}
}
