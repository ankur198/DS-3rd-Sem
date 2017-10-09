#include<stdio.h>
#include<conio.h>
int a[50][50], b[50][50], c[50][50];

void add();
void multiply();

void main()
{
	int choice = 0;
	while (choice != 3)
	{
		printf("\n\n1.Add\n2.Multiply\n3.Exit\nEnter a choice:");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			add();
			break;
		case 2:
			multiply();
			break;
		case 3:
			break;
		default:
			printf("\nYou have entered a wrong choice\n");
			break;
		}
	}
}

void add()
{
	int i, j;
	int dimension[2];
	printf("Enter size of matrix(m*n):\nm:");
	scanf("%d", &dimension[0]);
	printf("n:");
	scanf("%d", &dimension[1]);

	printf("\nEnter value of first array:\n");
	for (i = 0; i < dimension[0]; i++)
	{
		for (j = 0; j < dimension[1]; j++)
		{
			printf("[%d,%d]:\t", i, j);
			scanf("%d", &a[i][j]);
		}
	}

	printf("\n\n\nEnter value of second array:\n");
	for (i = 0; i < dimension[0]; i++)
	{
		for (j = 0; j < dimension[1]; j++)
		{
			printf("[%d,%d]:\t", i, j);
			scanf("%d", &b[i][j]);
		}
	}

	printf("\nAddition of two matrixes is:\n");
	for (i = 0; i < dimension[0]; i++)
	{
		for (j = 0; j < dimension[1]; j++)
		{
			c[i][j] = a[i][j] + b[i][j];
			printf("%d\t", c[i][j]);
		}
		printf("\n");
	}
}

void multiply()
{
	int i, j, k, sum;
	int dimension1[2], dimension2[2];

	printf("Enter size of first matrix(m*n):\nm:");
	scanf("%d", &dimension1[0]);
	printf("n:");
	scanf("%d", &dimension1[1]);

	printf("Enter size of second matrix(m*n):\nm:");
	scanf("%d", &dimension2[0]);
	printf("n:");
	scanf("%d", &dimension2[1]);

	if (dimension1[1] == dimension2[0])
	{
		printf("\nEnter value of first array:\n");
		for (i = 0; i < dimension1[0]; i++)
		{
			for (j = 0; j < dimension1[1]; j++)
			{
				printf("[%d,%d]:\t", i, j);
				scanf("%d", &a[i][j]);
			}
		}

		printf("\nEnter value of second array:\n");
		for (i = 0; i < dimension2[0]; i++)
		{
			for (j = 0; j < dimension2[1]; j++)
			{
				printf("[%d,%d]:\t", i, j);
				scanf("%d", &b[i][j]);
			}
		}

		for (i = 0; i < dimension1[0]; i++)
		{
			for (j = 0; j < dimension2[1]; j++)
			{
				sum = 0;
				for (k = 0; k < dimension1[1]; k++)
				{
					sum += a[i][k] * b[k][j];
				}
				c[i][j] = sum;
			}
		}

		printf("\nMultiplication of two matrixes is:\n");
		for (i = 0; i < dimension1[0]; i++)
		{
			for (j = 0; j < dimension2[1]; j++)
			{
				printf("%d\t", c[i][j]);
			}
			printf("\n");
		}
	}
	else
	{
		printf("Multiplication of these two order is not possible");
	}
}
