CC=gcc
CFLAGS=-Wall -pedantic -ansi -g -DDEBUG
CLIB= -lscreen -L.


hormiguero: graphic_engine.o object.o command.o game_loop.o space.o game_reader.o player.o game.o
	$(CC) -o $@ $^ $(CLIB)

graphic_engine.o: graphic_engine.c 
	$(CC) $(CFLAGS) -c $<

object.o: object.c 
	$(CC) $(CFLAGS) -c $<

command.o: command.c 
	$(CC) $(CFLAGS) -c $<

game_loop.o: game_loop.c 
	$(CC) $(CFLAGS) -c $<

space.o: space.c 
	$(CC) $(CFLAGS) -c $<

game_reader.o: game_reader.c 
	$(CC) $(CFLAGS) -c $<

player.o: player.c 
	$(CC) $(CFLAGS) -c $<

game.o: game.c 
	$(CC) $(CFLAGS) -c $<	

clean:
	rm -f *.o hormiguero