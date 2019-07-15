#include <bits/stdc++.h>

using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
};

void inorder(Node* root)
{
	if(root != NULL)
	{
		inorder(root->left);
		cout << " " << root->data << " ";
		inorder(root->right);
	}
}

void preorder(Node* root)
{
	if(root != NULL)
	{
		cout << " " << root->data << " ";
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(Node* root)
{
	if(root != NULL)
	{
		postorder(root->left);
		postorder(root->right);
		cout << " " << root->data << " ";
	}
}

Node* insert(Node* root, int value)
{
	Node* newNode = new Node;
	newNode->data = value;
	newNode->left = NULL;
	newNode->right = NULL;

	if (root == NULL)
	{
		return newNode;
	}
	if(root->data < value)
	{
		root->right = insert(root->right, value);
	}
	else if( root->data > value)
	{
		root->left = insert(root->left, value);
	}
	return root;
}

void deleteNode(Node* root, int value)
{
	if(root == NULL)
	{
		return ;
	}
	Node* leftChild = root->left;
	Node* rightChild = root->right;

	if(root->data < value)
	{
		if(rightChild->data == value)
		{
			root->right = NULL;
			return ;
		}
		deleteNode(root->right, value);
	}
	else if(root->data > value)
	{
		if(leftChild->data == value)
		{
			root->left = NULL;
			return ;
		}
		deleteNode(root->left, value);
	}
	else
	{
		root = NULL;
		return ;
	}
}

int main()
{
	Node* root = NULL;
	root = insert(root, 50);
	insert(root, 20);
	insert(root, 60);
	insert(root, 40);
	insert(root, 70);
	inorder(root);
	cout << endl;
	preorder(root);
	cout << endl;
	postorder(root);
	cout << endl;
	deleteNode(root, 70);
	inorder(root);
	return 0;
}