#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<string> v;

int cache[2001][2001];

int bitCount(int idx1, int idx2)
{
	int answer = 0;

	for(int i = 0; i < v[idx1].size(); ++i)
	{
		if((v[idx1][i] == '1') && (v[idx2][i] == '1'))
			++answer;
	}

	return answer;
}

int main(void)
{
	int n;
	cin >> n;

	string s;

	for(int i = 0; i < n; ++i)
	{
		cin >> s;
		v.push_back(s);
	}

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n / 2; ++j)
		{

			cache[i][j] = bitCount(i, j);
		}
	}


	cin >> n;

	for(int i = 0; i < n; ++i)
	{
		int p1, p2;
		cin >> p1 >> p2;

		if(p1 < p2)
		{
			int swap = p1;
			p1 = p2;
			p2 = swap;
		}

		p1 -=1;
		p2 -=1;


		cout << cache[p1][p2] << "\n";

	}
}
