#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> v;
int cache[40005]; 
int ans;


int main(void)
{
	int n;
	cin >> n;

	memset(cache, -1, sizeof(cache));

	for(int i = 0; i < n; ++i)
	{
		int s;
		cin >> s;

		v.push_back(s);
	}

}
