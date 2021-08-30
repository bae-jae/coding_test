#include <iostream>
#include <map>

using namespace std;

map<int, int> nerd;

bool can_push(int x, int y)
{
	map<int, int>:: iterator it = nerd.lower_bound(x);	//x보다 오른쪽에 있는 점 중에서 젤 작은거 찾음

	if(it == nerd.end())
		return false;

	return y < it->second;		//지배 받을려면 여기에도 지배 받아야함 
}

void remove(int x, int y)					//지배되는 점 삭제
{
	map<int, int>::iterator it = nerd.lower_bound(x);

	if(it == nerd.begin())		//점이 없을 경우 
		return;

	--it;

	while(true)
	{
		//지배하지 않는다 
		if(it->second > y)
			break;

		//이전점이 없으면 
		if(it == nerd.begin())
		{
			nerd.erase(it);
			break;				//>
		}
		else
		{
			map<int, int>::iterator jt = it;
			--jt;
			nerd.erase(it);
			it = jt;
		}
	}
}

int Register(int x, int y)
{
	if(can_push(x, y))
		return nerd.size();

	remove(x,y);
	nerd[x] = y;
	return nerd.size();
}
int main(void)
{
	int tc;
	cin >> tc;

	for(int Test = 0; Test < tc; ++Test)
	{
		int n;
		cin >> n;		//학생의 수 

		int answer  = 0;
		nerd.clear();

		for(int i = 0; i < n; ++i)
		{
		int x, y;
		cin >> x >> y;


		answer += Register(x, y);
		}
		cout << answer << "\n";
	}
}
