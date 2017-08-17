#include<stdio.h>
#include<conio.h>

void hanoi(int n, char from, char to, char aux);

void main() {
	int n;
	printf("Enter number of disks:");
	scanf("%d", &n);
	
	hanoi(n, 'A', 'C', 'B');
	
	getch();
}

void hanoi(int n, char from, char to, char aux)
{
	if (n == 1)
	{
		printf("\n Move disk 1 from rod %c to rod %c", from, to);
		return;
	}
	hanoi(n - 1, from, aux, to);
	printf("\n Move disk %d from rod %c to rod %c", n, from, to);
	hanoi(n - 1, aux, to, from);
}