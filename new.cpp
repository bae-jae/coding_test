#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> weight;

int main(void)
{
	int n;
	cin >> n;

	for(int i = 0; i < n; ++i)
	{
		int s;
		cin >> s;

		weight.push_back(s);
	}

	sort(weight.begin(), weight.end());

	int explore = weight.size() - 1;

	long long finalAns = 3000000005;
	int best1= 0;
	int best2 = 0;
	int best3 = 0;

	for(int i = 0; i < weight.size() - 2; ++i)
	{
		long long maxDist = 3000000005;
		int x = weight[i];
		int left = i + 1;
		int right = weight.size() - 1;

		while(left < right)
		{
			long long temp = x + weight[left] + weight[right];

			if(abs(finalAns) > abs(temp))
			{
				finalAns = temp;

				best1 = x;
				best2 = weight[left];
				best3 = weight[right];
			}

			if(temp < 0)
				left++;
			else if(temp > 0)
				right--;
			else
			{
				i = n;
				break;
			}
		}


	}

	cout << best1<< " " << best2<< " " << best3;
}
