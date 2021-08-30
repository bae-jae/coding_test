#include <iostream>
#include <cstring>


using namespace std;

int cache[100005];
int idx[100005];
int n, k;

int search(int pos)
{
	if(pos >= k)
	{
		cout << pos << " " << k << "ASD" << endl;
		return pos - k;
	}

	int& ret = cache[pos];

	cout << pos << " " << ret << "CAS" << endl;

	if(ret != -1)
		return ret;

	idx[pos] = 1;
	ret = search(pos + 1);

	if(pos - 1 >= 0)
	{
		if(ret > search(pos - 1))
		{
			ret = search(pos - 1);
			idx[pos] = 2;
		}
	}

	if(pos * 2 <= 100000)
	{
		if(ret > search(pos * 2))
		{
			ret = search(pos * 2);
			idx[pos] = 3;
		}
	}

	cout << pos << " " << idx[pos] << " " << ret + 1 << endl;
	return ret = ret + 1;
}

int main(void)
{
	memset(cache, -1, sizeof(cache));
	cin >> n >> k;
	cout << search(n);
}
