echo "Search Using Menu"
z=1
while[ $z -eq 1 ]
do
echo "Search Choice from Menu"
echo "1)Binary Search 2)Linear Search"
read opt
case $opt in
1) echo "***BINARY SEARCH"
echo "enter the limit"
read n
echo "enter the array values"
for((i=0;i<n;i++))
do
read a[$i]
done
l=0
h=`expr $n - 1`
f=0
echo "enter the value to be searched"
read x
while [ $f -eq 0 -a $l -lt $h ] 
do
m=`expr \( $l + $h \) / 2`
if [ ${a[$m]} -eq $x ] 
then f=1
elif [ ${a[$m]} -lt $x ] 
then l=`expr $m + 1` 
elif [ ${a[$m ]} -gt $x ] 
then h=`expr $m - 1`
fi 
done
if [ $f -eq 1 ]
then
echo "element found in $m" 
else
echo "not found"
fi
;;
2)echo "***LINEAR SEARCH***"
echo "enter the limit"
read n
echo "Enter the elememts" 
for (( i=0;i< $n;i++ ))
do 
read a[$i]
echo "enter the element to be searched"
read x
found=0
for (( i=0;i< $n;i++ )) 
do
if[${a[$i]}-eq$x]
then
echo "found in $i"
found=1
break
fi 
done
if[$found-eq 0]
then
echo "not found"
fi
;;
*)echo "INVALID OPTION"
;;
esac
z=0
echo "press 1 to cont"
read $z
done

'
output

Select Choice from Menu 1)Binary Search 2)Linear Search 
1
***BINARY SEARCH*** 
enter the limit
5
enter the array values 
1
2
3
4
5
enter the value to be searched 3
element found in 2 
press 1 to cont....
1
Select Choice from Menu 1)Binary Search 2)Linear Search 
2
***LINEAR SEARCH*** 
enter the limit
5
Enter the elememts 
10
20
30
40
15
enter the element to be searched 15
found in 4
press 1 to cont....
'