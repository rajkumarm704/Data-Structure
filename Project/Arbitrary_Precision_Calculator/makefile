all : main.out

reset : clean main.out


main.out : main.c
	gcc main.c apc.c dlist.c -o main.out

clean :
	rm main.out
