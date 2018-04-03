
CFLAGS=-Wall -Wextra -O

test: test.o is_number.o
	@$(CC) $(CFLAGS) -O $^ -o $@
	@./test

clean:
	rm -f test.o is_number.o test

.PHONY: clean test

