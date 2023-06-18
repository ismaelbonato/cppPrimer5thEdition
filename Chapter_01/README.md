## Chapter 1. Getting Started

### How to compile:

GCC 6.0+ or clang 3.3+

`g++ -std=c++11 app_name.cpp -o target`

`clang++ -std=c++11 app_name.cpp -o target`

## 1.1.1. Compiling and Executing Our Program

### [Exercise 1.1:](Exercise_01/Ex01.cpp)

*Review the documentation for your compiler and determine what file naming convention it uses. Compile and run the main program from page 2.*

**Answer**

- C, C++, Objective-C or Objective-C++ header file to be turned into a precompiled header.

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

*Change the program to return -1. A return value of -1 is often treated as an indicator that the program failed. Recompile and rerun our program to see how your system treats a failure indicator from main.*

## 1.2. A First Look at Input/Output

### [Exercise 1.3:](Exercise_03/Ex03.cpp)

*Write a program to print Hello, World on the standard output.*

### [Exercise 1.4:](Exercise_04/Ex04.cpp)

*Our program used the addition operator, +, to add two numbers. Write a program that uses the multiplication operator, \*, to print the product instead.*

### [Exercise 1.5:](Exercise_05/Ex05.cpp)

*We wrote the output in one large statement. Rewrite the program to use a separate statement to print each operand.*

### [Exercise 1.6:](Exercise_06/Ex06.cpp)

*Explain whether the following program fragment is legal. If the program is legal, what does it do? If the program is not legal, why not? How would you fix it?*

```cpp
    std::cout << "The sum of " << v1; <- [premature end line]
    << " and " << v2;
    << " is " << v1 + v2 << std::endl;
```

**Output:**

```cpp
    [Error] expected primary-expression before '<<' token
```
**Answer**

- This fragment is not legal, there is a premature end line ";" in between the command. The operator "<<" needs a stream operator.

    - **Correct Code:** 

```cpp
    std::cout << "The sum of " << v1
    << " and " << v2
    << " is " << v1 + v2 << std::endl;
```

## 1.3. A Word about Comments

### [Exercise 1.7:](Exercise_07/Ex07.cpp)

*Compile a program that has incorrectly nested comments.*

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

*Indicate which, if any, of the following output statements are legal: After you’ve predicted what will happen, test your answers by compiling a program with each of these statements. Correct any errors you encounter*

```cpp
std::cout << "/*";
std::cout << "*/";
std::cout << /* "*/" */;
std::cout << /* "*/" /* "/*" */;
```
**Error Message**

```cpp
Ex08.cpp:8:24: warning: missing terminating " character
    8 |     std::cout << /* "*/" */;
      |                        ^
Ex08.cpp:8:24: error: missing terminating " character
    8 |     std::cout << /* "*/" */;
      |                        ^~~~~
```
**Answer**

- `std::cout << "/*";` = **`Legal`**
- `std::cout << "*/";` =  **`Legal`**
- `std::cout << /* "*/" */;` = **`Illegal`**
- `std::cout << /* "*/" /* "/*" */;` = **`Legal`**


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

## 1.4.1. The while Statement

### [Exercise 1.9:](Exercise_09/Ex09.cpp)

*Write a program that uses a while to sum the numbers from 50 to 100.*

### [Exercise 1.10:](Exercise_10/Ex10.cpp)

*In addition to the ++ operator that adds 1 to its operand, there is a decrement operator (--) that subtracts 1. Use the decrement operator to write a while that prints the numbers from ten down to zero.*

### [Exercise 1.11:](Exercise_11/Ex11.cpp)

*Write a program that prompts the user for two integers. Print each number in the range specified by those two integers.*

## 1.4.2. The for Statement

### [Exercise 1.12:](Exercise_12/Ex12.cpp)

*What does the following for loop do? What is the final value of sum?*

```cpp
int sum = 0;
for (int i = -100; i <= 100; ++i)
sum += i;
```
**Answer**
- This loop perform the sum of all values between -100 and +100, so its results is **zero**.

### [Exercise 1.13:](Exercise_13/Ex13.cpp)

*Rewrite the exercises from § 1.4.1 (p. 13) using for loops.*

### [Exercise 1.14:](Exercise_14/Ex14.cpp)

*Compare and contrast the loops that used a for with those using a while. Are there advantages or disadvantages to using either form?*

**Answer**

- **`While`** is simpler to use and it's better when you don't know the scope, the amount of iterations or for infinite loops, 
- **`For`** is easier to use when the scope is limited, we know the the amount of iterations beforehand.

### [Exercise 1.15:](Exercise_15/Ex15.cpp)

*Write programs that contain the common errors discussed in the box on page 16. Familiarize yourself with the messages the compiler generates.*

## 1.4.3. Reading an Unknown Number of Inputs

### [Exercise 1.16:](Exercise_16/Ex16.cpp)

*Write your own version of a program that prints the sum of a set of integers read from cin.*

## 1.4.4. The if Statement

### [Exercise 1.17:](Exercise_17/Ex17.cpp)

*What happens in the program presented in this section if the input values are all equal? What if there are no duplicated values?*

**Answer**

- If all input are `equal` it will never prints the else statement, so it will never count any number.

- If all input are `different` it works as expected, but it will not print the last number'

### [Exercise 1.18:](Exercise_18/Ex18.cpp)

*Compile and run the program from this section giving it only equal values as input. Run it again giving it values in which no number is repeated.*

### [Exercise 1.19:](Exercise_19/Ex19.cpp)

 *Revise the program you wrote for the exercises in § 1.4.1 (p.13) that printed a range of numbers so that it handles input in which the first number is smaller than the second.*

 ## 1.5.1. The Sales_item Class

### [Exercise 1.20:](Exercise_20/Ex20.cpp)

*http://www.informit.com/title/032174113 contains a copy of Sales_item.h in the Chapter 1 code directory. Copy that file to your working directory. Use it to write a program that reads a set of book sales transactions, writing each transaction to the standard output.*

### [Exercise 1.21:](Exercise_21/Ex21.cpp)

*Write a program that reads two Sales_item objects that have the same `ISBN` and produces their sum.*

### [Exercise 1.22:](Exercise_22/Ex22.cpp)

*Write a program that reads several transactions for the same `ISBN`. Write the sum of all the transactions that were read.*

## 1.5.2. A First Look at Member Functions

### [Exercise 1.23:](Exercise_23/Ex23.cpp)

*Write a program that reads several transactions and counts how many transactions occur for each `ISBN`.*

### [Exercise 1.24:](Exercise_24/Ex24.cpp)

*Test the previous program by giving multiple transactions representing multiple `ISBNs`. The records for each ISBN should be grouped together.*

## 1.6. The Bookstore Program

### [Exercise 1.25:](Exercise_25/Ex25.cpp)

*Using the Sales_item.h header from the Web site, compile and execute the bookstore program presented in this section.*

