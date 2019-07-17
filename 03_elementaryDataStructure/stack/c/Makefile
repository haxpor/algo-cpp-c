NAME=stack_m
CMD_MKDIR=mkdir -p
BUILD_DIR=build

# main targets to build include (normal), ndebug, float, and double
# - (normal) - normal, use assert, Stack uses int type
# - ndebug - not use assert, Stack uses int type
# - float - use assert, Stack uses float type
# - double - use assert, Stack users double type
$(NAME): $(NAME).o stack.o
	${CMD_MKDIR} ${BUILD_DIR}
	gcc -std=c99 -Wall -o $(BUILD_DIR)/$(NAME) $(BUILD_DIR)/$(NAME).o $(BUILD_DIR)/stack.o -I.
# add -DNDEBUG to indicate we don't include assert in compile time
ndebug: $(NAME).o stack.o
	gcc -std=c99 -Wall -o $(BUILD_DIR)/$(NAME) $(BUILD_DIR)/$(NAME).o $(BUILD_DIR)/stack.o -I. -DNDEBUG
float: $(NAME).o-float stack.o-float
	gcc -std=c99 -Wall -o $(BUILD_DIR)/$(NAME) $(BUILD_DIR)/$(NAME).o $(BUILD_DIR)/stack.o -I.
double: $(NAME).o-double stack.o-double
	gcc -std=c99 -Wall -o $(BUILD_DIR)/$(NAME) $(BUILD_DIR)/$(NAME).o $(BUILD_DIR)/stack.o -I.

$(NAME).o: $(NAME).c
	${CMD_MKDIR} ${BUILD_DIR}
	gcc -std=c99 -Wall -c $(NAME).c -o $(BUILD_DIR)/$(NAME).o -I.
$(NAME).o-float: $(NAME).c
	${CMD_MKDIR} ${BUILD_DIR}
	gcc -std=c99 -Wall -c $(NAME).c -o $(BUILD_DIR)/$(NAME).o -I. -DSTACK_TYPE=float -DSTACK_TYPE_FP=1
$(NAME).o-double: $(NAME).c
	${CMD_MKDIR} ${BUILD_DIR}
	gcc -std=c99 -Wall -c $(NAME).c -o $(BUILD_DIR)/$(NAME).o -I. -DSTACK_TYPE=double -DSTACK_TYPE_FP=1

stack.o: stack.c stack.h
	gcc -std=c99 -Wall -c stack.c -o $(BUILD_DIR)/stack.o -I.
stack.o-float: stack.c stack.h
	gcc -std=c99 -Wall -c stack.c -o $(BUILD_DIR)/stack.o -I. -DSTACK_TYPE=float -DSTACK_TYPE_FP=1
stack.o-double: stack.c stack.h
	gcc -std=c99 -Wall -c stack.c -o $(BUILD_DIR)/stack.o -I. -DSTACK_TYPE=double -DSTACK_TYPE_FP=1

clean:
	rm -rf $(BUILD_DIR)/$(NAME)
	rm -rf $(BUILD_DIR)/*.o
