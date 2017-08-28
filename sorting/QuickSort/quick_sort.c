#include<stdio.h>
#include<stdlib.h>

//Function to swap two numbers
void swap_numbers(int *num1, int *num2)
{
	//temp variable to used for swapping
	int temp;

	//Swap the given two numbers
	temp = *num1;
	*num1 = *num2;
	*num2 = temp;

}

//Split function to divide the main array into two arrays
int split(int *arr, int low, int high)
{

	int pivot, p, q, i;

	//Set pivot to 0th index
	pivot = low;

	//Set low index to next element of pivot data
	low = pivot + 1;

	//Set p & q to low & high respectively
	p = low;
	q = high;

	//Run loop till p index is smaller than q index
	while (p <= q)
	{
		//Increment the p index if pth data is smaller than pivot data
		while (arr[p] < arr[pivot])
		{
			p++;
		}

		//Increment the q index if qth data is greater than pivot data
		while ( arr[q] > arr[pivot] )
		{
			q--;
		}

		//Swap p and q if p is smaller than q data
		if ( p < q )
		{
			swap_numbers(&arr[p], &arr[q]);
/*			temp = arr[p];
			arr[p] = arr[q];
			arr[q] = temp;	
*/		}

	}//while

	//Swap q and pivot
	swap_numbers(&arr[q], &arr[pivot]);
/*	temp = arr[q];
	arr[q] = arr[pivot];
	arr[pivot] = temp;
*/
	return q;

}

//Quick sort Funcion to sort sub ar
void quick_sort(int *arr, int low, int high)
{
	int i;

	if ( low < high )
	{
		i = split( arr, low, high );
		quick_sort(arr, low, i-1 );
		quick_sort(arr, i+1, high);
	}
}

int main()
{

	system("clear");

//	int  arr[] = { 11, 2, 9, 13, 47, 25, 17, 1, 90, 3 };
	int  arr[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	int i, low, high, pivot;

	printf("Original array is:\t");
	for ( i = 0; i < (sizeof(arr)/4); i++ )
		printf("%d ", arr[i] );
	printf("\n");

	low = 0;
	high = (sizeof(arr)/4) - 1;

	quick_sort( arr, low, high );

	printf("Sorted array is:\t");
	for ( i = 0; i < (sizeof(arr)/4); i++ )
		printf("%d ", arr[i] );
	printf("\n");

	return 0;
}
