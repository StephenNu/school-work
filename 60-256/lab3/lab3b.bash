#!/bin/bash
#Stephen Nusko
#103693282
#Jan 30 2013
#lab 52
# to write only the n lines after counting up m lines from the bottom.
# $1 = m $2 = n
if [ $# != 2 ]; then
	echo usage [m=number] [n=number]
else
	for ((i=$1; i<$(( $2 + $1 )); i++)); do
		echo $( tail -$i File.txt | head -n +1 ) # remove -n in tail on school computers
	done
fi
