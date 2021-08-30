#include <iostream>
#include <cstring>

using namespace std;

int map[1005][3];
int cache[3][1005][3];
int n;

int search(int first ,int idx, int undo)
{
	if(n == idx)
		return 0;

	int& ret = cache[first][idx][undo];

	if(ret != -1)
		return ret;

	ret = 987654321;

	if(idx == n - 1)
	{
		for(int i = 0; i < 3; ++i)
		{
			if(undo != i && first != i)
				ret = min(ret, search(first , idx + 1, i) + map[idx][i]);
		}
	}
	else
	{

		for(int i = 0; i < 3; ++i)
		{
			if(undo != i)
			{
				ret = min(ret, search(first, idx + 1, i) + map[idx][i]);
			}
		}
	}

	return ret;
}

int main(void)
{
	cin >> n;

	for(int i = 0; i < n; ++i)
	{
		int r, g, b;

		cin >> r >> g >> b;

		map[i][0] = r;
		map[i][1] = g;
		map[i][2] = b;
	}

	memset(cache, -1 ,sizeof(cache));

	int ans = 987654321;

	for(int i = 0; i < 3; ++i)
	{
		cout << search(i, 1, i) << " " << map[0][i] << endl;
		ans = min(ans, search(i, 1, i) + map[0][i]);

	}

	cout << ans << endl;
}
