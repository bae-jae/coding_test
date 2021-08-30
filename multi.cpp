#include <iostream>
#include <vector>

using namespace std;

int tap[105];
int stuff[105];
vector<int> list;

int search(int n, int use)
{
	int tapUse = 0;
	int answer = 0;

	for(int i = 0; i < list.size(); ++i)
	{
		if(tapUse < n)
		{
			if(tap[list[i]] == 0)
			{
				tap[list[i]] = 1;
				stuff[list[i]]--;	//사용함
				++tapUse;
			}
		}
		else
		{
			if(tap[list[i]] == 0)
			{
				int sub = 976543211;
				int pos = 0;

				for(int j = 0 ; j < 105; ++j)
				{
					if(tap[j] == 1)
					{
						if(sub >= stuff[j])
						{
							sub = stuff[j];
							pos = j;
						}
					}
				}

				tap[pos] = 0;

				tap[list[i]] = 1;
				stuff[list[i]]--;
				++answer;
			}
		}
	}

	return answer;
}

int main(void)
{
	int n;
	int use;
	cin >> n >> use;

	for(int i = 0; i < use; ++i)
	{
		int s;
		cin >> s;

		++stuff[s];
		list.push_back(s);
	}

	cout << search(n, use);
}
