echo "please enter the last number"
read n
x=0
y=1
s=0
echo "the fibonacci sum is :"
for ((j=0;j<n;j++))
do
	s=$((s+$x))
	t=$((x+y))
	x=$y
	y=$t
done
echo $s
