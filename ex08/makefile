# Make file that builds executable file main.exe

CC= gcc
CFLAGS= -ansi

ex8.exe: ex8.o tree.o
	$(CC) $(CFLAGS) -o ex8.exe ex8.o tree.o

ex8.o: ex8.c tree.h
	$(CC) $(CFLAGS) -c ex8.c

tree.o: tree.c tree.h
	$(CC) $(CFLAGS) -c tree.c

clean:
		rm *.o
