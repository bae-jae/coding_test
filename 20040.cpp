#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int parent[500005];

int find(int n1)
{
	if(parent[n1] == n1)
		return n1;
	
	return parent[n1] = find(parent[n1]);
}

int makeUnion(int n1, int n2)
{
	n1 = find(n1);
	n2 = find(n2);
	
	if(n1 == n2)
		return 1;
	
	parent[n2] = n1;
	
	return 0;
}

void init()
{
	for(int i = 0; i < 500005; ++i)
		parent[i] = i;
}

int main(void)
{
	int m ,n;
	cin >> n >> m;
	
	int answer = 0;
	init();
	
	for(int i = 0; i < m; ++i)
	{
		int s, e;
		cin >> s >> e;
		
		if(answer == 1)
			continue;
		
		if(makeUnion(s, e) == 1)
		{
			cout << i + 1;
			answer = 1;
		}
	}
	
	if(answer == 0)
		cout << 0;
}