#!/bin/bash

make -f ./../building/makefile

let passed=0;
let failed=0;
for f in $(ls ./test_cases/*.txt); do
	./../building/executable/a.out <$f > ./test_cases/`basename $f .txt`.output;
done;

for f in $(ls ./test_cases/*.output); do
	diff -Bw $f  ./test_cases/`basename $f .output`.txt.expected > ./test_cases/`basename $f .output`.diff;
done

for f in $(ls test_cases/*.diff); do
	echo "========================================================";
	echo "FILE:" `basename $f .output`;
	echo "========================================================";
	if [ -s $f ]; then
		cat ./test_cases/`basename $f .diff`.txt;
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

echo "rm test_cases/*.output";
rm test_cases/*.output
echo "rm test_cases/*.diff";
rm test_cases/*.diff
make -C ./../building clean
echo " ";


echo "";
echo "========================================================";
echo "                   RESULTS                              ";
echo "========================================================";
echo "PASSED: " $passed;
echo "FAILED: " $failed;
echo " ";
