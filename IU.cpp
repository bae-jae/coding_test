#include <iostream>

using namespace std;

int search(int score, int plus)
{
	int answer = 0;
	
	//많이 남았ㅇ르 경우 
	if(score == 3 && plus == 2)
		return 1;
	else if(score == 3 && plus != 2)
		return 0;

	if(score % 3 == 0 && plus >= 2)
	{
		answer += search(score / 3, plus - 2);
	}

	answer += search(score - 1, plus + 1);

	return answer;
}


int main(void)
{
	int tc;
	cin >> tc;

	for(int i = 0; i < tc; ++i)
	{
		int n;
		cin >> n;


	}

	return 0;
}
