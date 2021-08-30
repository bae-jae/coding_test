#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> board; //first는 

int search(void)
{
	int lastDay = board[board.size() - 1].first + 1;
	
	while(!board.empty())
	{
		int needDay = board.back().second;
		int fDay = board.back().first;
		board.pop_back();

		if(lastDay >  fDay)	//시간이 남은 경우
		{
			lastDay = fDay - needDay;
		}
		else	//즉 그전에 끝내야함 
		{
			lastDay = lastDay - needDay;
		}
	}

	return lastDay;
}
int main(void)
{
	int tc;
	cin >> tc;

	for(int test= 0; test < tc; ++test)
	{
		int n;
		cin >> n;

		for(int i = 0; i < n; ++i)
		{
			int t, d;
			cin >> t >> d;

			board.push(make_pair(d, t));
		}

		sort(board.begin(), board.end());

		cout << "#" << test + 1 << " " << search() << "\n";
	}
}
