#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
vector<int> psum;

int MOD = 20091101;

void calc_acc(void)
{
	psum.push_back(0);

	for(int i = 0; i < v.size(); ++i)
	{
		psum.push_back(v[i] + psum[i]);
	}
}

int search(int k)
{
	int ret = 0;
	vector<long long> count(k, 0);

	for(int i = 0; i < psum.size(); ++i)
	{
		psum[i] = psum[i] % k;
		cout << psum[i] << " ";
	}

	cout << endl;

	for(int i = 0; i < psum.size(); ++i)
		++count[psum[i]];

	for(int i = 0; i < k; ++i)
	{
		if(count[i] >= 2)
		{
			ret = (ret + (count[i] * (count[i] - 1) / 2)) % MOD;
		}
	}

	return ret;
}

int max(int n1, int n2)
{
	if(n1 > n2)
		return n1;
	
	return n2;
}

int search2(void)
{
	vector<int> prev(psum.size(), -1);
	vector<int> ret(psum.size(), 0);


	for(int i = 0; i < psum.size(); ++i)
	{
		//i를 사용안할떄 
		if(i > 0)
			ret[i] = ret[i - 1];
		else
			ret[i] = 0;

		
		int loc = prev[psum[i]];

		//i를 구매할때
		if(loc != -1)
			ret[i] = max(ret[loc] + 1, ret[i]);

		prev[psum[i]] = i;
	}

	return ret.back();
}
int main(void)
{
	int tc;
	cin >> tc;

	for(int test = 0; test < tc; ++test)
	{
		int n, k;
		cin >> n >> k;

		v.clear();
		psum.clear();

		for(int i = 0; i < n; ++i)
		{
			int s;
			cin >> s;

			v.push_back(s);
		}

		calc_acc();

		cout << search(k) << " " << search2() << "\n";
	}
}
