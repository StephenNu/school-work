#!/bin/bash
echo "good morning"
today=`date`
echo "Today $today"
dateFields=(`date`)
echo "Total count is ${#dateFields[@]}"
for field in ${dateFields[@]}
do
echo $field
done
echo "Month = ${dateFields[1]}"
echo "Time = ${dateFields[3]}"
echo "===="
echo "lets try some arithmetic"
echo -n "number: "
read a
echo -n "number: "
read b
sum=$(( $a + $b ))
echo "a + b = $sum"
if ((a==b)); then
echo "a is equal"
elif ((a>b)); then
echo "a is greater"
else
echo "a is less"
fi
