#include <iostream>
#include <string>

using namespace std;

string ans;
string s1;
string s2;

int cache[29];

void search(string& s, int idx)
{
	if(idx == s1.size())
	{
		string candAns;
		int start = 0;

		for(int i = 0; i < s.size(); ++i)
		{
			for(int j = start; j < s2.size(); ++j)
			{
				++start;

				if(s[i] == s2[j])
				{
					candAns.push_back(s[i]);
					break;
				}
			}
		}

		if(s.size() == candAns.size())
		{
			if(ans.size() < candAns.size())
				ans = candAns;
		}

		return;
	}

	
	search(s, idx + 1);
	s.push_back(s1[idx]);
	search(s, idx + 1);
	s.pop_back();
}

int main(void)
{
	cin >> s1;
	cin >> s2;

	for(int i = 0; i < s1.size(); ++i)
	{
		string s;
		s.push_back(s1[i]);


		int idx = s1[i] - 'A';

		if(cache[idx] == 0)
		{
			search(s, i + 1);
			cache[idx] = 1;
		}
	}
	cout << ans.size() << endl;
	cout << ans << endl;
}
