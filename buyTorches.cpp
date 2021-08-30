#include <iostream>

using namespace std;

long long findMeet(long long stick, long long d)
{
	if(stick % d == 0)
		return stick / d - 1;
	else
		return stick / d;
}
int main(void)
{
	int tc;
	cin >> tc;

	for(int test = 0; test < tc; ++test)
	{
		long long stick = 0;

		long long x, y, k;
		cin >> x >> y >> k;


		stick = (y * k) + k;

		long long d =  -1 * (x - 1) + 1;  //공비
		stick -= d;

		long long answer = 0; 
		answer += findMeet(stick, x - 1) + k;

		cout << answer << endl;
	}
}
