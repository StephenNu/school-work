#!/bin/bash
function dirSearch (){ 
	array=(`ls`)
	entries=($( ls -p | grep -v "/" | grep $1 ))
	location=$location$2
	for stuff in ${entries[*]}; do
		echo $location$stuff
	done
	for dir in ${array[*]}; do
		if [ -d $dir ]; then
			cd $dir && dirSearch $1 $dir/
		fi
	done
}
if  (($# == 0  ||  $# >= 2 )); then
	echo Incorrect amount of arguments please pass exactly one.
else
	location=""
	dirSearch $1 ./
fi
