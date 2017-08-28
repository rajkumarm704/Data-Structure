CFLAG := -I ../../Include/

../../Library/libarray_stack.so : array_stack.c
	gcc -fPIC -shared ${CFLAG} array_stack.c -o ../../Library/libarray_stack.so
clean :
	rm ../../Library/libarray_stack.so
