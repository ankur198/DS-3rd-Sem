#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>

int n,i,top=0;
int *a;

void createArray()
{
	a = (int *)malloc(sizeof(int)*n);
}

void initVal()
{
	for (i = 0; i < n; i++)
	{
		a[i] = 0;
	}
}

void printVal()
{
	printf("Values are:\n");
	for (i = 0; i < top; i++)
	{
		printf("%d\n", a[i]);
	}

}

void push()
{
	if (top < n)
	{
		printf("Enter element:");
		scanf("%d", &i);

		a[top] = i;
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
		i = a[top-1];
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
	i = a[top-1];
	printf("Peek element: %d\n", i);
	getch();
}

void main()
{
	printf("Enter size of array: ");
	scanf("%d", &n);
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