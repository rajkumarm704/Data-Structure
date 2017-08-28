#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{

	system("clear");
	
	char str[20], *ptr;
	float num1, num2;
	int temp = 1;
	float num;
	int i;

	printf("Enter a floating point number:");
	scanf("%[^\n]", str);

	ptr = strtok( str, "." );

	num1 = atoi(ptr);

	ptr = strtok( NULL, "." );

	num2 = atoi(ptr);

	for ( i = 0; i < strlen(ptr); i++ )
		temp *= 10;

	num2 /= temp;

	num = num1 + num2;

	printf("Floating number is:%f\n", num);

	return 0;
}
