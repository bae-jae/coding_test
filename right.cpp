#include <iostream>
#include <vector>


using namespace std;

vector<int> v;

int main(void)
{
	int n;
	cin >> n;

	for(int i = 0; i < n; ++i)
	{
		int s;
		cin >> s;

		v.push_back(s);
	}

	vector<int> nge(v.size());
	vector<int> idx(v.size());

	int last = v.size() - 1;

	nge[last] = -1;
	idx[last] = -1;

	for(int i = v.size() - 2; i >= 0; --i)
	{
		if(v[i] < v[i + 1])
		{
			nge[i] = v[i + 1];
			idx[i] = i + 1;
		}
		else
		{
			int lastVisited = idx[i + 1];

			while(lastVisited != -1)
			{
				if(v[i] < v[lastVisited])
					break;

				lastVisited = idx[lastVisited];
			}

			if(lastVisited == -1)
			{
				nge[i] = -1;
				idx[i] = -1;
			}
			else
			{
				 nge[i] = v[lastVisited];
				 idx[i] = lastVisited;
			}
		}
	}

	for(int i = 0; i < v.size(); ++i)
		cout << nge[i] << " ";


}
