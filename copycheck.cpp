#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<double> v;
int answer;

int main(void)
{
	int n;
	cin >> n;

	for(int i = 0; i < n; ++i)
	{
		int s;
		cin >> s;

		v.push_back(s);
	}

	sort(v.begin(), v.end());
	map<double, int> m;

	for(int i = 0; i < v.size(); ++i)
	{
		int start = m[v[i]];
		int end = i;

		if(start != i)
		{
			answer += (start - i);
			continue;
		}

		for(int j = start; j < v.size(); ++j)
		{
			if(v[i] <= v[j] && v[i] >= (0.9 * v[j]))
				end = j;
			else
				break;
		}

		m[v[i]] = end;
		answer += (end - i);
	}

	cout << answer << endl;
}
