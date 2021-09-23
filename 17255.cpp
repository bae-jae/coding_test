#include <iostream>
#include <string>
#include <map>

using namespace std;

string s;
map<string, int> m;
int ans = 0;

void search(string cand, string path, int left, int right)
{
	
	if(cand.size() == s.size())
	{
		if(m[path] == 0)
		{
			m[path] = 1;
			++ans;
		}
		
		return;
	}
	
	
	int ans = 0;
	
	if(left - 1 >= 0)
		search(s[left - 1] + cand, path + s[left - 1] + cand, left - 1, right);
	
	if(right + 1 < s.size())
		search(cand + s[right + 1], path + cand + s[right + 1], left, right + 1);
}

int main(void)
{
	cin >> s;
	
	
	for(int i = 0; i < s.size(); ++i)
	{
		string cand = "";
		
		search(cand + s[i], cand + s[i], i, i);
	}
	
	cout << ans;
}