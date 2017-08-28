#makefile for creating library			(library makefile)		DATE:25-07-2017


TARGET := ../Library/libfun.so
SOURCES := fun.c

all : ${TARGET}

${TARGET} : ${SOURCES}
	gcc -fPIC -shared ${SOURCES} -o ${TARGET}
clean:
	rm ${OBJS} ${TARGET}

