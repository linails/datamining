#! /bin/sh
# Created Time: 2015-11-12 10:59:31
#
int=1
echo "Creat tags begin"
while true
do
	echo $int
	int=`expr $int + 1`
	./ctags.sh
	sleep 5
done
echo "while end"
