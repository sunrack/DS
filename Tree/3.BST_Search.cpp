#include <iostream>
using namespace std;

//------------------------------------------------

Node *BST_Search_IT(int Node *root, int key)
{
	Node *node = root;

	while((node != NULL) && (key != node->data))
	{
		if(key < node->data)
		{
			node = node->left;
		}
		else
		{
			node = node->right;
		}
	}

	return node;
}

//------------------------------------------------

Node *BST_Search_RE(int Node *root, int key)
{
	if(root == NULL || root->data == key)
	{
		return root;
	}

	if(key < node->data)
	{
		return BST_Search_RE(root->left);
	}
	else
	{
		return BST_Search_RE(root->right);
	}
}

