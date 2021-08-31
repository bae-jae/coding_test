#include<iostream>
#include<queue>


using namespace std;

vector<long long> w;
vector<long long> wp;

int visited[200005];

int main(void)
{
	int n, t;
	cin >> n >> t;
	
	priority_queue<pair<long long, long long>> pq;
	
	for(int i = 0; i < n; ++i)
	{
		long long wi, pi;
		cin >> wi >> pi;
		
		pq.push({pi, wi});
	}
	
	long long  ans = 0;
	
	--t;
	
	while(!pq.empty())
	{
		long long pi = pq.top().first;
		long long wi = pq.top().second;
		
		pq.pop();
		
		ans += (wi + (pi * t));
		--t;
	}
	
	cout << ans;
}