#include <iostream>
#include <vector>

using namespace std;

int dx[2] = {1, 0};
int dy[2] = {0, 1};
int m , n;

int dfs(int y, int x, vector<vector<int>>& map, int dirction)
{
	int answer = 0;

	//outOfBound
	if(y < 0 || y >= m)
		return 0;
	if(x < 0 || x >= n)
		return 0;

	if(y == m -1 && x == n - 1)	//도착한 경우 
		return 1;
	
	if(map[y][x] == 1)
		return 0;		//통과 못하는 경우
	else if(map[y][x] == 0)
	{
		for(int i = 0; i < 2; ++i)	//0 right 1 down
		{
			answer += dfs(y + dy[i], x + dx[i], map, i);
		}
	}
	else if(map[y][x] == 2)
	{
		if(dirction == 0)
			answer += dfs(y + dy[0], x + dx[0], map , 0);
		else
			answer += dfs(y + dy[1], x + dx[1], map, 1);
	}

	return ret = answer;
}
int search(vector<vector<int>> map)
{
	int answer = 0 ;
	
	for(int i = 0; i <= 1; ++i)
		answer += dfs(0 + dy[i], 0 + dx[i], map, i);

	return answer;
}

int main(void)
{
	int tc;
	tc = 2;
	for(int i = 0; i < tc; ++i)
	{
		cin >> m >> n;

		vector<vector<int>> map;

		for(int y = 0; y < m; ++y)
		{
			vector<int> v;
			for(int x = 0; x < n; ++x)
			{
				int s;
				cin >> s;
				
				v.push_back(s);
			}

			map.push_back(v);
		}//input finish

		cout << search(map) << endl;
	}
}
