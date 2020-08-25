#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<long long, long long> p;

vector<int> room;
vector<int> roomNum;

int find(int x)
{
	if(p[x] == 0)
		return x;
	else
	{
		 p[x] = find(p[x]);
		 return p[x];
	}
}
void search()
{
	vector<int> confirm;

	for(int i = 0; i < roomNum.size(); ++i)	//i번째를 가져가야함 
	{
		long long sub = find(roomNum[i]);
		p[roomNum[i]] = sub + 1;
		confirm.push_back(sub);
	}

	for(int i = 0; i < confirm.size(); ++i)
		cout << confirm[i] << " " ;

}

int main(void)
{
	int tc;
	cin >> tc;

	for(int test = 0; test < tc; ++test)
	{
		int k;
		cin >> k;

		room.clear();
		roomNum.clear();

		for(int i = 0; i < 6; ++i)
		{
			int s;
			cin >> s;

			room.push_back(s);
		}


		for(int i = 0; i < room.size(); ++i)
		{
			int s;
			cin >> s;
			
			roomNum.push_back(s);
		}

		search();
	}
}
