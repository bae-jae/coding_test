#include <iostream>
#include <vector>

using namespace std;

/*
   종만북 이진탐색 반복문 불변식 증명
   1. lo < hi
	2. a[i-1] < x <= a[i]

	반복문을 탈출하려면  left + 1 >= right,   불변식에 의해 left < right,  left + 1 == right
  2. 탈출조건에 의해 탑은 항상 i라고 확정할 수 있음 
*/


int findMinTime(int n, vector<int> times)
{
	long long init = 1;

	long long left = 0;
	long long right = 1e18 + 1;

	cout << "초기화 " << right << endl;

	while(left + 1 < right)
	{
		long long mid = (left + right) / 2;
		long long person = 0;

		for(int i = 0; i < times.size(); ++i)
			 person += (mid / times[i]);

		if(person == n)
			return mid;

		if(person < n)		//작을때 올려줌 
			left = mid;		//왜 mid + 1은 안될까?   불변식이  깨짐 mid + 1이 정답이 될 수 있기때문 
		else
			right = mid;
	}

	return right;	//잘못됨 
}
int main(void)
{
	int tc;
	cin >> tc;

	for(int test = 0; test < tc; ++test)
	{
		int n;
		cin >> n;

		int human;
		cin >> human;

		vector<int> time;

		for(int i = 0; i < human; ++i)
		{
			int t;
			cin >> t;

			time.push_back(t);
		}
		//sear
		cout << findMinTime(n, time) << endl;
	}

}
