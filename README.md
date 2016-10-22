# Parsing exercise
Simple data science exercise demonstrating the use of these features:

* reading, writing, and parsing data
* header+source files
* OOP: inheritance
* pointers, references
* STL, Boost
* passing by reference/by value
* dynamic memory allocation
* C++11, C++14
* templates
* python like string formatting
* documentation
* testing

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
