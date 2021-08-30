#include <iostream>
#include <string>

using namespace std;

int answer = 0;
int arr[30];
string s;

void search(int len, int pick)
{
	if(len == s.size())
	{
		++answer;
		return;
	}

	for(int i = 0; i < 30; ++i)
	{
		if(arr[i] >= 1 && i != pick)
		{
			--arr[i];
			search(len + 1, i);
			++arr[i];
		}
	}
}

int main(void)
{
	cin >> s;

	for(int i = 0; i < s.size(); ++i)
		++arr[s[i] - 'a'];
	search(0, -1);

	cout << answer;
}
