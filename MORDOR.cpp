#include <iostream>
#include<vector>

using namespace std;

vector<int> h;

typedef struct Node
{
	int maxHeight;
	int minHeight;
}node;

vector<node> v;

int max(int n1, int n2)
{
	if(n1 > n2)
		return n1;

	return n2;
}

int min(int n1, int n2)
{
	if(n1 < n2)
		return n1;

	return n2;
}

node init(int left, int right, int nodePos)
{
	node newNode;

	if(left == right)
	{
		newNode.maxHeight = h[left];
		newNode.minHeight = h[left];
		
		v[nodePos] = newNode;
		
		return newNode;
	}

	int mid = (left + right) / 2;

	node l = init(left, mid, nodePos * 2);
	node r = init(mid + 1, right, nodePos * 2 + 1);
	
	newNode.maxHeight = max(l.maxHeight, r.maxHeight);
	newNode.minHeight = min(l.minHeight, r.minHeight);

	v[nodePos] = newNode;
	
	return newNode;
}

//				질의 구간 
node lastQuery(int left, int right, int nodeLeft, int nodeRight, int nodePos)
{
	if(right < nodeLeft || nodeRight < left)
	{
		node newNode;
		newNode.maxHeight = -1;
		newNode.minHeight = 987654321;
		return newNode;
	}

	//완전 포함된 경우 
	if( left <= nodeLeft && nodeRight <= right)
	{
		return v[nodePos];
	}

	int mid = (nodeLeft + nodeRight) / 2;

	node l = lastQuery(left, right, nodeLeft, mid, nodePos * 2);
	node r = lastQuery(left, right, mid + 1, nodeRight, nodePos * 2 + 1);

	node newNode;
	newNode.maxHeight = max(l.maxHeight, r.maxHeight);
	newNode.minHeight = min(l.minHeight, r.minHeight);

	return newNode;
}

int query(int left, int right)
{
	node newNode = lastQuery(left, right, 0, h.size() - 1, 1);

	return newNode.maxHeight - newNode.minHeight;
}

int main(void)
{
	int tc;
	cin >> tc;

	for(int test = 0; test < tc; ++test)
	{
		int n, q;
		cin >> n >> q;

		h.clear();
		v.clear();

		for(int i = 0; i < n; ++i)
		{
			int height;
			cin >> height;
			h.push_back(height);
		}

		v.resize(h.size() * 4);

		init(0, h.size() - 1, 1);

		int answer = 0;

		for(int i = 0; i < q; ++i)
		{
			int q1, q2;
			cin >> q1 >> q2;

			cout << query(q1, q2) << "\n";
		}

	}
}
