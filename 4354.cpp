#include <iostream>
#include <string>
#include <vector>

using namespace std;

string s;

int getCycle()
{
	int begin = 1;
	int matched = 0;
	
	vector<int> pi(s.size(), 0);
	
	while(begin + matched < s.size())
	{
		if(s[begin + matched] == s[matched])
		{
			++matched;
			pi[begin + matched - 1]= matched;
		}
		else
		{
			if(matched == 0)
			{
				++begin;
				continue;
			}
			
			begin += matched - pi[matched - 1];
			matched = pi[matched - 1];
			
		}
	}
	
	if((s.size() % begin) != 0)
		return 1;
	
	return (s.size() / begin);
}

int main(void)
{
	while(1)
	{
		cin >> s;
		
		if(s == ".")
			break;
		
		cout << getCycle() << "\n";
	}
}