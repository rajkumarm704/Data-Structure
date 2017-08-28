#include<stdio.h>
#include<stdlib.h>

#include<bitwise.h>

int main()
{
	system("clear");
	int option;
	int n,hnum,position,result,bit_set,value;	
	char ch;


while(1)
{
	printf("****************************************************");
	printf("\nSelect a function from the below menu:\n");
	printf("1. Get nbits function.\n");
	printf("2. Get nbits from position function.\n");
	printf("3. Set nbits function.\n");
	printf("4. Toggle bits from position function.\n");
	printf("5. Set nbits from position function.\n");		
	printf("\n\nEnter an option:");
	
	scanf("%d",&option);
	while(getchar() != '\n');
	printf("****************************************************\n");

switch(option)
{
	case 1:
		{
			printf("Enter number: ");
			scanf("%x",&hnum);
			while(getchar() != '\n');	
			printf("Enter number of bits to get: ");
			scanf("%x",&n);
			while(getchar() != '\n');

			//Print the input number
			printf("The number is ");
			print_bit_func(hnum);

			//Print the result
			result=get_nbits(hnum,n);
			printf("\nResult is ");
			print_bit_func(result);
			break;
		}
	case 2:
		{
			printf("Enter number: ");
			scanf("%x",&hnum);
			while(getchar() != '\n');	
			printf("Enter number of bits to get: ");
			scanf("%d",&n);
			while(getchar() != '\n');
			printf("Enter position of bits to get: ");
			scanf("%d",&position);
			while(getchar() != '\n');

			//Print the input number
			printf("The number is ");
			print_bit_func(hnum);

			//Print the result
			result=get_nbits_from_pos(hnum,n,position);
			printf("\nResult is ");
			print_bit_func(result);

			break;
		}

	case 3:
		{
			printf("Enter number: ");
			scanf("%x",&hnum);
			while(getchar() != '\n');
			printf("Enter value: ");
			scanf("%x",&value);
			while(getchar() != '\n');
			printf("Enter number of bits to set: ");
			scanf("%d",&bit_set);
			while(getchar() != '\n');

			//Print the input number
			printf("The number is ");
			print_bit_func(hnum);

			//Print the result
			result=set_nbits(hnum,value,bit_set);
			printf("\nResult is ");
			print_bit_func(result);

			break;
		}

	case 4:
		{
			printf("Enter number: ");
			scanf("%x",&hnum);
			while(getchar() != '\n');	
			printf("Enter number of bits to toggle: ");
			scanf("%d",&n);
			while(getchar() != '\n');
			printf("Enter position of bits to toggle: ");
			scanf("%d",&position);
			while(getchar() != '\n');

			//Print the input number
			printf("The number is ");
			print_bit_func(hnum);

			//Print the result
			result = toggle_bits_from_position(hnum, n, position);
			printf("\nResult is ");
			print_bit_func(result);
			break;
		}

	case 5:
		{

			printf("Enter hex number: ");
			scanf("%x",&hnum);
			while(getchar() != '\n');	
			printf("Enter number of bits to set: ");
			scanf("%d",&n);
			while(getchar() != '\n');
			printf("Enter position of bits to set: ");
			scanf("%d",&position);
			while(getchar() != '\n');
			printf("Enter value: ");
			scanf("%x",&value);
			while(getchar() != '\n');

			//Print the input number
			printf("The number is ");
			print_bit_func(hnum);	

			//Print the result
			result=set_nbits_from_position(hnum,n,position,value);
			printf("\nResult is ");
			print_bit_func(result);
			break;
		}


	default:printf("You have entered wrong option. Please try again...");

}
	printf("****************************************************\n");
	//Ask user for options
	printf("Do you want to continue(Y/N):");
	ch=getchar();
	while(getchar() != '\n');
	if(!(ch == 'Y' || ch == 'y'))
	{
		break;
	}
}
	return 0;
}
