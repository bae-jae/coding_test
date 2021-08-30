#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

map<vector<int>, int> m;

vector<int> changePos(vector<int> v)
{
	vector<int> cand = v;

	sort(v.begin(), v.end());

	for(int i = 0; i < cand.size(); ++i)
	{
		for(int j = 0; j < v.size(); ++j)
		{
			if(cand[i] == v[j])
			{
				cand[i] = j + 1;
				break;
			}
		}
	}
	
	for(int i = v.size() + 1; i <= 8; ++i)
		cand.push_back(i);

	return cand;
}


void search(void)
{
	vector<int> v;

	for(int i = 1; i <= 8; ++i)
		v.push_back(i);

	queue<vector<int>> q;

	q.push(v);
	m[v] = 0;


	while(!q.empty())
	{
		vector<int> tar = q.front();
		q.pop();
		int dist = m[tar];

		for(int i = 0; i < 7; ++i)
		{
			for(int j = i + 2; j <= 8; ++j)
			{
				reverse(tar.begin() + i, tar.begin() + j);

				if(m.count(tar) == 0)
				{
					q.push(tar);
					m[tar] = dist + 1;
				}
				
				reverse(tar.begin() + i, tar.begin() + j);
			}
		}

		++dist;
	}
}

int main(void)
{
	int tc;
	cin >> tc;

	search();

	for(int test = 0; test < tc; ++test)
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

		v = changePos(v);

		cout << m[v] << endl;
	}
}
