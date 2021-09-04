#include <iostream> //logo

using namespace std;

int board[2005][2005];
int visited[2005][2005];

int my[4] = {1, 0, -1, 0};
int mx[4] = {0, 1,  0,-1};

void drawPoint(int x1, int y1, int x2, int y2)
{
	for(int x = x1; x <= x2; ++x)
	{
		board[y1][x] = 1;
		board[y2][x] = 1;
	}
	
	for(int y = y1; y <= y2; ++y)
	{
		board[y][x1] = 1;
		board[y][x2] = 1;
	}
}

int outRange(int y, int x)
{
	if(y < 0 || y >= 2005)
		return 0;
	if(x < 0 || x >= 2005)
		return 0;
	
	return 1;
}

void dfs(int y, int x)
{	
	visited[y][x] = 1;
	
	for(int i = 0; i < 4; ++i)
	{
		int ry = y + my[i];
		int rx = x + mx[i];
		
		if(outRange(ry, rx) == 1 && board[ry][rx] == 1 && visited[ry][rx] == 0)
		{
			dfs(ry, rx);
		}
	}
}

int change(int x)
{
	return (x + 500) * 2;
}

int main(void)
{
	int tc;
	int ans = 0;
	
	cin >> tc;
	
	for(int i = 0; i < tc; ++i)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		
		
		x1 = change(x1); //정규화
		y1 = change(y1);
		x2 = change(x2);
		y2 = change(y2);
		
		drawPoint(x1, y1, x2, y2);
		
	}
	
	for(int i = 1000; i < 1100; ++i)
	{
		for(int j = 1000; j < 1100; ++j)
			cout << board[i][j];
		
		cout << endl;
	}
	
	
	for(int y = 0; y < 2005; ++y)
	{
		for(int x = 0; x < 2005; ++x)
		{
			if(board[y][x] == 1 && visited[y][x] == 0)
			{
				++ans;
				dfs(y, x);
			}
		}
	}
	
	if(board[1000][1000] == 1)
		--ans;
	
	
	cout << ans;
}