#!bin/sh
echo "Enter a"
read a
echo "Enter b"
read b
if [ $a -gt $b ]
then
	echo "${a} is greater than ${b}"
elif [ $a -eq $b ]
then
	echo "${a} is equal to ${b}"
else
	echo "${a} is lesser than ${b}"
fi

