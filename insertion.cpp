#include <iostream>
#include <vector>
#include <string.h>
#include <cstdlib>

using namespace std;
vector<int> v;

typedef struct Node{
	int pr;
	int key;
	int size;

	struct Node * left;
	struct Node * right;

	void setLeft(struct Node * n)
	{
		left = n;
		calcSize();
	}
	void setRight(struct Node * n)
	{
		right = n;
		calcSize();
	}

	void calcSize()
	{
		size = 1;

		if(left)
			size += left->size;
		if(right)
			size += right->size;
	}

}node;

typedef pair<node *, node *> nodePair;
		

vector<int> find_answer(int n)
{
	vector<int> answer;
	int arr[50001];
	memset(arr, 0, sizeof(arr));

	for(int i = v.size() - 1; i >= 0; --i)
	{
		int count = 0;

		for(int j = n; j >= 1; --j)
		{
			if((count == v[i]) && (arr[j] == 0))
			{
				arr[j] = -1;
				answer.push_back(j);
				break;
			}

			if(arr[j] == 0)
				++count;
		}
	}

	return answer;
}

nodePair split(node * root, int key)
{
	if(root == NULL)
		return nodePair(NULL, NULL);

	if(root->key < key)
	{
		nodePair np = split(root->right, key);
		root->setRight(np.first);
		return nodePair(root, np.second);
	}

	nodePair np = split(root->left, key);
	root->setLeft(np.second);
	return nodePair(np.first, root);
}

node * insert(node * root, node * target)
{
	if(root == NULL)
		return target;

	if(root->pr < target->pr) //바꿔야함 
	{
		nodePair splited = split(root, target->key);

		target->setLeft(splited.first);
		target->setRight(splited.second);

		return target;
	}
	else if(root->key > target->key)
		root->setLeft(insert(root->left, target));
	else
		root->setRight(insert(root->right, target));

	return root;
}

node * erase(node * root, int key)
{
	if(root == NULL)

}

int main(void)
{
	int tc;
	cin >> tc;

	for(int test = 0; test < tc; ++test)
	{
		int n;
		cin >> n;
		v.clear();

		node * root = new node();
		root->key = 1;
		root->pr = rand();

		for(int i = 2; i <= n; ++i)
		{
			node * newNode = new node();
			newNode->key = i;
			newNode->pr = rand();

			root = insert(root, newNode);
		}

		for(int i = 0; i < n; ++i)
		{
			int s;
			cin >> s;

			v.push_back(s);
		}

		vector<int> answer = find_answer(n);

		for(int i = 0; i < answer.size(); ++i)
			cout << answer[answer.size() -1 - i] << " " ;

		cout << "\n";
	}
}
