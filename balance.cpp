#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

vector<int> weight_list;
vector<int> list;

int cache[31][31 * 500 + 1];

void search(int idx, int weight)
{
	if(idx == weight_list.size())
		return;

	int &result = cache[idx][weight];

	if(result != -1)
		return;


	search(weight, idx + 1);
	search(weight + weight_list[idx] ,idx + 1);
	search( ,idx + 1);
}

int checkPossible(int w)
{
	for(int i = 0; i < list.size(); ++i)
	{
		if(w == list[i])
			return 1;
	}


	for(int i = 0; i < list.size(); ++i)
	{
		for(int j = i + 1; j < list.size(); ++j)
		{
			if(w + list[i] == list[j])
				return 1;
		}
	}

	return 0;
}

int main(void)
{
	int n;
	cin >> n;

	for(int i = 0; i < n; ++i)
	{
		int s;
		cin >> s;

		weight_list.push_back(s);
	}

	search(0, 0);
	sort(list.begin(), list.end());

	cin >> n;

	for(int i = 0; i < n; ++i)
	{
		int s;
		cin >> s;

		if(checkPossible(s) == 1)
			cout << "Y" << " ";
		else
			cout << "N" << " ";
	}

	return 0;
}

