#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	vector<int> v[30];

	v[0].push_back(3);

	cout << v[0][0] << endl;
}

