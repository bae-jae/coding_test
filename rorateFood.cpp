#include <iostream>
#include <vector>

using namespace std;

vector<int> map;

int visited[3005];

int main(void)
{
	int n, d, k, c;
	cin >> n >> d >> k >> c;


	for(int i = 0; i < n; ++i)
	{
		int s;
		cin >> s;

		map.push_back(s);
	}

	for(int i = 0; i < k - 1; ++i)
		map.push_back(map[i]);

	int ans = 0;

	cout << endl;


	for(int i = 0; i < k; ++i)
	{
		if(visited[map[i]] == 0)
			++ans;

		++visited[map[i]];
	}

	int count = ans;

	if(visited[c] == 0)
		++ans;

	cout << count << " " << ans << endl;

	for(int start = k; start < map.size(); ++start)
	{
		int food = map[start];
		int undo = map[start - k];
		
		--visited[undo];

		if(visited[undo] == 0)
			--count;

		if(visited[food] == 0)
			++count;

		++visited[food];

		if(visited[c] == 0)
			ans = max(ans, count + 1);
		else
			ans = max(ans, count);

		cout << start << " " << ans << endl;
	}

	cout << ans;
}
