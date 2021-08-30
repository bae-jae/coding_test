#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> price;
vector<int> lock;


int main(void)
{
	int tc;
	cin >> tc;

	for(int test = 0; test < tc; ++test)
	{
		int n;
		cin >> n;

		price.clear();
		lock.clear();

		for(int i = 0; i < n; ++i)
		{
			int s;
			cin >> s;

			price.push_back(s);
		}

		for(int i = 0; i < n; ++i)
		{
			int s;
			cin >> s;

			lock.push_back(s);
		}

		vector<int> temp;

		for(int i = 0; i < n; ++i)
		{
			if(lock[i] == 0)
				temp.push_back(-price[i]);
		}

		sort(temp.begin(), temp.end());
		int idx = 0;

		for(int i = 0 ; i < n; ++i)
		{
			if(lock[i] == 0)
			{
				price[i] = temp[idx] * - 1;
				++idx;
			}
		}

		for(int i = 0; i < price.size(); ++i)
		{
			cout << price[i] << " ";
		}
		cout << endl;
	}
}
