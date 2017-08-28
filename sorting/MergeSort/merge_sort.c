#include<stdio.h>
#include<stdlib.h>

#include "types.h"

//Merge array function
Status merge(int *A, int nA, int *L, int nL, int *R, int nR)
{

	//i index of Left array, j index of Right array, k index of Merged array
	int i, j, k;
	i = j = k = 0;

	//Copy the data into Merged Array
	while ( i < nL && j < nR )
	{
		//If data in left array is smaller than right array, copy the element from left array to merged array
		if ( L[i] < R[j] )
		{
			A[k] = L[i];
			i++;
		}//if

		//If data in right array is smaller than left array, copy the element from right array to merged array
		else if ( L[i] > R[j] )
		{
			A[k] = R[j];
			j++;
		}//if

		//If data in left array is equal to right array, copy the element from left array and right array to merged array
		else if ( L[i] == R[j] )
		{
			A[k] = L[i];
			k++;
			A[k] = R[j];
			i++, j++;

		}//if

		//Increment the merged array index
		k++;
	}//while

	//if right array index is smaller the right array size, copy all the elements of right array into merged array
	while (j < nR)
	{
		A[k] = R[j];
		j++,k++;
	}

	//if left array index is smaller the left array size, copy all the elements of left array into merged array
	while ( i < nL )
	{
		A[k] = L[i];
		k++, i++;
	}

}

//Dividing the Main array into smaller arrays
Status divide(int *A, int nA)
{
	int i, mid;
	
	//If number of elements in main array is 1, return (Base condition)
	if ( nA == 1)
		return failure;
	
	//Find the mid element
	mid = nA / 2;
	
	//Allocate memory for left and right sub-array
	int *L = malloc(mid * sizeof( int ) );
	int *R = malloc((nA - mid) * sizeof( int ) );

	//Copy the element from main array into left sub array
	for ( i = 0; i < mid; i++ )
	{
		L[i] = A[i];
	}//for

	//Copy the element from main array into right sub array
	for ( i = mid; i < nA; i++ )
	{
		R[i - mid] = A[i];
	}//for

	//Recursively call divide function to divide the main array into sub arrays
	divide(L, mid );
	divide(R, nA - mid );

	//Call merge function to merge all sub arrays into main sorted array
	merge(A, nA, L, mid, R, nA - mid);

}


int main()
{

	system("clear");

	//Initialise an array
	int A[8] = { 2, 4, 1, 6, 8, 5, 3, 7 };

	int i;
	int L[8], R[8];
	int nA, nL, nR;

	//Find the size of main array
	nA = sizeof(A)/4;

	//Display Original array
	printf("Original array is:\t");
	for ( i = 0; i < nA; i++ )
		printf("%d ", A[i] );
	printf("\n");

	//Call function to merge sort the main array
	divide(A, nA);

	//Display Sorted array
	printf("Sorted array is:\t");
	for ( i = 0; i < nA; i++ )
		printf("%d ", A[i] );
	printf("\n");

	return 0;
}
