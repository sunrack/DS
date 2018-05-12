#include <iostream>
using namespace std;

struct Node
{
	int key;
	Node *left;
	Node *right;

	Node(int k)
	{
		key = k;
		left = NULL;
		right = NULL;
	}
};

void InOrder(Node *root)
{
	if(root == NULL)
	{
		return;
	}

	InOrder(root->left);
	cout<<root->key<<" ";
	InOrder(root->right);
}

//----------------------------------------------------------------------

Node *Min(Node *root)
{
	Node *node = root;

	while(node != NULL && node->left != NULL)
	{
		node = node->left;
	}

	return node;
}

Node *Max(Node *root)
{
	Node *node = root;

	while(node != NULL && node->right != NULL)
	{
		node = node->right;
	}

	return node;
}

// max of left should < current
// min of right should > current
bool IsBST_RE(Node *root)
{
	if(root == NULL)
	{
		return true;
	}

	if((root->left != NULL) && (root->key < Max(root->left)->key))
	{
		return false;
	}

	if((root->right != NULL) && (root->key > Min(root->right)->key))
	{
		return false;
	}

	if(!IsBST_RE(root->left) || !IsBST_RE(root->right))
	{
		return false;
	}

	return true;
}

//----------------------------------------------------------------------
// 1. In order tranversal
// 2. keep the previously visited node (last)
// 3. if not left return false
// 4. if current < last then return false
// 5. last = current 
// 6. if not right return false
// 7. return true
bool IsBST_InOrder(Node *root)
{
	static Node *last = NULL;

	if(root == NULL)
	{
		return true;
	}

	if(!IsBST_InOrder(root->left))
	{
		return false;
	}

	if(last != NULL && root->key < last->key)
	{
		return false;
	}

	last = root;

	if(!IsBST_InOrder(root->right))
	{
		return false;
	}

	return true;
}

//----------------------------------------------------------------------

int main()
{
	/*
           4
      2        5
	1   3
	*/
	Node *root;
	root = new Node(4);
	root->left = new Node(2);
	root->right = new Node(5);
	root->left->left = new Node(1);
	root->left->right = new Node(3);

	InOrder(root);
	cout<<endl<<"IsBST_RE: "<<IsBST_RE(root)<<endl;
	cout<<"IsBST_InOrder: "<<IsBST_InOrder(root)<<endl;


	/*
           6
      2        4
	1   3
	*/

	root = new Node(6);
	root->left = new Node(2);
	root->right = new Node(4);
	root->left->left = new Node(1);
	root->left->right = new Node(3);

	InOrder(root);
	cout<<endl<<"IsBST_RE: "<<IsBST_RE(root)<<endl;
	cout<<"IsBST_InOrder: "<<IsBST_InOrder(root)<<endl;

		/*
           4
      3        6
	1   5
	*/

	root = new Node(4);
	root->left = new Node(3);
	root->right = new Node(6);
	root->left->left = new Node(1);
	root->left->right = new Node(5);

	InOrder(root);
	cout<<endl<<"IsBST_RE: "<<IsBST_RE(root)<<endl;
	cout<<"IsBST_InOrder: "<<IsBST_InOrder(root)<<endl;
}