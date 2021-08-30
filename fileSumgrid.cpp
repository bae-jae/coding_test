#include <iostream>
#include <vector>
#include <cstring>

using namespace std;


vector<int> map;
int visited[100001];

int getLeft(int idx)
{
	for(int i = idx - 1; i >= 0; --i)
	{
		if(visited[i] == 0)
			return i;
	}

	return -1;
}

int getRight(int idx)
{
	for(int i = idx + 1; i < map.size(); ++i)
	{
		if(visited[i] == 0)
			return 0;
	}

	return -1;
}

int find(void)
{
	for(int i = 0; i < map.size(); ++i)
	{
		if(visited[i] == 0)
		{
			int left = getLeft(i);
			int right = getRight(i);

			if(left == -1)
		}
	}
}

int main(void)
{
	int tc;
	cin >> tc;

	for(int i = 0; i < tc; ++i)
	{
		int n;
		cin >> n;

		map.clear();
		
		for(int  j = 0; j < n; ++j)
		{
			int s;
			cin >> s;

			map.push_back(s);
		}

		memset(visited, 0 ,sizeof(visited));
	}
}
