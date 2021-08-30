#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> arr;
int lis[1000000];


int nextFind(int end, int target)
{
	int idx = 0;
	int start = -1;

	cout << end << "ENDTE" << endl;

	while(start + 1 < end)
	{
		int mid = (start + end) / 2;

		if(lis[mid] < target)
		{
			start = mid;
		}
		else 
			end = mid;
	}

	return end;
}

int main(void)
{
	int n;
	cin >> n;

	for(int i = 0; i < n; ++i)
	{
		int s;
		cin >> s;

		arr.push_back(s);
	}

	int j = 0;
	lis[0] = arr[0];
	int i = 1;


	while(i < n)
	{
		cout << i << endl;

		if(lis[j] < arr[i])
		{
			lis[j + 1] = arr[i];
			++j;
		}
		else
		{
			int idx = nextFind(j, arr[i]);
			lis[idx] = arr[i];
		}

		++i;
	}

	cout << j + 1 << endl; 
}
