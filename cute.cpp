#include <iostream>
#include <vector>

using namespace std;

int min(int n1, int n2)
{
	if(n1 < n2)
		return n1;

	return n2;
}

int main(void)
{
	int n, k;
	cin >> n >> k;

	vector<int> v;

	for(int i = 0; i < n; ++i)
	{
		int s;
		cin >> s;

		if(s == 1)
			v.push_back(i);
	}

	//first search
	int winsize = 0;
	int count = 0;
	int answer = 987654321;

	for(int i = 0; i < v.size(); ++i)
	{
		if(i + k > v.size())
			break;

		answer = min(answer, v[i + k - 1] - v[i] + 1);
	}

	if(answer == 987654321)
		answer = -1;

	cout << answer;
}
