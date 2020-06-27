#! /bin/bash

input="$1"
output="$1"

caua()
{
    local input="$1"
    local output="$2"
    local s=""
    while read line
    do
	s=$line$s
	done < $input
    for word in $s
    do
	echo $word >> $output
    done
}

caua input.txt output.txt
