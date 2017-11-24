#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<stdlib.h>


struct node
{
	int data;
	struct node *parent, *left, *right;
};

struct node *root = NULL, *ptr, *ptrOld;
int hit;

void deleteWithTwoChild(struct node *);

struct node* createNode(int data)
{
	struct node *newNode;
	newNode = malloc(sizeof(struct node));
	newNode->data = data;
	newNode->parent = ptr;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

void insert(int data)
{

	if (!root)
	{
		root = malloc(sizeof(struct node));
		root->data = data;
		root->left = NULL;
		root->right = NULL;
		root->parent = NULL;
		return;
	}

	ptrOld = NULL;
	ptr = root;
	while (1)
	{
		if (ptr != NULL)
		{
			ptrOld = ptr;
			if (data >= ptr->data)
			{
				if (ptr->right != NULL)
				{
					ptr = ptr->right;
					continue;
				}
				else
				{
					ptr->right = createNode(data);
					break;
				}
			}
			else if (data < ptr->data)
			{
				if (ptr->left != NULL)
				{
					ptr = ptr->left;
					continue;
				}
				else
				{
					ptr->left = createNode(data);
					break;
				}
			}
		}
	}
}

int search(int data)
{
	hit = 0;
	ptr = root;
	while (ptr->data != data)
	{
		hit++;
		if (data > ptr->data)
		{
			if (ptr->right == NULL)
			{
				printf("Not found");
				return 0;
			}
			ptr = ptr->right;
		}
		else
		{
			if (ptr->left == NULL)
			{
				printf("Not found");
				return 0;
			}
			ptr = ptr->left;
		}
	}
	return 1;
}

void deleteNode(struct node *DeleteNode)
{

	if (DeleteNode->left==NULL &&DeleteNode->right==NULL)
	{
		ptr = DeleteNode->parent;
		if (ptr->left->data == DeleteNode->data)
		{
			ptr->left = NULL;
		}
		else
		{
			ptr->right = NULL;
		}
		free(DeleteNode);
	}

	else if (DeleteNode->left==NULL && DeleteNode->right!=NULL)
	{
		ptr = DeleteNode->data;
		if (ptr->left->data == DeleteNode->data)
		{
			ptr->left = DeleteNode->right;
		}
		else
		{
			ptr->right = DeleteNode->right;
		}
		free(DeleteNode);
	}
	else if (DeleteNode->left!=NULL&& DeleteNode->right==NULL)
	{
		ptr = DeleteNode->data;
		if (ptr->left->data == DeleteNode->data)
		{
			ptr->left = DeleteNode->left;
		}
		else
		{
			ptr->right = DeleteNode->left;
		}
		free(DeleteNode);
	}
	else
	{
		deleteWithTwoChild(DeleteNode);
	}
}

void deleteWithTwoChild(struct node *DeleteNode)
{
	struct node *minimum;
	minimum = DeleteNode->right;
	while (minimum->left!=NULL)
	{
		minimum = minimum->left;
	}
	DeleteNode->data = minimum->data;
	deleteNode(minimum);
}

void print()
{
	char c = 'a';
	while (c != 'q')
	{
		if (ptr == NULL)
		{
			printf("NO elements");
			break;
		}
		system("cls");
		printf("\t\t %d\n", ptr->data);
		printf("\t\t/ \\\n");
		printf("\t       %d   %d",
			ptr->left ? ptr->left->data : 0,
			ptr->right ? ptr->right->data : 0);
		printf("\n\nPress q to exit\n\nEnter direction(W,A,D):");
		c = getch(stdin);

		if (c == 'w')
		{
			if (ptr->parent == NULL)
			{
				printf("\n\nIt is root");
				continue;
			}
			ptr = ptr->parent;
			continue;
		}
		else if (c == 'a')
		{
			if (ptr->left)
			{
				ptr = ptr->left;
				continue;
			}
			else
			{
				printf("\nNo elements..");
				continue;
			}
		}
		else if (c == 'd')
		{
			if (ptr->right)
			{
				ptr = ptr->right;
				continue;
			}
			else
			{
				printf("\nNo elements..");
				continue;
			}
		}
	}
}

void printFromRoot()
{
	ptr = root;
	print();
}

void main()
{
	char ch;
	int d;
	while (1)
	{
		system("cls");

		printf("\n\n1. Insert\n2.Print\n3.Search\n4.Delete\n\n\nChoice: ");
		ch = getc(stdin);
		switch (ch)
		{
		default:
			break;
		case '1':
			printf("Enter element: ");
			scanf("%d", &d);
			insert(d);
			break;
		case '2':
			printFromRoot();
			break;
		case '3':
			printf("\nEnter data:");
			scanf("%d", &d);
			if (search(d) != 0)
			{
				printf("\n\nHit at: %d", hit);
				getch();
				print();
			}
			break;
		case '4':
			printf("\nEnter data:");
			scanf("%d", &d);
			if (search(d) != 0)
			{
				printf("\n\nHit at: %d", hit);
				deleteNode(ptr);
			}
			break;
		}
	}
}