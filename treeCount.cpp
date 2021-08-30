#include <iostream>
#include <map>

using namespace std;

int visited[4000];
map<int> m;

void search(int root, int height, int n)
{

	for(int i = root + 1; i < n; ++i)
	{
		if(root 
	}

	visited[allclear] = 1;

	if(allclear == -1)
	{
		return;
	}

	int idx = allclear;
	cout << idx << " ";

	for(int i = idx + 1; i < n; ++i)
	{
		if(visited[i] == 0)
		{
			visited[i] = 1;
			search(n);
			visited[i] = 0;
		}
	}

	visited[idx] = 0;
}
int main(void)
{
	int n, k;
	cin >> n >> k;

	search(n);
}
