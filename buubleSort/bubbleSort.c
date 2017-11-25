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

void bubbleSort()
{
	int outerLoop, innerLoop, max;
	for (outerLoop = 0; outerLoop < arraySize - 1; outerLoop++)
	{
		for (innerLoop = 0; innerLoop < arraySize - 1 - outerLoop; innerLoop++)
		{
			if (array[innerLoop] > array[innerLoop + 1])
			{
				max = array[innerLoop];
				array[innerLoop] = array[innerLoop + 1];
				array[innerLoop + 1] = max;
			}
		}
	}
}

void main()
{
	while (1)
	{
		system("cls");
		createArray();
		inputArray();
		bubbleSort();

		system("cls");
		printf("\n\n\nSorted elements: ");
		printArray();
		free(array);
		getch();
	}
}