#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>



using namespace std;

int visited[27][27];
int used[27][27];
string map[5];

int dy[4] = {-1, 0, 1,  0};
int dx[4] = { 0, 1, 0, -1};

vector<vector<int>> v;

int outRange(int y, int x)
{
	if(y < 0 || y >= 5)
		return 0;
	
	if(x < 0 || x >= 5)
		return 0;
	
	return 1;
}

void makeCircle(vector<int> &list, int next)
{
	if(list.size() == 7)
	{
		v.push_back(list);
		return;
	}
	
	for(int i = next + 1; i < 25; ++i)
	{
		list.push_back(i);
		makeCircle(list, i);
		list.pop_back();
	}
	
	return;
}


int findFriend(int y, int x)
{
	int count = 0;
	queue<pair<int, int>> q;
	
	memset(used, 0, sizeof(used));
	
	q.push({y, x});
	used[y][x] = 1;
	
	while(!q.empty())
	{
		int ry = q.front().first;
		int rx = q.front().second;
		
		q.pop();
		
		++count;
		
		for(int i = 0; i < 4; ++i)
		{
			int ny = ry + dy[i];
			int nx = rx + dx[i];
			
			if(outRange(ny, nx) == 0)
				continue;
			
			if(visited[ny][nx] == 1 && used[ny][nx] == 0)
			{
				used[ny][nx] = 1;
				q.push({ny, nx});
			}
		}
	}
	
	if(count == 7)
		return 1;
	
	return 0;
}


int checkFrined(vector<int> &ret)
{
	int y = 0;
	int s = 0;
	
	for(int i = 0; i < ret.size(); ++i)
	{
		int dy = ret[i] / 5;
		int dx = ret[i] % 5;
		
		visited[dy][dx] = 1;
		
		if(map[dy][dx] == 'Y')
			++y;
		else
			++s;
	}
	
	if(y < s)
	{
		
		int dy = ret[0] / 5;
		int dx = ret[0] % 5;
		
		int result = findFriend(dy, dx);
		
		return result;
	}
	
	return 0;
}

int main(void)
{	
	for(int i = 0; i < 5; ++i)
	{
		cin >> map[i];
	}
	
	vector<int> list;
	makeCircle(list, -1);
	
	cout << v.size() << "\n";
	
	int ans = 0;
	
	// list = {0, 1, 5, 6, 7, 9, 16};
	// ans = checkFrined(list);
		
	
	for(int i = 0; i < v.size(); ++i)
	{
		memset(visited, 0, sizeof(visited));
		ans += checkFrined(v[i]);
	}
	
	
	cout << ans << "\n";
}