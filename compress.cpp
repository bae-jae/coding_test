#include <iostream>
#include <string>
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

	for(int i  = 0; i < tc; ++i)
	{
		string s;
		cin >> s;

		int len = s.size();
		
		for(int i = 1; i < s.size(); ++i)
		{
			vector<string> v;

			for(int j = 0; j < s.size(); j += i)
			{
				v.push_back(s.substr(j, i));
			}

			string subAnswer = "";

			int count = 1;
			v.push_back("A");

			for(int j = 0; j < v.size() - 1; ++j)
			{
				cout << v[j] << " ";
				if(v[j] == v[j + 1])
					++count;
				else
				{
					if(count == 1)
						subAnswer += v[j];
					else
					{
						subAnswer += to_string(count) + v[j];
					}

					count = 1;
				}
			}
			cout << endl;
			len = min(len, subAnswer.size());
			cout << subAnswer << endl;
		}

		cout << len << endl;
	}
}
