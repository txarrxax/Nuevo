#!/bin/bash

throw_error(){ 
    echo -e "\e[1m\e[91mERROR: \e[93m${1}\e[39m\e[0m"
    exit
}

if [ $# == 0 ]; then
    echo "Usage: ./integration_tests.sh (-v) [.dat file] [.cmd file] [.out file]"
    exit
elif [ $# == 3 ]; then
    if [ "$1" = "-v" ]; then
        throw_error "Incorrect number of arguments"
    fi
    valgrind=false
    dat_file=$1
    in_file=$2
    out_file=$3
elif [ $# == 4 ]; then
    if [ "$1" != "-v" ]; then
        throw_error "Incorrect number of arguments"
    fi
    valgrind=true
    dat_file=$2
    in_file=$3
    out_file=$4
else
    throw_error "Incorrect number of arguments"
fi

if [ ! -e $dat_file ]; then
    throw_error "'${dat_file}' could not be found"
fi
if [ ! -e $in_file ]; then
    throw_error "'${in_file}' could not be found"
fi
if [ ! -e $out_file ]; then
    throw_error "'${out_file}' could not be found"
fi
make
echo -e "\e[96mRunning integration test...\e[39m"
if [ "$valgrind" = true ]; then
    valgrind ./anthill ${dat_file} -l ${in_file}.log < ${in_file}
else
    ./anthill ${dat_file} -l ${in_file}.log < ${in_file}
fi
echo -e "\n\e[96mRun results saved to \e[1m'${in_file}.log'\e[0m\e[39m"
answers=()
i=0
while read line; do
    ((i++))
    if ((i%2 == 0)); then
        answers+=($line)
    fi
done < ${in_file}.log
i=0
passed=0
while read line; do
    if [ $i == ${#answers[@]} ]; then
        throw_error "The test output was longer than the expected output"
    fi
    if [ "$line" = "${answers[$i]}" ]; then
        echo -e "\e[93mTest #${i}...\e[1m\e[92mOK\e[0m"
        ((passed++))
    else
        echo -e "\e[93mTest #${i}...\e[1m\e[91mERROR\e[0m"
    fi
    ((i++))
done < ${out_file}
if (( $i < ${#answers[@]} )); then
    throw_error "The test output was shorter than the expected output"
fi
echo -e "\e[1m\e[96mTest results: \e[0m\e[95m$((passed*100/i))% passed (${passed}/${i})"
