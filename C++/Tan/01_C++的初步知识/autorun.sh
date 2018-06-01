#!/bin/bash


cppname=$1
outname=${cppname%.*}
outname=$outname".out"
g++ $cppname -o $outname
./$outname
