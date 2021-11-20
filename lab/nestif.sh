#!bin/sh
echo "Enter your username "
read u
if [ "$u" = "Nevin" ]
then
	echo "Welcome Nevin, Please enter your password"
	read p
	if [ "$p" = "test123" ]
	then
	       echo "Credentials verified"
        else
 		echo "Wrong password!"
	fi
else
echo "Wrong username"
fi

