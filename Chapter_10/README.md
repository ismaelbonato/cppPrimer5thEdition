
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

*Assuming v is a `vector<double>`, what, if anything, is wrong with calling `accumulate(v.cbegin()`,` v.cend()`, 0)?*

**Answer**
- The function's return type is deduced by the type of the third argument.

### [Exercise 10.5:](Exercise_05/Ex_05.cpp)

 *In the call to equal on rosters, what would happen if both rosters held `C-style` `strings`, rather than library `strings`?*

**Answer**
- Both will work in the same way because iterator are a type of pointer.

## 10.2.2. Algorithms That Write Container Elements

### [Exercise 10.6:](Exercise_06/Ex_06.cpp)

 *Using `fill_n`, write a program to set a sequence of int values to 0.*

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
- back_inserter does not override the algorithm functions, the back_inserter is a special iterator used to insert new elements into the back of a container.

## 10.2.3. Algorithms That Reorder Container Elements

### [Exercise 10.9:](Exercise_09/Ex_09.cpp)

*Implement your own version of `elimDups`. Test your program by printing the vector after you read the input, after the call to unique, and after the call to erase.*


### Exercise 10.10: 

*Why do you think the algorithms don’t change the size of containers?*

**Answer**
- When an element is inserted or removed the iterators used as parameters are invalidated.
- The algorithms work with iterators in a generic way, the algorithms do not have any containers operations.

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

## 10.3.2. Lambda Expressions

### [Exercise 10.14:](Exercise_14/Ex_14.cpp)

*Write a lambda that takes two `ints` and returns their sum.*

### [Exercise 10.15:](Exercise_15/Ex_15.cpp)

*Write a lambda that captures an `int` from its enclosing function and takes an `int` parameter. The lambda should return the sum of the captured `int` and the `int` parameter.*

### [Exercise 10.16:](Exercise_16/Ex_16.cpp)

*Write your own version of the biggies function using lambdas.*

### [Exercise 10.17:](Exercise_17/Ex_17.cpp)

*Rewrite exercise 10.12 from § 10.3.1 (p. 387) to use a lambda in the call to sort instead of the `compareIsbn` function.*

### [Exercise 10.18:](Exercise_18/Ex_18.cpp)

*Rewrite biggies to use `partition` instead of `find_if`. We described the partition algorithm in exercise 10.13 in § 10.3.1 (p. 387).*

### [Exercise 10.19:](Exercise_19/Ex_19.cpp)

*Rewrite the previous exercise to use `stable_partition`, which like `stable_sort` maintains the original element order in the `partitioned` sequence.*

## 10.3.3. Lambda Captures and Returns

### [Exercise 10.20:](Exercise_20/Ex_20.cpp)

*The library defines an algorithm named `count_if`. Like `find_if`, this function takes a pair of iterators denoting an input range and a predicate that it applies to each element in the given range. `count_if` returns a count of how often the predicate is true. Use `count_if` to rewrite the portion of our program that counted how many words are greater than length 6.*


### [Exercise 10.21:](Exercise_21/Ex_21.cpp)

*Write a lambda that captures a local int variable and decrements that variable until it reaches 0. Once the variable is 0 additional calls should no longer decrement the variable. The lambda should return a bool that indicates whether the captured variable is 0.

## 10.3.4. Binding Arguments

### [Exercise 10.22:](Exercise_22/Ex_22.cpp)

*Rewrite the program to count words of size 6 or less using functions in place of the lambdas.*

### Exercise 10.23: 

*How many arguments does bind take?*

**Answer**
- The bind function accepts two arguments: a callable object and a list of arguments separated by a comma. In other words, the number of arguments is equal to the number of items in the list plus the callable object.

### [Exercise 10.24:](Exercise_23/Ex_23.cpp)

*Use `bind` and `check_size` to find the first element in a vector of `ints` that has a value greater than the length of a specified string value.*

### [Exercise 10.25:](Exercise_25/Ex_25.cpp)

*In the exercises for § 10.3.2 (p. 392) you wrote a version of biggies that uses partition. Rewrite that function to use `check_size` and bind.*

## 10.4.1. Insert Iterators

### Exercise 10.26: 

*Explain the differences among the three kinds of insert iterators.*

**Answer**
- **Front_inserter** : Creates an iterator adaptor that employs the `push_front` function. However, this results in the reversal of the sequence's order.
- **Inserter** : The Inserter function generates an iterator that employs the `insert` function, ensuring that an object is consistently inserted ahead of the given iterator.
- **Back_inserter** : Creates an iterator adaptor that uses the `push_back` function, it inserts the object ahead of the last position of the sequence.         


### [Exercise 10.27:](Exercise_26/Ex_26.cpp)

*In addition to `unique` (§ 10.2.3, p. 384), the library defines function named `unique_copy` that takes a third iterator denoting a destination into which to copy the unique elements. Write a program that uses `unique_copy` to copy the unique elements from a vector into an initially empty list.*

### [Exercise 10.28:](Exercise_27/Ex_27.cpp)

*Copy a vector that holds the values from 1 to 9 inclusive, into three other containers. Use an inserter, a back_inserter, and a front_inserter, respectively to add elements to these containers. Predict how the output sequence varies by the kind of inserter and verify your predictions by running your programs.*

## 10.4.2. iostream Iterators

### [Exercise 10.29:](Exercise_29/Ex_29.cpp)

*Write a program using stream iterators to read a text file into a vector of strings.*

### [Exercise 10.30:](Exercise_30/Ex_30.cpp)

*Use stream iterators, sort, and copy to read a sequence of integers from the standard input, sort them, and then write them back to the standard output.*

### [Exercise 10.31:](Exercise_31/Ex_31.cpp)

*Update the program from the previous exercise so that it prints only the unique elements. Your program should use `unqiue_copy` (§ 10.4.1, p. 403).*

### [Exercise 10.32:](Exercise_32/Ex_32.cpp)

*Rewrite the bookstore problem from § 1.6 (p. 24) using a vector to hold the transactions and various algorithms to do the processing. Use sort with your `compareIsbn` function from § 10.3.1 (p. 387) to arrange the transactions in order, and then use find and `accumulate` to do the `sum`.*

### [Exercise 10.33:](Exercise_33/Ex_33.cpp)

*Write a program that takes the names of an input file and two output files. The input file should hold integers. Using an `istream_iterator` read the input file. Using `ostream_iterators`, write the odd numbers into the first output file. Each value should be followed by a space. Write the even numbers into the second file. Each of these values should be placed on a separate line.*

----------------------------
### [Back to Chapter 9](../Chapter_09/README.md) - [Next to Chapter 11](../Chapter_11/README.md)