OBJS = bst.o main.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

main: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o main

clean:
	rm *.o *~ main
