#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
vector<int> mistake;
vector<int> psum;

int main(void)
{
	int n;
	cin >> n;
	
	for(int i = 0; i < n; ++i)
	{
		int s;
		cin >> s;
		
		v.push_back(s);
	}
	
	mistake.push_back(0);
	psum.push_back(0);
	//더미를 둘다 주고
	
	for(int i = 0; i < v.size() - 1; ++i)
	{
		if(v[i] <= v[i + 1])
		{
			mistake.push_back(0);
		}
		else
			mistake.push_back(1);
	}
	
	mistake.push_back(0);	//마지막은 실수를 안함
	
	for(int i = 1; i < mistake.size(); ++i)
		psum.push_back(psum[i-1] + mistake[i]);
	
	
	for(int i = 0; i < psum.size(); ++i)
		cout << psum[i] << " ";
	
	
	int q;
	cin >> q;
	
	for(int i = 0; i < q; ++i)
	{
		int x, y;
		cin >> x >> y;
		
		if(x == y)
		{
			cout << 0 << "\n";
			continue;
		}
		else{
			int ans = psum[y] - psum[x - 1];
			
			if(mistake[y] == 1)
				--ans;
			
			cout << ans << endl;
			
		}
	}
	
}