#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int min(int n1, int n2)
{
	if(n1 < n2)
		return n1;

	return n2;
}

int main(void)
{
	int n;
	cin >> n;

	vector<int> v;

	for(int i = 0; i < n; ++i)
	{
		int s;
		cin >> s;

		v.push_back(s);
	}

	sort(v.begin(), v.end());

	int answer = 0;

	for(int i = 0; i < v.size(); ++i)
	{
		int tar = v[i];
		int subAns = 0;

		for(int j = i + 1; j < i + 5; ++j)
		{
			if(v[j] - tar != 1)
			{
				++tar;
				++subAns;
			}
			else
				++tar;
		}

		answer = min(answer, subAns);
	}
	
	cout << answer;
}
