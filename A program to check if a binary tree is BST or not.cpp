A program to check if a binary tree is BST or not.
  
A better solution looks at each node only once. The trick is to write a utility helper function isBSTUtil(struct node* node, int min, int max) that
traverses down the tree keeping track of the narrowing min and max allowed values as it goes, looking at each node only once. 
The initial values for min and max should be INT_MIN and INT_MAX — they narrow from there. 
  
Follow the below steps to solve the problem:

Call isBstUtil function for the root node and set minimum value as INT_MIN and maximum value as INT_MAX
If the current node is NULL then return true
If the value of the node is less than the minimum value possible or greater than the maximum value possible then return false
Call the same function for the left and the right subtree and narrow down the minimum and maximum values for these calls accordingly

// code

#include <bits/stdc++.h>
using namespace std;

class node {
public:
	int data;
	node* left;
	node* right;

	node(int data)
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

int isBSTUtil(node* node, int min, int max);

int isBST(node* node)
{
	return (isBSTUtil(node, INT_MIN, INT_MAX));
}

int isBSTUtil(node* node, int min, int max)
{
	/* an empty tree is BST */
	if (node == NULL)
		return 1;


	if (node->data < min || node->data > max)
		return 0;

	return isBSTUtil(node->left, min, node->data - 1)
		&& // Allow only distinct values
		isBSTUtil(node->right, node->data + 1,
					max); // Allow only distinct values
}

int main()
{
	node* root = new node(4);
	root->left = new node(2);
	root->right = new node(5);
	root->left->left = new node(1);
	root->left->right = new node(3);

	// Function call
	if (isBST(root))
		cout << "Is BST";
	else
		cout << "Not a BST";

	return 0;
}



