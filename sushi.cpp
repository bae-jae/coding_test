#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int cache[500];
vector<int> price;
vector<int> favor;

int max(int n1, int n2)
{
	if(n1 > n2)
		return n1;

	return n2;
}
int main(void)
{
	int tc;
	cin >> tc;

	for(int test = 0; test < tc; ++ test)
	{
		int n, m;
		cin >> n >> m; 	//초밥의 종료 

		memset(cache, 0 ,sizeof(cache));

		price.clear();
		favor.clear();

		for(int i = 0; i < n; ++i)
		{
			int p, f;
			cin >> p >> f;

			p /= 100;
			price.push_back(p);
			favor.push_back(f);
		}

		m /= 100;

		int ret = 0;

		for(int i = 1; i <= m; ++i)	//예산일때 최대 행보도 
		{
			for(int j = 0; j < price.size(); ++j)
			{
				if(i >= price[j])
				{
					int sub = cache[i % 201];
					cache[i % 201] = max(sub, cache[(i - price[j]) % 201] + favor[j]);

					ret = max(cache[i % 201], ret);
				}
			}
		}

		cout << ret << endl;
	}
}
