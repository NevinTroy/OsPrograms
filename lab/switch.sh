#!bin/sh
read -p "Are you above 21: Y or N " AGE
case "${AGE}" in
	[yY])
	echo "Welcome" 
	;;
	[nN])
	echo "Denied"
	;;
*)
	echo "Please enter y or n"
	;;
esac
