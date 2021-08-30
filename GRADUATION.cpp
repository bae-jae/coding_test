#include <iostream>
#include <string.h>
#include <vector>

int mustListen[13];
int cache[1 << 13][20];			//이 학기에 졸업까지 남은 학기 수 
int semester[11];
int N, K, M, L;

using namespace std;

int bitCount(int bit)
{
	if(bit == 0)
		return 0;
	
	return (bit % 2) + bitCount(bit / 2);
}

int min(int n1 , int n2)
{
	if(n1 < n2)
		return n1;
	
	return n2;
}

//들을 지 말지 
int search(int listenList, int nowSemester)
{
	int& ret = cache[listenList][nowSemester];

	if(ret != -1)
		return ret;

	if(bitCount(listenList) == K)
		return 0;

	if(nowSemester == M)
	{
		return 9999;	//max임
	}

	ret = 9999;

	//돌아가면서 순환 
	ret = min(ret, search(listenList, nowSemester + 1));	//이번학기 듣지 않고 넘김 

	int canListenClass = semester[nowSemester];

	if(bitCount(canListenClass) > L)
	{
		//몇개만 선택해서 들어야 함
		for(int i = canListenClass; i; i = ((i - 1) & canListenClass))  //부분집합 순회 코드 
		{
			int secListenList = listenList;

			if((i & listenList) == i)	//이미 다 들은 내역
				continue;

			if(bitCount(i) > L)	//들을게 만아서 선택해야한다
				continue;
			else
			{
				for(int j = 0;  j < N; ++j)
				{
					if((i & (1 << j)) == (1 << j)) //과목이 존재하는 경우 
					{
						if((mustListen[j] & listenList) == mustListen[j])	//선수과목 들었는지 확인
						{
							secListenList |= (1 << j);
						}
					}
				}
			}

			ret = min(ret, search(secListenList, nowSemester + 1) + 1);
		}
	}
	else
	{
		int secListenList = listenList;

		for(int j = 0;  j < N; ++j)
		{
			if((canListenClass & (1 << j)) == (1 << j)) //과목이 존재하는 경우 
			{
				if((mustListen[j] & listenList) == mustListen[j])	//선수과목 들었는지 확인
				{
					secListenList |= (1 << j);
				}
			}
		}

		ret = min(ret, search(secListenList, nowSemester + 1) + 1);
	}
	
	return ret;
}

int main(void)
{
	int tc;

	cin >> tc;

	for(int test = 0; test < tc; ++test)
	{
		//int N; //전공 과목의 수 
		//int K; //들어야 할 과목의 수 
		//int M; //학기의 수 
		//int L; //한 학기에 최대로 들을 수 있는 과목의 수 

		cin  >> N >> K >> M >> L;

		memset(mustListen, 0, sizeof(mustListen));
		memset(cache, -1, sizeof(cache));

		int listenN;
		//선수과a목
		for(int i = 0; i < N; ++i)
		{
			cin >> listenN;

			int s;
			for(int j = 0; j < listenN; ++j)
			{
				cin >> s;
				mustListen[i] |= (1 << s);
			}
		}


		for(int i = 0; i < M; ++i) //학기의 수 
		{
			int s;
			cin >> s;

			semester[i] = 0;

			for(int j = 0; j < s; ++j)
			{
				int k;
				cin >> k;
				
				semester[i] |= (1 << k);
			}
		}


		int answer =  search(0, 0);

		if(answer == 9999)
		{
			cout << "IMPOSSIBLE" << "\n";
		}
		else
			cout << answer << "\n";
	}

}
