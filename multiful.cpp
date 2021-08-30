#include <iostream>

using namespace std;

long long search(long long t, long long num, int div)
{
	long long ans = 1;

	if(num == 1)
		return t;

	if(t % 2 != 0)
		return (search(t, num - 1, div) * t) % div;

	ans = search(t, num / 2, div);
	ans %= div;

	return (ans * ans) % div;
}

int main(void)
{
	long long a, b, c;
	cin >> a >> b >> c;

	cout << search(a, b, c) % c;
}
