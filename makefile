.PHONY: clean run compile
run: fork
	@./fork
clean:
	rm *.o
	rm fork
compile fork: fork.o
	@gcc -o fork fork.o -lm
