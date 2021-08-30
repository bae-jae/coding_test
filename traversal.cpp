#include <iostream>

using namespace std;

int firstSearch[101];
int midSearch[101];
int n;
int tar = 0;

int findMiddle(int target)
{
	for(int i = 0; i < n; ++i)
	{
		if(midSearch[i] == target)
		{
			return i;
		}
	}
}

void search(int left, int right)
{
	if(left == right)
	{
		//cout << midSearch[left] << " ";
		return;
	}

	int pos = findMiddle(firstSearch[tar]);
	tar += 1;
	//cout << left << " " << right << " " << pos << "\n";

	search(left, pos);
	search(pos + 1, right);

	cout << midSearch[pos] << " ";
	//cout << midSearch[first] << " " << midSearch[sec] << " " << midSearch[pos] << " ";
}

int main(void)
{
	int tc;
	cin >> tc;

	for(int test = 0; test < tc; ++test)
	{
		cin >> n;

		for(int i = 0; i < n; ++i)   
		{
			cin >> firstSearch[i];
		}

		for(int i = 0; i < n; ++i)
		{
			cin >> midSearch[i];
		}
		tar = 0;
		search(0, n);
		cout << "\n";
	}

	return 0;
}
