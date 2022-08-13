ex9.exe: ex9.o stack.o
	gcc -o ex9.exe ex9.o stack.o

ex9.o: ex9.c stack.h
	gcc -c ex9.c

stack.o: stack.c stack.h
	gcc -c stack.c

clean:
	rm *.o
