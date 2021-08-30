#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int longest = 0;

typedef struct treeNode{
	int x;
	int y;
	int r;
	vector<struct treeNode> child;
}node;

float getDis(int x1, int y1, int x2, int y2)
{
	return sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
}

void makeTree(node * p, node subNode)
{
	int n = p->child.size();

	if(n == 0)		//아직 자식이 없다면 
	{
		p->child.push_back(subNode);
		return;
	}
	else
	{
		for(int i = 0; i < n; ++i)
		{
			 float dis = getDis(subNode.x, subNode.y, p->child[i].x, p->child[i].y);

			 if(p->child[i].r >= dis)		//범위안에 포함하고 있으면 
			 {
				 makeTree(&(p->child[i]), subNode);	//넣을곳 탐색하로 떠남 
				 return;
			 }
			 else if(subNode.r >= dis)
			 {
				 subNode.child.push_back(p->child[i]);
				 p->child[i] = subNode;
				 return;
			 }
		}
	}
	//범위 안에는 걸리는데 자식중에 포함 할 수 있는게 없을 경우
	p->child.push_back(subNode);
	return;

}

int max(int n1,int n2)
{
	if(n1 > n2)
		return n1;

	return n2;
}

int findHeight(node * root)
{
	int h = 0;
	int hidx = -1;

	vector<int> result;

	for(int i = 0; i < root->child.size(); ++i)
	{
		result.push_back(findHeight(&(root->child[i])));
	}

	if(result.size() == 0)
		return 0;

	sort(result.begin(), result.end());

	if(result.size() >= 2)
		longest = max(longest, 2 + result[result.size() - 1] + result[result.size() - 2]);

	return result.back() + 1;
}

int main(void)
{
	int tc;
	cin >> tc;

	for(int test = 0; test < tc; ++test)
	{
		int n;
		cin >> n;

		node root;

		for(int i = 0; i < 1; ++i) 
		{
			int x, y, r;
			cin >> x >> y >> r;

			node sub;
			
			sub.x = x;
			sub.y = y;
			sub.r = r;

			root = sub;
		}

		for(int i = 1; i < n; ++i) 
		{
			int x, y, r;
			cin >> x >> y >> r;

			node sub;
			
			sub.x = x;
			sub.y = y;
			sub.r = r;

			makeTree(&root, sub);

			//cout << root.child.size() << endl;
		}
		longest = 0;
		longest = max(longest, findHeight(&root));
		cout << longest << "\n";
	}
}
