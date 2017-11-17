#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>

int maxItem,i,top=0;
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
	for (i = top - 1; i >= 0; i--)
	{
		printf("%d\t", array[i]);
	}
}

void push()
{
	if (top < maxItem)
	{
		printf("Enter element:");
		scanf("%d", &i);

		array[top] = i;
		top++;
	}
	else
	{
		printf("\nCant push");
		getch();
	}
}

void pop()
{
	if (top > 0)
	{
		i = array[top-1];
		top--;
		printf("Deleted element: %d\n", i);
		getch();
	}
	else
	{
		printf("\nCant perform");
		getch();
	}
}

void peek()
{
	i = array[top-1];
	printf("Peek element: %d\n", i);
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
		printf("\n\n\n\n\t1.Push\n\t2.Pop\n\t3.Peek\n\t4.Exit\n\t\n\tChoice: ");
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