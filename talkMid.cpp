#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{
	int n;
	cin >> n;

	vector<int> answer;

	priority_queue<int> minHeap;
	priority_queue<int> maxHeap;

	for(int i = 0; i < n; ++i)
	{
		int cand;
		cin >> cand;

		if(minHeap.size() == maxHeap.size())
		{
			maxHeap.push(cand);
		}
		else
			minHeap.push(-cand);

		if(!minHeap.empty() && !maxHeap.empty())
		{
			int minTop = -minHeap.top();
			int maxTop = maxHeap.top();

			if(maxTop > minTop)
			{
				minHeap.pop();
				maxHeap.pop();

				maxHeap.push(minTop);
				minHeap.push(-maxTop);

			}
		}

		answer.push_back(maxHeap.top());

	}

	cout << "ans" << endl;
	for(int i = 0; i < answer.size(); ++i)
		cout << answer[i] << "\n";
}
