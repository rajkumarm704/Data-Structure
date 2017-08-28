#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{

	system("clear");

	int i, j, sep_count = 0;
	char exp[200], str[200] ;


	printf("Enter the expression:"), scanf("%[^\n]", exp );

	printf("\nOriginal Exp:%s\n", exp);

	for ( i = 0; exp[i] != '\0'; i++)
	{
		if ( exp[i] == ' ' || exp[i] == '\t' )
		{
			exp[i] = '\5';
		}
	}

	printf("\nActual Exp:%s\n", exp);

	for ( i = 0, j = 0; i < strlen(exp); i++, j++ )
	{
		if ( exp[i] == '\5' )
		{
			j--;
			continue;
		}
		if ( exp[i] >= 48 &&  exp[i] <= 57 )
		{
			if ( exp[i+1] == '\5' )
			{
//				printf("excape if\t%c\t%c\n", exp[i], exp[i+1] );
				str[j] = exp[i];
				str[j+1] = ',';
				j++;
				sep_count++;
				continue;

			}//if
			if ( exp[i+1] < 48 || exp[i+1] > 57 )
			{
//				printf("if\t\t\t%c\t%c\n", exp[i], exp[i+1] );
				str[j] = exp[i];
				str[j+1] = ',';
				str[j+2] = exp[i+1];
				str[j+3] = ',';
				sep_count += 2;
				i++, j += 3;
			}
			else
			{
//				printf("else\t\t\t%c\n", exp[i] );
				str[j] = exp[i];

			}//else
		}//if
		else if ( exp[i] < 48 || exp[i] > 57 )
		{
//			printf("else if\t\t\t%c\n", exp[i] );
			str[j] = exp[i];
			str[j+1] = ',';
			sep_count++;
			j++;

		}//else if
	
	}//for

	int *postfix_arr = malloc( ( strlen(str) - sep_count + 1 ) * sizeof(char) );
	int *oper_stack = malloc( ( strlen(str) - sep_count + 1 ) * sizeof(char) );


	printf("\nExp:%s\nsep_count:%d\n\n", str, sep_count);

	free(postfix_arr);
	return 0;
}
