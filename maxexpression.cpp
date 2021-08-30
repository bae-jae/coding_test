#include <iostream>
#include <string>

using namespace std;

string change(string s, int target)
{
	char t;
	
	if(target == 0)
		t = '*';
	else if(target == 1)
		t = '+';
	else 
		t = '-';

	for(int i = 0; i < s.size(); ++i)
	{
		if(
	}
}
long long search(string s)
{
	int arr[3] = {0, 0, 0};		//not use

	for(int i = 0; i < 3; ++i)
	{
		arr[i] = 1;
		
		for(int j = 0; j < 3; ++j)
		{
			if(arr[j] != 0)
				continue;

			for(int k = 0; k < 3; ++k)
			{
				if(arr[k] != 0)
					continue;

			}

			arr[j] = 0;
		}

		arr[i] = 0;
	}
}
int main(void)
{
	int tc;
	cin >> tc;

	for(int test = 0; test < tc; ++test)
	{
		string s;
		cin >> s;


	}
}
