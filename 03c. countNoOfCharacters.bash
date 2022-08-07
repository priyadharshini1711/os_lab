echo "enter the filename"
read text
c=`echo $text | wc -c`
w=`echo $text | wc -w`
echo no of characters: $c
echo no of words: $w

'
output

enter the filename
main.bash
no of characters: 10
no of words: 1
'