# Chapter 6. Functions

### How to compile:

GCC 6.0+ or clang 3.3+

`g++ -std=c++11 app_name.cpp -o target`

`clang++ -std=c++11 app_name.cpp -o target`


## 6.1. Function Basics

### Exercise 6.1: 

*What is the difference between a parameter and an argument?*

**Answer**

- Arguments are the inputs of the function, they are used to initialize the function's parameters.

- Parameters are the objects locally created and initialized by the arguments given to the function. 

### Exercise 6.2: 

*Indicate which of the following functions are in error and why. Suggest how you might correct the problems.*

```cpp
(a) int f() {
        string s;
        // ...
        return s;
    }
(b) f2(int i) { /* ... */ }
(c) int calc(int v1, int v1) /* ... */ }
(d) double square(double x) return x * x;
```

**Answer**

- (a) The return of the function is an `int` but `s` is a `string`.
    ```cpp
    string f() {
        string s;
        // ...
        return s;
    }
    ```

- (b) The function `f2` has no return type `void`.
    ```cpp
    void f2(int i) { /* ... */ }
    ```
- (c) The first compound statement operator curly braces is used to begin the statement is missing.
    ```cpp
    int calc(int v1, int v1) { /* ... */ }
    ```

- (d) The both compound statement operator curly braces is missing.
    ```cpp
    double square(double x) { return x * x; }
    ```

### [Exercise 6.3:](Exercise_03/Ex03.cpp)

*Write and test your own version of `fact`.*

### [Exercise 6.4:](Exercise_04/Ex04.cpp)

*Write a function that interacts with the user, asking for a number and generating the factorial of that number. Call this function from main.*

### [Exercise 6.5:](Exercise_05/Ex05.cpp)

*Write a function to return the absolute value of its argument.*

## 6.1.1. Local Objects

### Exercise 6.6: 

*Explain the differences between a `parameter`, a `local variable`, and a `local static variable`. Give an example of a function in which each
might be useful.*

**Answer**

- A **Parameter** is a local variable that is initialized by an function's argument. Its lifetime begin when the function starts and it's destroyed in the end of the function.
- A **Local Variable** is a variable defined in the function's scope, if not initialized and if it's a built in type its value is undefined.  Its lifetime begin when the function starts and it's destroyed in the end of the function.
- A **Local Static Variable** is a variable defined in the function's scope but its life time is the same of the global scope.

### [Exercise 6.7:](Exercise_07/Ex07.cpp)

*Write a function that returns `0` when it is first called and then generates numbers in sequence each time it is called again.*

## 6.1.2. Function Declarations

### [Exercise 6.8:](Exercise_08/Chapter6.h)

*Write a header file named `Chapter6.h` that contains declarations for the functions you wrote for the exercises in § 6.1 (p. 205).*

## 6.1.3. Separate Compilation

### [Exercise 6.9:](Exercise_09/Ex09.cpp)

*Write your own versions of the `fact.cc` and `factMain.cc` files. These files should include your `Chapter6.h` from the exercises in the previous section. Use these files to understand how your compiler supports separate compilation.*

## 6.2.1. Passing Arguments by Value

### [Exercise 6.10:](Exercise_10/Ex10.cpp)

*Using pointers, write a function to swap the values of two `ints`. Test the function by calling it and printing the swapped values.*

## 6.2.2. Passing Arguments by Reference

### [Exercise 6.11:](Exercise_11/Ex11.cpp)

*Write and test your own version of reset that takes a reference.*

### [Exercise 6.12:](Exercise_12/Ex12.cpp)

*Rewrite the program from exercise 6.10 in § 6.2.1 (p. 210) to use references instead of pointers to swap the value of two `ints`. Which version do you think would be easier to use and why?*

### Exercise 6.13: 

*Assuming `T` is the name of a type, explain the difference between a function declared as `void f(T)` and `void f(T&)`.*

**Answer**

- In the first function `void f(T)`, a new object of type `T` will be created in the function's scope and initialized by the argument passed to this function. As a copy of another object, all changes to this new object will be restrict to the local scope and this object will be destroyed within the end of the scope.
- In the second function `void f(&t)`, a new reference will be created in the function's scope, this reference is bound to the object passed as argument. The life time of this reference begins with the beginning of the function and ends within the function ending, but the object that the reference is bound continue to exist.

### Exercise 6.14: 

*Give an example of when a parameter should be a reference type. Give an example of when a parameter should not be a reference.*


### Exercise 6.15: 

*Explain the rationale for the type of each of find_char’s parameters In particular, why is `s` a reference to `const` but occurs is a plain reference? Why are these parameters references, but the char parameter `c` is not? What would happen if we made `s` a plain reference? What if we made occurs a reference to `const`?*