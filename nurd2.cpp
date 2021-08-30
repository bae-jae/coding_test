#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<int, int> m;


//upeert lower tow search
int search(int prob, int noodle)
{
		auto it = m.lower_bound(prob);	//key

		if(it == m.end())	//지배 당하지 않음 
		{
			return true;
		}

		if(it->second < noodle)
			return true;

		return false;
}

void removeDominate(int prob, int noodle)
{
	auto it =  m.lower_bound(prob);

	if(it == m.begin())	//지배할 수 있는 점이 없다 
		return;

	--it;
	while(true)
	{
		if(it->second > noodle)
			break;			//지배 못함 

		if(it == m.begin())
		{
			m.erase(it);
			break;
		}
		else
		{
			auto jt = it;		//다름 
			--jt;

			m.erase(it);
			it = jt;
		}
	}
}

int registered(int prob, int noodle)
{
	if(search(prob, noodle))
	{
		m[prob] = noodle;
	}
	else
	{
		removeDominate(prob, noodle);
	}
	return m.size();
}

int main(void)
{
	int tc;
	cin >> tc;

	for(int test = 0; test < tc; ++test)
	{
		vector<pair<int, int>> board;

		int n;
		cin >> n;

		for(int i = 0; i < n; ++i)
		{
			int prob;
			int noodle;

			cin >> prob >> noodle;

			m.clear();
			board.push_back(make_pair(prob, noodle));
		}

		int answer = 0;
		for(int i = 0; i < n; ++i)
		{
			answer += registered(board[i].first, board[i].second);
		}

		cout << answer  << "\n";
	}
}

