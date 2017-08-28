#include<stdio.h>
#include<stdlib.h>

//Display Array
void display_array(int *A, int size)
{
	int ii;

	printf("Array:");
	for ( ii = 0; ii < size; ii++ )
	{
		printf("%d ", A[ii]);
	}
	printf("\n");
}

//Swap function
void swap(int *num1, int *num2)
{
	int temp;
	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

//Max heapify function
void MaxHeapify(int *A, int i, int size)
{
	int L = 2*i + 1, R = 2*i + 2, Large;

	//If left node is greater than root node, make its data's index as large index
	if ( A[L] > A[i] && L < size )
	{
		Large = L;
	}
	else
	{
		Large = i;
	}

	//If right node is greater than root node, make its data's index as large index
	if ( A[Large] < A[R] && R < size )
	{
		Large = R;
	}

	//Swap data & Recursively call function to create max heap
	if ( Large != i )
	{
		swap( &A[Large], &A[i]);
		MaxHeapify(A, Large, size);
	}
}

//Bulid Max Heap Function
void BuildMaxHeap(int *A, int size)
{
	int n, i;

	//Make the max heap
	for ( i = (size/2) - 1; i >= 0; i-- )
	{
		MaxHeapify(A, i, size);
	}
	
	//Decrement the size
	n = size - 1;

	//Swap the first and last element of array, and max heapify again
	if (n >= 0 )
	{
		swap( &A[0], &A[n] );
		BuildMaxHeap(A, n );
	}

}

int main()
{

	system("clear");

	//Data pool
	int A[] = {1, 4, 10, 8, 7, 9, 3, 2, 4, 6 }, i;

	//Find size of array
	int size = sizeof(A)/4;

	//Display Original heap array
	printf("Original Heap:\t\t");
	display_array(A, size);

	BuildMaxHeap(A, size);

	//Display Sorted heap array
	printf("Sorted Heap:\t\t");
	display_array(A, size);

	return 0;
}
