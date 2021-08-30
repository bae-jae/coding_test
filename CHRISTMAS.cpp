#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
vector<long long> pSum;


const int maxDiv = 20091101;

void calcPsum(int k)
{
	pSum.push_back(v[0]);

	for(int i = 1; i < v.size(); ++i)
	{
		pSum.push_back(v[i] + pSum[i-1]);
	}
	
	for(int i = 0; i < pSum.size(); ++i)
	{
		pSum[i] = pSum[i] % k;
		
	}

	cout << 0 % k << endl;
}

int calcFindMax(int k)
{
	pSum.insert(pSum.begin(), 0);

	long long answer = 0;

	vector<long long> count(k, 0);

	for(int i = 0; i < pSum.size(); ++i)
	{
		++count[pSum[i]];
	}

	for(int i = 0; i < k; ++i)
	{
		if(count[i] >= 2)
		{
			answer = (answer + ((count[i] * (count[i] - 1)) / 2)) % maxDiv;
		}
	}

	return answer;
}

int max(int n1, int n2)
{
	if(n1 > n2)
		return n1;
	
	return n2;
}

int search(int k)
{
	vector<int> cache(k, -1);
	vector<int> memory(pSum.size(), 0);

	for(int i = 0; i < pSum.size(); ++i)
	{

		if(i > 0)
		{
			//구매 x
			memory[i] = memory[i-1]; 	//구매 안할때 
		}
		else
			memory[i] = 0;
		//매할때
		if(cache[pSum[i]] != -1)
		{
			memory[i] = max(memory[i], memory[cache[pSum[i]]] + 1);
		}
		cache[pSum[i]] = i;	//자기자신 업데이트 
	}

	return memory[pSum.size() - 1];
}

int main(void)
{
	int tc;
	cin >> tc;

	for(int test = 0; test < tc; ++test)
	{
		int n, k;
		cin >> n >> k;

		for(int i = 0; i < n; ++i)
		{
			int in;
			cin >> in;

			v.push_back(in);
		}

		calcPsum(k);


		cout << calcFindMax(k) << " " << search(k) << endl;
		v.clear();
		pSum.clear();
	}
}
