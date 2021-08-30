#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>

using namespace std;

vector<pair<int, int>> list;
int visited[101];
string ans;

void search(int nx, int ny, int fx, int fy)
{
	int dist = abs(fx - nx) + abs(fy - nx);

	if(dist <= 1000)
	{
		ans = "happy";
		return;
	}

	for(int i = 0; i < list.size(); ++i)
	{
		dist = abs(list[i].first - nx) + abs(list[i].second - ny);
		//cout << nx << " " << ny << " " << list[i].first << " " << list[i].second << " " << dist << endl;
		if(visited[i] == 0 && dist <= 1000)
		{
			visited[i] = 1;
			search(list[i].first, list[i].second, fx, fy);
		}
	}

	return;
}

int main(void)
{
	int tc;
	cin >> tc;

	for(int test = 0; test < tc; ++test)
	{
		memset(visited, 0, sizeof(visited));
		ans = "sad";
		list.clear();

		int n;
		cin >> n;

		int startx, starty;
		cin >> startx >> starty;

		for(int i = 0; i < n; ++i)
		{
			int x, y;
			cin >> x >> y;

			list.push_back(make_pair(x, y));
		}
		
		int endx, endy;
		cin >> endx >> endy;

		search(startx, starty, endx, endy);

		cout << ans << endl;
	}

}
