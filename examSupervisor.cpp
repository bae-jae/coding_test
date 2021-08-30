#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int tc;
	cin >> tc;

	for(int test = 0; test < tc; ++test)
	{
		int testroom;
		cin >> testroom;
		
		vector<int> cand;
		
		int super;
		int sub;

		for(int i = 0; i < testroom; ++i)
		{
			int a;
			cin >> a;

			cand.push_back(a);
		}

		cin >> super >> sub;

		int answer = 0;

		for(int i = 0; i < cand.size(); ++i)
		{
			int needOversee = cand[i] - super;
			++answer;

			if(needOversee <= 0)
				continue;
			else
			{
				int div = needOversee / sub; 

				if(needOversee % sub >= 1)
					++answer;

				answer += div;
			}

		}

		cout << answer << endl;
	}
}
