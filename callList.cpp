#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

vector<string> list;
vector<int> len;
map<string ,int> m;

int main(void)
{
	int tc;
	cin >> tc;

	for(int test =0; test < tc; ++test)
	{
		int n;
		cin >> n;

		int can = 1;

		list.clear();
		len.clear();
		m.clear();

		cin.ignore();

		for(int i = 0; i < n; ++i)
		{
			string s;
			getline(cin, s);

			cout << s << endl;

			s.erase(remove(s.begin(), s.end(), ' '), s.end());

			list.push_back(s);

			if(m[s] != 0)
				can = 0;

			m[s] = i + 1;

		}

		for(int i = 0; i < n; ++i)
		{
			for(int j = 1; j <= list[i].size() - 1; ++j)
			{

				string sub = list[i].substr(0, j);

				if(m[sub] != 0)
				{
					can = 0;
					break;
				}
			}

			if(can == 0)
				break;
		}

		if(can == 1)
			cout << "YES";
		else
			cout << "NO";
	}
}
