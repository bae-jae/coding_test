#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, int> cache;
int last;
int len;

void init()
{
	cache.clear();
	last = 27;
	len = 1;

	for(int i = 0; i < 26; ++i)
	{
		char a = 'A' + i;
		string s;
		s.push_back(a);
		cache[s] = i + 1;
	}
}
void search(string target)
{
	vector<int> answer;
	string cand;
	int lastNum;

	for(int i = 0; i < target.size(); ++i)
	{
		cand += target[i];
		int targetNum = cache[cand];

		if(targetNum == 0)
		{
			cache[cand] = last;
			++last;
			answer.push_back[lastNum];

			cand = target[i];
			lastNum = cache[cand];
			continue;
		}

		lastNum = targetNum;
	}
	answer.push_back(lastNum);

	for(int i = 0; i < answer.size(); ++i)
	{
		cout << answer[i] << " ";
	}
}

int main(void)
{
	int tc;
	cin >> tc;

	for(int test = 0; test < tc; ++test)
	{
		init();
		string target;
		cin >> target;

		search(target)
	}
}
