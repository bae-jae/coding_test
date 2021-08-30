#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;


vector<pair<int, int>> reverseMap[1005];
vector<pair<int, int>> map[1005];
int score[1005];

void search(int town)
{
	priority_queue<pair<int , int>> pq;

	pq.push(make_pair(0, town));
	score[town] = 0;

	while(!pq.empty())
	{
		int cost = -pq.top().first;
		int next = pq.top().second;	//check pls

		pq.pop();

		if(score[next] < cost)
			continue;
		
		for(int i = 0; i < map[next].size(); ++i)
		{
			int nextCost = cost + map[next][i].second;
			int nextSrc = map[next][i].first;

			if(score[nextSrc] > nextCost)
			{
				score[nextSrc] = nextCost;
				pq.push(make_pair(-nextCost, nextSrc));
			}
		}
	}
}

void findroute(vector<int> &v, int startNode, int endNode, int n)
{
	v.push_back(endNode);

	if(startNode == endNode)
		return ;


	for(int i = 0; i < reverseMap[endNode].size(); ++i)
	{
		if(score[endNode] == (score[reverseMap[endNode][i].first] + reverseMap[endNode][i].second))
		{
			findroute(v, startNode, reverseMap[endNode][i].first, n);
			break;
		}
	}
}

int main(void)
{
	int n;
	cin >> n;

	int m;
	cin >> m;

	for(int i = 0; i < 1005; ++i)
		score[i] = 987654321;

	for(int i = 0; i < m; ++i)
	{
		int in, out, cost;

		cin >> in >> out >> cost;

		reverseMap[out].push_back(make_pair(in, cost));
		map[in].push_back(make_pair(out, cost));
	}

	int in, out;
	cin >> in >> out;

	search(in);

	cout << score[out] << "\n";

	vector<int> v;
	findroute(v, in, out, n);

	cout << v.size() << "\n";

	for(int i = v.size() - 1; i >= 0; --i)
		cout << v[i] << " ";

}
