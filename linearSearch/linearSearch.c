#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>

int *array;
int arraySize;

void createArray()
{
	printf("\nEnter size of array: ");
	scanf("%d", &arraySize);
	array = (int *)malloc(sizeof(int)*arraySize);
}

void inputArray()
{
	int i;
	printf("\nEnter elements:");
	for (i = 0; i < arraySize; i++)
	{
		printf("\n[%d]: ", i + 1);
		scanf("%d", &array[i]);
	}
}

void printArray()
{
	int i;
	for (i = 0; i < arraySize; i++)
	{
		printf("%d  ", array[i]);
	}
}

void linearSearch(int data)
{
	int i;
	for (i = 0; i < arraySize; i++)
	{
		if (data == array[i])
		{
			printf("\nFound at location: %d", i + 1);
		}
	}
	printf("\n\nEnd of search...");
	getch();
}

void main()
{
	int data;
	createArray();
	inputArray();
	while (1)
	{
		system("cls");
		printArray();
		printf("\n\n\nEnter element to be searched: ");
		scanf("%d", &data);
		linearSearch(data);
	}
}