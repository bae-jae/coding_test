#include <iostream>
#include <string>

using namespace std;

int search(string s , int k)
{
	int one = 0;
	int zero = 0;

	for(int i = 0; i < k; ++i)
	{
		if(s[i] == '0')
			++one;
		else if(s[i] == '1')
			++zero;
	}

	if(one > (k / 2) || zero > (k / 2))
		return 0;


	for(int i = k; i < s.size(); ++i)
	{
		if(s[i] == '?')
			s[i] = s[i-k];

		if(s[i] != s[i - k])
		{
			if(s[i-k] == '?')
			{
				int idx = i - k;

				while(idx >= 0)
				{
					s[idx] = s[i];
					idx = idx - k;
				}
			}
			else
				return 0;
		}
	}

	one = 0;
	zero = 0;

	for(int i = 0; i < k; ++i)
	{
		if(s[i] == '0')
			++one;
		else if(s[i] == '1')
			++zero;
	}

	cout << one << " " << zero << endl;

	if(one > (k / 2) || zero > (k / 2))
		return 0;

	return 1;
}

int main(void)
{
	int tc;
	cin >> tc;

	for(int i = 0; i < tc; ++i)
	{
		int n, k;
		cin >> n >> k;

		string s;
		cin >> s;

		int answer = search(s, k);

		if(answer == 1)
			cout << "YES";
		else
			cout << "NO";

		cout << "\n";
	}
}
