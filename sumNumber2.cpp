#include <iostream>
#include <vector>


using namespace std;

int main(void)
{
	long long n , m;
	cin >> n >> m;


	vector<int> v;

	for(int i = 0; i < n; ++i)
	{
		int s;
		cin >> s;
		v.push_back(s);
	}

	long long sum = 0;
	int start = 0;
	int end = 0;
	int ans = 0;

	for(int i = 0; i < n; ++i)
	{
		sum += v[i];
		end = i;

		if(sum >= m)
		{
			break;
		}
	}

	while(end < v.size())
	{
		if(sum == m)
			++ans;

		sum -= v[start];
		++start;

		if(sum < m)
		{
			++end;

			for(; end < v.size(); ++end)
			{
				sum += v[end];

				if(sum >= m)
					break;
			}

			if(end == v.size())
				break;
		}
	}

	cout << ans << "\n";
}
