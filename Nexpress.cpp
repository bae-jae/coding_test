#include <iostream>
#include <string>

using namespace std;
int target;
int value;

int min(int n1, int n2)
{
	if(n1 < n2)
		return n1;

	return n2;
}

int search(int n, int count)
{
	int answer = 987654321;

	if(count >= 9)
		return 9;

	if(n == target)
		return count;
	
	answer = search(n + value, count + 1);
	answer = min(search(n * value, count + 1), answer);
	answer = min(answer, search(n / value, count + 1));

	string s = to_string(n);

	int len = 1;
	
	for(int i = 0; i < s.size(); ++i)
		len *= 10;

	answer = min(answer , search(n * len + value, count + 1));

	return answer;
}
int main(void)
{
	int n;
	cin >> n;

	for(int test = 0; test < n; ++test)
	{
		cin >> value >> target;

		cout << search(value, 1) << endl;
	}
}
