#!/bin/bash

names=`ls | grep seqential`
#$echo $names
for name in $names
do
	echo $name
	name_bk=$name
	name='sequential_'${name#*_}
	echo $name
	mv $name_bk $name
done
