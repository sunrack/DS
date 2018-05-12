#include <iostream>
using namespace std;

//-----------------------------------------------------

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

void BST_Print(Node *root)
{
	if(root == NULL)
	{
		return;
	}
	
	BST_Print(root->left);
	cout<<root->key<<" ";
	BST_Print(root->right);
}

Node *GetBST()
{
	/*
		  4
	   /     \
	  2       6
	 / \     
	1   3   

	*/

	Node *root = new Node(4);
	root->left = new Node(2);
	root->right = new Node(6);

	root->left->left = new Node(1);
	root->left->right = new Node(3);

	return root;
}

//---------------------------------------------------------------------------------
// Recursively insert key into a subtree(node)
// 1. if node == NULL,  node = new Node
// 2. if node != NULL
// 		if key == node, no recursive call
// 		if key < node, node.left = f(node.left)
//      if key > node, node.right = f(node.right)
// 3. return note (so previous call can set left/right properly)

Node *BST_Insert_RE(Node *node, int key)
{
	if(node == NULL)
	{
		node = new Node(key);
	}
	else
	{
		if(key < node->key)
		{
			node->left = BST_Insert_RE(node->left, key);
		}
		else if(key > node->key)
		{
			node->right = BST_Insert_RE(node->right, key);
		}
		else
		{
			// if exsiting, no change (no further call) and start to stack back
		}
	}

	// return node itself 
	return node;
}

//---------------------------------------------------------------------------------
// Iteratively insert key into a subtree with node as root
// 1. if root == NULL, return new node
// 2. if root != NULL
//      find the NULL leaf node and it's parent
// 		if existing, return NULL
// 3. new node and update parent
// 4. return the newed node 

Node *BST_Insert_IT(Node *root, int key)
{
	if(root == NULL)
	{
		return new Node(key);
	}

	Node *node = root;
	Node *parent = NULL;

	while(node != NULL)
	{
		if(key == node->key)
		{
			return NULL;
		}
		else if(key < node->key)
		{
			parent = node;
			node = node->left;
		}
		else if(key > node->key)
		{
			parent = node;
			node = node->right;
		}
	}

	node = new Node(key);

	if(parent->key > key)
	{
		parent->left = node;
	}	
	else
	{
		parent->right = node;
	}

	return node;
}

//---------------------------------------------------------------------------------

int main()
{
	cout<<endl<<"Recursive-------------------------------"<<endl;
	Node *root = GetBST();

	BST_Print(root);
	cout<<endl;
	
	//insert a new node
	BST_Insert_RE(root, 5);
	BST_Print(root);
	cout<<endl;
	
	//insert an existing node
	BST_Insert_RE(root, 3);
	BST_Print(root);
	cout<<endl;

	//---------------------------------------
	cout<<endl<<"Iterative-------------------------------"<<endl;
	Node *root1 = GetBST();

	BST_Print(root1);
	cout<<endl;
	
	//insert a new node
	BST_Insert_IT(root1, 5);
	BST_Print(root1);
	cout<<endl;
	
	//insert an existing node
	BST_Insert_IT(root1, 3);
	BST_Print(root1);
	cout<<endl;
}