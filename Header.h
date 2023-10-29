#ifndef HEADER_H
#define HEADER_H
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Tree
{
	char val[11];
	int count;
	struct Tree* left;
	struct Tree* right;
}Tree;

//functions declarations
void add_node(Tree* root, char *val);
void postorder_print(Tree* root);
int treeHight(Tree* root);
char* find_min(Tree* root);
int Search_elem(Tree* root, char *val);
void free_tree(Tree** root);

#endif