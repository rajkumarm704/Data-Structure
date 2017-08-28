#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{

	system("clear");

	int i, j, sep_count = 0;
	char exp[200], str[200] ;
	
//	char *operators = "()#*/%#+-#&^|";
	char *operators = "|^&#-+#%/*#()";
	char *ptr;

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
		if ( exp[i] >= 48 && exp[i] <= 57 )
		{
			if ( exp[i+1] == '\5' )
			{
//				printf("excape if\t%c\t%c\n", exp[i], exp[i+1] );
				str[j] = exp[i];
				str[j+1] = ',';
				j++;
				sep_count++;
				continue;

			}//if; it is a space or tab
			if ( exp[i+1] == '\0' )
			{
//				printf("else\t\t\t%c\t%c\n", exp[i], exp[i+1] );
//				printf("else\t\t\t%c\n", exp[i] );
				str[j] = exp[i];
				str[j+1] = ',';
				j++;

			}//else; it is the last operand
			else if ( exp[i+1] < 48 || exp[i+1] > 57 )
			{
//				printf("if\t\t\t%c\t%c\n", exp[i], exp[i+1] );
				str[j] = exp[i];
				str[j+1] = ',';
				str[j+2] = exp[i+1];
				str[j+3] = ',';
				sep_count += 2;
				i++, j += 3;
			}//else if; it is an operand
			else
			{
//				printf("else\t\t\t%c\t%c\n", exp[i], exp[i+1] );
				str[j] = exp[i];
			}//else; it is a number

		}//if
		else if ( exp[i] < 48 || exp[i] > 57 )
		{
//			printf("else if\t\t\t%c\n", exp[i] );
			str[j] = exp[i];
			str[j+1] = ',';
			sep_count++;
			j++;

		}//else if; it is an operator
	
	}//for

	str[j] = '$';
	str[j+1] = '\0';

	printf("\nExp:%s\n\n", str);

	char *postfix_arr = malloc( ( strlen(str) ) * sizeof(int) );
	char *oper_stack = malloc( ( strlen(str) - sep_count + 1 ) * sizeof(char) );
	int arr_idx = 0, stack_idx = 0;
	int temp, flag = 0, bracket = 0;
	int prec_scan = 0, prec_stack = 0;
	
	char atoi_v[5];

	ptr = strtok(str, "," );

	while ( ptr != NULL )
	{
//		printf("####\t");
		
		for ( i = 0; operators[i] != '\0' ; i++ )
		{
			if ( operators[i] == '#' )
				prec_scan++;

			if ( *ptr == operators[i] )
			{
//				printf("(prec_stack:%d,\tprec_scan:%d)\t", prec_stack, prec_scan);

				if ( stack_idx == 0 )
				{
//					printf("empty, push operator into stack.\t");
					oper_stack[stack_idx] = *ptr;
					stack_idx++;
					prec_stack = prec_scan;
				}//if; empty, push operator into stack
				else if ( stack_idx > 0 )
				{
					if ( *ptr == '(' )
					{
//						printf("push operator into stack.\t");
						oper_stack[stack_idx] = *ptr;
						stack_idx++;
						prec_stack = 0;
						bracket = 1;

					}//if; push operator into stack
					else if ( *ptr == ')' )
					{
//						printf("pop all operator till \'(\' into stack.\t");
						for ( --stack_idx ; oper_stack[stack_idx] != '('; stack_idx-- )
						{
//							printf("%c,", oper_stack[stack_idx] );
							sprintf( atoi_v, "%c", oper_stack[stack_idx] );
							strcat( postfix_arr, atoi_v );
							strcat( postfix_arr, "," );
	
						}//for
						prec_stack = 0;

					}//else if; pop all operator till '(' into stack
					else if ( bracket == 1 )
					{
						oper_stack[stack_idx] = *ptr;
						stack_idx++;
						prec_stack = prec_scan;
						bracket = 0;

					}//else if; an opening bracket is encountered, push the opertor into stack
					else if ( prec_stack > prec_scan )
					{
//						printf("pop operator into postfix array & push operator into stack.\t");
						stack_idx--;
						sprintf( atoi_v, "%c", oper_stack[stack_idx] );
						strcat( postfix_arr, atoi_v );
						strcat( postfix_arr, "," );
						oper_stack[stack_idx] = *ptr;
						stack_idx++;
		
					}//else if; pop operator into postfix array & push operator into stack
					else if ( prec_stack < prec_scan )
					{
//						printf("push operator into stack.\t");
						oper_stack[stack_idx] = *ptr;
						stack_idx++;

					}//else if; push operator into stack
					else if ( prec_stack == prec_scan )
					{
//						printf("pop stack operator into postfix array & push scan operator into stack.\t");
						stack_idx--;
						sprintf( atoi_v, "%c", oper_stack[stack_idx] );
						strcat( postfix_arr, atoi_v );
						strcat( postfix_arr, "," );
						oper_stack[stack_idx] = *ptr;
						stack_idx++;

					}//else if; pop stack operator into postfix array & push scan operator into stack

					prec_stack = prec_scan;

				}//else if

				flag = 1;				
			}//if

		}//for

		if ( *ptr == '$' )
		{
//			printf("End of expression.\t");
			for ( --stack_idx ; stack_idx != -1; stack_idx-- )
			{
//				printf("stack id:%d ",stack_idx);
				if ( oper_stack[stack_idx] == '(' || oper_stack[stack_idx] == ')' )
				{
					stack_idx--;
					continue;

				}//if '(' or ')' are encountered, ignore them

				sprintf( atoi_v, "%c", oper_stack[stack_idx] );
				strcat( postfix_arr, atoi_v );
				strcat( postfix_arr, "," );
				oper_stack[stack_idx] = '\0';

			}//for

		}//else if; end of expression is reached, pop all operators into postfix array

		if ( flag == 0 && *ptr != '$')
		{
			strcat( postfix_arr , ptr );
			strcat( postfix_arr , "," );
		}//if

		prec_scan = 0;
		flag = 0;

//		printf("%s ", ptr );
//		printf("\t####\n");
		ptr = strtok( NULL, "," );

	}//while

	oper_stack[stack_idx] = '\0';

	printf("\nPostfix Array:%s\n\n", postfix_arr );
//	printf("Operator Stack:%s\tstack_idx:%d\n",oper_stack, stack_idx);

	free( oper_stack );

//	int *num_stack = malloc( ( strlen(postfix_arr) - sep_count + 1 ) * sizeof(int) );
	float *num_stack = malloc( ( strlen(postfix_arr) - sep_count + 1 ) * sizeof(float) );
	stack_idx = 0;flag = 0;
	float temp_result = 0;
//	int temp_result;

	ptr = strtok(postfix_arr, "," );

	while ( ptr != NULL )
	{
//		printf("####\n");

		for ( i = 0; operators[i] != '\0' ; i++ )
		{

			if ( *ptr == operators[i] )
			{
				switch(*ptr)
				{
					case '+' :
						temp_result = num_stack[stack_idx - 2] + num_stack[stack_idx - 1];
						stack_idx -= 2;
						num_stack[stack_idx] = temp_result;
						stack_idx++;
						break;
					case '-' :
						temp_result = num_stack[stack_idx - 2] - num_stack[stack_idx - 1];
						stack_idx -= 2;
						num_stack[stack_idx] = temp_result;
						stack_idx++;
						break;

					case '*' :
						temp_result = num_stack[stack_idx - 2] * num_stack[stack_idx - 1];
						stack_idx -= 2;
						num_stack[stack_idx] = temp_result;
						stack_idx++;
						break;

					case '/' :
						temp_result = num_stack[stack_idx - 2] / num_stack[stack_idx - 1];
						stack_idx -= 2;
						num_stack[stack_idx] = temp_result;
						stack_idx++;
						break;

					case '%' :
						temp_result = (int)num_stack[stack_idx - 2] % (int)num_stack[stack_idx - 1];
						stack_idx -= 2;
						num_stack[stack_idx] = temp_result;
						stack_idx++;
						break;

				}//switch

				flag = 1;

//		printf("temp result:%f\n", temp_result);

			}//if

		}//for

		if ( flag == 0 && *ptr != '\0')
		{
			num_stack[stack_idx] = atof( ptr );
//			num_stack[stack_idx] = atoi( tptr );
			stack_idx++;


		}//if

		flag = 0;

//		printf("%s ", ptr );
//		printf("\n####\n");
		ptr = strtok( NULL, "," );


	}//while

	printf("\nFinal result is:");
	for ( i = 0; i < stack_idx; i++ )
		printf("%f ", num_stack[i] );		
//		printf("%d ", num_stack[i] );

	printf("\n\n");

	return 0;
}


