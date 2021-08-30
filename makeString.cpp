#include <iostream>
#include <string>
#include <stack>

using namespace std;

string s;
int ans;

void getLongDis(int idx, string& cand)
{
	if(idx == s.size())
	{
		int startCount = 0;
		int startIdx = 0;

		int endIdx = 0;
		int endCount = 0;

		cout << cand << endl;

		for(int i = 0; i < cand.size(); ++i)
		{
			startIdx = i;

			if(cand[i] == 'K')
				++startCount;
			else
				break;
		}

		for(int i = cand.size() - 1; i >= 0; --i)
		{
			endIdx = i;

			if(cand[i] == 'K')
				++endCount;
			else
				break;
		}

		if(endCount != startCount)
		{
			return;
		}

		for(int i = startIdx; i <= endIdx; ++i)
		{
			if(cand[i] != 'R')
				return;
		}

		if(ans < cand.size())
			ans = cand.size();

		return;
	}

	getLongDis(idx + 1, cand);

	cand.push_back(s[idx]);
	getLongDis(idx + 1, cand);
	cand.pop_back();
}

int main(void)
{
	cin >> s;

	string sub;
	getLongDis(0, sub);

	cout << ans;
}
