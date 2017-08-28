###############################################################
SOURCES := $(wildcard *.c)
TARGETS := $(SOURCES:.c=.out)
CFLAG := -I ../Include/
LFLAG := -L ../Library/ -lfun -lbitwise -lslist -ldlist -larray_stack -lqueue_c
###############################################################

#			flags				      #
###############################################################
all : ${TARGETS}

#array stacks
#reset : clear_screen clean_larray_stack_lib make_larray_stack_lib clean_array_stack_main.out array_stack_main.out

#dlist
#reset : clear_screen clear_screen clean_dlist_lib dlist_lib clean ${TARGETS}

#slist
reset :  clear_screen clean_slist_lib make_slist_lib clean_slist_main.out slist_main.out

#queue_c
#reset : clear_screen clean_lqueue_c make_lqueue_c clean_circular_queue_main circular_queue_main.out

###############################################################

#			basic				      #
###############################################################
clear_screen :
	clear
%.out : %.c
	gcc $^ ${CFLAG} ${LFLAG} -o $@
clean : 
	rm ${TARGETS}
###############################################################

#		circular_queue				      #
###############################################################

make_lqueue_c :
	make -C ../queues/circular_queue

clean_lqueue_c :
	make clean -C ../queues/circular_queue

circular_queue_main.out : circular_queue_main.c
	gcc $^ ${CFLAG} ${LFLAG} -o $@

clean_circular_queue_main :
	rm circular_queue_main.out

###############################################################


#		array_stack_main			      #
###############################################################
array_stack_main.out : array_stack_main.c
	gcc $^ ${CFLAG} ${LFLAG} -o $@

make_larray_stack_lib :
	make -C ../stacks/array_stacks/

clean_larray_stack_lib :
	make clean -C ../stacks/array_stacks/

clean_array_stack_main.out :
	rm array_stack_main.out
###############################################################

#			slist				      #
###############################################################
clean_slist_main.out :
	rm slist_main.out

slist_main.out : slist_main.c
	gcc $^ 	${CFLAG} ${LFLAG} -o $@

make_slist_lib :
	make -C ../slist/
clean_slist_lib :
	make clean -C ../slist/
###############################################################

#			dlist				      #
###############################################################
dlist_lib :
	make -C ../dlist/
clean_dlist_lib :
	make clean -C ../dlist/
dlist_main.out : dlist_main.c
	gcc $^ ${CFLAG} ${LFLAG} -o $@
###############################################################


