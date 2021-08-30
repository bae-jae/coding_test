#include <iostream>
#include <string>
#include <vector>

using namespace std;


int search(string s1, string s2)
{
	vector<string> subset1;
	vector<string> subset2;

	for(int i = 0; i <= s1.size() - 2; ++i)
	{
		string s = "";
		int count = 0;

		for(int j = i; j < i + 2; ++j)
		{
			if('A' <= s1[j] <= 'Z' || 'a' <= s1[j] <= 'z')
			{
				++count;
				s += tolower(s1[j]);
			}
			else
			{
				break;
			}
		}

		if(count == 2)
			subset1.push_back(s);

	}

	for(int i = 0; i <= s2.size() - 2; ++i)
	{
		string s = "";
		int count = 0;

		for(int j = i; j < i + 2; ++j)
		{
			if('A' <= s2[j] <= 'Z' || 'a' <= s2[j] <= 'z')
			{
				++count;
				s += tolower(s2[j]);
			}
			else
			{
				break;
			}
		}

		if(count == 2)
			subset2.push_back(s);
	}


	double intersection = 0;
	double n = subset1.size() + subset2.size();


	for(int i = 0; i < subset1.size(); ++i)
	{
		for(int j  = 0; j < subset2.size(); ++j)
		{
			cout << subset1[i] << " " << subset2[j] << endl;
			if(subset1[i] == subset2[j])
			{
				subset2.erase(subset2.begin() + j);
				++intersection;
				break;
			}
		}
	}

	double answer = (intersection / (n - intersection));
	double answer2 = answer * 65536;
	cout << answer << " " << intersection << " " << n - intersection <<endl;

	return answer2;
}
int main(void)
{
	int tc;
	cin >> tc;

	for(int test = 0; test < tc; ++test)
	{
		string str1;
		string str2;

		cin >> str1 >> str2;

		cout << search(str1, str2) << endl;
	}
}
