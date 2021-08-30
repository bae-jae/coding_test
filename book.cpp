#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0}; 
int visited[101][101];

int dfs(int x, int y, int target, vector<vector<int>>& p)
{
	int answer = 1;

	if(y >= p.size() || y < 0)
		return 0;
	if(x >= p[0].size() || x < 0)
		return 0;	

	if(visited[y][x] == 1)
		return 0;
	
	if(visited[y][x] == 1)
		return 0;

	if(p[y][x] == target)
	{
		visited[y][x] = 1;
		for(int i = 0; i < 4; ++i)
		{
			answer += dfs(x + dx[i], y + dy[i], target, p);
		}

		return answer;
	}

	return 0;
}

int max(int n1, int n2)
{
	if(n1 > n2)
		return n1;

	return n2;
}

int search(vector<vector<int>>& p)
{
	map<int, int> m;
	int domain = 0;
	int answer = 1;

	for(int i = 0; i < p.size(); ++i)
	{
		for(int j = 0; j < p[i].size(); ++j)
		{
			if(visited[i][j] == 0 && p[i][j] != 0)
			{
				++domain;
				cout << p[i][j] << endl;
				answer = max(answer , dfs(j, i, p[i][j], p));
			}
		}
	}

	return answer;
}

int main(void)
{
	int n, m;
	cin >> m >> n;


	//m * n 

	vector<vector<int>> p;

	for(int i = 0; i < m; ++i)
	{
		vector<int> v;

		for(int j = 0; j < n; ++j)
		{
			int s;
			cin >> s;

			v.push_back(s);
		}
		p.push_back(v);
	}

	cout << search(p) << endl;
}
