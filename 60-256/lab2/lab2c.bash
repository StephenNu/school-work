#!/bin/bash
#Stephen Nusko
#103693282
#Jan 23 2013
#lab 52
#purpose is to calculate the factorial of the single passed argument

#fact is the recursive function to caluclate the factorial
function fact {
	if (($1==0)); then
		echo 1
	else
		result=$(fact $(($1-1)))
		echo $(($1*result))
	fi
}
#checks the arguments amounts and if correct launches fact.
if (($#==0||$#>=2)); then
	echo No or too many arguments passed. Provide 1 numeric argument.
elif (($1)); then
	fact $1
else
	echo Not a valid number
fi
