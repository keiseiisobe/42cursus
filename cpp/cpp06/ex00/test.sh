#! /bin/bash

ofile="result.txt";

rm -rf result.txt;

echo "**********char test**********" >> ${ofile};
arg=('a' 'b' 'c' 'x' 'y' 'z' 'A' 'B' 'C' 'X' 'Y' 'Z' '!' '"' "#" '$' '{' '|' '}' '~');

for i in ${arg[@]}
do
	./convert ${i} >> ${ofile}
done

echo "**********int test**********" >> ${ofile};
arg=(0 1 -1 100 -100 2147483647 -2147483648 2147483648 -2147483649 9223372036854775807 -9223372036854775808 9223372036854775808 -9223372036854775809);

for i in ${arg[@]}
do
	./convert ${i} >> ${ofile}
done

echo "**********float test**********" >> ${ofile};
arg=(0.0f 0.1f -0.1f 42.42f -42.42f 2147483647.5f -2147483648.5f 3.40282e+38f 1.17549e-38f 1.79769e+308f 2.22507e-308f nanf +inff -inff);

for i in ${arg[@]}
do
	./convert ${i} >> ${ofile}
done
