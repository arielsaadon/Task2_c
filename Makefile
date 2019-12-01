CC = gcc
AR = ar rcs
CFLAGS = -Wall -c
DEPS = myBank.h
OBJ = myBank.o

all : mybank mains

mybank : $(OBJ)
	$(AR) libmyBank.a $(OBJ)

mains :	main.o mybank
	$(CC) -o $@ main.o -I. -L. ./libmyBank.a

main.o : main.c $(DEPS)
	$(CC) $(CFLAGS) main.c

myBank.o : myBank.c $(DEPS)
	$(CC) $(CFLAGS) myBank.c

.PHONY : all clean mybank

clean :
	rm -f *.o *.a mains
