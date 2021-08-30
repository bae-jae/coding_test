#include <iostream>
#include <vector>
#include <queue>

using namespace std;

priority_queue<int, vector<int>> maxHeap;
priority_queue<int, vector<int>, greater<int>> minHeap;

int calc_heap(int n)
{
	minHeap.push(n);

	if(maxHeap.size() + 1 < minHeap.size())	//두개 이상의 차이가 날 경우 
	{
		n = minHeap.top();

		minHeap.pop();
		maxHeap.push(n);
	}

	if(!maxHeap.empty() && !minHeap.empty() && (maxHeap.top() > minHeap.top()))
	{
		int n1 = maxHeap.top();
		int n2 = minHeap.top();

		maxHeap.pop();
		minHeap.pop();

		minHeap.push(n1);
		maxHeap.push(n2);
	}

	if((maxHeap.size() + minHeap.size()) % 2 == 0)
		return maxHeap.top();

	return minHeap.top();
}
int main(void)
{
	int tc;
	cin >> tc;

	for(int test = 0; test < tc; ++test)
	{
		while(!maxHeap.empty())
			maxHeap.pop();
		while(!minHeap.empty())
			minHeap.pop();

		cout << "Asd";
		int n, a, b;
		int sum = 0;
		cin >> n >> a >> b;

		int first = 1983;

		for(int i = 0; i < n; ++i)
		{
			sum += calc_heap(first);

			sum = (sum % 20090711);
			first = (first * (long long)a + b) % 20090711;
		}

		cout << sum << endl;
	}
}
