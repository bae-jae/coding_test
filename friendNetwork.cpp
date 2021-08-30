#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string, int> m;
int parent[2001];
int count[2001];
int h[2001];

void init()
{
	for(int i = 0; i < 2001; ++i)
	{
		count[i] = 1;
		parent[i] = i;
		h[i] = 1;
	}
}

int find(int n1)
{
	if(parent[n1] == n1)
		return n1;
	else
	{
		return parent[n1] = find(parent[n1]); 
	}
}

int unionSet(int n1, int n2)
{
	cout << n1 << " " << n2 << endl;
	n1 = find(n1);
	n2 = find(n2);

	cout << n1 << " " << n2 << endl;

	if(n1 == n2)
		return count[n1];

	if(h[n1] > h[n2])
	{
		int swap = n1;
		n1 = n2;
		n2 = swap;
	}

	parent[n2] = n1;

	if(h[n1] == h[n2])
		++h[n1];

	return count[n1] += count[n2];

}
int main(void)
{
	int tc;
	cin >> tc;

	for(int test = 0; test < tc; ++test)
	{
		int n;
		cin >> n;

		int count = 1;
		m.clear();
		init();

		for(int i = 0; i < n; ++i)
		{
			string s1, s2;
			cin >> s1 >> s2;

			if(m[s1] == 0)
			{
				m[s1] = count;
				++count;
			}
			if(m[s2] == 0)
			{
				m[s2] = count;
				++count;
			}

			cout << unionSet(m[s1], m[s2]) << "\n";
		}
	}
}
