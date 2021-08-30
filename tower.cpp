#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int cache[200000][2];
vector<int> board;

int min(int n1, int n2)
{
	if(n1 < n2)
		return n1;

	return n2;
}

int search(int start, int turn)
{
	int &ret = cache[start][turn];

	if(start >= board.size())
		return 0;	//죽일 수 없음

	if(ret != -1)
		return ret;

	ret = 0;
	if(turn == 0)	//나 다 죽을 수 있음 
		ret = min(search(start + 1, 1), search(start + 2, 1));
	else
		ret = min(search(start + 1, 0) + board[start], search(start + 2, 0) + board[start] + board[start + 1]);

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

		memset(cache, -1, sizeof(cache));
		board.clear();

		for(int i = 0; i < n; ++i)
		{
			int s;
			cin >> s;

			board.push_back(s);
		}

		cout << search(0, 1) << endl;
	}
}
