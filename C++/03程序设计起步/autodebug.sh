#!/bin/bash
cppFile=$1
outFile=${cppFile%.*}".out"
echo $cppFile
echo $outFile
g++ -d cppFile -o outFile
gdb outFile
