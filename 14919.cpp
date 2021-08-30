#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

int main(void)
{
	int m;
	cin >> m;

	double l = (double)1/m + 0.00000001;
	vector<double> v;
	vector<int> ans;

	for(int i = 0; i < m; ++i)
	{
		double cand = (i + 1) * l * 10000000;
		v.push_back(cand);

		if(((i + 1) * 10000000) % m != 0)
			v[i]++;

		ans.push_back(0);
	}

	double x;

	while(~scanf("%lf", &x))
	{
		x += 0.0000001;
		x = x * 10000000;
		for(int i = 0; i < v.size(); ++i)
		{
			if(x < v[i])
			{
				ans[i]++;
				break;
			}
		}
	}

	for(int i = 0; i < ans.size(); ++i)
		cout << ans[i] << " ";

}
