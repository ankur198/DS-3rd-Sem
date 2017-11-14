#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>

struct Leaf
{
	int data;
	struct Leaf *left, *right, *parent;
};

int i, pos;
struct Leaf *root = NULL, *ptr, *newLeaf, *selectedLeaf;

void checkToMakeRoot()
{
	if (!root)
	{
		root = newLeaf;
		selectedLeaf = root;
		root->parent = NULL;
		pos = 0;
	}
}

void attachToParent()
{
	if (pos == 1)
	{
		selectedLeaf->left = newLeaf;
	}
	else if (pos == 2)
	{
		selectedLeaf->right = newLeaf;
	}

	if (newLeaf!=root)
	{
		newLeaf->parent = selectedLeaf;
	}
}

void createLeaf()
{
	newLeaf = (struct Leaf*)malloc(sizeof(struct Leaf));
	printf("\nEnter element: ");
	scanf("%d", &i);
	newLeaf->data = i;
	newLeaf->left = NULL;
	newLeaf->right = NULL;

	checkToMakeRoot();
	attachToParent();
}

void deleteLeaf(struct Leaf *leaf)
{
	struct Leaf *parent;
	if (leaf->left)
	{
		deleteLeaf(leaf->left);
	}
	if (leaf->right)
	{
		deleteLeaf(leaf->right);
	}
	if (leaf == root)
	{
		root = NULL;
		return;
	}
	parent = leaf->parent;
	if (leaf == parent->left)
	{
		parent->left = NULL;
	}
	else if (leaf == parent->right)
	{
		parent->right = NULL;
	}
	free(leaf);
	selectedLeaf = parent;
}

void resetSelectLeaf()
{
	selectedLeaf = NULL;
	if (root)
	{
		selectedLeaf = root;
	}
}

void printBranch()
{
	if (selectedLeaf)
	{
		system("cls");
		printf("\n\n\t\t %d\n\t\t/ \\\n\t       %d   %d", selectedLeaf->data,
			selectedLeaf->left ? selectedLeaf->left->data : 0,
			selectedLeaf->right ? selectedLeaf->right->data : 0);
	}
}

void selectLeaf()
{
	int ch = 0;
	while (ch != 7)
	{
		if (selectedLeaf && root)
		{
			printBranch();
			printf("\n\n\n");
			if (selectedLeaf->left != NULL)
			{
				printf("1.Select leaf %d", selectedLeaf->left->data);
			}
			else
			{
				printf("1.Insert at left");
			}
			printf("\n");
			if (selectedLeaf->right != NULL)
			{
				printf("2.Select leaf %d", selectedLeaf->right->data);
			}
			else
			{
				printf("2.Insert at right");
			}
			printf("\n3. Edit current");
			printf("\n4. Go up\n5. Goto root\n6.Delete\n7. Exit");

			printf("\nEnter choice: ");
			scanf("%d", &i);
			ch = i;

			switch (i)
			{
			case 1:
				if (selectedLeaf->left)
				{
					selectedLeaf = selectedLeaf->left;
				}
				else
				{
					pos = 1;
					createLeaf();
				}
				break;
			case 2:
				if (selectedLeaf->right)
				{
					selectedLeaf = selectedLeaf->right;
				}
				else
				{
					pos = 2;
					createLeaf();
				}
				break;
			case 3:
				printf("\n\nEnter new value: ");
				scanf("%d", &i);
				selectedLeaf->data = i;
				break;
			case 4:
				if (selectedLeaf != root)
				{
					selectedLeaf = selectedLeaf->parent;
				}
				break;
			case 5:
				resetSelectLeaf();
				break;
			case 6:
				deleteLeaf(selectedLeaf);
				break;
			default:
				printf("\nInvalid value");
				break;
			}
		}
		else
		{
			break;
		}
	}
}

void main()
{
	while (1)
	{
		system("cls");
		if (!root)
		{
			createLeaf();
		}
		selectLeaf();
	}
}