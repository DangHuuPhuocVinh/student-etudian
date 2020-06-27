#! /bin/bash

caub()
{
local input=$1
local output=$2
while read line
do
    n=${#line}
    res=''
    for (( i=$n-1; i>=0; i--))
    do
	res="$res${line:$1:1}"
    done
    echo $res>>output
done  < $input
}

caub input.txt output.txt
