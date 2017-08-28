#include<stdio.h>
#include<stdlib.h>

//user defined data type for flags
typedef enum
{
	found, not_found
}bool_t;

//Binary search function
bool_t binary_search(int *arr, int mid, int key, int start, int end)
{
	//If the element to found is at mid of array; return (base condition)
	if (arr[mid] == key)
	{
		return found;	
	}

	//If start and end index are equal, return data not found
	if (start == end)
	{
		return not_found;
	}

	//If the data to be searched is greater than mid element, change start & mid index to the next index of mid index, call the function recursively
	if (key > arr[mid])
	{
		start = mid + 1;
		mid = (start + end)/2;
		binary_search(arr, mid, key, start, end);
	}

	//If the data to be searched is smaller than mid element, change end & mid index to the previous index of mid index, call the function recursively
	else if (key < arr[mid])
	{
		end = mid-1;
		mid = (start + end)/2;
		binary_search(arr, mid, key, start, end);	
	}

}

int main()
{

	system("clear");

	//Main array
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	
	int key, i, n, mid ;

	//Find the size of array
	n = (sizeof(arr) / 4);

	//Find the mid element index
	mid = n/2;

	//Initialise the start & end index
	int start = 0, end = n-1;

	bool_t status;

	//Display the main array
	printf("Array is:");
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);

	//Prompt user for data to search
	printf("\nEnter the data to search:"), scanf("%d", &key);

	//Call the binary search funtion
	status = binary_search(arr, mid, key, start, end);

	//Print message according to flags
	if (status == found)
		printf("Data found.\n");
	else if (status == not_found)
		printf("Data not found.\n");

	return 0;
}
