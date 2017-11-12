#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>

int maxItem, i, front = -1, rear = 0;
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

void print(int i)
{
	printf("%d\t", array[i]);
}

void printVal()
{
	printf("Raw Values are:\n");
	for (i = 0; i < maxItem; i++)
	{
		print(i);
	}

	printf("\n\nFormatted Values are:\n");
	if (front > -1)
	{
		for (i = front; i < rear; i++)
		{
			print(i);
		}
		if (front >= rear)
		{
			for (i = front; i < maxItem; i++)
			{
				print(i);
			}
			for (i = 0; i < rear; i++)
			{
				print(i);
			}
		}
	}
	printf("\n\nFront: %d\nRear: %d", front, rear);
}

void push()
{
	if (rear != front)
	{
		printf("Enter value:");
		scanf("%d", &i);
		array[rear] = i;
		rear++;
		if (rear == maxItem)
		{
			rear = 0;
		}
		if (front == -1)
		{
			front++;
		}
	}
	else
	{
		printf("\nCant insert item");
		getch();
	}
}

void pop()
{
	if (front != -1)
	{
		printf("\nDeleted element: %d", array[front]);
		front++;
		if (front == maxItem)
		{
			front = 0;
		}
	}
	else
	{
		printf("Cant delete element");
	}
	if (front == rear)
	{
		front = -1;
		rear = 0;
	}
	getch();
}

void peek()
{
	if (front != -1)
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