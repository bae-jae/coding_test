#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int tc;
	cin >> tc;

	for(int test = 0; test < tc; ++test)
	{
		int arrive, a , b, c;
		cin >> arrive >> a >> b >> c;

		vector<int> start;
		vector<int> needTime;


		start.push_back(a);
		start.push_back(b);
		start.push_back(c);

		for(int i = 0; i < 3; ++i){

			if(arrive <= start[i])
				needTime.push_back(start[i] - arrive);
			else{
				int n = arrive / start[i];
				int mod = arrive % start[i];

				if(mod == 0)
					needTime.push_back(mod);
				else
					needTime.push_back(start[i] * (n + 1) - arrive);
			}
		}

		int ans = needTime[0];

		for(int i = 0; i < needTime.size(); ++i)
		{
			if(ans > needTime[i])
				ans = needTime[i];
		}
		cout << ans << endl;
	}
}
