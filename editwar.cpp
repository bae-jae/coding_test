#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

vector<int> visited, enemy;

//경로 압축 사용 
//합병 사용

void init(vector<int> &ack, int n)
{
	visited.resize(n);
	enemy.resize(n);

	for(int i = 0; i < n; ++i)
	{
		visited[i] = 0;
		enemy[i] = 0;
		ack[i] = i;	
	}
}

int find(vector<int> &parent, int n1)
{
	if(parent[n1] == n1)  //부모 찾음
		return n1;

	return parent[n1] = find(parent, parent[n1]);		//경로 압축 과정
}

void merge(vector<int> &parent, vector<int> &rank, vector<int> &size, int n1, int n2)
{
	int n1Parent = find(parent, n1);
	int n2Parent = find(parent, n2);

	if(n1Parent == n2Parent)
		return;	//같은 집

	int rankN1 = rank[n1Parent];
	int rankN2 = rank[n2Parent];

	if(rankN1 < rankN2)
	{
		int swap;

		swap = n1Parent;
		n1Parent = n2Parent;
		n2Parent = swap;
	}

	parent[n2Parent] = n1Parent;
	size[n1Parent] += size[n2Parent];

	if(rankN1 == rankN2) 	//같을때만 증가시켲 주면 됨
	{
		++rank[n1Parent];
	}
}

int findAnswer(vector<int> &ack, vector<int> &ackS, int n1, int n2)
{
	//n1, n2 merge 후 

	int p1 = ack[n1];
	int p2 = ack[n2];

	cout << n1 << " " << n2 << " " << p1 << " " << p2 << endl;
	if(p1 == p2)
		return 0;	//잘못됨 

	if(visited[p1] == 0 || visited[p2] == 0)
	{
		enemy[p2] += ackS[p1];
		enemy[p1] += ackS[p2];
	}

	visited[p1] = 1;
	visited[p2] = 1;

	return - 1;
	
}

int maxFind(vector<int> &ackP, vector<int> &ackSize)
{
	int sum = 0;
	for(int i = 0;  i < ackP.size(); ++i)
	{
		if(ackP[i] == i)	//즉 자기가 부모다 
		{
			int p1 = ackP[i];

			if(ackSize[p1] < enemy[p1])
			{
				sum += enemy[p1];
			}
		}
	}

	return sum;
}

int main(void)
{
	int tc;
	cin >> tc;

	vector<pair<int, int>> disList;

	for(int test = 0; test < tc; ++test)
	{
		int n, m;	//친구의 수 댓글의 수 
		cin >> n >> m;
		int answer = -1;

		vector<int> ackP(n, 0);
		vector<int> ackR(n, 0);
		vector<int> ackS(n, 1);
		vector<int> disPos;
		
		disList.clear();

		init(ackP, n);

		for(int i = 0; i < m; ++i)
		{
			string s;
			int a, b;
			cin >> s >> a >> b;

			if(s == "ACK")
			{
				merge(ackP, ackR, ackS, a, b);
			}
			else
			{
				disPos.push_back(i + 1);
				disList.push_back(make_pair(a, b));
			}
		}

		//잘모된 부분 찾는 법
		for(int i = 0; i < disList.size(); ++i)
		{
			answer = findAnswer(ackP, ackS, disList[i].first, disList[i].second);

			if(answer != -1)
			{
				answer = disPos[i];
				break;
			}
		}

		if(answer == -1)
		{
			int maxSize = maxFind(ackP, ackS);
			cout << "MAX PARTY SIZE IS " << maxSize << "\n";
		}
		else
			cout << "CONTRADICTION AT " << answer << "\n";
	}
}
