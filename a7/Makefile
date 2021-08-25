all: a.out

a.out: queue.c queue.h stack.c stack.h tree.c tree.h files.c
	gcc -g  queue.c queue.h stack.c stack.h tree.c tree.h files.c -o a.out

.PHONY: run
run:
	./a.out
.PHONY: clean
clean:
	rm ./a.out
