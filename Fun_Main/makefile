#					(main makefile)		DATE:25-07-2017


#makefile using library

TARGET := main.out
SOURCES := main.c
CFLAG := -I ../Include/			#Header file
LFLAG := -L ../Library/ -lfun		#Library files

all : ${TARGET}

${TARGET} : ${SOURCES}
	gcc ${CFLAG} ${LFLAG} ${SOURCES} -o ${TARGET}
#	gcc ${SOURCES} ${CFLAG} ${LFLAG} -o ${TARGET}
clean:
	rm ${TARGET}


#makefile using variables		

#TARGET := main.out
#SOURCES := main.c ../Fun/fun.c
#OBJS := fun.o main.o
#CFLAG := -I ../Include/
#
#all : ${OBJS} ${TARGET}
#
#${OBJS} : ${SOURCES}
#	gcc ${CFLAG} -c ${SOURCES}
#${TARGET} : ${OBJS}
#	gcc ${OBJS} -o ${TARGET}
#clean:
#	rm ${OBJS} ${TARGET}


#makefile using names

#all : main.o fun.o main.out clean_object
#main.o : main.c
#	gcc -I ../Include/ -c main.c
#fun.o : ../Fun/fun.c
#	gcc -c ../Fun/fun.c
#main.out : fun.o main.o
#	gcc main.o fun.o -o main.out
#clean_object :
#	rm *.o
#clean :
#	rm *.o main.out
