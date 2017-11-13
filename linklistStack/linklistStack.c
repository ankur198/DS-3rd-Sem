#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>

struct Node
{
	int data;
	struct Node *previous;
};

int i;
struct Node *top = NULL, *newNode;

void setPointerToPreviousNode()
{
	newNode->previous = top;
	top = newNode;
}

void createNode()
{
	newNode = (struct Node*)malloc(sizeof(struct Node));
	printf("\nEnter element: ");
	scanf("%d", &i);
	newNode->data = i;
	newNode->previous = NULL;
	
	setPointerToPreviousNode();
}

void print()
{
	struct Node *ptr = top;
	printf("\n\n");
	while (ptr)
	{
		printf("%d\t", ptr->data);
		ptr = ptr->previous;
	}
	printf("\n\n");
}

void push()
{
	createNode();
}

void pop()
{
	if (top)
	{
		printf("Deleted element is: %d", top->data);
		top = top->previous;
	}
	else
	{
		printf("\nCant pop");
	}
	getch();
}

void peek()
{
	if (top)
	{
		printf("Peek element is: %d", top->data);
	}
	else
	{
		printf("No element");
	}
	getch();
}

void main()
{
	while (1)
	{
		print();
		printf("\n\n\n\n1.Push\n2.Pop\n3.Peek\n4.Exit\n\nChoice: ");
		scanf("%d", &i);

		switch (i)
		{
		case 1:
			push();
			break;
		case 2:
			pop();
			break;
		case 3:
			peek();
			break;
		case 4:
			exit(0);
		default:
			printf("Invalid option");
			break;
		}
		system("cls");
	}
}