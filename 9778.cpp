#include <iostream>

using namespace std;

int main(void)
{
	int tc;
	cin >> tc;

	for(int test = 0; test < tc; ++test)
	{
		int n;
		cin >> n;

		int arr[12];

		for(int i = 0; i < 12; ++i)
			arr[i] = 4;

		arr[10] = 16;

		int canGo = 0;
		int NotGo = 0;
		int nowScore = 0;

		for(int i = 0; i < n; ++i)
		{
			int s;
			cin >> s;

			--arr[s];
			nowScore += s;
		}

		for(int i = 2; i < 12; ++i)
		{
			if(arr[i] >= 1)
			{
				if(nowScore + i <= 21)
					++canGo;
				else
					++NotGo;
			}
		}

		if(canGo > NotGo)
			cout << "GAZUA" << "\n";
		else
			cout << "STOP" << "\n";
	}
}
