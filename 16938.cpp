#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> v;
vector<long long> psum;

int visited[20];
int ans[20];
int n, l, r, x; 

//			v는 정렬됨
void search(int idx, int check)
{
	if(idx == v.size() + 1)
		return;
	
	if(check == 1)
	{
		int sum = 0;
		int start = -1;
		int end = -1;

		for(int i = 0; i < 20; ++i)
		{
			if(visited[i] == 1)
			{
				end = i;
				sum += v[i];

				if(start == -1)
					start = i;

				cout << v[i] << " ";
			}
		}

		if(start != -1 && end != -1)
		{
			int dist = v[end] - v[start];

			if((l <= sum && sum <= r) && dist >= x)
			{
				cout << sum << " " << "정답";
				ans[end - start + 1] += 1;
			}
			else
				cout << "실패";

			cout << endl;
		}
	}
	
	visited[idx] = 1;
	search(idx + 1, 1);
	visited[idx] = 0;
	
	search(idx + 1, 0);
}

int main(void)
{
	cin >> n >> l >> r >> x;
	
	for(int i = 0; i < n; ++i)
	{
		int s;
		cin >> s;
		
		v.push_back(s);
	}
	
	sort(v.begin(), v.end());
	
	search(0, 0);
	
	int asum = 0;
	
	for(int i = 0; i < 20; ++i)
		asum += ans[i];
	
	
	cout << asum << endl;
}