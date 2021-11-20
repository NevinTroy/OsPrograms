#!/bin/sh
echo "Enter the number:"
read n
r=0
s=0
while [ $n -gt 0 ]
do
	i=$(( $n % 10 ))
	r=$(( $r*10 +$i ))
	s=$(( s+i ))
	n=$(( $n/10 ))
done
echo "Reverse is: ${r}"
echo "Sum of its digits is: ${s}"

