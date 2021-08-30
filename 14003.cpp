#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> idx;

vector<int> list;
vector<int> ans;

int main(void)
{
	int n;
	int len = 0;
	cin >> n;
	
	for(int i = 0; i < n; ++i)
	{
		int s;
		cin >> s;
		
		ans.push_back(s);
		
		auto pos = lower_bound(list.begin(), list.end(), s);
		
		if(pos == list.end())
		{
			++len;
			list.push_back(s);
			
			idx.push_back(list.size());
		}
		else{
			
			list[pos - list.begin()] = s;
			idx.push_back(pos - list.begin() + 1);
		}
	}
	
	cout << len << "\n";
	
	vector<int> show;
	
	for(int i = idx.size() - 1; i >= 0; --i)
	{
		if(len == idx[i])
		{
			--len;
			show.push_back(ans[i]);
		}
		
		cout << idx[i] << " " << len << " " << ans[i] << endl;
		
		if(len == 0)
			break;
	}
	
	for(int i = show.size() -1; i >= 0; --i)
	{
		cout << show[i] << " ";
	}

}