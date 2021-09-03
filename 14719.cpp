#include <iostream>

using namespace std;

int board[505][505];
int main(void)
{
	int h, w;
	cin >> h >> w;
	
	for(int i  = 0; i < w; ++i)
	{
		int s;
		cin >> s;
		
		for(int j = 0; j < s; ++j)
			board[j][i] = 1;
	}
	
	for(int i = 0; i < h; ++i)
	{
		for(int j = 0; j < w; ++j)
			cout << board[i][j] << " " ;
		
		cout << endl;
	}
	
	int ans = 0;
	
	for(int i = 0; i < h; ++i)
	{
		int left = -1;
		int right = -1;
		
		int leftWall = -1;
		int rightWall = -1;
		
		for(int j = 0; j < w; ++j)
		{
			if(board[i][j] == 1)
				leftWall = j;
			
			if(board[i][j] == 0 && leftWall != -1)
			{
				left = j;
				break;
			}
		}
		
		for(int j = w - 1; j >= 0; --j)
		{
			if(board[i][j] == 1)
				rightWall = j;
			
			if(board[i][j] == 0 && rightWall != -1)
			{
				right = j;
				break;
			}
		}
		
		if(left != -1 && right != -1)
		{
			for(int j = left; j <= right; ++j)
			{
				if(board[i][j] == 0)
					++ans;
			}
		}
	}
	
	cout << ans;
}