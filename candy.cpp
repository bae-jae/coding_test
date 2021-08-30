#include <iostream>
#include <vector>
#include <string>

using namespace std;

int max(int n1, int n2)
{
	if(n1 > n2)
		return n1;

	return n2;
}

int columeCheck(vector<string>& map)
{
	for(int i = 0; i < map[0].size(); ++i)
	{
		int cand = 1;
		for(int j = 0; j < map.size() - 1; ++j)
		{
			if(map[j][i] == map[j + 1][i])
				++cand;
			else
			{
				answer = max(answer, cand);
				cand = 1;
			}
		}
	}
	return answer;
}
int rowCheck(vector<string> & map)
{
	int answer = 1;

	for(int i = 0; i < map.size(); ++i)
	{
		int cand = 1;

		for(int j = 0; j < map[i].size() - 1; ++j)
		{
			if(map[i][j] == map[i][j + 1])
				++cand;
			else
			{
				
				answer = max(answer ,cand);
				cand = 1;
			}
		}
	}

	return answer;
}

int solution(vector<string>& map)
{
	int answer = 1;
	
	for(int i = 0; i < map[0].size(); ++i)
	{
		for(int j = 0; j < map.size() - 1; ++j)
		{
			if(map[j][i] != map[j + 1][i])
			{
				char s = map[j][i];
				map[j][i] = map[j + 1][i];
				map[j + 1][i] = s;

				answer = max(rowCheck(map), answer);
				answer = max(columeCheck(map), answer);

				s = map[j + 1][i];
				map[j + 1][i] = map[j][i];
				map[j][i] = s;
			}
		}
	}

	for(int i = 0; i < map.size(); ++i)
	{
		for(int j = 0; j < map[i].size() - 1; ++j)
		{
			if(map[i][j] != map[i][j + 1])
			{
				char s= map[i][j];
				map[i][j] = map[i][j + 1];
				map[i][j + 1] = s;
				
				answer = max(columeCheck(map), answer);
				answer = max(rowCheck(map), answer);


				s = map[i][j + 1];
				map[i][j + 1] = map[i][j];
				map[i][j] = s;
			}
		}
	}

	return answer;
}
int main(void)
{
	int n;
	cin >> n;

	vector<string> map;

	for(int i = 0; i < n; ++i)
	{
		string s;
		cin >> s;
		map.push_back(s);
	}

	cout << solution(map);
}
