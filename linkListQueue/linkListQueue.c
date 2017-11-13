#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>

struct Node
{
	int data;
	struct Node *next;
};

int i;
struct Node *front = NULL, *rear = NULL, *newNode;
struct Node *ptr;

void setPointerToNextNode()
{
	if (front)
	{
		rear->next = newNode;
	}
	else
	{
		front = newNode;
	}
	rear = newNode;
}

void createNode()
{
	newNode = (struct Node*)malloc(sizeof(struct Node));
	printf("\nEnter element: ");
	scanf("%d", &i);
	newNode->data = i;
	newNode->next = NULL;

	setPointerToNextNode();
}

void print()
{
	ptr = front;
	printf("\n\n");
	while (ptr)
	{
		printf("%d\t", ptr->data);
		ptr = ptr->next;
	}
	printf("\n\n");
}

void push()
{
	createNode();
}

void pop()
{
	if (front)
	{
		printf("Deleted element is: %d", front->data);
		ptr = front;
		front = front->next;
		free(ptr);
	}
	else
	{
		printf("\nCant pop");
	}
	getch();
}

void peek()
{
	if (front)
	{
		printf("Peek element is: %d", front->data);
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