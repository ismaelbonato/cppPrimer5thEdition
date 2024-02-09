# Chapter 7. Classes

### How to compile:

GCC 6.0+ or clang 3.3+

`g++ -std=c++11 app_name.cpp -o target`

`clang++ -std=c++11 app_name.cpp -o target`

## 7.1.1. Designing the Sales_data Class

### [Exercise 7.1:](Exercise_01/Ex01.cpp)

*Write a version of the transaction-processing program from §1.6 (p. 24) using the Sales_data class you defined for the exercises in § 2.6.1 (p. 72).*

## 7.1.2. Defining the Revised Sales_data Class

### [Exercise 7.2:](Exercise_02/Ex02.cpp)

*Add the combine and `isbn` members to the Sales_data class you wrote for the exercises in § 2.6.2 (p. 76).*

### [Exercise 7.3:](Exercise_03/Ex03.cpp)

*Revise your transaction-processing program from § 7.1.1 (p.256) to use these members.*

### [Exercise 7.4:](Exercise_04/Ex04.cpp) 

*Write a class named Person that represents the name and address of a person. Use a string to hold each of these elements. Subsequent exercises will incrementally add features to this class.*

### [Exercise 7.5:](Exercise_05/Ex05.cpp) 

*Provide operations in your Person class to return the name and address. Should these functions be const? Explain your choice.*

**Answer**

- In order to make this more flexible and secure it is better to use `const` in all cases possible. In this case, the object `Jhon` is `nonConst` and can be converted in a `const` object, but the inverse is not possible, if `Jhon` is a `const Person Jhon` and the function is not a `const` it will be illegal.

## 7.1.3. Defining Nonmember Class-Related Functions

### [Exercise 7.6:](Exercise_06/Ex06.cpp)

*Define your own versions of the add, read, and print functions.*

### [Exercise 7.7:](Exercise_07/Ex07.cpp)

*Rewrite the transaction-processing program you wrote for the exercises in § 7.1.2 (p. 260) to use these new functions.*

### Exercise 7.8:

*Why does read define its `Sales_data` parameter as a plain reference and print define its parameter as a reference to `const`*

**Answer**
- It is simple, the `read` function is a `write` function, it must have access to write the object. The `print` function is `read` function, it does not need access to `write` the object, then, we can use the modifier `const` to protect the object.

### [Exercise 7.9:](Exercise_09/Ex09.cpp)

*Add operations to `read` and `print` Person objects to the code you wrote for the exercises in § 7.1.2 (p. 260).*

### Exercise 7.10:

*What does the condition in the following `if` statement do?*
```cpp
if (read(read(cin, data1), data2))
```

**Answer**
- The first `read(cin, data1)` will read the input and will return the reference to the last character read + 1, then the next `read(cin, data2)` will continue reading where the `read(cin, data1)` read stopped.
- The `if` statement will be false if a null character is found before both read functions finished, in another words, this if will execute only when there is enough data in the input stream to populate the objects inside those functions.

## 7.1.4. Constructors

### [Exercise 7.11:](Exercise_11/Ex11.cpp)

*Add constructors to your Sales_data class and write a program to use each of the constructors.*

### [Exercise 7.12:](Exercise_12/Ex12.cpp)

Move the definition of the Sales_data constructor that takes an `istream` into the body of the Sales_data class.*

### [Exercise 7.13:](Exercise_13/Ex13.cpp)

*Rewrite the program from page 255 to use the `istream constructor`.*

### [Exercise 7.14:](Exercise_14/Ex14.cpp)

*Write a version of the default constructor that explicitly initializes the members to the values we have provided as `in-class initializers`.*

### [Exercise 7.15:](Exercise_15/Ex015.cpp) 

*Add appropriate constructors to your Person class.*