# Chapter 5. Statements

### How to compile:

GCC 6.0+ or clang 3.3+

`g++ -std=c++11 app_name.cpp -o target`

`clang++ -std=c++11 app_name.cpp -o target`

## 5.1. Simple Statements

### Exercise 5.1:

*What is a null statement? When might you use a null statement?*

**Answer**

- A Null Statement is an empty statement, it means it has just a semi colon `;`.
    ```cpp
    ; // a null statement.
    ```
- Usually a null statement is used with loops when whe just need to find a object in a list but with any interaction. As example:
    ```cpp
    while (...)
    ;
    ```

- As alternative I prefer using a  empty compound statement also known as block statement. As example.
    ```cpp
    while (...) {}
    ```

### Exercise 5.2: 

*What is a block? When might you might use a block?*

**Answer**

- A block is a compound statement, it means it is sequence of statements in order to form a block of statements in between curly braces.
- It is used when we need a new scope or with some types of statements like loops and conditional statements that can hold just one statement (simple statement or compound statement).

### [Exercise 5.3:](Exercise_03/Ex03.cpp)

*Use the comma operator (§ 4.10, p. 157) to rewrite the `while` loop from § 1.4.1 (p. 11) so that it no longer requires a `block`. Explain whether this rewrite improves or diminishes the readability of this code.*

**Answer**

- Using comma operator diminishes the readability, but it is always better than using logical `&&` and `||`  operator, as you can see above.

    ```cpp
    //Using logical AND operator
    (sum += val) &&  (++val);
    //Using logical OR operator
    (sum += val) ||  (++val);
    //Using Comma operator    
    sum += val,  ++val; // Comma has lowest precedence
    ```

## 5.2. Statement Scope

### Exercise 5.4: 

*Explain each of the following examples, and correct any problems you detect.*

```cpp
(a) while (string::iterator iter != s.end()) { /* . . . */ }
(b) while (bool status = find(word)) { /* . . . */ }
if (!status) { /* . . . */ }
```

- **(a)** - You can only initialize a variable inside a scope using the equal `=` operator, for using a control expression a variable needs to be previously initialized.
    ```cpp
    std::string::iterator iter = s.begin();
    while (iter != s.end()) { /* . . . */ }
    ```

- **(b)** - There is an error with the second part of the code, `status` is not declared in the `if` scope just in the `while` scope.
    ```cpp
    bool status;
    while (status = find(word)) { /* . . . */ }
    if (!status) { /* . . . */ }
    ```

## 5.3.1. The if Statement

### [Exercise 5.5:](Exercise_05/Ex05.cpp) 

*Using an if–else statement, write your own version of the program to generate the letter grade from a numeric grade.*

### [Exercise 5.6:](Exercise_06/Ex06.cpp)

*Rewrite your grading program to use the conditional operator (§ 4.7, p. 151) in place of the if–else statement.*

### Exercise 5.7: 

*Correct the errors in each of the following code fragments:*

```cpp
(a) if (ival1 != ival2)
        ival1 = ival2
    else ival1 = ival2 = 0;
```
```cpp
(b) if (ival < minval)
        minval = ival;
    occurs = 1;
```
```cpp
(c) if (int ival = get_value())
        cout << "ival = " << ival << endl;
    if (!ival)
        cout << "ival = 0\n";
```
```cpp
(d) if (ival = 0)
        ival = get_value();
```

**Answer**


```cpp
(a) if (ival1 != ival2)
        ival1 = ival2; // missing the semicolon
    else ival1 = ival2 = 0;
```
```cpp
(b) if (ival < minval) { // missing the courly braces
        minval = ival;
        occurs = 1;
    }
```
```cpp
(c) if ( int ival = get_value()) // using else you don't need to declare `ival` in a parent scope.
        cout << "ival = " << ival << endl;
    else
        cout << "ival = 0\n";
```
```cpp
(d) if (ival == 0) // this code is meaningless without using the equality operator.
        ival = get_value();
```

### Exercise 5.8: 

*What is a “dangling else”? How are else clauses resolved in C++?*

**Answer**

- A dangling else an else wrongly placed, It can appears when we use nested `if` without using curly braces, in this case an `else` may not respect the indentation of the code, when it happens the compiler combine the `else` with the nearest `if`. An example bellow.

    ```cpp
    // as the programer coded
    if (...) 
        if (...)
            // code
    else
        // code

    // as the compiler read
    if (...) {
        if (...) {
            // code
        } else {
            // code
        }
    }
    ```

## 5.3.2. The switch Statement

### [Exercise 5.9:](Exercise_09/Ex09.cpp) 

*Write a program using a series of if statements to count the number of vowels in text read from cin.*

### [Exercise 5.10:](Exercise_10/Ex10.cpp) 

*There is one problem with our vowel-counting program as
we’ve implemented it: It doesn’t count capital letters as vowels. Write a program that counts both lower- and uppercase letters as the appropriate vowel—that is, your program should count both `'a'` and `'A'` as part of aCnt, and so forth.*


### [Exercise 5.11:](Exercise_11/Ex11.cpp) 

*Modify our vowel-counting program so that it also counts the number of blank spaces, tabs, and newlines read.*

### [Exercise 5.12:](Exercise_12/Ex12.cpp) 

*Modify our vowel-counting program so that it counts the
number of occurrences of the following two-character sequences: ff, fl, and fi.*

### Exercise 5.13: 

*Each of the programs in the highlighted text on page 184 contains a common programming error. Identify and correct each error. *