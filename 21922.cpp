#include <iostream>

using namespace std;

int visited[2005][2005][5];
int board[2005][2005];

//			 북 동 남 서
int dy[4] = {-1, 0, 1, 0};
int dx[4] = { 0, 1, 0,-1};

int n, m;

int changDir(int p, int d)
{
	//북 동 남 서 : 1 2 3 4
	if(p == 3)
	{
		if(d == 1)
			return 2;
		if(d == 2)
			return 1;
		if(d == 3)
			return 4;
		
		return 3;
	}
	
	if(p == 4)
	{
		if(d == 1)
			return 4;
		if(d == 2)
			return 3;
		if(d == 3)
			return 2;
		
		return 1;
	}
	
	return d;
}

int outRange(int y, int x)
{
	if(y < 0 || y >= n)
		return 0;
	
	if(x < 0 || x >= m)
		return 0;
	
	return 1;
}

void dfs(int y, int x, int d)
{
	int pos = board[y][x];
	d = changDir(pos,d);
	
	cout <<y << " " <<x << " " << d << endl;
	
	if(visited[y][x][d] == 1)
		return;

	visited[y][x][d] = 1;
	
	if(pos == 1 && (d == 2 || d == 4))
		return;
	
	if(pos == 2 && ( d == 1 || d == 3))
		return;
	
	int ry = y + dy[d - 1];
	int rx = x + dx[d - 1];
		
	if(outRange(ry, rx) == 1)
		dfs(ry, rx, d);
}

int main(void)
{
	cin >> n >> m;
	
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			int s;
			cin >> s;
			
			board[i][j] = s;
		}
	}
	
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			if(board[i][j] == 9)
			{
				cout << "int " << i << " " << j << endl;
				for(int d = 1; d <= 4; ++d)
				{
					dfs(i, j, d);
				}
			}
		}
	}
	
	int ans = 0;
	
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
				for(int d = 1; d <= 4; ++d)
				{
					if(visited[i][j][d] == 1)
					{
						++ans;
						//cout <<"ASD" << i << " " << j << endl;
						break;
					}
				}
		}
	}
	
	cout << ans;
}