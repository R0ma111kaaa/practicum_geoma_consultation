clear:
	rm -rf *.o *.a *_test

quadratic.o: quadratic.h quadratic.c
	gcc -g -c quadratic.c -o quadratic.o

quadratic.a: quadratic.o
	ar rc quadratic.a quadratic.o

quadratic_test.o: quadratic_test.c quadratic.a
	gcc -g -c quadratic_test.c -o quadratic_test.o

quadratic_test: quadratic_test.o quadratic.a
	gcc -g -static -o quadratic_test quadratic_test.o quadratic.a -lm

test: quadratic_test
	./quadratic_test
