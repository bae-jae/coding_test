#include <iostream>
#include <vector>

using namespace std;

vector<int> list;
int cache[35][16000];

void check(int weight, int idx)
{
	if(idx == list.size())
	{
		return;
	}

	int &ret = cache[idx][weight];

	if(ret != -1)
		return;

	cache[idx][weight] = 1;

	check(weight + list[idx], idx + 1);
	check(weight - list[idx], idx + 1);
	check(weight, idx + 1);

	return;
}

int main(void)
{
	int n;
	cin >> n;

	for(int i = 0; i < n; ++i)
	{
		int s;
		cin >> s;

		list.push_back(s);
	}

	check(0, 0);

	cin >> n;

	for(int i = 0; i < n; ++i)
	{
		int weight;
		cin >> weight;

		int ans = cache[n][weight];

		if(ans == 1)
			cout << 'Y' << "\n";
		else
			cout << 'N' << "\n";

	}
}
