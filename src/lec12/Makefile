CC      = gcc
CFLAGS  = -Wall -g -std=c11

myproj: main.o mylib.o
	$(CC) $(CFLAGS) -o myproj main.o mylib.o

main.o: main.c mylib.h
	$(CC) $(CFLAGS) -c main.c

mylib.o: mylib.c mylib.h
	$(CC) $(CFLAGS) -c mylib.c

clean:
	rm -f *.o myproj
