#include <iostream>
#include "../utility/printCollection.h"
using namespace std;

struct bsnode{
	int data;
	bsnode* left;
	bsnode* right;
};

void add_bsnode(bsnode* &root, int value)
{
	if(root == NULL)
	{
		bsnode* tmp = new bsnode();
		tmp->data = value;
		tmp->left = NULL;
		tmp->right = NULL;
		root = tmp;
		return;
	}
	if(value > root->data)
		add_bsnode(root->right, value);
	else if(value < root->data)
		add_bsnode(root->left, value);
	else
		cout << "duplicate value" << endl;
}

void print_tree(bsnode* root)
{
	if(root == NULL)
		return;
	if(root->left != NULL)
		print_tree(root->left);
	cout << root->data << " ";
	if(root->right != NULL)
		print_tree(root->right);
}


void check_node(bsnode* root, int n, int &depth, vector<int> &path)
{
	//如果当前深度>n，不需要继续访问
	if(depth > n || root == NULL)
		return;

	//检查前压栈当前节点，depth+1
	path.push_back(root->data);
	depth++;

	//如果当前深度=n
	if(depth == n)
		if(root->left == NULL && root->right == NULL)
		{
			cout << "path found: " << endl;
			printCollection(path);
			cout << endl;			
		}

	//如果当前深度<n
	if(depth < n)
		if(root->left != NULL)
			check_node(root->left, n, depth, path);
		if(root->right != NULL)
			check_node(root->right, n, depth, path);

	//检查完出栈当前节点，depth-1
	path.pop_back();
	depth--;
	return;
}

void print_node(bsnode* root, int n)
{
	if(root == NULL)
		return;

	//每次检查前重定义depth
	int depth = -1;
	vector<int> path;

	//每次检查前clear path
	path.clear();

	//检查当前节点的所有叶子节点的高度
	check_node(root, n, depth, path);
	
	//递归检查左子树
	print_node(root->left, n);
	//递归检查右子树
	print_node(root->right, n);
}


int main()
{
	bsnode* root = NULL;
	add_bsnode(root, 10);	
	add_bsnode(root, 6);
	add_bsnode(root, 16);
	add_bsnode(root, 4);
	add_bsnode(root, 8);
	add_bsnode(root, 14);
	add_bsnode(root, 18);
	add_bsnode(root, 2);
	add_bsnode(root, 5);
	add_bsnode(root, 12);
	add_bsnode(root, 15);
	add_bsnode(root, 20);
	add_bsnode(root, 11);

	cout << "Tree content: " << endl;
	print_tree(root);
	cout << endl << endl;

	int height = 2; 
	cout << "Nodes that with height " << height << " are:" << endl;
	print_node(root, height);
	cout << endl;
}
