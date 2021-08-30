//1195 백준

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//2와 2만 안겹치면 맞물림 
string s1;
string s2;


int pos1[105];
int pos2[105];

int min(int n1, int n2)
{
	if(n1 < n2)
		return n1;
	
	return n2;
}

int find(int jump)
{
	int cache[300] = {0,};
	
	for(int i =0; i < 105; ++i)
	{
		if(pos1[i] == 1)
		{
			if(i + jump < 0)		//왼쪽으로 미는 경우 마이너스 값은 기록안함 
				continue;
			
			cache[i + jump] = 1;	//2가 지금 어디로 밀렸는지 기록
		}
	}
	
	// cout << jump << endl;
	
	// for(int i =0; i < 20; ++i)
	// {
	// 	cout << cache[i] << " ";
	// }
	
	// cout << endl;
	
	// for(int i =0; i < 20; ++i)
	// {
	// 	cout << pos2[i] << " ";
	// }
	
	// cout << endl;
	
	
	for(int i = 0; i < 105; ++i)
	{
		if(cache[i] == 1)
		{
			if(cache[i] == pos2[i])
			{
				return 0;			//밀려도 홈이 안맞다면 
			}
		}
	}
	
	return 1;						//홈이 맞을떄
}

int main(void)
{
	cin >> s1 >> s2;
	
	//s1이 항상 작도록 
	
	if(s1.size() > s2.size())
	{
		string cand = s1;
		s1 = s2;
		s2 = cand;
		
	}
	
	for(int i = 0; i < s1.size(); ++i)
	{
		if(s1[i] == '2')
			pos1[i] = 1;
	}
	
	
	for(int i = 0; i < s2.size(); ++i)
	{
		if(s2[i] == '2')
		{
			pos2[i] = 1;
		}
	}
	
	int ans = s1.size() + s2.size();
	
	//현재 자리에서 왼쪽에서 오른쪽으로 보내봄   
	// 12   ->    12   ->  
	// 22   ->   22    -> 이상없다면 결과 반환 
	
	for(int i = 0; i <= s2.size(); ++i)
	{
		int j = find(i);
		
		if(j == 1)
		{
			if(s1.size() + i <= s2.size())		//밀어도 s2사이즈 안이라면 항상 s2가 됨 
			{
				ans = s2.size();
			}
			else
			{
				ans = s2.size() + ((s1.size() + i) - s2.size());			// s2 + 얼마만큼 밀었는지
			}
			
			break;
		}
	}
	
	//현재 자리에서 오른쪽에서 왼쪽으로 보내봄   
	// 12   ->  12     ->   12   
	// 22   ->   22    ->     22    -> 이상없다면 결과 반환 
	
	for(int i = 0; i <= s2.size(); ++i)
	{
		int j = find(-i);
		
		if(j == 1)
		{
			ans = min(ans, s2.size() + i);		
			break;
		}
	}
	
	cout << ans;
}