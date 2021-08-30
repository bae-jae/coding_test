#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
vector<int> pSum;

int main(void)
{
	int l;
	int aDis, aDam;
	int c;

	cin >> l;
	cin >> aDis >> aDam;
	cin >> c;

	for(int i = 0; i < l; ++i)
	{
		int n;
		cin >> n;

		v.push_back(n);
	}

	for(int i = 0; i < aDis; ++i)
	{
		if(i >= l)
			break;

		pSum.push_back(v[i]);
	}

	int sec = aDam;

	for(int i = aDis; i < v.size(); ++i)
	{
		pSum.push_back(v[i] + sec);
		sec += aDam;
	}

	vector<int> needSec;
	int useC = 0;

	for(int i = 0; i < pSum.size(); ++i)
	{
		int needT = pSum[i] / aDam + useC;

		if(pSum[i] % aDam != 0)
			++needT;

		if(needT > i + 1 && c >= 1)
		{
			--c;
			++useC;
		}
		else if(c == 0 && needT > i + 1)
		{
			cout << "NO";
			return 0;
		}
	}

	cout << "YES";
	return 0;
}
