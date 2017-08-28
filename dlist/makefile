CFLAG := -I ../Include/

../Library/libdlist.so : dlist.c
	gcc -fPIC -shared ${CFLAG} dlist.c -o ../Library/libdlist.so
clean :
	rm ../Library/libdlist.so
