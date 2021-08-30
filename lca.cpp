#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> map;
int v[500001];

void dfs(int s)
{
	queue<pair<int, int>> q;

	q.push(make_pair(s, 1));

	while(!q.empty())
	{
		int node = q.front().first;
		int height = q.front().second;

		q.pop();


		if(v[node] != 0)
			continue;

		v[node] = height;

		for(int i = 0; i < map[node].size(); ++i)
		{
			q.push(make_pair(map[node][i], height + 1));
		}
	}
}

int findLCA(int s, int e)
{
	if(v[s] > v[e])
	{
		int swap = s;
		s = e;
		e = swap;
	}

	cout << "ASD" << s << " " << e << " " << v[s] << " " << v[e] << map[e].size() << endl;
	//s가 항상 노이 큼 
	while(v[s] != v[e])	//높이가 같을때 까지 올라감 
	{
		for(int i = 0; i < map[e].size(); ++i)
		{
			if((v[e] - 1) == v[map[e][i]])
			{
				e = map[e][i];
				break;
			}
		}
	}

	cout << v[s] << " " << v[e] << " " << s << " " << e << endl;

	//높이 같으니 한칸씩 올라감 

	while(s != e)
	{
		for(int i = 0; i < map[e].size(); ++i)
		{
			if(v[e] - 1 == v[map[e][i]])
			{
				e = map[e][i];
				break;
			}
		}

		for(int i = 0; i < map[s].size(); ++i)
		{
			if(v[s] - 1 == v[map[s][i]])
			{
				s = map[s][i];
				break;
			}
		}

	}

	return s;
}


int main(void)
{
	int n;
	cin >> n;

	map.resize(n + 1);

	cout << n << endl;
	for(int i = 0; i < n - 1; ++i)
	{
		int s, e;

		cin >> s >> e;

		map[s].push_back(e);
		map[e].push_back(s);
	}

	dfs(1);

	int m;
	cin >> m;

	for(int i = 0; i < m; ++i)
	{
		int s, e;
		cin >> s >> e;

		cout << findLCA(s, e) << "\n";
	}

}
