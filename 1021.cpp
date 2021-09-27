#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> target;
int visited[55];
int n;
int mem[55];

pair<int, int> moveCount(int start, int pos, int move)
{
	int subStart1 = start;	//0일때 왜 문제인가
	int cicle1 = 0;
	
	while(true)
	{
		if(subStart1 == pos)	//삭제지점
			break;
		
		//1이 이미 지워줬다면 
		if(visited[subStart1] == 1)
		{
			subStart1 += move;
		}else
		{
			++cicle1;
			subStart1 += move;
		}
		
		if(subStart1 > n)	//마지막인덱스라면
			subStart1 = 1; //제일마지막 인덱스 줌
		
		if(subStart1 == 0)
			subStart1 = n;
	}
	
	return {subStart1, cicle1};
}

//1~n
int search(int start, int idx)
{
	//마지막 순번에 도달하면 0
	if(idx == target.size())
		return 0;
	
	int cicle2 = 0;
	
	while(true)						//삭제하고 나서 원래 앞으로 넘겨줘야 하는 부분을 구현함
	{
		if(visited[start] == 1)
		{
			++start;
		}else
		{			
			
			break;		
		}
	}
	
	pair<int, int> p1 = moveCount(start, target[idx], 1);
	pair<int, int> p2 = moveCount(start, target[idx], -1);
	
	
	
	visited[target[idx]] = 1;	//삭제 처리
	
	if(p1.second < p2.second)
	{
		mem[idx] = idx;
		return search(p1.first, idx + 1) + p1.second;
	}
	else{
		mem[idx] = idx;
		return search(p2.first, idx + 1) + p2.second;
	}
	
	
	return 987654321;
}
int main(void)
{
	int m;
	cin >> n >> m;
	
	for(int i = 0; i < m; ++i)
	{
		int s;
		cin >> s;
		
		target.push_back(s);
	}
	

	
	cout << endl;
	
	cout << search(1, 0);
}