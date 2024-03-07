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

----------------------------
### [Back to Chapter 7](../Chapter_07/README.md) - [Next to Chapter 9](../Chapter_09/README.md)