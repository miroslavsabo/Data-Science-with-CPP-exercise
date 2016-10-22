#!/bin/bash

set -e

# prettyfy
~/Downloads/astyle/build/gcc/bin/astyle --suffix=none --style=allman --recursive  './*.cpp'  './*.h'

# compile
g++ -std=c++14 *.cpp -o parser

# document
doxygen parsing-exercise.conf

# execute
./parser
