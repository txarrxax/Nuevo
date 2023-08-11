#!/bin/bash
tests=('command_test' 'enemy_test' 'game_reader_test' 'game_test' 'inventory_test' 'link_test' 'object_test' 'player_test' 'set_test' 'space_test')

function exe (){
    make $1
    echo "executing $1"
    ./$1
}

function exe_valgrind (){
    make $1
    echo "executing $1 with valgrind"
    valgrind ./$1
}

if [ $# == 2 ]
then
    if [ $1 == "0" ]
    then
        exe $2
    elif [ $1 == "1" ]
    then
        exe_valgrind $2
    else
        echo "The first argument must be 0 or 1"
    fi
fi

if [ $# == 1 ]
then
    if [ $1 == "0" ]
    then
        for i in "${tests[@]}"
        do
            exe $i
        done
    elif [ $1 == "1" ]
    then
        for i in "${tests[@]}"
        do
            exe_valgrind $i
        done
    else
        echo "The first argument must be 0 or 1"
    fi
fi

    