#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

int used[100005];
int nextPos[100005];

void init(void)
{
	for(int i = 0; i < 100005; ++i)
		nextPos[i] = i;

}

int find(int pos)
{
	if(pos == 0)
		return 0;

	if(used[pos] == 0)
		return pos;

	int next = nextPos[pos];

	return nextPos[pos] = find(next);
}

int main(void)
{
	int g, p;
	cin >> g >> p;

	for(int i = 0; i < p; ++i)
	{
		int s;
		cin >> s;

		v.push_back(s);
	}

	int ans = 0;

	for(int i = 0; i < v.size(); ++i)
	{
		int start = v[i];
		int cant = 1;

		if(used[start] == 0)
		{
			used[start] = 1;
			++ans;
			nextPos[start] = start - 1;
		}
		else
		{
			int p = find(start);

			if(p == 0)
				break;

			used[p] = 1;
			++ans;
			nextPos[p] = p - 1;

			
		}
	}

	cout << ans;
}
