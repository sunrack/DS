#include <iostream>
#include <queue>
using namespace std;

// https://onlinegdb.com/SJII8umRM

//---------------------------------------------------------------

struct Node
{
	int data;
	Node *left;
	Node *right;

	Node(int d)
	{
		data = d;
		left = NULL;
		right = NULL;
	}
};

//---------------------------------------------------------------

// the height is the # of edges on the longest path
// O(n)
int GetTreeHeight_Iterative(Node *root)
{
	int height = 0;
	queue<Node *> list;

	if(root == NULL)
	{
		return height;
	}

	list.push(root);

	while(!list.empty())
	{
		int count = list.size();

		while(count > 0)
		{
			Node *node = list.front();
			list.pop();
			count--;

			if(node->left != NULL)
			{
				list.push(node->left);
			}

			if(node->right != NULL)
			{
				list.push(node->right);
			}
		}

		if(!list.empty())
		{
			height++;
		}
	}

	return height;
}

/*

queue 	height 		count
1			0			1
2 3			0			0

2 3			1			2
3 4 5		1			1
4 5 		1			0

4 5 		2			2
5			2			1
_			2			0
*/


//---------------------------------------------------------------

int main()
{
	//		    1
	//	   2		3
	// 4	  5
	//
	Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->right->right = new Node(5);

	cout<<GetTreeHeight_Iterative(root)<<endl;
}