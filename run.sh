#!/bin/bash

set -e

# prettyfy
~/Downloads/astyle/build/gcc/bin/astyle --suffix=none --style=allman --recursive  './*.cpp'  './*.h'

# compile
g++ -std=c++14 main.cpp  temperature.cpp utils.cpp -o parser

# test
#cmake CMakeLists.txt
#make
#./runTests

# document
#doxygen parsing-exercise.conf

# execute
./parser

# recommend
#cppclean .
