#!/bin/bash
function checkPrime {
	not=0
	for ((i=2; i < $1; i++)); do
		if [ $(($1 % $i)) == 0 ]; then
			not=1 
		fi
	done
	if [ $not == 0 ]; then
		echo $1
	fi
}
function primes {
	for ((i=2; i <= $1; i++)); do
		checkPrime $i
	done
}
if [ -z $(echo $1 | tr -d '[0-9]') ] && [ $# == 1 ]; then
	if (( $1 >= 2 )); then
		primes $1
	else
		echo Please input exactly 1 positive number greater then 1
	fi
else
	echo Please input exactly 1 positive number greater then 1
fi
