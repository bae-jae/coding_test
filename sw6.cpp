#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

vector<int> board;
int cache[10001];
int k;

int max(int n1, int n2)
{
	if(n1 > n2)
		return n1;

	return n2;
}
int search(int start)
{
	if(start >= board.size())
		return 0;

	int &ret = cache[start];

	if(ret != -1)
		return ret;

	ret = 0;
	int enter = 0;
	int fs = start;

	//현재 시작점에서 몇개 담을 수 있는지  
	for(int i = start + 1; i < board.size(); ++i)
	{
		if(board[i] - board[start] <= k)
		{
			enter = 1;
			++ret;
			fs = i;
		}
		else
			break;
	}

	if(enter == 1)
		++ret;		//나 자신 ㅂ포함 

	for(int i = fs; i < board.size(); ++i)
	{
		if(board[i] - board[start] > k)
		{
			ret = max(ret, search(i));
		}
	}

	return ret;
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
		memset(cache, -1, sizeof(cache));

		for(int i = 0; i < n; ++i)
		{
			int s;
			cin >> s;

			board.push_back(s);
		}

		sort(board.begin(), board.end());

		int answer = 0;

		for(int i = 0; i < board.size(); ++i)
		{
			answer = max(answer , search(i));
		}

		cout << "#" << test + 1 << " " << answer << endl;
	}
}
