#!/bin/sh

for item in *
do
	if [ -f $item ]
	then
		echo"    $item   "
		if[ -x $item ]
		then
			chmod -x $item
		elif [ -w $item ]
		then
			chmod -w $item
		else
			chmod +r $item
		fi
	fi
done
echo "Completed"
ls -l
