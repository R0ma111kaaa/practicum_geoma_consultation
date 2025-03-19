clear:
	rm -rf *.o *.a *_test

stack.o: stack.h stack.c
	gcc -g -c stack.c -o stack.o

stack.a: stack.o
	ar rc stack.a stack.o

stack_test.o: stack_test.c stack.a
	gcc -g -c stack_test.c -o stack_test.o

stack_test: stack_test.o stack.a
	gcc -g -static -o stack_test stack_test.o stack.a -lm

test: stack_test
	./stack_test