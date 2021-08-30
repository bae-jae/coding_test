#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> v;

map<int, int> l;
map<int, int> r;

int main(void)
{
	int n;
	int target;
	cin >> n >> target;
	
	for(int i = 0; i < n; ++i)
	{
		int s;
		cin >> s;
		
		v.push_back(s);
	}
	
	int targetidx = 0;
	
	for(int i = 0; i < n; ++i)
	{
		if(v[i] == target)
		{
			targetidx = i;
			break;
		}
	}
	
	int g, G;
	g = G = 0;
	int ans = 0;
	
	for(int i = targetidx - 1; i >= 0; --i)
	{
		if(v[targetidx] > v[i])
			g++;
		else
			G++;
		
		l[g - G]++;
	}
	
	g = G = 0;
	
	for(int i = targetidx + 1; i < v.size(); ++i)
	{
		if(v[targetidx] > v[i])
			g++;
		else
			G++;
		
		r[G - g]++;
	}
	
	l[0]++;
	r[0]++;
	
	for(auto [i,j] : l){
		ans += r[i]*j;
	}
	
	cout << ans;
}