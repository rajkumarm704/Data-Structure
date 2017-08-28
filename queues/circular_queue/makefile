CFLAG := -I ../../Include/

../../Library/libqueue_c.so : circular_queue.c
	gcc $^ -fPIC -shared ${CFLAG} -o ../../Library/libqueue_c.so

clean :
	rm ../../Library/libqueue_c.so
