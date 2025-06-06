clear:
	rm -rf *.o *.a *_test

check_fmt:
	clang-format -style=LLVM -i `find -regex ".+\.[ch]"` --dry-run --Werror

fmt:
	clang-format -style=LLVM -i `find -regex ".+\.[ch]"`

TASK_DIRS := $(shell find . -maxdepth 1 -type d \( -name 'task[0-9]*' -o -name 'laboratornaya_*' \))

.PHONY: test $(TASK_DIRS)

test: $(TASK_DIRS)
	@echo "Все тесты завершены успешно или их не было вообще"

$(TASK_DIRS):
	$(MAKE) -C $@ test