#include <iostream>
#include <string>

using namespace std;

int find(string s)
{
	if(s.size() == 0)
	{
		return 1;
	}

	int ans = 0;

	for(int i = 0; i < s.size(); ++i)
	{
		int end = -1;

		for(int j = i + 1; j < s. size(); ++j)
		{
			if(s[i] != s[j])
				break;

			end = j;
		}


		if(end != -1)
		{
			string sub;
			for(int j = 0; j < i; ++j)
				sub += s[j];

			for(int j = end + 1; j < s.size(); ++j)
				sub += s[j];

			ans = find(sub);

			if(ans == 1)
				return 1;
		}
	}

	return ans;
}
int main(void)
{
	int tc;
	cin >> tc;

	for(int test = 0; test < tc; ++test)
	{
		string s;
		cin >> s;

		cout << find(s) << "\n";
	}
}
