#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>

struct Node
{
	int data;
	struct Node *next;
};

struct Node *Head = NULL;
struct Node *newNode;
struct Node *ptr;

void createNode()
{
	int d;
	//struct Node node;
	newNode = (struct Node*)malloc(sizeof(struct Node));
	printf("\nEnter data: ");
	scanf("%d", &d);
	newNode->data = d;
	newNode->next = NULL;
	//node.data = d;
	//node.next = NULL;
	//newNode = &node;
}

void insertAtBegin()
{
	createNode();
	if (Head == NULL)
	{
		Head = newNode;
	}
	else
	{
		newNode->next = Head;
		Head = newNode;
	}
}

void insetAtEnd()
{
	createNode();
	ptr = Head;
	if (Head == NULL)
	{
		Head = newNode;
	}
	else
	{
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = newNode;
	}
}

void insertAtLoc()
{
	int position;
	printf("\nEnter the loctaion after which you want to add: ");
	scanf("%d", &position);
	position--;
	ptr = Head;
	if (Head != NULL)
	{
		ptr = Head;
		while (ptr->next != NULL && position>0)
		{
			ptr = ptr->next;
			position--;
		}
		if (!position)
		{
			createNode();
			newNode->next = ptr->next;
			ptr->next = newNode;
		}

		else
		{
			printf("Invalid position");
		}
	}
	else
	{
		printf("Invalid position");
	}
}

void display()
{
	ptr = Head;
	while (ptr)
	{
		printf("\n%d", ptr->data);
		ptr = ptr->next;
	}
}

void main()
{
	int choice;
	while (1)
	{
		system("cls");
		printf("\n\n1.Insert node at begining\n2.At end\n3.At location\n4.Display\n5.Exit\n\nEnter a choice: ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			insertAtBegin();
			break;
		case 2:
			insetAtEnd();
			break;
		case 3:
			insertAtLoc();
			break;
		case 4:
			display();
			getch();
			break;
		case 5:
			exit(0);
		default:
			break;
		}
	}
}