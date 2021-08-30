#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int n;
vector<string> v;
long long score[100];

int main(void)
{
	int n;
	cin >> n;

	string s;

	for(int i = 0; i < n; ++i)
	{
		cin >> s;

		v.push_back(s);
		reverse(s.begin(), s.end());
		
		long long d = 1;
		
		for(int i = 0; i < s.size(); ++i)
		{
			int idx = s[i] - 'A';

			score[idx] += d;

			d *= 10;
		}
	}

	vector<long long> scoreList;

	for(int i = 0; i < 100; ++i)
		scoreList.push_back(-score[i]);

	sort(scoreList.begin(), scoreList.end());

	int maxNum = 10;
	map<int, int> m;

	for(int i = 0; i < scoreList.size(); ++i)
	{
		int ps = -scoreList[i];

		if(ps == 0)
			break;

		if(m[ps] == 0)
		{
			m[ps] = maxNum;
			--maxNum;
		}
	}

	int ans = 0;

	for(int i = 0; i < 100; ++i)
	{
		if(score[i] == 0)
			continue;

		ans += (score[i] * m[score[i]]);

		cout << score[i] << " " << m[score[i]] << " " << endl;
	}

	cout << ans;


	//빠르게 찾는법? 


}
