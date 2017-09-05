#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>

struct Node
{
	int data;
	struct Node *Next;
	struct Node *Prev;
};

struct Node *Head;
struct Node *newNode;
struct Node *ptr;
struct Node *prev;

void createNode()
{
	newNode = (struct Node*)malloc(sizeof(struct Node));
	printf("\nEnter data:");
	scanf("%d");
	newNode->Next = NULL;
	newNode->Prev = NULL;
}

int isEmpty()
{
	if (Head == NULL)
	{
		printf("\nList is empty");
		return 1;
	}
	return 0;
}

void insertAtBegin()
{
	if (isEmpty()) 
	{

	}
	else if (Head->Next == NULL)
	{

	}
}