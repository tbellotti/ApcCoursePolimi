all: stack_test
stack_test : stack_test.o
	g++ -Wall stack_test.o -o stack_test

stack_test.o : stack_test.cpp
	g++ -Wall stack_test.cpp -c -o stack_test.o

clean :
	rm -rf *.o

distclean :
	rm -f stack_test