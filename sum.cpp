#include <iostream>
#include <cstring>
#include <queue>
#include <cmath>

using namespace std;

int prime[4000005];

int checkPrime(int n)
{
	if(n <= 1)
		return 0;

	if(n % 2 == 0)
		return n == 2 ? 1:0;

	for(int i = 3; i <= sqrt(n); i += 2)
	{
		if(n % i == 0)
			return 0;
	}

	return 1;
}

void inputPrime(int n)
{
	for(int i = 1; i <= n; ++i)
	{
		if(checkPrime(i) == 1)
			prime[i] = 1;
		else
			prime[i] = 0;
	}
}

int search(int n)
{
	int sum = 0;
	
	queue<int> q;

	int ans = 0;
	int end;

	for(int i = 1; i <= n; ++i)
	{
		if(prime[i] == 1)
		{
			q.push(i);
			sum += i;
		}

		end = i;

		if(sum >= n)
			break;
	}

	while(end <= n)
	{
		if(sum == n)
			++ans;

		sum -= q.front();
		q.pop();

		if(sum < n)
		{
			++end;
			
			for(; end <= n; ++end)
			{
				if(prime[end] == 1)
				{
					sum += end;
					q.push(end);
				}

				if(sum >= n)
					break;
			}
		}
	}

	return ans;
}

int main(void)
{
	 int n;
	 cin >> n;

	 inputPrime(n);
	
	 cout << search(n) << endl;
}
