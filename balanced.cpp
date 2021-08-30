#include <iostream>
#include <string>

using namespace std;

int findNext(string s, int idx)
{
	for(int i = idx; i < s.size(); ++i)
	{
		if(s[i] == '?')
			return i;
	}

	return s.size();
}

int firstSearch(string s, int k)
{
	for(int i = 0; i < s.size(); ++i)
	{
		if(i + k >= s.size() + 1)
			return 1;

		string cand = s.substr(i, k);

		int zero = 0;
		int one = 0;

		for(int j = 0; j < cand.size(); ++j)
		{
			if(cand[j] == '0')
				++zero;
			else if(cand[j] == '1')
				++one;
		}

		if(zero >= (k / 2) + 1)
			return 0;
		if(one >= (k / 2) + 1)
			return 0;
	}
}

int search(string s, int k, int next)
{
	int answer = 1;

	if(next == s.size())
	{
		for(int i = 0; i < s.size(); ++i)
		{
			if(i + k >= s.size() + 1)
				return 1;

			string cand = s.substr(i, k);

			int zero = 0;
			int one = 0;

			for(int j = 0; j < cand.size(); ++j)
			{
				if(cand[j] == '0')
					++zero;
				else if(cand[j] == '1')
					one++;
			}

			if(zero != one)
				return 0;
		}
	}

	for(int i = next; i < s.size(); ++i)
	{
		if(s[i] == '?')
		{
			int next = findNext(s, i + 1);

			s[i] = '1';
			answer = search(s,k, next);

			if(answer == 1)
				return 1;

			s[i] = '0';
			answer = search(s,k, next);

			s[i] = '?';	//복원
			break;
		}
	}

	return answer;
}
int main(void)
{
	int tc;
	cin >> tc;

	for(int test = 0; test < tc; ++test)
	{
		int n, k;
		string s;
		
		cin >> n >> k;
		cin >> s;

		int answer = firstSearch(s, k);

		if(answer == 0)
			cout << "NO" << "\n";
		else
		{
			answer = search(s, k, 0);

			if(answer == 1)
				cout << "YES" << "\n";
			else
				cout << "NO" << "\n";
		}
	}

}
