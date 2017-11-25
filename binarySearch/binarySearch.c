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

void binarySearch(int data)
{
	int start = 0, end = arraySize,
		mid, i;
	while (1)
	{
		if (start == end || start > end)
		{
			printf("Data not found");
			getch();
			break;
		}
		mid = (start + end) / 2;
		if (data == array[mid])
		{
			printf("Data found at location: %d", mid + 1);
			getch();
			break;
		}
		else if (data > array[mid])
		{
			start = mid + 1;
			continue;
		}
		else
		{
			end = mid;
			continue;
		}
	}
}

void main()
{
	int data;
	createArray();
	inputArray();
	bubbleSort();
	while (1)
	{
		system("cls");
		printArray();
		printf("\n\n\nEnter element to be searched: ");
		scanf("%d", &data);
		binarySearch(data);
	}
}