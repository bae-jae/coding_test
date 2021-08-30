#include <iostream>
#include <string>

using namespace std;

int answer = 0;

int changeIdx(char c)
{
	if(c == 'A')
		return 0;
	else if(c == 'C')
		return 1;
	else if(c == 'G')
		return 2;
	
	return 3;
}

void checkanswer(int arr[], int count[])
{
	int can = 1;
	
	for(int i = 0; i < 4; ++i)
	{
		if(count[i] < arr[i])
		{
			can = 0;
			break;
		}
	}

	if(can == 1)
		++answer;
}

int main(void)
{
	int sn, mn;
	cin >> sn >> mn;

	string s;
	cin >> s;

	int arr[4];

	int count[4];

	for(int i = 0; i < 4; ++i)
	{
		count[i] = 0;
		cin >> arr[i];

	}

	for(int i = 0; i < mn; ++i)
	{
		int idx = changeIdx(s[i]);
		++count[idx];
	}

	checkanswer(arr, count);

	int first = 0;
	for(int i = mn; i < s.size(); ++i)
	{
		int idx = changeIdx(s[i]);
		++count[idx];

		idx = changeIdx(s[i - mn]);
		--count[idx];

		checkanswer(arr, count);
	}

	cout << answer;
}
