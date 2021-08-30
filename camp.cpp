#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int s[5005][5005];

int min(int n1, int n2)
{
	if(n1 < n2)
		return n1;

	return n2;
}

int max(int n1, int n2)
{
	if(n1 > n2)
		return n1;

	return n2;
}

void partial_sum(int n)
{
	for(int i = 1; i < n; ++i)
		s[0][i] = s[0][i - 1] + s[0][i];

	for(int i = 1; i < n; ++i)
		s[i][0] = s[i][0] + s[i-1][0];

	for(int i = 1; i < n; ++i)
	{
		for(int j = 1; j < n; ++j)
		{
			s[i][j] = s[i][j] + s[i-1][j] + s[i][j-1] - s[i-1][j-1];
		}
	}
}
int search(vector<vector<int>> data)
{
	int answer = 0;
	vector<int> y;
	vector<int> x;

	for(int i = 0; i < data.size(); ++i)
	{
		y.push_back(data[i][0]);
		x.push_back(data[i][1]);
	}
	
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());

	x.erase(unique(x.begin(), x.end()), x.end());
	y.erase(unique(y.begin(), y.end()), y.end());

	for(int i = 0; i < data.size(); ++i)
	{
		for(int j = 0; j < x.size(); ++j)
		{
			if(data[i][0] == x[j])
			{
				data[i][0] = j + 1;
				break;
			}
		}
		
		for(int j = 0; j < y.size(); ++j)
		{
			if(data[i][1] == y[j])
			{
				data[i][1] = j + 1;
				break;
			}
		}
	}


	for(int i = 0; i < data.size(); ++i)
	{
		s[data[i][0]][data[i][1]] = 1;		//쇄기가 존재함
	}//전처리 
	
	for(int i = 0; i < 6; ++i)
	{
		for(int j = 0; j < 6; ++j)
			cout << s[i][j] << " ";

		cout << endl;
	}

	cout << endl;

	partial_sum(data.size());

	for(int i = 0; i < 6; ++i)
	{
		for(int j = 0; j < 6; ++j)
			cout << s[i][j] << " ";

		cout << endl;
	}

	for(int i = 0; i < data.size(); ++i)
	{
		//query
		for(int j = i + 1; j < data.size(); ++j)
		{
			if(data[i][0] == data[j][0] || data[i][1] == data[j][1])
				continue;

			int sx = min(data[i][1], data[j][1]);
			int sy = min(data[i][0], data[j][0]);
			int ex = max(data[i][1], data[j][1]);
			int ey = max(data[i][0], data[j][0]); 

			int can = s[ey][ex] - s[sy-1][ex] - s[ey][sx-1] + s[sy-1][sx-1] - 2;

			cout << i << " " << j << " " << sx << " " << ex << " " << sy << " " << ey << endl;
			if(can == 0)
				++answer;
		}
	}

	return answer;
}
int main(void)
{
	int tc = 1;
	vector<vector<int>> data;

	int n;
	cin >> n;


	for(int i = 0; i < n; ++i)
	{
		vector<int> v;
		for(int j = 0; j < 2; ++j)
		{
			int s;
			cin >> s;

			v.push_back(s);
		}

		data.push_back(v);
	}

	cout << search(data) << endl;
}
