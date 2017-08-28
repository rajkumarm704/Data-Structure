CFLAG := -I ../Include/

../Library/libslist.so : slist.c
	gcc -fPIC -shared ${CFLAG} slist.c -o ../Library/libslist.so
clean :
	rm ../Library/libslist.so
