#!/bin/bash

make -f ./makefile

let passed=0;
let failed=0;
for f in $(ls ./tests/*.txt); do
	./executable/a.out <$f > ./tests/`basename $f .txt`.output;
done;

for f in $(ls ./tests/*.output); do
	diff -Bw $f  ./tests/`basename $f .output`.txt.expected > ./tests/`basename $f .output`.diff;
done

for f in $(ls tests/*.diff); do
	echo "========================================================";
	echo "FILE:" `basename $f .output`;
	echo "========================================================";
	if [ -s $f ]; then
		cat ./tests/`basename $f .diff`.txt;
		echo "--------------------------------------------------------";
		cat $f
		failed=$((failed+1));
	else
		passed=$((passed+1));
		echo "GOOD JOB! no errors";
		echo "";
	fi
done

echo " ";
echo "--------------------------------------------------------";
echo "                 cleaning up";
echo "--------------------------------------------------------";

echo "rm tests/*.output";
rm tests/*.output
echo "rm tests/*.diff";
rm tests/*.diff
make clean
echo " ";


echo "";
echo "========================================================";
echo "                   RESULTS                              ";
echo "========================================================";
echo "PASSED: " $passed;
echo "FAILED: " $failed;
echo " ";