#include <iostream>
#include <cmath>

using namespace std;


int r, c;
int answer = 0;

int outofrange(int starty, int startx, int endy, int endx)
{
	if(startx <= c && c <= endx)
	{
		if(starty <= r && r <= endy)
			return 1;
	}

	return 0;
}
void search(int size, int score, int sy, int sx, int ey, int ex)
{


	search(size, y, x, y + size / 2 - 1, x + size / 2 - 1);
	search(size, y, x + size / 2, y + size / 2 - 1, ex);
	search(size, y + size / 2, x);
	search(size, y + size / 2, x + size / 2);
}

int main(void)
{
	int n;
	cin >> n >> r >> c;

	search(1 << n, 0);

	cout << answer;
}
