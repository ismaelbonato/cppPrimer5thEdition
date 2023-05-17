## Chapter 1: Getting Started

### [Exercise 1.1:](Exercise_01/Ex01.cpp)

**`Question`** *Review the documentation for your compiler and determine what file naming convention it uses. Compile and run the main program from page 2.*

**`Answer`**: C, C++, Objective-C or Objective-C++ header file to be turned into a precompiled header.

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

### [Exercise 1.2:](Exercise_02/Ex02.cpp)

**`Question`** *Change the program to return -1. A return value of -1 is often treated as an indicator that the program failed. Recompile and rerun our program to see how your system treats a failure indicator from main.*

### [Exercise 1.3:](Exercise_03/Ex03.cpp)

**`Question`** *Write a program to print Hello, World on the standard output.*

### [Exercise 1.4:](Exercise_04/Ex04.cpp)

**`Question`** *Our program used the addition operator, +, to add two numbers. Write a program that uses the multiplication operator, \*, to print the product instead.*

### [Exercise 1.5:](Exercise_05/Ex05.cpp)

**`Question`** *We wrote the output in one large statement. Rewrite the program to use a separate statement to print each operand.*

### [Exercise 1.6:](Exercise_06/Ex06.cpp)

**`Question`** *Explain whether the following program fragment is legal. If the program is legal, what does it do? If the program is not legal, why not? How would you fix it?*

```cpp
    std::cout << "The sum of " << v1; <- [premature end line]
    << " and " << v2;
    << " is " << v1 + v2 << std::endl;
```

**`Answer`**: This fragment is not legal, there is a premature end line ";" in between the command. The operator "<<" needs a stream operator.

**Error Message:**

```cpp
    [Error] expected primary-expression before '<<' tokencpp
```

**Correct Code**

```cpp
    std::cout << "The sum of " << v1
    << " and " << v2
    << " is " << v1 + v2 << std::endl;
```

### [Exercise 1.7:](Exercise_07/Ex07.cpp)

**`Question`** *Compile a program that has incorrectly nested comments.*

**Error Message**

```cpp
$ g++ Ex07.cpp
Ex07.cpp:5:3: error: empty character constant
    5 | * ''cannot nest'' is considered source code,
      |   ^~~~~~~~
Ex07.cpp:5:16: error: empty character constant
    5 | * ''cannot nest'' is considered source code,
      |                ^~
Ex07.cpp:4:23: error: ‘cannot’ does not name a type
    4 | * comment pairs /* */ cannot nest.
      |                       ^~~~~~
```

### [Exercise 1.8:](Exercise_08/Ex08.cpp)

**`Question`** *Indicate which, if any, of the following output statements are legal: After you’ve predicted what will happen, test your answers by compiling a program with each of these statements. Correct any errors you encounter*

```cpp
std::cout << "/*";
std::cout << "*/";
std::cout << /* "*/" */;
std::cout << /* "*/" /* "/*" */;
```

- `std::cout << "/*";` = **`Legal`**

- `std::cout << "*/";` =  **`Legal`**

- `std::cout << /* "*/" */;` = **`Ilegal`**

- `std::cout << /* "*/" /* "/*" */;` = **`Legal`**

**Error Message**

```cpp
Ex08.cpp:8:24: warning: missing terminating " character
    8 |     std::cout << /* "*/" */;
      |                        ^
Ex08.cpp:8:24: error: missing terminating " character
    8 |     std::cout << /* "*/" */;
      |                        ^~~~~
```

**Correct Code**

```cpp
std::cout << "/*" << std::endl;
std::cout << "*/" << std::endl;
std::cout << /* "*/" */" << std::endl;
std::cout << /* "*/" /* "/*" */ << std::endl;
```

**Output**

```cpp
/*
*/
 */
 /* 
```

### [Exercise 1.9:](Exercise_09/Ex09.cpp)

**`Question`** *Write a program that uses a while to sum the numbers from 50 to 100.*

### [Exercise 1.10:](Exercise_10/Ex10.cpp)

**`Question`** *In addition to the ++ operator that adds 1 to its operand, there is a decrement operator (--) that subtracts 1. Use the decrement operator to write a while that prints the numbers from ten down to zero.*

### [Exercise 1.12:](Exercise_12/Ex12.cpp)

**`Question`** * What does the following for loop do? What is the final value of sum?*

```cpp
int sum = 0;
for (int i = -100; i <= 100; ++i)
sum += i;
```

**`Answer`**: This loop perform the sum of all values between -100 and +100, so its results is **zero**.

### [Exercise 1.13:](Exercise_13/Ex13.cpp)

**`Question`** *Rewrite the exercises from § 1.4.1 (p. 13) using for loops.*

### [Exercise 1.14:](Exercise_14/Ex14.cpp)

**`Question`** *Compare and contrast the loops that used a for with those using a while. Are there advantages or disadvantages to using either form?*

while is simple when you don't know the scope or for infinite loops, for is easier to use when the scope is limited.



### [Exercise 1.10:](Exercise_09/Ex09.cpp)

**`Question`** *In addition to the ++ operator that adds 1 to its operand, there is a decrement operator (--) that subtracts 1. Use the decrement operator to write a while that prints the numbers from ten down to zero.*

### [Exercise 1.10:](Exercise_09/Ex09.cpp)

**`Question`** *In addition to the ++ operator that adds 1 to its operand, there is a decrement operator (--) that subtracts 1. Use the decrement operator to write a while that prints the numbers from ten down to zero.*

### [Exercise 1.10:](Exercise_09/Ex09.cpp)

**`Question`** *In addition to the ++ operator that adds 1 to its operand, there is a decrement operator (--) that subtracts 1. Use the decrement operator to write a while that prints the numbers from ten down to zero.*

### [Exercise 1.10:](Exercise_09/Ex09.cpp)

**`Question`** *In addition to the ++ operator that adds 1 to its operand, there is a decrement operator (--) that subtracts 1. Use the decrement operator to write a while that prints the numbers from ten down to zero.*

### [Exercise 1.10:](Exercise_09/Ex09.cpp)

**`Question`** *In addition to the ++ operator that adds 1 to its operand, there is a decrement operator (--) that subtracts 1. Use the decrement operator to write a while that prints the numbers from ten down to zero.*

### [Exercise 1.10:](Exercise_09/Ex09.cpp)

**`Question`** *In addition to the ++ operator that adds 1 to its operand, there is a decrement operator (--) that subtracts 1. Use the decrement operator to write a while that prints the numbers from ten down to zero.*

### [Exercise 1.10:](Exercise_09/Ex09.cpp)

**`Question`** *In addition to the ++ operator that adds 1 to its operand, there is a decrement operator (--) that subtracts 1. Use the decrement operator to write a while that prints the numbers from ten down to zero.*


