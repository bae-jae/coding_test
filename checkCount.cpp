#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
int use[500001];

int main(void)
{
	int n;
	cin >> n;

	for(int i = 0; i < n; ++i)
	{
		int s;
		cin >> s;

		v.push_back(s);
		use[s] = 1;
	}

	sort(v.begin(), v.end());
	int answer = 0;

	for(int i = 0; i < v.size(); ++i)
	{
		answer += abs(v[i] - (i + 1));
	}

	cout << answer;
}
