clear:
	rm -rf *.o *.a *_test

integral.o: integral.h integral.c
	gcc -g -c integral.c -o integral.o

integral.a: integral.o
	ar rc integral.a integral.o

integral_test.o: integral_test.c integral.a
	gcc -g -c integral_test.c -o integral_test.o

integral_test: integral_test.o integral.a
	gcc -g -static -o integral_test integral_test.o integral.a -lm

test: integral_test
	./integral_test