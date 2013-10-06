#!/bin/bash
#Stephen Nusko
#103693282
#Jan 23 2013
#lab 52
#purpose to check to see inputted arguments are numbers.
#check if no arguments.
if [ $# == 0 ]; then
	echo "No arguments passed. Try again"
#otherwise check to see if the arguments are numbers and output the result.
else
	for number in $*; do
		if [ -z $(echo $number | tr -d '[0-9]') ]; then
			echo $number is a number
		else
			echo $number is not a number 
		fi
	done
fi
