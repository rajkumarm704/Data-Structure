SOURCE 	:= main.c
TARGET 	:= main.out
CFLAG	:= -I ../Include/
LFLAG	:= -L ../Library/ -lbitwise 

all	: ${TARGET}
reset : clean_lib make_lib clean ${TARGET}

${TARGET} : ${SOURCE}
	gcc ${CFLAG} ${LFLAG} ${SOURCE} -o ${TARGET}
clean	:
	rm ${TARGET}
clean_lib : 
	make clean -C ../bitwise/
make_lib :
	make -C ../bitwise/



#all : main.o bitwise.o main.out

#main.o : main.c
#	gcc -I ../Include/ -c main.c
#bitwise.o : ../bitwise/bitwise.c
#	gcc -c ../bitwise/bitwise.c
#main.out : main.o bitwise.o
#	gcc main.o bitwise.o -o main.out
#clean :
#	rm *.o *.out
