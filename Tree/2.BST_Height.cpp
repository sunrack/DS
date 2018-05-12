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
int GetTreeHeight_Recursive(Node *root)
{
	if(root == NULL)
	{
		return -1;
	}
	else
	{
		int hL = GetTreeHeight_Recursive(root->left);
		int hR = GetTreeHeight_Recursive(root->right);

		// get the highest child
		if(hL > hR)
		{
			return (hL + 1);
		}
		else
		{
			return (hR + 1);
		}
	}
}

//---------------------------------------------------------------
// the height is the # of edges on the longest path
// O(n)
//
// 1. if root == NULL, return 0
// 2. push first level into queue
// 3. process current level(count = queue size): pop each node and push its children
//    when done, if still has node for next level(queue is not empty), height++
// 4. return height
//

int GetTreeHeight_Iterative(Node *root)
{
	int height = 0;
	queue<Node *> list;

	if(root == NULL)
	{
		return height;
	}

	// queue first level
	list.push(root);

	while(!list.empty())
	{
		int count = list.size();

		while(count > 0)
		{
			// pop current level and push their children
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

		// still has nodes for next level
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

	cout<<"Iterative = "<<GetTreeHeight_Iterative(root)<<endl;


	cout<<"Recursive = "<<GetTreeHeight_Recursive(root)<<endl;
}