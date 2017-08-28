#include<stdio.h>
#include<stdlib.h>

int main()
{

	system("clear");

//	int *a, *b, *c;
	int a, b, c;
	char str[20];

	FILE *fp = NULL;

	fp = fopen("NewFile.txt", "r" );

//	fscanf(fp, "%d %*c %d %*c %s %*c %d %*c",  &a, &b, str, &c);
	fscanf(fp, "%d # %d ; %s ; %d ;",  &a, &b, str, &c);

	printf("%d %d %s %d\n", a, b, str, c);

	printf("Done\n");
	
	fclose(fp);


	return 0;
}
