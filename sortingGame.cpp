#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <map>

using namespace std;

map<vector<int>, int> answerList;

vector<int> makeNode(vector<int>& v, int start, int end)
{
	vector<int> newNode;

	for(int i = 0; i < v.size(); ++i)
	{
		newNode.push_back(v[i]);
	}

	for(int i = 0; i <= (end - start); ++i)
		newNode[start + i] = v[end - i];

	return newNode;
}

vector<int> changeRelative(vector<int> v)
{
	vector<int> rel;
	
	for(int i = 0; i < v.size(); ++i)
	{
		int smaller = 1;

		for(int j = 0; j < v.size(); ++j)
		{
			//i가 비교대상 j가 얼마나 있는지 
			if((i != j) && (v[i] > v[j]))
				++smaller;
		}

		rel.push_back(smaller);
	}

	return rel;
}

void search(void)
{
	vector<int> org;

	for(int i = 1; i <= 8; ++i)
		org.push_back(i);

	queue<vector<int>> q;

	answerList[org] = 0;
	q.push(org);

	while(!q.empty())
	{
		vector<int> key = q.front();
		q.pop();
		int cnt = answerList[key];

		//for(int i = 0; i < key.size(); ++i)
		//	cout << key[i] << " ";
		//cout << endl;

		for(int i = 0; i < 8; ++i)
		{
			for(int j = i + 1; j < 8; ++j)
			{
				vector<int> node = makeNode(key, i ,j);

		//		for(int k = 0; k < node.size(); ++k)
		//			cout << node[k] << " ";
		//		cout <<"asd"<< endl;

				if(answerList.count(node) == 0)
				{
					answerList[node] = cnt + 1;
					q.push(node);
				}
			}
		}

	}
}

int main(void)
{
	int tc;
	cin >> tc;
	search();

	for(int test = 0; test < tc; ++test)
	{
		int n;
		cin >> n;
		
		vector<int> v;

		for(int i = 0; i < n; ++i)
		{
			int s;
			cin >> s;

			v.push_back(s);
		}

		v = changeRelative(v);

		for(int i = v.size() + 1; i <= 8; ++i)
		{
			v.push_back(i);
		}

		cout << answerList[v] << endl;

	}
}
