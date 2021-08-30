#include <iostream>

using namespace std;

int answer = 987654321;
void search(int n, int max, int count)
{
	if(n >= max)
	{
		if(n > max)
			return;
		else
			answer = min(answer, count);
	}

	if(count >= answer)
		return;

	search(n * 2, max, count + 1);
	search(n * 10 + 1, max, count + 1);
}

int main(void)
{
	long long a,b;
	cin >> a >> b;

	search(a, b, 0);

	if(answer == 987654321)
		answer = -1;
	else
		answer += 1;

	cout << answer << endl;
}
