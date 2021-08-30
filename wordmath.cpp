#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <map>

using namespace std;

vector<string> v;
int score[28];

int main(void)
{
	int n;
	cin >> n;

	map<int, int> m;


	for(int i = 0; i < n; ++i)
	{
		string s;
		cin >> s;

		v.push_back(s);

		for(int j = 0; j < s.size(); ++j)
		{
			int sc = pow(10, s.size() - j - 1);

			score[s[j] - 'A'] += sc;
		}
	}

	int max = 9;

	for(int i = 0 ; i < 28; ++i)
	{
		int idx = i;

		for(int j = 0; j < 28; ++j)
		{
			if(score[idx] < score[j])
			{
				idx = j;
			}
		}

		if(score[idx] == 0)
			break;

		cout << "idx " << score[idx] << endl;

		score[idx] = 0;
		m[idx] = max;
		--max;
	}

	cout << pow(10, 0) << endl;

	int answer = 0;
	for(int i = 0; i < v.size(); ++i)
	{
		int sub = 0;
		for(int j = 0; j < v[i].size(); ++j)
		{
			int sc = m[v[i][j] - 'A'];
			sub += pow(10, v[i].size() - j - 1) * sc;
		}

		answer += sub;
	}

	cout << answer << endl;
}
