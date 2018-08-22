NAME=stack_m

$(NAME): $(NAME).o stack.o
	gcc -std=c99 -Wall -o $(NAME) $(NAME).o stack.o -I.

# add -DNDEBUG to indicate we don't include assert in compile time
ndebug: $(NAME).o stack.o
	gcc -std=c99 -Wall -o $(NAME) $(NAME).o stack.o -I. -DNDEBUG
float: $(NAME).o-float stack.o-float
	gcc -std=c99 -Wall -o $(NAME) $(NAME).o stack.o -I.
double: $(NAME).o-double stack.o-double
	gcc -std=c99 -Wall -o $(NAME) $(NAME).o stack.o -I.

$(NAME).o: $(NAME).c
	gcc -std=c99 -Wall -c $(NAME).c -o $(NAME).o -I.
$(NAME).o-float: $(NAME).c
	gcc -std=c99 -Wall -c $(NAME).c -o $(NAME).o -I. -DSTACK_TYPE=float -DSTACK_TYPE_FP=1
$(NAME).o-double: $(NAME).c
	gcc -std=c99 -Wall -c $(NAME).c -o $(NAME).o -I. -DSTACK_TYPE=double -DSTACK_TYPE_FP=1
stack.o: stack.c stack.h
	gcc -std=c99 -Wall -c stack.c -o stack.o -I.
stack.o-float: stack.c stack.h
	gcc -std=c99 -Wall -c stack.c -o stack.o -I. -DSTACK_TYPE=float -DSTACK_TYPE_FP=1
stack.o-double: stack.c stack.h
	gcc -std=c99 -Wall -c stack.c -o stack.o -I. -DSTACK_TYPE=double -DSTACK_TYPE_FP=1
clean:
	rm -rf $(NAME)
	rm -rf *.o
