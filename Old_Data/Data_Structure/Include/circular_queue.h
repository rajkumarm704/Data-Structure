#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

typedef int data_t;

typedef enum
{
	queue_not_created_failure, queue_full_failure, queue_created_success, success, dequeue_success

}bool_queue_c;

typedef struct _queue_circular
{
	data_t *queue;
	data_t fidx;
	data_t ridx;
	size_t size;
	int count;

}queue_c;


//Create queue
bool_queue_c create_queue(queue_c *q);

//Add elements into queue
bool_queue_c enqueue_c(queue_c *q, data_t data);

//Print the contenets of queue
bool_queue_c display_queue_c(queue_c *q);

//Delete elements from Circular Queue
bool_queue_c dequeue_c(queue_c *q);

#endif
