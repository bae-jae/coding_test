#include <iostream>
#include <string>

using namespace std;

string s;

int is_good(string s)
{
	int len = s.size() / 2;

	for(int i = 1; i <= len; ++i)
	{
		int pos = s.size() - i;

		string s1 = s.substr(pos, i);
		string s2 = s.substr(pos - i, i);

		if(s1 == s2)
			return 0;
	}

	return 1;
}

int search(int pos, int n)
{
	if(pos == n)
	{
		for(int i = 0; i < s.size(); ++i)
		{
			cout << s[i];
		}

		cout << endl;

		return 1;
	}


	for(int i = 1; i <= 3; ++i)
	{
		s.push_back(i + '0');

		if(is_good(s) == 1)
		{
			cout << s << endl;
			if(search(pos + 1, n) == 1)
				return 1;
		}

		s.pop_back();
	}

	return 0;
}
int main(void)
{
	int n;
	cin >> n;

	if(n == 1)
		cout << "1";
	else
	{
		s = "1";
		search(1, n);
	}
}
