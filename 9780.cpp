#include <iostream>
#include <vector>

using namespace std;

vector<int> map;
vector<int> orgMap;
vector<int> attack;
vector<int> spread;

int max(int n1, int n2)
{
	if(n1 > n2)
		return n1;

	return n2;
}

void update(int day)
{
	//퍼지는거 구현 함

	for(int i = 0; i < spread.size(); ++i)
	{
		if(spread[i] == day-1) //전파시작 
		{
			if((i - 1 > 0) && (attack[i-1] == 0))
			{
				spread[i-1] = day + 1;
				map[i-1] = 0;
			}

			if((i + 1 < map.size()) && (attack[i+1] == 0))
			{
				spread[i + 1] = day + 1;
				map[i + 1] = 0;
			}
		}
	}
}

void miusUpdate(int day)
{
	for(int i = 0; i < spread.size(); ++i)
	{
		if(spread[i] == day + 1) //전파시작 
		{
			if((i - 1 > 0))
			{
				spread[i-1] = 0;
				map[i-1] = orgMap[i-1];
			}

			if((i + 1) < map.size())
			{
				spread[i + 1] = 0;
				map[i + 1] = orgMap[i+1];
			}
		}
	}
}

int search(int n, int day)
{
	update(day);

	if(n >= map.size())
		return 0;		//탈출사례 

	int kill = 0;

	for(int i = n; i < map.size(); ++i)
	{
		//공격안당함 
		if(attack[i] == 0)
		{
			attack[i] = 1;
			spread[i] = day;	//전파 등록 

			kill = max(kill, search(i, day + 1) + map[i]);

			miusUpdate(day);
			spread[i] = 0;
			attack[i] = 0;
		}
	}

	return kill;
}

int main(void)
{
	int tc;
	cin >> tc;

	for(int test = 0; test < tc; ++test)
	{
		int n;
		cin >> n;

		map.clear();
		attack.clear();
		spread.clear();
		orgMap.clear();

		orgMap.resize(n + 1);
		attack.resize(n + 1);
		map.resize(n + 1);
		spread.resize(n + 1);

		for(int i = 0; i < n; ++i)
		{
			int live;
			cin >> live;

			map[i] = live;
			attack[i] = 0;
			spread[i] = -1;
			orgMap[i] = live;
		}

		cout << search(0, 0);

	}
}
