#include "Header.h"


//create new nodein the tree
void add_node(Tree** root, char* val)
{
	if (*root == NULL)
	{
		Tree* new_node = (Tree*)malloc(sizeof(Tree));
		if (new_node == NULL)
		{
			printf("Error allocating memory");
			exit(1);
		}
		strcpy(new_node->val, val);    /*copy the key value to the new node*/
		new_node->count = 1;
		new_node->left = NULL;
		new_node->right = NULL;
		*root = new_node;
		return;
	}

	int cmp = strcmp(val, (*root)->val);
	if (cmp < 0)
	{
		add_node(&((*root)->left), val);
	}
	else if (cmp > 0)
	{
		add_node(&((*root)->right), val);
	}
	else
	{
		(*root)->count++;
	}
}
//prints recursive all the keys of a binary trees in postorder 

void postorder_print(Tree* root)
{
	if (root == NULL)
	{
		return;
	}

	postorder_print(root->left);
	postorder_print(root->right);
	for (int i = 0; i < root->count; i++) {
		printf("%s ", root->val);
	}
}


/*returns the hight of a given tree*/
int treeHight(Tree* root)    
{
	int lh, rh;
	if (root == NULL)
		return -1;
	lh = treeHight(root->left);
	rh = treeHight(root->right);
	if (lh > rh)
		return 1 + lh;
	else
		return 1 + rh;
}



//Gets a string and checks if found in the tree if found returns 1 otherwise 0
int Search_elem(Tree* root, char* val)
{
	if (root == NULL)
	{
		return 0;    // value is not exist
	}
	if (strcmp(root->val, val) == 0)
	{
		return 1;   // value exist
	}
	if (strcmp(val, root->val) < 0)
	{
		return Search_elem(root->left, val); // search in the left subtree
	}
	else
	{
		return Search_elem(root->right, val); // search in the right subtree
	}
}


//the function return the minimum data in the binary tree
char* find_min(Tree* root)
{
	if (root == NULL)
	{
		// In case the tree is empty
		return ;
	}
	while (root->left != NULL)
	{
		// looping left until we find the minimum element, because the tree is binary we will search the value of the left child
		root = root->left;
	}
	return root->val; 
}


void free_tree(Tree** root)
{
	if (*root == NULL)
	{
		return;
	}

	free_tree(&((*root)->left));
	free_tree(&((*root)->right));
	free(*root);
	*root = NULL;
}




