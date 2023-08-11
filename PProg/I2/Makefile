CC=gcc
CFLAGS=-Wall -pedantic -ansi -g -DDEBUG
CLIB= -lscreen -L.


hormiguero: graphic_engine.o object.o enemy.o command.o game_loop.o space.o game_reader.o player.o game.o set.o
	$(CC) -o $@ $^ $(CLIB)

graphic_engine.o: graphic_engine.c 
	$(CC) $(CFLAGS) -c $<

object.o: object.c 
	$(CC) $(CFLAGS) -c $<

enemy.o: enemy.c
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

set.o: set.c
	$(CC) $(CFLAGS) -c $<

test: space_test enemy_test set_test

space_test: space_test.o space.o set.o
	$(CC) -o $@ $^ $(CLIB)

enemy_test: enemy_test.o enemy.o
	$(CC) -o $@ $^ $(CLIB)

set_test: set_test.o set.o
	$(CC) -o $@ $^ $(CLIB)

space_test.o: space_test.c
	$(CC) $(CFLAGS) -c $<

enemy_test.o: enemy_test.c
	$(CC) $(CFLAGS) -c $<

set_test.o: set_test.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o hormiguero space_test enemy_test set_test

run:
	./hormiguero anthill.dat

runv:
	valgrind ./hormiguero anthill.dat

prueba: main_prueba.o 
	$(CC) -o $<
 main_prueba.o: main_prueba.c 
	$(CC) -c $<
