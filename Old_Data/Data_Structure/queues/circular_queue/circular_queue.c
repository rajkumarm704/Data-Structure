#include<stdio.h>
#include<stdlib.h>
#include<circular_queue.h>

//Create queue
bool_queue_c create_queue(queue_c *q)
{
	printf("Enter the size of Circular Queue:"), scanf("%ld", &q->size );

	q->queue = malloc( q->size * sizeof( data_t ) );

	if ( q != NULL )
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
	if ( q->fidx < 0 && q->ridx < 0 )
	{
		q->fidx = 0;
		q->ridx = 0;
		q->queue[q->ridx] = data;
		q->count++;
		return success;

	}//if
 	else if ( q->count < (int)q->size - 1 )
	{
		q->ridx = ( q->ridx + 1) % (int)q->size;
		q->queue[q->ridx] = data;
		q->count++;
		return success;

	}//else if
	else if ( q->ridx == (int)q->size - 1 && q->count >=0 && q->count <= (int)q->size - 1 )
	{
		printf("Queue Initialised.\n");
		q->ridx = 0;
		q->count = 0;
		q->queue[q->ridx] = data;
		q->count++;
		return success;

	}//else if
	else if ( q->count == (int)q->size - 1 )
	{
		return queue_full_failure;

	}//else if

}

//Print the contenets of queue
bool_queue_c display_queue_c(queue_c *q)
{
	int i;

	printf("Queue is:");

if ( q->
	for ( i = q->fidx; i <= ( q->ridx ) % (int)q->size; i++ )
	{
		printf("%d ", q->queue[i] );

	}//for

	printf("\n");
	
	return success;

}

//Delete elements from Circular Queue
bool_queue_c dequeue_c(queue_c *q)
{
	if ( q->fidx >= 0 && q->fidx <= q->count )
	{
		q->fidx = ( q->fidx + 1 ) % (int)q->size ;
		return dequeue_success;

	}//if

}


