#!/bin/bash

throw_error(){ 
    echo -e "\e[1m\e[91mERROR: \e[93m${1}\e[39m\e[0m"
    exit
}

if [ $# != 2 ]; then
    echo "Usage: ./coverage_test.sh [module name] [required tests per function]"
    exit
fi

module="include/${1}.h"
tests="include/${1}_test.h"

if [ ! -e $module ]; then
    throw_error "'${module}' could not be found"
fi 
if [ ! -e $tests ]; then
    throw_error "'${tests}' could not be found"
fi

echo -e "\e[1m\e[96mRunning coverage test for ${1} module...\e[0m"

functions=()
tPerFs=()
flag=0
tmp=""
delim="("

while read line; do
    if [[ $line == *"*/"* ]]; then
        flag=1
        continue
    fi
    if [ $flag -eq 1 ] && [[ $line == *"${1}_"* ]]; then
        tmp=${line#*${1}_}
        tmp=${tmp%${delim}*}
        tmp=${tmp% *}
        functions+=("${tmp}()")
        tPerFs+=(0)
    fi
    flag=0
done < ${module}

while read line; do
    if [[ $line == "void test"* ]]; then
        for (( i=0; i < ${#functions[@]}; i++ )); do
            if [[ $line == *"${1}_${functions[$i]}"* ]]; then
                ((tPerFs[$i]++))
            fi
        done
    fi
done < ${tests}

passed=0
for (( i=0; i < ${#functions[@]}; i++ )); do
    if [[ ${tPerFs[$i]} -ge ${2} ]]; then
        echo -e "\e[93mFunction ${functions[$i]}...\e[1m\e[92mOK \e[0m\e[95m(${tPerFs[$i]}/${2})\e[0m"
        ((passed++))
    else
        echo -e "\e[93mFunction ${functions[$i]}...\e[1m\e[91mERROR \e[0m\e[95m(${tPerFs[$i]}/${2})\e[0m"
    fi
done

if [ $i -eq 0 ]; then
    throw_error "No functions were detected"
else
    echo -e "\e[1m\e[96mTest results: \e[0m\e[95m$((passed*100/i))% passed (${passed}/${i})\n"
fi
