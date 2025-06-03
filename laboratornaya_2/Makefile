clear:
	rm -rf *.o *.a *_test

check_fmt:
	clang-format -style=LLVM -i `find -regex ".+\.[ch]"` --dry-run --Werror

fmt:
	clang-format -style=LLVM -i `find -regex ".+\.[ch]"`

.PHONY: test

SRC := linear_allocator.c pool_allocator.c array_list.c hashtable.c
TEST_DIR := ./tests
TEST_FILES := $(wildcard $(TEST_DIR)/*_test.c)

test:
	@for file in $(TEST_FILES); do \
		outfile=$$(mktemp); \
		gcc -I./src -o $$outfile $$file $(SRC) && $$outfile || exit 1; \
		rm -f $$outfile; \
	done
	@echo "все тесты завершены успешно"
	