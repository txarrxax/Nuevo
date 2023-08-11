CC=gcc
CFLAGS=-Wall -ansi -pedantic
FILES=position.o track.o gps.o main.o

gps: $(FILES)
	$(CC) -o gps $(FILES)

position.o: position.c
	$(CC) $(CFLAGS) -c $<

track.o: track.c
	$(CC) $(CFLAGS) -c $<

gps.o: gps.c
	$(CC) $(CFLAGS) -c $<

main.o: main.c
	$(CC) $(CFLAGS) -c $<

runv:
	valgrind ./gps

clean:
	rm -f *.o gps