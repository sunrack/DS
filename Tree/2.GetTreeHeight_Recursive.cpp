#include <iostream>
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

	cout<<GetTreeHeight_Recursive(root)<<endl;
}