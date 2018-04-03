
test: test.o is_number.o
	@$(CC) -O $^ -o $@
	@./test

clean:
	rm -f test.o is_number.o test

.PHONY: clean test

