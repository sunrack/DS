#include <iostream>

struct Node
{
	int data,
	Node *left;
	Node *right;

	Node(int d)
	{
		data = d;
		left = NULL;
		right = NULL;
	}
};

int Height(Node *root)
{
	if(root == NULL)
	{
		return 0;
	}
	else
	{
		int h1 = Height(root->left);
		int hr = Height(root->right);

		if(h1 > hr)
		{`
			return (hl + 1);
		}
		else
		{
			return (hr + 1);
		}
	}
}

void main()
{
	Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->right->right = new Node(5);

	cout<<Height(root)<<endl;

}