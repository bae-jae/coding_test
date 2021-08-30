#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<int> board;
vector<int> answer;
vector<int> chMap;

string canAnswer(void)
{
	int out = 1;
	for(int i = 0; i < board.size(); ++i)
	{
		if(board[i] != answer[i])	//다름 
		{
			out = 0;
			break;
		}
	}

	if(out == 1)
		return "Yes";

	int different = 0;
	
	for(int i = 0; i < chMap.size(); ++i)
	{
		for(int j = i + 1; j < chMap.size(); ++j)
		{
			if(chMap[i] != chMap[j])
			{
				++different;
			}
		}
	}

	if(different == 0)
		return "No";

	return "Yes";
}
int main(void)
{
	int tc;
	cin >> tc;

	for(int test = 0; test < tc; ++test)
	{
		int n;
		cin >> n;


		board.clear();
		answer.clear();
		chMap.clear();

		for(int i = 0; i < n; ++i)
		{
			int s;
			cin >> s;

			board.push_back(s);
			answer.push_back(s);
		}

		sort(answer.begin(), answer.end());

		for(int i = 0; i < n; ++i)
		{
			int s;
			cin >> s;
			
			chMap.push_back(s);
		}

		cout << canAnswer() << "\n";
	}
}
