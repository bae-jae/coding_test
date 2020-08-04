#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int max(int n1, int n2)
{
	if(n1 > n2)
		return n1;

	return n2;
}

int search(vector<vector<int>> diskList)
{
	sort(diskList.begin(), diskList.end());

	int nowTime = diskList[0][0];
	int len = -1;
	int answer = 0;

	priority_queue<pair<int ,int>> pq;

	while(true)
	{
		int first = 0;;
		for(int i = len + 1; i < diskList.size(); ++i)
		{

			if(diskList[i][0] <= nowTime)
				pq.push(make_pair(-diskList[i][1], i));
			else
				break;

			len = i + 1;
		}

		if(!pq.empty())
		{
			int needTime = -pq.top().first;
			int candLen = pq.top().second;

			pq.pop();

			nowTime += needTime;
			answer  += (nowTime - diskList[candLen][0]);
		}
		else
		{
			if(len < diskList.size())
				nowTime = diskList[len][0];
		}

		if((len == diskList.size()) && pq.empty())
			break;

	}

	return answer / diskList.size();
}

int main(void)
{
	int tc;
	cin >> tc;

	for(int test =0; test < tc; ++test)
	{
		int n;
		cin >> n;

		vector<vector<int>> diskList;
		
		for(int i = 0; i < n; ++i)
		{
			vector<int> v;

			for(int j = 0; j < 2; ++j)
			{
				int time;
				cin >> time;

				v.push_back(time);
			}

			diskList.push_back(v);
		}

		cout << search(diskList) << endl;
	}
}
