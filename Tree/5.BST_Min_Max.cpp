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
} ;

Node *BST_FindMin_IT(Node *root)
{
	Node *node = root;

	while(node != NULL and node->left != NULL)
	{
		node = node->left;
	}

	return node;
}

Node *BST_FindMin_RE(Node *root)
{
	if (root == NULL || root->left == NULL)
	{
		return root;
	}

	return BST_FindMin_RE(root->left);
}

Node *BST_FindMax_IT(Node *root)
{
	Node *node = root;

	while(node != NULL and node->right != NULL)
	{
		node = node->right;
	}

	return node;
}

Node *BST_FindMax_RE(Node *root)
{
	if (root == NULL || root->right == NULL)
	{
		return root;
	}

	return BST_FindMin_RE(root->right);
}

int main()
{
	/*
           4
      2        5
	1   3
	*/
	Node *root = new Node(4);
	root->left = new Node(2);
	root->right = new Node(5);

	root->left->left = new Node(1);
	root->left->right = new Node(3);

	Node *min = BST_FindMin_IT(root);
	cout<<"Min Iterative: "<<min->key<<endl;


	min = BST_FindMin_RE(root);
	cout<<"Min Recursive: "<<min->key<<endl;

	Node *max = BST_FindMax_IT(root);
	cout<<"Max Iterative: "<<max->key<<endl;


	max = BST_FindMax_RE(root);
	cout<<"Max Recursive: "<<max->key<<endl;
}