#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

//void main() 
//{
//	int choice;
//	do
//	{
//		printf("Enter a choice:");
//		printf("\n1.hjgjhg\n2.\n3.\n4 Exit");
//		scanf("%d", &choice);
//		switch (choice)
//		{
//		case 1:
//			break;
//		case 2:
//			break;
//		case 3:
//			break;
//		default:
//			break;
//		}
//	} while (choice!=4);
//}

int main()
{
	char *str;

	/* Initial memory allocation */
	str = (char *)malloc(15);
	str = "hello";
	//strcpy(str, "tutorialspoint");
	printf("String = %s,  Address = %u\n", str, str);

	/* Reallocating memory */
	str = (char *)realloc(str, 25);
	strcat(str, ".com");
	printf("String = %s,  Address = %u\n", str, str);

	free(str);
	getch();
	return(0);
}