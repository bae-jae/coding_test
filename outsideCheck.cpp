#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int n;
int answer = 987654321;

vector<int> weak;
vector<int> dist;

int checkweak[202];
int checkDist[202];

int min(int n1, int n2)
{
	if(n1 < n2)
		return n1;

	return n2;
}

void search(int w, int use)
{

	int end = 1;

	if(use >= answer)
		return;

	for(int i = 0; i < weak.size(); ++i)
	{
		if(checkweak[weak[i]] == 0)
		{
			end = 0;
			break;
		}
	}

	if(end == 1)
	{
		answer = min(answer , use);
		return;
	}

	if(w >= weak.size())
		return;

	//이 공간을 막지 않는다
	search(w + 1, use);

	//안쓰고 넘아가는 경우 
	for(int j = 0; j < dist.size(); ++j)
	{
		if(checkDist[j] == 0)	//j를 쓰지 않을 경우 
		{
			checkDist[j] = 1;

			int idx = weak[w];

			for(int jump = 0; jump < dist[j]; ++jump)
			{
				if(idx >= n)
					idx = 0;

				checkweak[idx] += 1;
				++idx;
			}

			search(w + 1, use + 1);

			idx = weak[w];
				
			for(int jump = 0; jump < dist[j]; ++jump)
			{
				if(idx >= n)
					idx = 0;

				checkweak[idx] -= 1;
				++idx;
			}

			idx = weak[w];
				
			for(int jump = 0; jump < dist[j]; ++jump)
			{
				if(idx == -1)
					idx = n - 1;

				checkweak[idx] += 1;
				--idx;
			}

			search(w + 1, use + 1);
				
			idx = weak[w];
				
			for(int jump = 0; jump < dist[j]; ++jump)
			{
				if(idx == -1)
					idx = n - 1;

				checkweak[idx] -= 1;
				--idx;
			}

			checkDist[j] = 0;
		}
	}
}

int main(void)
{
	int tc;
	cin >> tc;

	for(int test = 0; test < tc; ++test)
	{
		memset(checkDist, 0, sizeof(checkDist));
		memset(checkweak, 0, sizeof(checkweak));
		
		cin >> n;		//외벽의 길이 

		int weekN;
		cin >> weekN;

		weak.clear();
		dist.clear();

		for(int i = 0; i < weekN; ++i)
		{
			int s;
			cin >> s;

			weak.push_back(s);
		}
		
		int distN;
		cin >> distN;

		for(int i = 0; i < distN; ++i)
		{
			int s;
			cin >> s;

			dist.push_back(s);
		}

		search(0, 0);

		cout << answer << endl;
	}
}
