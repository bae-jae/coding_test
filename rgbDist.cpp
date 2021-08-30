#include <iostream>


using namespace std;

int color[1005];
int price[1005][3];

int main(void)
{
	int n;
	cin >> n;

	for(int i = 0; i < n; ++i)
	{
		int r,g,b;
		cin >> price[i][0] >> price[i][1] >> price[i][2];
	}

	cout << search(
}

