CC=gcc
CFLAGS=-Wall -Wextra -g
OBJS=main.o hashmap.o

bin: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o bin

run: bin
	./bin

clean:
	rm -f *.o bin
