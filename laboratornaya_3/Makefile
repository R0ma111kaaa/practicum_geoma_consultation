SRC := gc.c destructors.c cycles.c ../laboratornaya_2/pool_allocator.c
TEST_DIR := ./tests
TEST_FILES := $(wildcard $(TEST_DIR)/*_test.c)

CFLAGS := -Wall -Wextra -I./src -I../laboratornaya_2

test:
	@for file in $(TEST_FILES); do \
		outfile=$$(mktemp); \
		gcc $(CFLAGS) -o $$outfile $$file $(SRC) && $$outfile || exit 1; \
		rm -f $$outfile; \
	done
	@echo "все тесты завершены успешно"

valgrind:
	@for file in $(TEST_FILES); do \
		outfile=$$(mktemp); \
		gcc -g $(CFLAGS) -o $$outfile $$file $(SRC) && \
		valgrind --leak-check=full --error-exitcode=1 $$outfile || exit 1; \
		rm -f $$outfile; \
	done
	@echo "все тесты под valgrind завершены успешно"

clear:
	rm -rf *.o *.a *_test
