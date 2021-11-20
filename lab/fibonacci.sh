#!/bin/sh
echo "Enter the number: "
read n
x=0
y=1
sum=0
for ((j=0;j<n;j++))
do
	sum=$((sum+$x))
	t=$((x+y))
	x=$y
	y=$t
done
echo "Sum is: ${sum}"

