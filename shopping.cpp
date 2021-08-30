#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int min(int n1, int n2)
{
	if(n1 < n2)
		return n1;

	return n2;
}

void search(vector<string> list)
{
	vector<string> ans;
	map<string, int> m;

	for(int i = 0; i < list.size(); ++i)	//몇개 있는지 체크 
	{
		int in = 0;
		for(int j = 0; j < ans.size(); ++j)
		{
			if(ans[j] == list[i])
			{
				in = 1;
				break;
			}
		}

		if(in == 0)
			ans.push_back(list[i]);
	}

	//ans 배열에 정답있음 

	int left = 0;
	int right = 0;
	int pick = 0;

	int minSize = 987654321;
	int arr[2];

	while(right < list.size())
	{
		if(m.find(list[right]) == m.end()) //map에 없음
		{
			++pick;
		}

		m[list[right]] = right;
		++right;

		if(pick == ans.size())	//정답 도달 
		{
			if(right - left + 1  == ans.size())	//줄이기 없어도 됨 
			{
				arr[0] = left;
				arr[1] = right;
				break;	//탈출 
			}
			else
			{
				int subLeft = left;
				int subRight = right;

				for(int i = left; i < right; ++i)
				{
					if(m[list[i]] != i)	//인게스가 다름 앞에 있다는 소리
						subLeft += 1;
					else
					{
						m.erase(m.find(list[i]));
						--pick;	//빠져나가야함 
					}
				}

				if(minSize > subRight - subLeft + 1)
				{
					minSize = subRight = subLeft + 1;
					arr[0] = subLeft;
					arr[1] = subRight;
				}
			}
		}
	}

	cout << arr[0] << " " << arr[1] << endl;
}

int main(void)
{
	int tc;
	cin >> tc;

	for(int test = 0; test < tc; ++test)
	{
		vector<string> list;
		int n;
		cin >> n;

		for(int i = 0; i < n; ++i)
		{
			string s;
			cin >> s;

			list.push_back(s);
		}

		search(list);
	}
}
