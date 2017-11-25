#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<stdlib.h>

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

void selectionSort()
{
	int sorted = 0, min, i, replace;

	while (sorted != arraySize)
	{
		min = array[sorted];
		replace = sorted;
		for (i = sorted; i < arraySize; i++)
		{
			if (min > array[i])
			{
				min = array[i];
				replace = i;;
			}
		}

		array[replace] = array[sorted];
		array[sorted] = min;
		sorted++;
	}
}

void main()
{
	while (1)
	{
		system("cls");
		createArray();
		inputArray();
		selectionSort();

		system("cls");
		printf("\n\n\nSorted elements: ");
		printArray();
		getch();
	}
}