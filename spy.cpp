#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;

vector<int> v;
string ans;

int visited[10];
int ansCount;

int isPrime(int n) {
	cout << "in " << n << endl;
    if( n <= 1 )
        return 0; //1은 소수가 아님.
         
	// 짝수는 소수에서 제외
	// 단, 2는 유일하게 짝수 중에서 소수
    if( n%2 == 0) 
        return n==2 ? 1 : 0;
         
	// n이 홀수인 경우 sqrt(n)까지 나눠서 나눠떨어지는지 여부 체크
    for(int i=3; i<=sqrt(n); i += 2) { 
		// 나눠 떨어진다면 약수에 해당하므로 소수가 아님.
        if( n % i == 0)
            return 0;
    }
    // 위에서 걸러지지 않은 나머지 경우는 소수에 해당됨
	return 1; 
}


void find(int len, int idx)
{
	if(len == idx)
	{
		int ians = stoi(ans);
		
		if(isPrime(ians) == 1)
			++ansCount;
		
		return;
	}
	
	int begin = -1;
	
	for(int i = 0; i < v.size(); ++i)
	{
		if(visited[i] == 0 && (begin != v[i]))
		{
			if(idx == 0 && v[i] == 0)
				continue;
			
			visited[i] = 1;
			
			ans.push_back(v[i] + '0');
			find(len, idx + 1);
			ans.pop_back();
			
			begin = v[i];
			
			visited[i] = 0;
		}
	}
}


int main(void)
{
	int n;
	cin >> n;
	
	for(int i = 0; i < n; ++i)
	{
		string s;
		cin >> s;
		
		v.clear();
		ansCount = 0;
		ans.clear();
		
		for(int k = 0; k < s.size(); ++k)
		{
			int idx = s[k] - '0';
			
			v.push_back(idx);
		}
		
		sort(v.begin(), v.end());
		
		
		for(int k = 1; k <= s.size(); ++k)
		{
			find(k, 0);
		}
		
		cout << ansCount << "\n";
	}
}
