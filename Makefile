CC = clang
CFLAGS = -g -Wall 

all: main

build_main: main

main: main.o linkedlist_lib.o guards.o
	@echo "Building main"
	${CC} ${CFLAGS} main.o linkedlist_lib.o guards.o -o main

guards.o: guards.c
	${CC} ${CFLAGS} -c guards.c

main.o: main.c
	@echo "Compiling main.c file"
	${CC} ${CFLAGS} -c main.c

string_lib.o: linkedlist_lib.c
	@echo "Compiling linkedlist_lib.c file"
	${CC} ${CFLAGS} -c linkedlist_lib.c

run:
	./main

clean: 
	rm -f *.o main
