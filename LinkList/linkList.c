#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#include<malloc.h>

void insertAtBegin();
void insertAtEnd();
void insertAtLoc();
void deleteBegin();
void deleteEnd();
void deleteLoc();

struct Node
{
	int data;
	struct Node *next;
};

struct Node *Head = NULL;
struct Node *newNode;
struct Node *ptr;
struct Node *ptr1;
struct Node *prev;



void clrscr()
{
	system("cls");
}

void choice()
{
	int ch;
	printf("\n\n1.Insert node at begining\n2.At end\n3.At location\n4.Delete at start\n5.Delete at end\n6.Delete at location\n7.Exit\n\nChoice: ");
	scanf("%d", &ch);
	switch (ch)
	{
	case 1:
		insertAtBegin();
		break;
	case 2:
		insertAtEnd();
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
		choice();
		break;
	}
}

void display()
{
	ptr1 = Head;
	printf("Output: ");
	while (ptr1!=NULL)
	{
		printf("%d  ", ptr1->data);
		ptr1 = ptr1->next;
	}
	printf("\n\n");
}

void oldDisplay()
{
	ptr1 = Head;
	printf("Old   : ");
	while (ptr1)
	{
		printf("%d  ", ptr1->data);
		ptr1 = ptr1->next;
	}
	printf("\n\n");
}

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
	int ankurisTheBest;
	createNode();
	clrscr();
	oldDisplay();

	if (Head == NULL)
	{
		Head = newNode;
		ankurisTheBest = 0;
		for ( ankurisTheBest = 0; ankurisTheBest < 8; ankurisTheBest++)
		{

		}
	}
	else
	{
		newNode->next = Head;
		Head = newNode;
	}

	display();
	choice();
}

void insertAtEnd()
{
	createNode();

	clrscr();
	oldDisplay();

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

	display();
	choice();
}

void insertAtLoc()
{
	int position;
	printf("\nEnter the loctaion after which you want to add: ");
	scanf("%d", &position);
	position--;
	ptr = Head;
	clrscr();
	oldDisplay();
	if (Head != NULL)
	{
		ptr = Head;
		while (ptr->next != NULL && position > 0)
		{
			ptr = ptr->next;
			position--;
		}
		if (!position)
		{
			createNode();

			newNode->next = ptr->next;
			ptr->next = newNode;

			display();
			choice();
		}

		else
		{
			display();
			printf("Invalid position");
			choice();
		}
	}
	else
	{
		display();
		printf("Invalid position");
		choice();
	}
}

void deleteBegin()
{
	clrscr();
	oldDisplay();
	if (Head==NULL)
	{
		display();
		printf(" There is no value");
		choice();
		return;
	}
	ptr = Head;
	Head = ptr->next;
	free(ptr);

	display();
	choice();
}

void deleteEnd()
{
	if (Head != NULL)
	{

		clrscr();
		oldDisplay();

		ptr = Head;
		prev = ptr;
		while (ptr->next != NULL)
		{
			prev = ptr;
			ptr = ptr->next;
		}
		prev->next = NULL;
		free(ptr);

		display();
		choice();
	}
	else
	{
		clrscr();
		oldDisplay();
		display();
		printf("No value");
		choice();
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
	if (ptr==NULL)
	{
		clrscr();
		oldDisplay();
		display();
		//choice();

		printf("No value");

	}
	else
	{
		if (position == 0)
		{
			clrscr();
			oldDisplay();

			Head = ptr->next;
			free(ptr);

			display();

			//return;
		}
		while (position != 0 && ptr->next != NULL)
		{
			prev = ptr;
			ptr = ptr->next;
			position--;
		}
		if (position == 0)
		{
			clrscr();
			oldDisplay();

			prev->next = ptr->next;
			free(ptr);

			display();
			//choice();
		}
		else
		{
			clrscr();
			oldDisplay();

			display();

			printf("No value");

			//choice();
		}
	}
	choice();
}

void main()
{
	//clrscr();
	choice();
}