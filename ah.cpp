#include <iostream>
#include <vector>

using namespace std;


int min(int n1, int n2)
{
	if(n1 < n2)
		return n1;

	return n2;
}

int main(void)
{
	int tc;
	cin >> tc;

	for(int i = 0; i < tc; ++i)
	{
		int n;
		cin >> n;
		
		int one = 0;
		int zero = 0;

		for(int j = 0; j < n; ++j)
		{
			int s;
			cin >> s;

			if(s == 1)
			{
				++one;
			}
			else
			{
				++zero;
			}
		}

		if(zero >= one)
		{
			cout << zero << "\n";

			for(int k = 0; k < zero; ++k)
			{
				cout << 0 << " ";
			}
			cout << endl;
		}
		else
		{
			if(one % 2 == 1)
				--one;

			cout << one << endl;

			for(int k = 0; k < one; ++k)
				cout << 1 << " ";

			cout << endl;
		}
	}
}
