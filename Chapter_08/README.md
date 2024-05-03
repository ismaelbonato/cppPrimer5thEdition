### [Back to Chapter 7](../Chapter_07/README.md)

# Chapter 8. The IO Library

### How to compile:

GCC 6.0+ or clang 3.3+

`g++ -std=c++11 app_name.cpp -o target`

`clang++ -std=c++11 app_name.cpp -o target`

## 8.1.2. Condition States


### [Exercise 8.1:](Exercise_01/Ex01.cpp) 

*Write a function that takes and returns an `istream&`. The function should read the stream until it hits end-of-file. The function should print what it reads to the standard output. Reset the stream so that it is valid before returning the stream.*


### [Exercise 8.2:](Exercise_02/Ex02.cpp)

*Test your function by calling it, passing cin as an argument.*

### Exercise 8.3: 

*What causes the following while to terminate?*
```cpp
while (cin >> i) /* ... */
```
**Answer**
- This while will terminate when a EOF is found or the internal state of the stream is in fail state.


## 8.2.1. Using File Stream Objects

### [Exercise 8.4:](Exercise_04/Ex04.cpp)

*Write a function to open a file for input and read its contents into a vector of strings, storing each line as a separate element in the vector.*

### [Exercise 8.5:](Exercise_05/Ex05.cpp)

*Rewrite the previous program to store each word in a separate element.*

### [Exercise 8.6:](Exercise_06/Ex06.cpp)

*Rewrite the bookstore program from § 7.1.1 (p. 256) to read its transactions from a file. Pass the name of the file as an argument to main (§ 6.2.5, p. 218).*


## 8.2.2. File Modes

### [Exercise 8.7:](Exercise_07/Ex07.cpp)

*Revise the bookstore program from the previous section to write its output to a file. Pass the name of that file as a second argument to main.*

### [Exercise 8.8:](Exercise_08/Ex08.cpp)

*Revise the program from the previous exercise to append its output to its given file. Run the program on the same output file at least twice to ensure that the data are preserved.*

## 8.3.1. Using an `istringstream`

### [Exercise 8.9:](Exercise_09/Ex09.cpp)

*Use the function you wrote for the first exercise in § 8.1.2 (p.314) to print the contents of an `istringstream` object.*

### [Exercise 8.10:](Exercise_10/Ex10.cpp)

*Write a program to store each line from a file in a `vector<string>`. Now use an `istringstream` to read each element from the vector a word at a time.*

### [Exercise 8.11:](Exercise_11/Ex11.cpp)

*The program in this section defined its `istringstream` object inside the outer while loop. What changes would you need to make if record were defined outside that loop? Rewrite the program, moving the definition of record outside the while, and see whether you thought of all the changes that are needed.*

**Answer**
- It does need to clear the internal state of the stream each time the `istringstream` perform a copy of the line. 

    ```cpp         
    record.clear();
    record.str(line);
    ```
    
### [Exercise 8.12:] 

*Why didn’t we use in-class Initializers in `PersonInfo`?*

**Answer**
- `PersonInfo` is a aggregate class or structure, all members are public there are no need to initialize aggregate class members because there is no internal logic.

## 8.3.2. Using `ostringstreams`

### [Exercise 8.13:](Exercise_13/Ex13.cpp)

*Rewrite the phone number program from this section to read from a named file rather than from cin.*

### Exercise 8.14: 

*Why did we declare entry and `nums` as `const auto &`?*

**Answer**
- When handling objects that have unknown size, it is better to pass as a reference than a copy. A reference perform a lot better than copying the whole object.
- As we are using reference as a parameter, we need to protect the data from corruption.

----------------------------
### [Back to Chapter 7](../Chapter_07/README.md) - [Next to Chapter 9](../Chapter_09/README.md)