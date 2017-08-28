#include<stdio.h>

//Get nbits function
int get_nbits(int hnum, int n)
{
	int mask=0,i;
	mask=((1<<n)-1);
	hnum=hnum&mask;
	return hnum;
//	printf("Number is: %x\n",hnum);
	return 0;
}

//Get nbits from position function
int get_nbits_from_pos(int hnum,int n,int position)
{

	int mask=0,iter=0,i,position_copy,result;

	position_copy=position;
	position--;

	iter=position*n;
	mask=((1<<n)-1)<<iter;	

	result=hnum&mask;
	result=result>>(iter);
	return result;

}

//Set nbits Function
int set_nbits(int hnum,int value,int bit_set)
{

	int mask=0,mask_2=0,i,value_temp;

	mask_2=((1<<bit_set)-1);	
	mask_2=~mask_2;
	mask=((1<<bit_set)-1);	
	
	hnum&=mask_2;	
	value_temp=value&mask;

	hnum |= value_temp;
	return hnum;
//	printf("Number is: %x\n",hnum);

}

//Toggle bits from position Function
int toggle_bits_from_position(int hnum,int n, int position)
{

	int mask,result;

	position--;
	mask = ( (1 << n ) - 1 );
	mask = mask << position;
	result = hnum ^ mask ;
	return result;
}

//Set nbit from position function
int set_nbits_from_position(int hnum,int n,int position, int value)
{

	int mask=0,mask_copy=0;
	int i,position_copy,result;

	position--;
	mask=((1<<n)-1)<<position;	
	mask_copy=mask;	
	mask=~mask;
	result=hnum&mask;
	value&=mask_copy;
	result=result|value;

	return result;
}


//Print bit function
void print_bit_func(int num)
{
	int i;
	for(i=31;i>=0;i--)
		(1<<i)&num?putchar('1'):putchar('0');
	printf("\n");
}
