#include <iostream>
#include <vector>

using namespace std;

int gcd(int p, int q)
{
	if(q == 0)
		return p;

	return gcd(q, p % q);
}

int main(void)
{
	int n1, n2;
	cin >> n1 >> n2;

	vector<int> v1, v2;

	for(int i = 0; i < n1; ++i)
	{
		int n;
		cin >> n;

		v1.push_back(n);
	}

	for(int i = 0; i < n2; ++i)
	{
		int n;
		 cin >> n;

		 v2.push_back(n);
	}

	int g = 0;

	for(int i = 1; i < v1.size(); ++i)
	{
		g = gcd(g, abs(v1[i] - v1[i-1]));
	}

	for(int i = 0; i < v2.size(); ++i)
	{
		cout << gcd(v1[0] + v2[i], g) << " ";
	}
}
