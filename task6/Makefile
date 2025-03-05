clear:
	rm -rf *.o *.a *_test

list.o: list.h list.c
	gcc -g -c list.c -o list.o

list.a: list.o
	ar rc list.a list.o

list_test.o: list_test.c list.a
	gcc -g -c list_test.c -o list_test.o

list_test: list_test.o list.a
	gcc -g -static -o list_test list_test.o list.a -lm

test: list_test
	./list_test