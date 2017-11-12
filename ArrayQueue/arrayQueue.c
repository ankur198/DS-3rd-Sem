#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>

int maxItem, i, front = 0, rear = 0;
int *array;

void createArray()
{
	array = (int *)malloc(sizeof(int)*maxItem);
}

void initVal()
{
	for (i = 0; i < maxItem; i++)
	{
		array[i] = 0;
	}
}

void printVal()
{
	printf("Values are:\n");
	for (i = front; i < rear; i++)
	{
		printf("%d\t", array[i]);
	}
}

void push()
{
	if (rear<maxItem)
	{
		printf("Enter value:");
		scanf("%d", &i);
		array[rear] = i;
		rear++;
	}
	else
	{
		printf("\nCant insert item");
		getch();
	}
}

void pop()
{
	if (front!=rear)
	{
		printf("\nDeleted element: %d", array[front]);
		front++;
	}
	else
	{
		printf("Cant delete element");
	}
	if (front==rear)
	{
		front = rear = 0;
	}
	getch();
}

void peek()
{
	if (front != rear)
	{
		printf("\nPeek element: %d", array[front]);
	}
	else
	{
		printf("\nNo element");
	}
	getch();
}


void main()
{
	printf("Enter size of array: ");
	scanf("%d", &maxItem);
	createArray();
	initVal();

	while (1)
	{
		printVal();
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