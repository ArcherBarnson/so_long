#!/bin/bash

if [ -z "$1" ]
then
echo "./generator_so_long.sh [height] [width] [number of collectibles]"
exit 1
fi
if [ -z "$2" ]
then
echo "./generator_so_long.sh [height] [width] [number of collectibles]"
exit 1
fi
if [ -z "$3" ]
then
echo "./generator_so_long.sh [height] [width] [number of collectibles]"
exit 1
fi

a="0"
while [ "$a" != "$2" ]
do
echo -n "1"
a=$[$a+1]
done
printf "\n"

nbline=$1
let "nbline-=2"
lenline=$2
let "lenline-=2"

p_x=$((1 + RANDOM % $lenline))
p_y=$((1 + RANDOM % $nbline))

e_x="0"
while [ "$e_x" = "0" -o \( "$p_x" = "$e_x" -a "$p_y" = "$e_y" \) ]
do
e_x=$((1 + RANDOM % $lenline))
e_y=$((1 + RANDOM % $nbline))
done

entries_y=($(shuf -ri 1-$lenline -n $3 | sort -n))
entries_x=($(shuf -ri 1-$nbline -n $3 | sort -n))

y="0"
while [ "$y" = "0" ]
do

for (( i=0; i< $3; i++ ));
do
if [ \( "${entries_x[$i]}" = "$p_x" -a "${entries_y[$i]}" = "$p_y" \) -o \( "${entries_x[$i]}" = "$e_x" -a "${entries_y[$i]}" = "$e_y" \) ]
then
entries_x[$i]=$((1 + RANDOM % $lenline))
entries_y[$i]=$((1 + RANDOM % $nbline))
i=0
let "i-=1"
continue
fi
for (( j=$i+1; j< $3; j++ ));
do
if [ "${entries_x[$i]}" = "${entries_x[$j]}" -a "${entries_y[$i]}" = "${entries_y[$j]}" ]
then
entries_x[$i]=$((1 + RANDOM % $lenline))
entries_y[$i]=$((1 + RANDOM % $nbline))
i=0
let "i-=1"
j=0
let "j-=1"
continue 2
fi
done
done

let "y+=1"
done

#echo $p_x $e_x
#echo $p_y $e_y
#echo ${entries_x[@]}
#echo ${entries_y[@]}

let "nbline+=1"
let "lenline+=1"

n="1"
while [ "$n" != "$nbline" ]
do
echo -n "1"
a="1"
while [ "$a" != "$lenline" ]
do

if [ "$n" = "$p_y" -a "$a" = "$p_x" ]
then
echo -n "P"
else
if [ "$n" = "$e_y" -a "$a" = "$e_x" ]
then
echo -n "E"
else
i=0
for (( i=0; i< $3; i++ ));
do
if [ "$n" = "${entries_x[$i]}" -a "$a" = "${entries_y[$i]}" ]
then
echo -n "C"
break
fi
done
if [ "$i" = "$3" ]
then
r=($(shuf -ri 1-4 -n 1))
if [ "$r" = "1" ]
then
echo -n "1"
else
echo -n "0"
fi
fi
fi
fi
a=$[$a+1]
done
echo "1"

n=$[$n+1]
done



a="0"
while [ "$a" != "$2" ]
do
echo -n "1"
a=$[$a+1]
done
