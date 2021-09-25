#include <iostream>

using namespace std;

int price[52];

int main(void)
{
	int day, money;
	cin >> day >> money;
	
	for(int i = 1; i <= day; ++i)
	{
		cin >> price[i];
	}
	
	int hold = 0;
	
	for(int i = 1; i < day; ++i)
	{
		if(price[i] <= price[i + 1]) //내일 가격의 상승
		{
			if(hold == 0)
			{
				hold = money / price[i] ;	//코인 구매 
				money = money - (price[i] * hold);
			}
		}
		else						//내일 가격의 하락 
		{
			int total = price[i] * hold;
			hold = 0;
			money += total;
		}
		
		cout << i << " "<< price[i] << " " << hold << " " << money << endl;
	}
	
	int total = price[day] * hold;
	money += total;
	
	cout << money;
}