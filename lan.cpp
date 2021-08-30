#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector<int> xList;
vector<int> yList;

double map[501][501];

double minWeight[501];
int visited[501];

double calcDist(int x1, int y1, int x2, int y2)
{
	double sub = pow((x2- x1), 2) + pow((y2 - y1), 2);

	return sqrt(sub);
}


void init(int n)
{
	for(int i = 0; i < n; ++i)
	{
		minWeight[i] = 987654321;
		visited[i] = 0;

		for(int j = 0; j < n; ++j)
		{
			if(i != j)
			{
				map[i][j] = calcDist(xList[i], yList[i], xList[j], yList[j]);

			}
		}
	}
}

double search(int n)
{
	double need = 0;

	minWeight[0] = 0;

	for(int i = 0; i < n; ++i)	//출발점 
	{
		int u = -1;

		for(int j = 0; j < n; ++j)
		{
			if((visited[j] == 0) && ((u == -1) || minWeight[u] > minWeight[j]))
				u = j;
		}

		//u가 최소값을 가짐 현재 방문한 노드가 됨 

		for(int k = 0; k < n; ++k)
		{
			if(u != k)
			{
			if((visited[k] == 0) && (minWeight[k] > map[u][k]))
			{
				minWeight[k] = map[u][k];

			}
			}
		}

		need += minWeight[u];
		visited[u] = 1;
	}

	return need;
}

//유니온 파인드까지 

int main(void)
{
	int tc;
	cin >> tc;

	for(int test = 0; test < tc; ++test)
	{
		int n, m;
		cin >> n >> m;

		xList.clear();
		yList.clear();

		for(int i = 0; i < n; ++i)
		{
			int x;
			cin >> x;

			xList.push_back(x);
		}

		for(int j = 0; j < n; ++j)
		{
			int y;
			cin >> y;

			yList.push_back(y);
		}

		init(n);

		for(int i = 0; i < m; ++i)
		{
			int e1, e2;
			cin >> e1 >> e2;

			map[e1][e2] = 0;
			map[e2][e1] = 0;
		}


		printf("%.10f\n", search(n));
	}
}
