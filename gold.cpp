#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

int canUse[1000005];

void decimal(void)
{
	canUse[0] = -1;
	canUse[1] = -1;

	int max = 1000000;

	for(int i = 2; i <= 1000000; ++i)
	{
		if(canUse[i] == -1)
			continue;

		canUse[i] = 1;

		if(i % 2 == 0)
			canUse[i] = -1;

		int start = i;
		int idx = 2;

		while(start * idx <= max)
		{
			canUse[start * idx] = -1;
			++idx;
		}
	}
}

int main(void)
{

	while(1)
	{
		int s;
		cin >> s;

		if(s == 0)
			break;

		v.push_back(s);
	}

	decimal();

	for(int i = 0; i < 30; ++i)
		cout << canUse[i] << " ";

	cout << endl;

	for(int i = 0; i < v.size(); ++i)
	{
		int left = 0;
		int right = v[i];

		while(left <= right)
		{
			cout << i << " " << left << " " << right << endl;
			if(canUse[left] == -1)
			{
				++left;
				continue;
			}
			
			if(canUse[right] == -1)
			{
				--right;
				continue;
			}

			if(left + right > v[i])
				--right;

			if(left + right < v[i])
				++left;

			if(left + right == v[i])
				break;
		}

		if(left > right)
		{
			cout <<"ASD"<< "\n";
		}
		else
			cout << v[i] << " = " << left << " + " << right << "\n";
	}
}
