#include <iostream>
#include <vector>
#include <map>
#include <string.h>

using namespace std;
	

int pre_hash[3001][3001];
int suf_hash[3001][3001];


int main(void)
{
	int tc;
	cin >> tc;

	for(int test = 0; test < tc; ++test)
	{
		int n;
		cin >> n;

		vector<int> v;
		map<int, int> m;

		memset(pre_hash, 0, sizeof(pre_hash));
		memset(suf_hash, 0, sizeof(suf_hash));

		for(int k = 0; k < n; ++k)
		{
			int s;
			cin >> s;

			v.push_back(s);
		}


		for(int i = 0; i < v.size(); ++i)
		{
			pre_hash[i][v[i]] = m[v[i]];	//i의 이전에 몇개인지 
			++m[v[i]];

			for(int j = i + 1; j < n; ++j)
				pre_hash[j][v[i]] = m[v[i]]; //i의 이후의 값을 포함
		}

		map<int, int> mm;

		for(int i = v.size() - 1; i >= 0; --i)
		{
			suf_hash[i][v[i]] = mm[v[i]];
			mm[v[i]]++;

			for(int j = i - 1; j >= 0; --j)
				suf_hash[j][v[i]] = mm[v[i]]; //값 업데이트 
		}

		int answer = 0;

		for(int j = 0; j < n; ++j)
		{
			for(int k = j + 1; k < n; ++k)
			{
				answer += pre_hash[j][v[k]] * suf_hash[k][v[j]];
			}
		}

		cout << answer << endl;
	}
}
