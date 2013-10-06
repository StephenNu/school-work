#!/bin/bash
# $1 = m $2 = n
function acker {
	if [ $1 == 0 ]; then
		echo $(($2 + 1))
	elif [ $1 > 0 ] && [ $2 == 0 ]; then
		echo $(acker $(($1 - 1)) 1)
	else
		echo $(acker $(($1 - 1)) $(acker $1 $(($2 - 1))))
	fi
}
if [ $# != 2 ]; then
	echo Please enter exactly two positive numbers.
elif [ -z  $(echo $1 | tr -d '[0-9]') ] && [ -z $(echo $2 | tr -d '[0-9]') ] && [ $1 >= 1 ] && [ $2 >= 1 ]; then
	acker $1 $2
else
	echo Please enter exactly two positive numbers.
fi
