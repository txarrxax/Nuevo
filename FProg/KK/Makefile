CC = gcc
CFLAGS = -g -Wall -ansi -pedantic

#battleship: game.o player.o board.o
#	$(CC) $(CFLAGS) -o battleship $^

game.o: game.c
	$(CC) $(CFLAGS) $^ -c $@

player.o: player.c
	$(CC) $(CFLAGS) $^ -c $@

board.o: board.c
	$(CC) $(CFLAGS) $^ -c $@

clean:
	rm *.o battleship