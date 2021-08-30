#include <iostream>
#include <vector>
#include <string>
#include <string.h>

using namespace std;

vector<string> words;
int map[51];

int cmp(string s1, string s2)
{
	int count = 0;
	
	for(int i = 0; i < s1.size(); ++i)
	{
		if(s1[i] != s2[i])
			++count;
	}

	return count;
}

int min(int n1, int n2)
{
	if(n1 < n2)
		return n1;

	return n2;
}
int search(string begin, string target, int count)
{
	int ans = 987654321;
	cout << "진입" << endl;

	if(begin == target)
	{
		cout << count << endl;
		return count;
	}

	for(int i = 0; i < words.size(); ++i)
	{
		if(map[i] == 0 && cmp(begin, words[i]) == 1)
		{
			map[i] = 1;
			cout << begin << " " << target << ans << endl;
			ans = min(ans, search(words[i], target, count + 1));
			map[i] = 0;
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
		string begin;
		string end;

		cin >> begin >> end;
		
		int n;
		cin >> n;

		for(int i = 0; i < n; ++i)
		{
			string cand;
			cin >> cand;

			words.push_back(cand);
		}

		memset(map, 0, sizeof(map));
		cout << search(begin, end, 0) << endl;
	}
}
