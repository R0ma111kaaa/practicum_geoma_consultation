clear:
	rm -rf *.o *.a *_test

check_fmt:
	clang-format -style=LLVM -i `find -regex ".+\.[ch]"` --dry-run --Werror

fmt:
	clang-format -style=LLVM -i `find -regex ".+\.[ch]"`

square_solution.o: square_solution.h square_solution.c
	gcc -g -c square_solution.c -o square_solution.o

square_solution.a: square_solution.o
	ar rc square_solution.a square_solution.o

square_test.o: square_test.c
	gcc -g -c square_test.c -o square_test.o

square_test: square_test.o square_solution.a
	gcc -g -static -o square_test square_test.o adsquare_solutiond.a

test: square_test
	./*_test

