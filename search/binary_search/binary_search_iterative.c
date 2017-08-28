#include<stdio.h>
#include<stdlib.h>

int main()
{

	system("clear");

	//Main array
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int start, end, mid, i, key;

	start = 0;

	//Finding the size of main array
	end = (sizeof( arr )/4) - 1;

	//Find the mid element index
	mid = ( start + end ) / 2 ;

	//Display the main array
	printf("Array is:");
	for (i = 0; i < (sizeof(arr)/4); i++)
	{
		printf("%d ", arr[i] );
	}

	//Prompt user for data to search
	printf("\nEnter the data to search:"), scanf("%d", &key);

	//Run an infinite loop
	while ( 1 )
	{
		//If the data to be searched is greater than mid element, change start index to the next index of mid index
		if (  key > arr[mid] ) 
		{
			start = mid + 1;
		}
		//If the data to be searched is smaller than mid element, change end index to the previous index of mid index
		else if ( key < arr[mid] )
		{
			end = mid - 1;
		}
		
		//Update the mid element index
		mid = ( start + end ) / 2;

		//If start index crosses end index, and data is not found; display the message and quit
		if ( start > end || start == end && arr[mid] != key )
		{
			printf("Data not found\n");
			break;
		}

		//If the data is found; display the message and quit
		else if ( arr[mid] == key || arr[start] == key || arr[end] == key )
		{
			printf("Data found\n");
			break;
		}

	}//while

	return 0;
}
