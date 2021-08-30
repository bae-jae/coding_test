#include <iostream>
#include <string.h>

using namespace std;

int map[100001];

int main(void)
{
	int tc;
	cin >> tc;

	for(int test = 0; test < tc; ++ test)
	{
		int n;
		cin >> n;

		memset(map, 0, sizeof(map));

		for(int i = 0; i < n; ++i)
		{
			int s;
			cin >> s;

			map[s] = 1;
		}

		int choice = 0;

		for(int i = 1; i <= n; ++i)
		{
			if(map[i] == 0)
			{
				choice = 1;
				break;
			}
		}

		if(choice == 1)		//아닌경우 
			cout << "#" << test << " " << "NO" << endl;
		else
			cout << "#" << test << " " << "YES" << endl;
	}
}
