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

//Bubble sort
void bubble_sort(int *arr, int n)
{
	printf("\nBubble sort\n");
	int i, j, temp, swap_flag = 0;

	//Outer loop for checking smaller number, the number of times the number of elements in the array
	for ( i = 0; i < n; i++ )
	{
		//Inner loop for checking smaller number in current array
		for ( j = 0; j < n-1; j++ )
		{
			//swap the numbers if the currnt number is greater then next number
			if ( arr[j] > arr[j+1] )
			{
				swap_numbers(&arr[j], &arr[j+1]);

				//Set swap flag to break the loop, if numbers were swapped
				swap_flag = 1;

			}//if; swap the bigger number with smaller one
		}//for

		//Reset the swap flag
		if (swap_flag == 1)
		{
			swap_flag = 0;
		}
	
		//return from function if no swapping was done, array is sorted
		else if (swap_flag == 0)
		{
			return;
		}

	}//for

}

void insertion_sort(int *arr, int n)
{
	printf("\nInsertion sort\n");

	int i, ii, j, temp;

	//Outer loop for checking each array element
	for ( i = 0; i < n; i++ )
	{
		//Inner loop for checking the swapped data again
		for ( j = i+1; j > 0; j-- )
		{
			//Check if the current number is smaller then previous number, swap if true
			if ( arr[j-1] > arr[j] )
			{
//				printf("swap\t");
				swap_numbers(&arr[j], &arr[j-1]);
			}//if; swap numbers

/*			printf("Intermediate array:\t");
			for ( ii = 0; ii < n; ii++ )
				printf("%d ", arr[ii] );
			printf("\n");
*/
		}//for
//		printf("\n");

	}//for

}

//Selection sort
void selection_sort(int *arr, int n)
{
	printf("\nSelection sort\n\n");

	int i, ii, j, temp, smaller_num , count = 1;

	//Outer loop for checking smaller number, the number of times the number of elements
	for ( i = 0; i < n-1 ; i++ )
	{
		//Assign the current data as smaller element
		smaller_num = arr[i];

		//Inner loop for finding out smaller number in current array
		for ( j = i; j < n; j++ )
		{
			//If smaller number is greater then current number, assign the current number as smaller number, store current index
			if ( smaller_num > arr[j] )
				smaller_num = arr[j], count = j;
		}//for

		//Swap ith data with smallest number
		swap_numbers(&arr[i], &arr[count]);

		//Reset small number count
		count = 0;

/*		printf("Intermediate array:\t");
		for ( ii = 0; ii < n; ii++ )
			printf("%d ", arr[ii] );
		printf("\n\n");
*/
	}//for


}

int main()
{

	system("clear");

	int n, i;

	n = 9;

	//Prompt user for number of elements in array	
	printf("Enter the number of elements:"), scanf("%d", &n);

	int arr[n];
//	int arr[9] = {5, 3, 4, 7, 2, 8, 6, 9, 1};

	//Prompt user for elements in array
	printf("Enter the elements:");
	for ( i = 0; i < n; i++ )
		scanf("%d", &arr[i] );

	//Display original array
	printf("Original array:\t");
	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i] );
	}

	printf("\n");

	//Call bubble sort function
	bubble_sort(arr, n);

	//Call insertion sort function
//	insertion_sort(arr, n);

	//Call selection sort function
//	selection_sort(arr, n);

	//Display sorted array
	printf("Sorted array:\t");
	for ( i = 0; i < n; i++ )
		printf("%d ", arr[i] );

	printf("\n");


	return 0;
}
