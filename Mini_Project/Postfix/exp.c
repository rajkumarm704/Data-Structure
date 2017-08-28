#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{

	system("clear");

	char buffer[10] = "abcde";
	char *str = malloc( 10 * sizeof( char ) );
	char temp[5];

	sprintf(temp, "%c", buffer[0] );
	strcat( str, temp );
	sprintf(temp, "%c", buffer[1] );
	strcat( str, temp );
	sprintf(temp, "%c", buffer[2] );
	strcat( str, temp );
	
	printf("string:%s\n", str);

	return 0;
}
