#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <string.h>

using namespace std;

int w,h;
string map[105];

int visited[105][105];

int key;
int ans;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = { 0, 0,-1, 1};

int outRange(int y, int x)
{
	if(y < 0 || y >= h)
		return 0;

	if(x < 0 || x >= w)
		return 0;

	return 1;
}

void bfs(int startY, int startX)
{
	queue<pair<int, int>> q;

	visited[startY][startX] = 1;
	q.push({startY, startX});

	while(!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;

		q.pop();

		if(map[y][x] == '$')
		{
			map[y][x] = '.';
			++ans;
		}


		for(int i = 0; i < 4; ++i)
		{
			int my = y + dy[i];
			int mx = x + dx[i];


			if(outRange(my, mx) == 1 && visited[my][mx] == 0 && map[my][mx] != '*')
			{
				char nowPos = map[my][mx];

				if(nowPos == '.' || nowPos == '$')
				{
					visited[my][mx] = 1;
					q.push({my, mx});
				}

				if('a' <= nowPos && nowPos <= 'z')
				{
					int temp_key = key & (1 << (nowPos - 'a'));

					if(temp_key == 0)
					{
						key = key | (1 << (nowPos - 'a'));
						memset(visited, 0, sizeof(visited));
					}

					visited[my][mx] = 1;
					q.push({my, mx});
				}

				if('A' <= nowPos && nowPos <= 'Z')
				{
					int temp = key & (1 << (nowPos - 'A'));

					if(temp != 0)
					{
						visited[my][mx] = 1;
						q.push({my, mx});
					}
				}
			}
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
		ans = 0;
		key = 0;
		memset(visited, 0, sizeof(visited));

		cin >> h >> w;

		string mm(w + 2, '.');

		map[0] = mm;

		for(int i = 1; i <= h; ++i)
		{
			string s;
			cin >> s;

			s = '.' + s + '.';

			map[i] = s;
		}

		map[h + 1] = mm;

		w += 2;
		h += 2;

		cout << "map" << endl;

		for(int i = 0; i < h; ++i)
		{
			cout << map[i] << endl;
		}

		cout << endl;

		string keyList;
		cin >> keyList;

		for(int i = 0; i < keyList.size(); ++i)
		{
			if(keyList[i] == '0')
			{
				break;
			}
		
			key = key | (1 << (keyList[i] - 'a'));
		}

		bfs(0, 0);

		cout << ans << "\n";
	}
}
