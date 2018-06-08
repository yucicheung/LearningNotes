#!/bin/bash

infile=$1
outfile=${infile%.}.out
g++ -std=c++11 $infile -o $outfile
./$outfile
