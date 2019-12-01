CC = gcc
AR = ar rcs
CFLAGS = -Wall -c
DEPS = myBank.h
OBJ = myBank.o

.PHONY : all clean mains mybank

all : mybank mains

mybank : $(OBJ)
	$(AR) libmyBank.a $(OBJ)

mains :	main.o mybank
	$(CC) -o $@ main.o -I. -L. ./libmyBank.a

main.o : main.c $(DEPS)
	$(CC) $(CFLAGS) main.c

myBank.o : myBank.c $(DEPS)
	$(CC) $(CFLAGS) myBank.c

clean :
	rm -f *.o *.a mains
