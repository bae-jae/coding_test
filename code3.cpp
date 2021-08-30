#include <iostream>
#include <string.h>

using namespace std;

int map[51][51];
int targetX, targetY;
vector<pair<int, int>> gdPeople;
vector<pair<int, int>> bdPeople;

int mx[4] = {-1, 0, 1, 0};
int my[4] = {0, 1, 0, -1};

int outRange(int y, int x)
{
	if(x < 0 && x >= targetX)
		return 0;

	if(y < 0 && y >= targetY)
		return 0;

	return 1;
}

int search(int y, int x)
{
	if((y == targetY) && (x == targetX))
		return 1;


}
int main(void)
{
	int tc;
	cin >> tc;

	for(int test = 0; test < tc; ++test)
	{
		cin >> targetX  >> targetY;

		gdPeople.clear();
		bdPeople.clear();


		for(int i = 0; i < targetY; ++i)
		{
			for(int j = 0; j < targetX; ++j)
			{
				string s;
				cin >> s;

				int cs;
				if(s == ".") 		//pass
					cs = 0;

				if(s == "G")
				{
					cs = 1;
					gdPeople.push_back(make_pair(i, j));
				}

				if(s == "B")
				{
					cs = 2;
					bdPeople.push_back(make_pair(i, j));
				}

				if(s == "#")		//block
					cs = 3;

				map[i][j] = cs;
			}
		}


	}
}
