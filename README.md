# Parsing exercise
Simple data science exercise demonstrating the use of these features:

* reading, writing, and parsing data
* header+source files
* OOP: inheritance, virtual methods
* pointers, references
* STL, Boost
* passing by reference/by value
* dynamic memory allocation
* C++11, C++14 features
* templates
* python like string formatting (with Boost Format)
* printing in color
* documentation
* testing (with Google Test)
* CLI arguments
* make
* include guards (via #pragma once)
* macros

# Setup
```
# setup C++
sudo apt-get install g++

# install boost
sudo apt-get install libboost-all-dev

# install doxygen
sudo apt-get install doxygen
sudo apt-get install graphviz

# generate a project-specific doxygen configuration file
doxygen -g parsing-exercise.conf

# install astyle c++ prettyfier
download https://sourceforge.net/projects/astyle/files/latest/download?source=files
cd astyle/build/gcc
make

# install code correctness recommender
sudo pip install --upgrade cppclean

# install google test
sudo apt-get install libgtest-dev
sudo apt-get install cmake # install cmake
cd /usr/src/gtest
sudo cmake CMakeLists.txt
sudo make
# copy or symlink libgtest.a and libgtest_main.a to your /usr/lib folder
sudo cp *.a /usr/lib

# make run.sh executable
chmod +x run.sh

# run
./run.sh
```

# TODO
* better naming
* better optimization
* add tests
* more comments
* use typedefs
* use initializers whenever you can
* better project structure
* check that station is string and temperature is number
