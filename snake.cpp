#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int map[101][101];
int mx[4] = {1, 0, 0, -1};
int my[4] = {0, -1, 1, 0};
//sec를 전역으로 설정해부


int findBody(vector<pair<int, int>>& list, int ry ,int rx)
{
	for(int i = 1; i < list.size(); ++i)
	{
		if(list[i].first == ry && list[i].second == rx)
			return 1;
	}

	return 0;
}

int outRange(int dy, int dx, int n)
{
	if(dy < 0 || dy >= n)
		return 0;

	if(dx < 0 || dx >= n)
		return 0;

	return 1;
}

int findTailList(int n, vector<pair<int, int>>& list, int sec, int nextsec, int dir)
{
	for(int i = sec; i <= nextsec; ++i)
	{
		int ry = list[0].first + my[dir];
		int rx = list[0].second + mx[dir];

		if(outRange(ry, rx, n) == 0)
		{
			return i;
		}

		if(map[ry][rx] == 1)//스내이크 있음
		{
			map[ry][rx] = 0;
			list.insert(list.begin(), make_pair(ry, rx));

			continue;
		}

		if(findBody(list, ry, rx) == 1)
			return i;		//사고난 경우

		for(int m = list.size() - 1; m >= 1; --m)
		{
			list[m] = list[m - 1];
		}

		list[0].first = ry;
		list[0].second = rx;



	}

	return 0; //성공햇다는 표시 
}

int search(int n, vector<pair<int, char>> move)
{
	int dir = 0;
	int sec = 1;

	vector<pair<int, int>> body;

	body.push_back(make_pair(0, 0));

	for(int i = 0; i < move.size(); ++i)
	{
		int nextsec = move[i].first;
		char changeDir = move[i].second;

		int ans = findTailList(n, body, sec, nextsec, dir);

		if(ans != 0)
			return ans;

		sec = nextsec + 1;
		
		if(dir == 0)
		{
			if(changeDir == 'L')
				dir = 1;
			else
				dir = 2;
		}
		else if(dir == 1)
		{
			if(changeDir == 'L')
				dir = 3;
			else
				dir = 0;
		}
		else if(dir == 2)
		{
			if(changeDir == 'L')
				dir = 0;
			else
				dir = 3;
		}
		else
		{
			if(changeDir == 'L')
				dir = 2;
			else
				dir = 1;
		}
	}

	//죽지않음
	return findTailList(n, body, sec, 100, dir);	//최대시간
}

int main(void)
{
	int tc;
	cin >> tc;

	for(int test = 0; test < tc; ++test)
	{
		int n;
		cin >> n;

		memset(map, 0, sizeof(map));

		int k;
		cin >> k;

		for(int i = 0; i < k; ++i)
		{
			int y, x;
			cin >> y >> x;

			map[y- 1][x- 1] = 1;
		}

		int l;
		cin >> l;

		vector<pair<int, char>> move;
		for(int i = 0; i < l; ++i)
		{
			int sec;
			char d;
			cin >> sec >> d;

			move.push_back(make_pair(sec, d));
		}

		cout << search(n, move) << endl;
	}
}
