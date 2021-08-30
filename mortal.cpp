#include <iostream>
#include <string>

using namespace std;

int cache[200005][2];
vector<int> board;

int search(start)
{
}
int main(void)
{
	int tc;
	cin >> tc;

	for(int test =0; test < tc; ++test)
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
	}
}
