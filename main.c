#include "Header.h"


int main()
{
	char val[11], *min;
	int num, height,n;
	Tree *root= NULL;
	printf("MENU: \n");
	printf("1. add node to tree\n2. print tree's data values (postorder) \n3.calculate and present tree hight\n");
	printf("4. present the minimum key value\n5. find specific key value in the tree\n");
	printf("Enter 6 to end the program\n");
	printf("\nPlease select number between 1-5, and for exit press 6: ");
	scanf("%d", &num);
		while (num != 6)    /*if the user choose 6 the program end*/
		{
			// if the user choose 1 - then ask for a key and insert a node with the key value to the tree
			//if there's already a node with the same key, increase the counter of this node
			if (num == 1)
			{
				n = 0;
				printf("Please enter key (string): ");
				scanf("%s", val);
				if (Search_elem(root, val) == 0)
					n++;
				add_node(&root, val);   /*calling add node function*/
				if (n == 1)
					printf("the node has been successfully added");
				else
					printf("The node was not added because the key already exists in the tree");


			}
			else if (num == 2)
			{
				printf("printing postorder keys:\n");
				postorder_print(root);     /*calling printing in postorder function*/

			}
			else if (num == 3)
			{
				height = treeHight(root);   /*calling the calculating hight function and present tree's hight*/
				if (height == -1)
					printf("The tree is empty his height is %d\n", height);
				else
					printf("Tree height is %d\n", height);

			}
			else if (num == 4)
			{
			    min = find_min(root);   /*calling the function that present the minimum value in the tree*/
				if (min ==NULL)
				{
					printf("Tree is empty, theres no minimum value\n");
				}
				else
				{
					printf("Minimum key value is: %s\n", min);   
				}
			}
			else if (num == 5)
			{
				printf("Please enter key (string, max 10 letters): ");
				scanf("%s", val);
				if (Search_elem(root, val))     /*calling the function that searching value in the tree */
				{
					printf("the value is exist");
				}
				else
				{
					printf("the value not exist");
				}
			}
			/*if the user select wrong digit (not 1-6)*/
			else
			{
				printf("\nwrong number, please choose another number in the range 1-5, or 6 for EXIT");
			}
			    printf("\n\nMENU: \n");
			    printf("1. add node to tree\n2. print tree's data values (postorder) \n3.calculate and present tree hight\n");
			    printf("4. present the minimum key value\n5. find specific key value in the tree\n");
			    printf("Enter 6 to end the program\n");
			    printf("\nPlease select number between 1-5, and for exit press 6: ");
				rewind(stdin);
			    scanf("%d", &num);

		}
		printf("\nThe program is over\nThank you!");
		free_tree(&root);  //free the nodes in the tree

	return 0;
}


	























	

