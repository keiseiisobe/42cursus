#! /bin/bash

ofile="result.txt";

echo "**********char test**********" >> ${ofile};
arg=('a' 'b' 'c' 'x' 'y' 'z' 'A' 'B' 'C' 'X' 'Y' 'Z' '!' '"' "#" '$' '{' '|' '}' '~');

for i in ${arg[@]}
do
	./convert ${i} >> ${ofile}
done
