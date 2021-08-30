#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int tc;
	cin >> tc;

	for(int test = 0; test < tc; ++test)
	{
		int n, t;
		cin >> n >> t;

		vector<int> v;
		for(int i = 0; i < n; ++i)
		{
			int s;
			cin >> s;

			v.push_back(s);
		}

		vector<int> cand = v;

		sort(cand.begin(), cand.end());

		int num1 = 0;
		int num2 = 0;

		for(int i = 0; i < cand.size() - 1; ++i)
		{
			if(cand[i] + cand[i + 1]  >= t)
			{
				num1 = cand[i];
				num2 = cand[i + 1];
				break;
			}
		}

		int use = 0;
		for(int i = 0; i < v.size(); ++i)
		{
			if(num1 == num2)
			{
				if(v[i] == num1)
				{
					if(use == 1)
					{
						use = 0;
						cout << "0" << " ";
					}
					else
					{
						use = 1;
						cout << "1" << " ";
					}
				}
				else
					if(v[i] < num1)
						cout << "0" << " ";
					else
						cout << "1" << " ";
			}
			else
				if(v[i] <= num1)
					cout << "0" << " ";
				else
					cout << "1" << " ";
		}
		cout << endl;

	}
}
