#include<conio.h>
#include<stdio.h>

int factorial(int integer)
{
	if (integer==0)
	{
		return 1;
	}
	return integer*factorial(integer - 1);
}

void main()
{
	int num;
	printf("Enter number:");
	scanf("%d", &num);
	num = factorial(num);
	printf("\nFactorial is: %d", num);
	getch();
}