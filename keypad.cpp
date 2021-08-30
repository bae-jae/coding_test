#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

int map[4][3];

string search(vector<int> v, string hand)
{
	vector<int> left{1, 4, 7};
	vector<int> right{3, 6, 9};
	string answer = "";

	int lx = 0, ly = 3, rx = 2, ry = 3;

	for(int i = 0 ; i < v.size(); ++i)
	{
		int leftIn = 0;
		int rightIn = 0;
		int tx = -1, ty = -1;

		for(int y = 0; y < 4; ++y)
		{
			for(int x = 0; x < 3; ++x)
			{
				if(v[i] == map[y][x])
				{
					tx = x;
					ty = y;
					break;
				}
			}

			if(tx != -1)
				break;
		}


		for(int j = 0; j < left.size(); ++j)
		{
			if(left[j] == v[i])
			{
				leftIn = 1;
				break;
			}
		}

		for(int j = 0; j < right.size(); ++j)
		{
			if(right[j] == v[i])
			{
				rightIn = 1;
				break;
			}
		}

		if(leftIn == 1)
		{
			lx = tx;
			ly = ty;
			answer += "L";
		}
		else if(rightIn == 1)
		{
			rx = tx;
			ry = ty;
			answer += "R";
		}
		else	//거리비교 
		{
			int lmx = abs(lx - tx);
			int lmy = abs(ly - ty);

			int rmx = abs(rx - tx);
			int rmy = abs(ry - ty);

			if(lmx + lmy > rmx + rmy)
				answer += "R";
			else if(lmx + lmy < rmx + rmy)
				answer += "L";
			else
			{
				if(hand == "right")
					answer += "R";
				else
					answer += "L";
			}
		}
		
	}
	return answer;
}


int main(void)
{
	int tc;
	cin >> tc;

	for(int test = 0; test < tc; ++test)
	{
		int n;
		cin >> n;
		
		vector<int> v;

		for(int i = 0; i < n; ++i)
		{
			int s;
			cin >> s;

			v.push_back(s);
		}

		int start = 1;

		for(int i = 0; i < 4; ++i)
		{
			for(int j= 0; j < 3; ++j)
			{
				map[i][j] = start;
				++start;
			}
		}

		map[3][0] = -1;
		map[3][1] = 0;
		map[3][2] = -1;

		string hand;
		cin >> hand;

		cout << search(v, hand) << endl;
	}
}
