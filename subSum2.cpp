#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> list;

map<int, int> l;

int target;
long long ans;
int m;
int e;

void findL(int idx, int value)
{
	if(idx == m)
	{
		l[value] += 1;
		return;
	}

	findL(idx + 1, value);
	findL(idx + 1, value + list[idx]);

}

void findR(int idx, int value)
{
	if(idx == e)
	{
		ans += l[target - value];
		return;
	}


	findR(idx + 1, value);
	findR(idx + 1, value + list[idx]);
}


int main(void)
{
	int n;

	cin >> n >> target;

	for(int i = 0; i < n; ++i)
	{
		int s;

		cin >> s;

		list.push_back(s);
	}

	m = list.size() / 2;
	e = list.size();

	findL(0, 0);
	findR(list.size() / 2, 0);


	if(target == 0)
		ans -= 1;


	cout << ans << endl;
}
