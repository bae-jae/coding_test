#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <cmath>

using namespace std;


string s1, s2;
int n;

vector<int> screw1;
vector<int> screw2;

int cache[10005][12];
int choice[10005][12];

int search(int idx, int plus)
{
	if(n == idx)
		return 0;
	
	int &ret = cache[idx][plus];
	
	if(ret != -1)
		return ret;
	
	int cur = (screw1[idx] + plus) % 10;
	
	int left = (screw2[idx] + 10 - cur) % 10;
	int right = (cur + 10 - screw2[idx]) % 10;
	
	
	int l = search(idx + 1, (plus + left) % 10) + left;				//left
	int r = search(idx + 1, plus) + right;				//right
	
	if(l > r)
	{
		ret = r;
		choice[idx][plus] = -right;
	}
	else{
		ret = l;
		choice[idx][plus] = left;
	}
	
	return ret;
}

void printAns(int idx, int plus)
{
	if(n == idx)
		return;
	
	cout << idx + 1 << " " << choice[idx][plus] << "\n";
	
	int cur = (screw1[idx] + plus) % 10;
	
	int left = (screw2[idx] + 10 - cur) % 10;
	int right = (cur + 10 - screw2[idx]) % 10;
	
	if(choice[idx][plus] < 0)
	{
		printAns(idx + 1, plus);
	}
	else{
		printAns(idx + 1, (plus + left) % 10);
	}
}

int main(void)
{
	cin >> n;
	
	cin >> s1;
	cin >> s2;
	
	memset(cache, -1, sizeof(cache));
	
	for(int i = 0; i < s1.size(); ++i)
	{
		int sc1 = s1[i] - '0';
		int sc2 = s2[i] - '0';
		
		screw1.push_back(sc1);
		screw2.push_back(sc2);
	}
	
	
	cout << search(0,0) << "\n";
	printAns(0,0);
}