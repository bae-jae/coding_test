#include <iostream>

using namespace std;

int ans;

int maxGet(int weight, int target)
{
	return weight / target;
}

void get(int personWeight, int candCount, int cnts, int weight)
{
		if(candCount > cnts)		//구매가능한 개수가 카운터보다 맞ㄶ다면 
		{
			ans += cnts;
			personWeight -= (cnts * weight);
		}
		else
		{
			ans += candCount;
			personWeight -= (candCount * weight);
		}
}
int main(void)
{
	int tc;
	cin >> tc;

	for(int test = 0; test < tc; ++test)
	{
		int p, f;
		cin >> p >> f;

		int cnts, cntf;
		cin >> cnts >> cntf;

		int weights, weightf;
		cin >> weights >> weightf;

		ans = 0;

		if(weights < weightf)
		{
			if(p < f)
			{
				int candCount = maxGet(p, weights);
				p = get(p, candCount, cnts, weights);

				candCount = maxGet(weightf);
				get(candCount, cntf, weightf);
			}
		}
		else
		{
			int candCount = maxGet(weightf);
			get(candCount , cntf, weightf);

			candCount = maxGet(weights);
			get(candCount, cnts, weights);
		}

		cout << ans << endl;
	}
}
