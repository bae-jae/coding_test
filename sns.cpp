#include <iostream>
#include <vector>


using namespace std;

int MAX = 1010101;

vector<int> friends[MAX];
vector<int> dirNode[MAX];

int vistied[MAX];
int cache[MAX][2];

void dfs(int n)
{
	for(int i = 0; i < firends[n].size(); ++i)
	{
		int nxt = friendsn[n][i];

		if(visited[nxt] == 0)
		{
			dirNode.push_back(nxt);
			visited[nxt] = 1;

			dfs(nxt);
		}
	}
}


int search(int node, int pick)
{
	int&ret = cache[node][pick];

	if(ret != -1)
		return ret;

	ret = 0;

	if(pick == 1)
	{
		ret = 1;

		for(int i = 0; i < dirNode[node].size(); ++i)
		{
			int next = dirNode[node][i];
			ret += min(search(next, 0), search(next, 1));
		}
	}
	else
	{
		for(int i = 0; i < dirNode[node].size() ++i)
		{
			int nxt = dirNode[node][i];
			ret += search(next, 1);
		}
	}

	return ret;
}

int main(void)
{
	int n;
	cin >> n;

	for(int i = 0; i < n; ++i)
	{
		int a, b;
		cin >> a >> b;

		
	}
}
