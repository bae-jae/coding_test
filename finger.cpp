#include <iostream>
#include <vector>

using namespace std;

int min(int n1, int n2)
{
	if(n1 > n2)
		return n2;

	return n1;
}

long long search(vector<int> v)
{
	long long answer = 0;
	int firstSearch = 0;

	long long plus = 0;
	int minus = 0;

	//코인 안드는거 
	for(int i = 0; i < v.size(); ++i)
	{
		if(v[i] > 0)
			plus += v[i];
		else
		{
			if(abs(v[i]) < plus)
			{
				plus += v[i];		//음수이기때문
				v[i] = 0;
			}
			else
			{
				v[i] += plus;
				plus = 0;
			}
		}
	}	//돈 안드는거 제거 

	for(int i = 0; i < v.size(); ++i)
	{
		if(v[i] < 0)
			answer += abs(v[i]);
	}

	return answer;
}


int main(void)
{
	int tc;
	cin >> tc;

	for(int test = 0; test < tc; ++test)
	{
		int n;
		cin >> n;

		vector<int> v;
		for(int i = 0; i < n; ++i)
		{
			int c;
			cin >> c;

			v.push_back(c);
		}

		cout << search(v) << endl;
	}
}
