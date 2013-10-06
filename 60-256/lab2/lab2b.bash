#!/bin/bash
#Stephen Nusko
#103693282
#Jan 23 2013
#lab 52
#to find the greatest common divisor of the two input numbers.

#gcd is a recursive function to calucalte the GCD
function gcd() {
value=$(($1%$2))
if (($value==0)); then
	echo $2
else
	result=$((
	))
	echo 
fi
}
#checks arguments amount
if (($#==0||$#>2||$#==1)); then
	echo Provide exactly 2 numeric arguments
elif ((!$1||!$2)); then
	echo One or more arguments are invalid numbers
else
	if (($1>=$2)); then
		`gcd $1 $2`
		echo $?
	else
		`gcd $1 $2`
		echo $?
	fi
fi
