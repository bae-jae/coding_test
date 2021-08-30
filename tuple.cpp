#include <iostream>
#include <string>
#include <vector>
#include <string.h>

using namespace std;

vector<string> search(string s)
{
	int num;
	string maxN = "";
	string sub = "";
	vector<string> qu;

	for(int i = 1; i < s.size() - 1; ++i)
	{
		if(s[i] == '{')
		{
			sub = "";
		}
		else if(s[i] == '}')
		{
			qu.push_back(sub);
			sub = "";
		}
		else
			sub += s[i];
	}

	return qu;
}

vector<int> sol(string target)
{
	string sub = "";
	vector<int> ans;
	vector<string> s = search(target);
	vector<vector<int>> list;
	int arr[100005];

	memset(arr, 0, sizeof(arr));

	for(int i = 0; i < s.size(); ++i)
	{
		vector<int> v;
		for(int j = 0; j < s[i].size(); ++j)
		{
			if(s[i][j] == ',')
			{
				v.push_back(atoi(sub.c_str()));
				sub = "";
			}
			else
				sub += s[i][j];
		}

		v.push_back(atoi(sub.c_str()));
		sub = "";
		list.push_back(v);
	}


	for(int i = 1; i <= s.size(); ++i)
	{
		for(int j = 0; j < list.size(); ++j)
		{
			if(i == list[j].size())
			{
				for(int k = 0; k < list[j].size(); ++k)
				{
					if(arr[list[j][k]] == 0)
					{
						arr[list[j][k]] = 1;
						ans.push_back(list[j][k]);
					}
				}
			}
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

		vector<int> v = sol(s);

		for(int i = 0; i < v.size(); ++i)
		{
			cout << v[i] << " ";
		}

		cout << "\n";
	}
}
