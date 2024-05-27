
### [Back to Chapter 9](../Chapter_09/README.md)

# Chapter 10. Generic Algorithms

### How to compile:

GCC 6.0+ or clang 3.3+

`g++ -std=c++11 app_name.cpp -o target`

`clang++ -std=c++11 app_name.cpp -o target`

## 10.1. Overview

### [Exercise 10.1:](Exercise_01/Ex_01.cpp)

*The algorithm header defines a function named count that, like find, takes a pair of iterators and a value. count returns a count of how often that value appears. Read a sequence of `ints` into a vector and print the count of how many elements have a given value.*

### [Exercise 10.2:](Exercise_02/Ex_02.cpp) 

*Repeat the previous program, but read values into a list of
strings.*

## 10.2.1. Read-Only Algorithms

### [Exercise 10.3:](Exercise_03/Ex_03.cpp) 

*Use accumulate to sum the elements in a `vector<int>`.*

### [Exercise 10.4:](Exercise_04/Ex_04.cpp)

*Assuming v is a `vector<double>`, what, if anything, is wrong with calling accumulate(v.cbegin(), v.cend(), 0)?*

**Answer**
- The function's return type is deduced by the type of the third argument.

### [Exercise 10.5:](Exercise_05/Ex_05.cpp)

*In the call to equal on rosters, what would happen if both rosters held `C-style` strings, rather than library strings?*

**Answer**
- Both will work in the same way because iterator are a type of pointer.


----------------------------
### [Back to Chapter 9](../Chapter_09/README.md) - [Next to Chapter 11](../Chapter_11/README.md)