#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

vector<int> list;


int main(void)
{
	int n;
	cin >> n;

	for(int i = 0; i < n; ++i)
	{
		int s;
		cin >> s;

		list.push_back(s);
	}

	sort(list.begin(), list.end());

	int start = 0;
	int end = list.size() - 1;

	int ans = 987654321;

	vector<int> v(2);

	while(start < end)
	{
		int cand = list[start] + list[end];

		int undos = start;
		int undoe = end;

		if(cand < 0)
			++start;
		else
			--end;

		if(abs(ans - 0) > (abs(cand) - 0))
		{
			ans = abs(cand - 0);

			v[0] = list[undos];
			v[1] = list[undoe];
		}
	}

	cout << v[0] << " " << v[1] << endl;
}
