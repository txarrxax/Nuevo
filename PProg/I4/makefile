CC=gcc
CFLAGS=-Wall -ansi -pedantic
FILES=obj/command.o obj/dialogue.o obj/enemy.o obj/game.o obj/game_loop.o obj/game_management.o obj/game_rules.o obj/graphic_engine.o obj/inventory.o obj/link.o obj/object.o obj/player.o obj/set.o obj/space.o
TESTS=obj/command_test.o obj/enemy_test.o obj/game_test.o obj/game_management_test.o obj/game_rules_test.o obj/inventory_test.o obj/link_test.o obj/object_test.o obj/player_test.o obj/set_test.o obj/space_test.o
CLIB=-lscreen -Llib
CINCL=-I include
f=-g

anthill: $(FILES)
	@if [ "$(f)" = "-g" ]; then\
		echo -e "\n\e[1m\e[93mEsta es una versión de testing, use la opción f=-On con n€[1, 3] para versión optimizada\n\e[0m\e[39m";\
	fi
	gcc $(f) -o anthill $(CFLAGS) -DDEBUG $(FILES) $(CLIB) $(CINCL)

obj/command.o: src/command.c
	gcc $(f) $(CFLAGS) -c $^ -o $@ $(CINCL)

obj/dialogue.o: src/dialogue.c
	gcc $(f) $(CFLAGS) -c $^ -o $@ $(CINCL)

obj/enemy.o: src/enemy.c
	gcc $(f) $(CFLAGS) -c $^ -o $@ $(CINCL)

obj/game.o: src/game.c
	gcc $(f) $(CFLAGS) -c $^ -o $@ $(CINCL)

obj/game_loop.o: src/game_loop.c
	gcc $(f) $(CFLAGS) -c $^ -o $@ $(CINCL)

obj/game_management.o: src/game_management.c
	gcc $(f) $(CFLAGS) -c $^ -o $@ $(CINCL)

obj/game_rules.o: src/game_rules.c 
	gcc $(f) $(CFLAGS) -c $^ -o $@ $(CINCL)

obj/graphic_engine.o: src/graphic_engine.c
	gcc $(f) $(CFLAGS) -c $^ -o $@ $(CINCL)

obj/inventory.o: src/inventory.c
	gcc $(f) $(CFLAGS) -c $^ -o $@ $(CINCL)

obj/link.o: src/link.c
	gcc $(f) $(CFLAGS) -c $^ -o $@ $(CINCL)

obj/object.o: src/object.c
	gcc $(f) $(CFLAGS) -c $^ -o $@ $(CINCL)

obj/player.o: src/player.c
	gcc $(f) $(CFLAGS) -c $^ -o $@ $(CINCL)

obj/set.o: src/set.c
	gcc $(f) $(CFLAGS) -c $^ -o $@ $(CINCL)

obj/space.o: src/space.c
	gcc $(f) $(CFLAGS) -c $^ -o $@ $(CINCL)


command_test: obj/command_test.o obj/command.o 
	gcc $(f) -o command_test $(CFLAGS) $^ $(CINCL)

obj/command_test.o: src/command_test.c
	gcc $(f) $(CFALGS) -c $^ -o $@ $(CINCL)


enemy_test: obj/enemy_test.o obj/enemy.o 
	gcc $(f) -o enemy_test $(CFLAGS) $^ $(CINCL)

obj/enemy_test.o: src/enemy_test.c
	gcc $(f) $(CFALGS) -c $^ -o $@ $(CINCL)


game_test: obj/game_test.o obj/game.o obj/command.o obj/space.o obj/object.o obj/player.o obj/enemy.o obj/link.o obj/dialogue.o obj/set.o obj/game_management.o obj/inventory.o
	gcc $(f) -o game_test $(CFLAGS) $^ $(CINCL)

obj/game_test.o: src/game_test.c
	gcc $(f) $(CFALGS) -c $^ -o $@ $(CINCL)


game_management_test: obj/game_management_test.o obj/game_management.o obj/game.o obj/space.o obj/object.o obj/set.o obj/player.o obj/inventory.o obj/enemy.o obj/link.o obj/dialogue.o 
	gcc $(f) -o game_management_test $(CFLAGS) $^ $(CINCL)

obj/game_management_test.o: src/game_management_test.c
	gcc $(f) $(CFALGS) -c $^ -o $@ $(CINCL)


game_rules_test: obj/game_rules_test.o obj/game_rules.o obj/game.o obj/player.o obj/space.o obj/object.o obj/link.o obj/set.o obj/game_management.o obj/enemy.o obj/inventory.o obj/dialogue.o
	gcc $(f) -o game_rules_test $(CFLAGS) $^ $(CINCL)

obj/game_rules_test.o: src/game_rules_test.c
	gcc $(f) $(CFLAGS) -c $^ -o $@ $(CINCL)


inventory_test: obj/inventory_test.o obj/inventory.o obj/set.o
	gcc $(f) -o inventory_test $(CFLAGS) $^ $(CINCL)

obj/inventory_test.o: src/inventory_test.c
	gcc $(f) $(CFALGS) -c $^ -o $@ $(CINCL)


link_test: obj/link_test.o obj/link.o
	gcc $(f) -o link_test $(CFLAGS) $^ $(CINCL)

obj/link_test.o: src/link_test.c
	gcc $(f) $(CFLAGS) -c $^ -o $@ $(CINCL)


object_test: obj/object_test.o obj/object.o
	gcc $(f) -o object_test $(CFLAGS) $^ $(CINCL)

obj/object_test.o: src/object_test.c
	gcc $(f) $(CFLAGS) -c $^ -o $@ $(CINCL)


player_test: obj/player_test.o obj/player.o obj/inventory.o obj/set.o
	gcc $(f) -o player_test $(CFLAGS) $^ $(CINCL)

obj/player_test.o: src/player_test.c
	gcc $(f) $(CFALGS) -c $^ -o $@ $(CINCL)


set_test: obj/set.o obj/set_test.o
	gcc $(f) -o set_test $(CFLAGS) $^ $(CINCL)

obj/set_test.o: src/set_test.c
	gcc $(f) $(CFALGS) -c $^ -o $@ $(CINCL)


space_test: obj/space_test.o obj/space.o obj/set.o
	gcc $(f) -o space_test $(CFLAGS) $^ $(CINCL)

obj/space_test.o: src/space_test.c
	gcc $(f) $(CFALGS) -c $^ -o $@ $(CINCL)

dialogue_test: obj/dialogue_test.o obj/dialogue.o obj/game.o obj/game_management.o obj/space.o obj/player.o obj/object.o obj/enemy.o obj/link.o obj/inventory.o obj/set.o
	gcc $(f) -o dialogue_test $(CFLAGS) $^ $(CINCL)

obj/dialogue_test.o: src/dialogue_test.c
	gcc $(f) $(CFLAGS) -c $^ -o $@ $(CINCL)



clean:
	rm -f obj/*.o
	rm -f command_test
	rm -f enemy_test
	rm -f inventory_test
	rm -f game_test
	rm -f game_management_test
	rm -f game_rules_test
	rm -f dialogue_test
	rm -f link_test
	rm -f object_test
	rm -f player_test
	rm -f set_test
	rm -f space_test
	rm -rf doc/html
	rm -rf doc/latex
	rm -rf doc/man

	

run:
	./anthill anthill.dat

runv:
	valgrind --leak-check=full ./anthill anthill.dat

doxygen: doc/Doxyfile
	doxygen doc/Doxyfile

coverage: coverage_test.sh
	@./coverage_test.sh command 2

	@./coverage_test.sh dialogue 2

	@./coverage_test.sh enemy 2

	@./coverage_test.sh game_management 2
	
	@./coverage_test.sh game_rules 2
	
	@./coverage_test.sh game 2
	
	@./coverage_test.sh inventory 2
	
	@./coverage_test.sh link 2
	
	@./coverage_test.sh object 2
	
	@./coverage_test.sh player 2
	
	@./coverage_test.sh set 2
	
	@./coverage_test.sh space 2
