#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 200005;
int s, e;

queue<pair<int, int>> q;

int subway[MAX];
vector<int> map[200005];

int bfs(int start)
{
	start = start + 100000;
	
	for(int i = 0; i < map[start].size(); ++i)
	{
		q.push({map[start][i], 0});	
	}
	
	while(!q.empty()){
		int line = q.front().first;
		int cost = q.front().second;
		
		q.pop();
		
		if(subway[line] != -1)
			continue;
		
		subway[line] = cost;

		if(line == e + 100000)
			return cost;
		
		for(int i = 0; i < map[line].size(); ++i)
		{
			if(subway[map[line][i]] != -1)
				continue;
			
			if(map[line][i] < 100000){						//노드로 들어와서 링크로 연결됨
				q.push({map[line][i], cost + 1});	
			}
			else{										//링크로 들어오고 노드로 나간다	
				q.push({map[line][i], cost});		//다른 링크의 값은 현재 링크에 _ 1
			}
		}
	}
	
	return -1;
}

int main(void)
{
	int n, l;
	cin >> n >> l;
	
	for(int i = 1; i <= l; ++i)
	{
		while(1)
		{
			int gate;
			cin >> gate;
			
			if(gate == -1)
				break;
			
			map[i].push_back(gate + 100000);
			map[gate + 100000].push_back(i);
		}
	}
	
	memset(subway, -1, sizeof(subway));
	
	cin >> s >> e;
	
	cout << bfs(s);
	
}