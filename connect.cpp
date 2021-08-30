#include <iostream>
#include <string.h>

using namespace std;

int cache[31][31];
int n, m;

int find(int e, int w)
{
	if(e == n)
		return 1;

	int &ret = cache[e][w];

	if(ret != -1)
		return ret;

	ret = 0;

	for(int i = w; i < m; ++i)
	{
		ret += find(e + 1, i + 1);
	}

	return ret;
}
int main(void)
{
	int tc;
	cin >> tc;

	for(int i = 0; i < tc; ++i)
	{
		cin >> n >> m;

		memset(cache, -1, sizeof(cache));

		cout << find(0,0) << endl;
	}

}
