# Chapter 1: Getting Started

## [Exercise 1.1:](Exercise_01/Ex01.cpp) 
*Review the documentation for your compiler and determine what file naming convention it uses. Compile and run the main program from page 2.*

**Answer**: C, C++, Objective-C or Objective-C++ header file to be turned into a precompiled header.

[**Documentation**:](https://gcc.gnu.org/onlinedocs/gcc-4.4.1/gcc/Overall-Options.html#index-file-name-suffix-71)

```cpp
file.cc
file.cp
file.cxx
file.cpp
file.CPP
file.c++
file.C
```

## [Exercise 1.2:](Exercise_02/Ex02.cpp) 
*Change the program to return -1. A return value of -1 is often treated as an indicator that the program failed. Recompile and rerun our program to see how your system treats a failure indicator from main.*

## [Exercise 1.3:](Exercise_03/Ex03.cpp) 
*Write a program to print Hello, World on the standard output.*

## [Exercise 1.4:](Exercise_04/Ex04.cpp) 
*Our program used the addition operator, +, to add two numbers. Write a program that uses the multiplication operator, *, to print the product instead.*

## [Exercise 1.5:](Exercise_05/Ex05.cpp)
*We wrote the output in one large statement. Rewrite the program to use a separate statement to print each operand.*

## [Exercise 1.6:](Exercise_06/Ex06.cpp)
*Explain whether the following program fragment is legal. If the program is legal, what does it do? If the program is not legal, why not? How would you fix it?*

**Answer**: This fragment is not legal, there is a premature end line ";" in beetween the comand. The operator "<<" needs a stream operator.

- Wrong

**`[Error] expected primary-expression before '<<' token`**

```cpp
    std::cout << "The sum of " << v1; <- [premature end line]
    << " and " << v2;
    << " is " << v1 + v2 << std::endl;
```
- Correct
```cpp
    std::cout << "The sum of " << v1
    << " and " << v2
    << " is " << v1 + v2 << std::endl;
```
## [Exercise 1.7:](Exercise_07/Ex07.cpp)
*Compile a program that has incorrectly nested comments.*


