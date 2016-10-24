#!/bin/bash

set -e

# prettyfy
~/Downloads/astyle/build/gcc/bin/astyle --suffix=none --style=allman --recursive  './*.cpp'  './*.h'

# compile
# -Wunused (GCC, Clang) should warn about unused variables
g++ -std=c++14 -Wunused main.cpp  temperature.cpp utils.cpp -o parser

# test
cmake CMakeLists.txt
make
./runTests

# document
doxygen parsing-exercise.conf

# execute
./parser

# recommend improvements
cppclean .

# measure performance
#valgrind --tool=callgrind ./parser
#gprof2dot -f callgrind callgrind.out.* | dot -Tsvg -o output.svg
