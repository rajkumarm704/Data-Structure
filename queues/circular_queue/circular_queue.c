#include<stdio.h>
#include<stdlib.h>
#include<circular_queue.h>

//Create queue
bool_queue_c create_queue(queue_c *q)
{
	//Prompt user for size of queue
	printf("Enter the size of Circular Queue:"), scanf("%ld", &q->size );

	//Allocate memory for queue
	q->queue = malloc( q->size * sizeof( data_t ) );

	//Check if memory was allocated
	if ( q->queue != NULL )
	{
		q->fidx = -1;
		q->ridx = -1;
		q->count = -1;
		return queue_created_success;
	}//if
	else
		return queue_not_created_failure;

}

//Add elements into queue
bool_queue_c enqueue_c(queue_c *q, data_t data)
{

	//If number of data in queue is equal to size of queue, return queue full error
	if ( q->count == (int)q->size - 1 )
	{
		printf("q->count:%d\tq->fidx:%d\tq->ridx:%d\n", q->count, q->fidx, q->ridx);
		return queue_full_failure;

	}//if

	//If front and rear index is smaller than 0, initialise the queue indicies
	else if ( q->fidx < 0 && q->ridx < 0 )
	{
		q->fidx = 0;
		q->ridx = 0;

		//Insert data into queue
		q->queue[q->ridx] = data;

		//Increment the number of data count
		q->count++;

//		printf("q->count:%d\tq->fidx:%d\tq->ridx:%d\n", q->count, q->fidx, q->ridx);
		return success;

	}//else if

	//If queue has empty space, insert element
 	else if ( q->count < (int)q->size )
	{

		//Increment the rear index using modulus operator
		q->ridx = ( q->ridx + 1) % (int)q->size;

		//Insert data into queue
		q->queue[q->ridx] = data;

		//Increment the number of data count
		q->count++;

//		printf("q->count:%d\tq->fidx:%d\tq->ridx:%d\n", q->count, q->fidx, q->ridx);
		return success;

	}//else if

	//If rear index is equal to one less than size of queue and queue has empty space, enter data at start
	else if ( q->ridx == (int)q->size - 1 && q->count >=0 && q->count < (int)q->size )
	{
		printf("Queue Initialised.\n");
		q->ridx = 0;
		//Insert data into queue
		q->queue[q->ridx] = data;

		//Increment the number of data count
		q->count++;

//		printf("q->count:%d\tq->fidx:%d\tq->ridx:%d\n", q->count, q->fidx, q->ridx);
		return success;

	}//else if

}

//Print the contents of queue
bool_queue_c display_queue_c(queue_c *q)
{
	int i;

	//Return failure if queue is empty
	if ( q->count < 0 )
		return queue_empty_failure;

	//If queue has data, display them
	else if ( q->count >= 0 && q->count < q->size )
	{
		printf("Queue is:");

		//Display data in queue from front index o rear index using modulus operator
		for ( i = q->fidx; i != q->ridx ; i = ( i + 1 ) % (int)q->size )
		{
			printf("%d ", q->queue[i] );

		}//for

		//Display last data
		printf("%d\n", q->queue[i] );
	
		return success;
	}
}

//Delete elements from Circular Queue
bool_queue_c dequeue_c(queue_c *q)
{
	//If front index is greater than 0 and less than size, decrement count and increment front index
	if ( q->fidx >= 0 && q->fidx < q->size && q->count >= 0)
	{
		q->fidx = ( q->fidx + 1 ) % (int)q->size ;
		q->count--;
		return dequeue_success;

	}//if

	//Return queue empty failure is queue is empty
	else if ( q->count < 0 )
	{
		return queue_empty_failure;

	}//else if
}


