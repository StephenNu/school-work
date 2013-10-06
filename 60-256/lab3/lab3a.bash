#!/bin/bash
#Stephen Nusko
#103693282
#Jan 30 2013
#lab 52
#to gather the information about a product based on inputted id
if [ $# == 0 ]; then
	echo please provide exactly one product id
elif ! [ $(grep -o "$1" "inventory.txt") ]; then
	echo invalid id
else
	fields=($(grep -w $1 inventory.txt))
	cost=$(( ${fields[1]} * ${fields[2]} ))
	fields=($(grep -w $1 product.txt))
	echo ${fields[1]} total is $ $cost
fi
