
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

## 10.2.2. Algorithms That Write Container Elements

### [Exercise 10.6:](Exercise_06/Ex_06.cpp)

*Using fill_n, write a program to set a sequence of int values to 0.*

### Exercise 10.7: 

*Determine if there are any errors in the following programs
and, if so, correct the error(s):*

- (a)
    ```cpp
    vector<int> vec; list<int> lst; int i;
    while (cin >> i)
        lst.push_back(i);
    copy(lst.cbegin(), lst.cend(), vec.begin());
    ```
- (b)
    ```cpp
    vector<int> vec;
    vec.reserve(10); // reserve is covered in § 9.4 (p. 356)
    fill_n(vec.begin(), 10, 0);
    ```
**Answer**

- (a) The third iterator has to belong to an container equal or greater in size.
    ```cpp
    vector<int> vec; list<int> lst; int i;
    while (cin >> i)
        lst.push_back(i);
    copy(lst.cbegin(), lst.cend(), back_inserter(vec));
    ```
- (b) Reserve is mean to reserve more space in memory, it is different than create new elements in the container.
    ```cpp
    vector<int> vec;
    vec.reserve(10); // reserve is covered in § 9.4 (p. 356)
    fill_n(vec.begin(), vec.size(), 0);
    ```

### Exercise 10.8: 

*We said that algorithms do not change the size of the containers over which they operate. Why doesn’t the use of back_inserter invalidate this claim?*

**Answer**
- back_inserter does not invalidade the algorithm functions, the back_inserter is a special iterator used to insert new elements in the back of a container.

## 10.2.3. Algorithms That Reorder Container Elements

### [Exercise 10.9:](Exercise_09/Ex_09.cpp)

*Implement your own version of `elimDups`. Test your program by printing the vector after you read the input, after the call to unique, and after the call to erase.*


### Exercise 10.10: 

*Why do you think the algorithms don’t change the size of containers?*

**Answer**
- When a element is inserted or removed the iterators used as parameters are invalidated.
- The algorithms work with iterators in a generic way, algorithms have not containers operations. 

## 10.3.1. Passing a Function to an Algorithm

### [Exercise 10.11:](Exercise_11/Ex_11.cpp)

*Write a program that uses `stable_sort` and `isShorter` to sort a vector passed to your version of `elimDups`. Print the vector to verify that your program is correct.*

### [Exercise 10.12:](Exercise_12/Ex_12.cpp)

*Write a function named `compareIsbn` that compares the `isbn()` members of two `Sales_data` objects. Use that function to sort a vector that holds `Sales_data` objects.*

**Output**

```cpp
Exercise_12$ ./a.out  < input 
0-201-78340-X 2  40 20
0-201-78342-X 3  30 10
0-201-78343-X 3  30 10
0-201-78344-X 3  30 10
0-201-78345-X 3  30 10
0-201-78346-X 3  30 10
0-201-78346-X 3  60 20
0-201-78347-X 3  60 20
0-201-78347-X 3  30 10
0-201-78347-X 3  30 10
0-201-78347-X 3  30 10
0-201-78348-X 3  30 10
0-201-78349-X 3  60 20
```

### [Exercise 10.13:](Exercise_13/Ex_13.cpp)

*The library defines an algorithm named `partition` that takes a predicate and partitions the container so that values for which the predicate is true appear in the first part and those for which the predicate is false appear in the second part. The algorithm returns an iterator just past the last element for which the predicate returned true. Write a function that takes a string and returns a bool indicating whether the string has five characters or more. Use that function to partition words. Print the elements that have five or more characters.*


----------------------------
### [Back to Chapter 9](../Chapter_09/README.md) - [Next to Chapter 11](../Chapter_11/README.md)