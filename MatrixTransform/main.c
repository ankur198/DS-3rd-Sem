#include<stdio.h>>
#include<conio.h>

int Mat[10][10];
int tMat[10][10];
int dimensions[2];

void getMat()
{
	int i, j;
	printf("Enter matrix sice\nM: ");
	scanf("%d", &dimensions[0]);
	printf("N: ");
	scanf("%d", &dimensions[1]);

	for (i = 0; i < dimensions[0]; i++)
	{
		for (j = 0; j < dimensions[1]; j++)
		{
			printf("[%d,%d]: ", i + 1, j + 1);
			scanf("%d", &Mat[i][j]);
		}
	}
}

void transform()
{
	int i, j;
	for (i = 0; i < dimensions[0]; i++)
	{
		for (j = 0; j < dimensions[1]; j++)
		{
			tMat[j][i] = Mat[i][j];
		}
	}
}

void printMat()
{
	int i, j;
	printf("\n\nInput:\n");
	for (i = 0; i < dimensions[0]; i++)
	{
		for (j = 0; j < dimensions[1]; j++)
		{
			printf("%d\t", Mat[i][j]);
		}
		printf("\n");
	}

	printf("\n\nOutput:\n");
	for (i = 0; i < dimensions[1]; i++)
	{
		for (j = 0; j < dimensions[0]; j++)
		{
			printf("%d\t", tMat[i][j]);
		}
		printf("\n");
	}
}

void main()
{
	getMat();
	transform();
	printMat();
	getch();
}