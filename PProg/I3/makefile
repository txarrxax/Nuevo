CC=gcc
CFLAGS=-Wall -ansi -pedantic -DDEBUG
FILES=obj/command.o obj/enemy.o obj/game.o obj/game_loop.o obj/game_reader.o obj/graphic_engine.o obj/inventory.o obj/link.o obj/object.o obj/player.o obj/set.o obj/space.o
TESTS=obj/command_test.o obj/enemy_test.o obj/game_test.o obj/game_loop_test.o obj/game_reader_test.o obj/inventory_test.o obj/link_test.o obj/object_test.o obj/player_test.o obj/set_test.o obj/space_test.o
CLIB=-lscreen -Llib
CINCL=-I include
f=-g

anthill: $(FILES)
	@if [ "$(f)" = "-g" ]; then\
		echo -e "\n\e[1m\e[93mEsta es una versión de testing, use la opción f=-On con n€[1, 3] para versión optimizada\n\e[0m\e[39m";\
	fi
	gcc -o anthill $(CFLAGS) $(FILES) $(CLIB) $(CINCL)

obj/command.o: src/command.c
	gcc $(CFLAGS) -c $^ -o $@ $(CINCL)

obj/enemy.o: src/enemy.c
	gcc $(CFLAGS) -c $^ -o $@ $(CINCL)

obj/game.o: src/game.c
	gcc $(CFLAGS) -c $^ -o $@ $(CINCL)

obj/game_loop.o: src/game_loop.c
	gcc $(CFLAGS) -c $^ -o $@ $(CINCL)

obj/game_reader.o: src/game_reader.c
	gcc $(CFLAGS) -c $^ -o $@ $(CINCL)

obj/graphic_engine.o: src/graphic_engine.c
	gcc $(CFLAGS) -c $^ -o $@ $(CINCL)

obj/inventory.o: src/inventory.c
	gcc $(CFLAGS) -c $^ -o $@ $(CINCL)

obj/link.o: src/link.c
	gcc $(CFLAGS) -c $^ -o $@ $(CINCL)

obj/object.o: src/object.c
	gcc $(CFLAGS) -c $^ -o $@ $(CINCL)

obj/player.o: src/player.c
	gcc $(CFLAGS) -c $^ -o $@ $(CINCL)

obj/set.o: src/set.c
	gcc $(CFLAGS) -c $^ -o $@ $(CINCL)

obj/space.o: src/space.c
	gcc $(CFLAGS) -c $^ -o $@ $(CINCL)



command_test: obj/command_test.o obj/command.o 
	gcc -o command_test $(CFLAGS) $^ $(CINCL)

obj/command_test.o: src/command_test.c
	gcc $(CFALGS) -c $^ -o $@ $(CINCL)


enemy_test: obj/enemy_test.o obj/enemy.o 
	gcc -o enemy_test $(CFLAGS) $^ $(CINCL)

obj/enemy_test.o: src/enemy_test.c
	gcc $(CFALGS) -c $^ -o $@ $(CINCL)


game_test: obj/game_test.o obj/game.o obj/player.o obj/space.o obj/object.o obj/link.o obj/set.o obj/game_reader.o obj/enemy.o obj/inventory.o 
	gcc -o game_test $(CFLAGS) $^ $(CINCL)

obj/game_test.o: src/game_test.c
	gcc $(CFALGS) -c $^ -o $@ $(CINCL)


game_reader_test: obj/game_reader_test.o obj/game_reader.o obj/game.o obj/space.o obj/object.o obj/set.o obj/player.o obj/inventory.o obj/enemy.o obj/link.o
	gcc -o game_reader_test $(CFLAGS) $^ $(CINCL)

obj/game_reader_test.o: src/game_reader_test.c
	gcc $(CFALGS) -c $^ -o $@ $(CINCL)


inventory_test: obj/inventory_test.o obj/inventory.o obj/set.o
	gcc -o inventory_test $(CFLAGS) $^ $(CINCL)

obj/inventory_test.o: src/inventory_test.c
	gcc $(CFALGS) -c $^ -o $@ $(CINCL)


link_test: obj/link_test.o obj/link.o
	gcc -o link_test $(CFLAGS) $^ $(CINCL)

obj/link_test.o: src/link_test.c
	gcc $(CFLAGS) -c $^ -o $@ $(CINCL)

object_test: obj/object_test.o obj/object.o
	gcc -o object_test $(CFLAGS) $^ $(CINCL)

obj/object_test.o: src/object_test.c
	gcc $(CFLAGS) -c $^ -o $@ $(CINCL)


player_test: obj/player_test.o obj/player.o obj/inventory.o obj/set.o
	gcc -o player_test $(CFLAGS) $^ $(CINCL)

obj/player_test.o: src/player_test.c
	gcc $(CFALGS) -c $^ -o $@ $(CINCL)


set_test: obj/set.o obj/set_test.o
	gcc -o set_test $(CFLAGS) $^ $(CINCL)

obj/set_test.o: src/set_test.c
	gcc $(CFALGS) -c $^ -o $@ $(CINCL)


space_test: obj/space_test.o obj/space.o obj/set.o
	gcc -o space_test $(CFLAGS) $^ $(CINCL)

obj/space_test.o: src/space_test.c
	gcc $(CFALGS) -c $^ -o $@ $(CINCL)



clean:
	rm -f obj/*.o
	rm -f command_test
	rm -f enemy_test
	rm -f inventory_test
	rm -f game_test
	rm -f game_reader_test
	rm -f link_test
	rm -f object_test
	rm -f player_test
	rm -f set_test
	rm -f space_test
	

run:
	./anthill anthill.dat

runv:
	valgrind --leak-check=full ./anthill anthill.dat
