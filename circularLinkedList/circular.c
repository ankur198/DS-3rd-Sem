#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>

struct Node
{
	int Data;
	struct Node *Next;
};


struct Node *Head = NULL;
struct Node *ptr = NULL;
struct Node *newNode = NULL;
struct Node *prev;


void createNode()
{
	int d;
	newNode = (struct Node*)malloc(sizeof(struct Node));
	printf("\nEnter data: ");
	scanf("%d", &d);
	newNode->Data = d;
	newNode->Next = NULL;
}

void insertAtBegin()
{
	createNode();
	if (Head==NULL)
	{
		Head = newNode;
		newNode->Next = Head;
	}
	else
	{
		ptr = Head;
		while (ptr->Next!=Head)
		{
			ptr = ptr->Next;
		}
		ptr->Next = newNode;
		newNode->Next = Head;
		Head = newNode;
	}
}

void insertAtEnd()
{
	createNode();
	if (Head == NULL)
	{
		Head = newNode;
		newNode->Next = Head;
	}
	else
	{
		ptr = Head;
		while (ptr->Next != Head)
		{
			ptr = ptr->Next;
		}
		ptr->Next = newNode;
		newNode->Next = Head;
		//Head = newNode;
	}
}

void insertAtLoc()
{
	int n;
	//createNode();
	printf("\nEnter location at which you want to insert: ");
	scanf("%d", &n);
	//n--;
	if (n == 1)
	{
		insertAtBegin();
	}
	else if(n>1)
	{
		n--;
		ptr = Head;
		while (ptr->Next!=Head && n>1)
		{
			ptr = ptr->Next;
			n--;
		}
		if (n==1)
		{
			createNode();
			newNode->Next = ptr->Next;
			ptr->Next = newNode;
		}
		else if (n==2)
		{
			createNode();
			ptr->Next = newNode;
			newNode->Next = Head;
		}
		else
		{
			printf("\nPosition is incorrect");
		}
	}
}

void display()
{
	ptr = Head;
	if (ptr!=NULL)
	{
		while (ptr->Next!=Head)
		{
			printf("%d ", ptr->Data);
			ptr = ptr->Next;
		}
		printf("%d ", ptr->Data);
	}
}

void deleteAtBegin()
{
	if (Head==NULL)
	{
		printf("\n empty");
	}
	else
	{
		ptr = Head;
		while (ptr->Next!=Head)
		{
			ptr = ptr->Next;
		}
		prev = Head;
		Head = Head->Next;
		ptr->Next = Head;
		free(prev);
	}
}

void deleteAtEnd()
{
	if (Head == NULL)
	{
		printf("\n empty");
	}
	else
	{
		ptr = Head;
		prev = ptr;
		while (ptr->Next != Head)
		{
			prev = ptr;
			ptr = ptr->Next;
		}
		prev->Next = Head;
		free(ptr);
	}
}

void deleteAtLoc()
{
	int n;
	printf("\n\nEnter the position at which you want to delete: ");
	scanf("%d", &n);
	//n--;
	if (n==1)
	{
		deleteAtBegin();
	}
	else if(n>1)
	{
		//n--;
		ptr = Head;
		prev = ptr;
		while (ptr->Next != Head && n > 1)
		{
			prev = ptr;
			ptr = ptr->Next;
			n--;
		}
		if (n==1)
		{
			if (ptr->Next == Head)
			{
				deleteAtEnd();
			}
			else
			{
				prev->Next = ptr->Next;
				free(ptr);
			}
			
		}
		else
		{
			printf("Wrong position");
		}
	}
}

void main()
{
	int ch;
	while (1)
	{
		system("cls");
		display();
		printf("\n\n1.Insert At start\n2.Insert At end\n3.Insert At Loc\n4.Delete At Begin\n5.Delete at end\n6.Delete at loc\n");
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
			deleteAtBegin();
			break;
		case 5:
			deleteAtEnd();
			break;
		case 6:
			deleteAtLoc();
			break;
		default:
			break;
		}
	}
}