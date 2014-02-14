OBJS = bst.o main.o
INC = bst.h
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

main: $(OBJS) $(INC)
	$(CC) $(LFLAGS) $(OBJS) -o main

clean:
	rm *.o *~ main
