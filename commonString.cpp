#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int>arr[28];
int visited[28];


string s1;
string s2;

int find(void)
{
	for(int i = 0; i < s1.size(); ++i)
	{
		int idx = s1[i] - 'A';

		if(visited[idx] == 1)
			continue;

		visited[idx] = 1;

		for(int j = 0; j < s2.size(); ++j)
		{
			if(s1[i] == s2[j])
			{
				arr[idx].push_back(j);
			}
		}
	}

	int ans = 0;

	for(int i = 0; i < s1.size(); ++i)
	{
		int idx = s1[i] - 'A';
		int mv = idx;
		int candans = 0;

		for(int k = 0; k < arr[idx].size(); ++k)
		{
			for(int j = arr[idx][k]; j < s2.size(); ++j)
			{
				if(s1[mv] != s2[j])
					break;

				++mv;
				++candans;
			}

			ans = max(ans, candans);
		}
	}

	return ans;
}

int main(void)
{
	string s1;
	string s2;

	cin >> s1 >> s2;

	if(s2.size() < s1.size())
	{
		string s = s2;
		s2 = s1;
		s1 = s2;
	}

	cout << find();

}
