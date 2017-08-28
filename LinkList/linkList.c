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
struct Node *prev;

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
	printf("Output: ");
	while (ptr)
	{
		printf("%d  ", ptr->data);
		ptr = ptr->next;
	}
	printf("\n\n");
}


void deleteBegin() 
{
	ptr = Head;
	Head = ptr->next;
	free(ptr);
}

void deleteEnd()
{
	if (Head!=NULL)
	{
		ptr = Head;
		prev = ptr;
		while (ptr->next != NULL)
		{
			prev = ptr;
			ptr = ptr->next;
		}
		prev->next = NULL;
		free(ptr);
	}
}

void deleteLoc()
{
	int position;
	printf("\nEnter the position at which you want to delete the element: ");
	scanf("%d", &position);
	position--;
	ptr = Head;
	prev = ptr;
	if (position==0)
	{
		Head = ptr->next;
		free(ptr);
		return;
	}	
	while (position!=0 && ptr->next!=NULL)
	{
		prev = ptr;
		ptr = ptr->next;
		position--;
	}
	if (position==0)
	{
		prev->next = ptr->next;
		free(ptr);
	}
}

void main()
{
	int choice;
	while (1)
	{
		system("cls");
		display();
		printf("\n\n1.Insert node at begining\n2.At end\n3.At location\n4.Delete at start\n5.Delete at end\n6.Delete at location\n7.Exit\n\nChoice: ");
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
			deleteBegin();
			break;
		case 5:
			deleteEnd();
			break;
		case 6:
			deleteLoc();
			break;
		case 7:
			exit(0);
		default:
			break;
		}
	}
}