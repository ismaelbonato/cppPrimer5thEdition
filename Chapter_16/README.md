### [Back to Chapter 15](../Chapter_15/README.md)

# Chapter 16. Templates and Generic Programming

### How to compile:

GCC 6.0+ or clang 3.3+

`g++ -Wall -Wextra -pedantic -std=c++11 target`

`clang++ -Wall -Wextra -pedantic -std=c++11 target`

## 16.1.1. Function Templates

### Exercise 16.1
*Define instantiation.*

**Answer**
- Instantiation is the process by which the compiler generates a specific version of the template. This occurs when the template is used in the code at compile time. At this point, the compile uses deduction to determine the types used in that version.

### [Exercise 16.2](Exercise_02/Ex02.cpp)

*Write and test your own versions of the compare functions.*

### [Exercise 16.3](Exercise_03/Ex03.cpp)

*Call your compare function on two `Sales_data` objects to see how your compiler handles errors during instantiation.*

**Output**
- GCC
```shell
Ex03.cpp: In instantiation of ‘int compare(const T&, const T&) [with T = SalesData]’:
Ex03.cpp:17:12:   required from here
Ex03.cpp:6:11: error: no match for ‘operator<’ (operand types are ‘const SalesData’ and ‘const SalesData’)
    6 |     if (a < b) return -1;
      |         ~~^~~
Ex03.cpp:7:11: error: no match for ‘operator>’ (operand types are ‘const SalesData’ and ‘const SalesData’)
    7 |     if (a > b) return 1;
      |         ~~^~~
```
- CLANG
```shell
Ex03.cpp:6:11: error: invalid operands to binary expression ('const SalesData' and 'const SalesData')
    6 |     if (a < b) return -1;
      |         ~ ^ ~
Ex03.cpp:17:5: note: in instantiation of function template specialization 'compare<SalesData>' requested here
   17 |     compare(sales1, sales2);    
      |     ^
Ex03.cpp:7:11: error: invalid operands to binary expression ('const SalesData' and 'const SalesData')
    7 |     if (a > b) return 1;
      |         ~ ^ ~
2 errors generated.
```

### [Exercise 16.4](Exercise_04/Ex04.cpp)

*Write a template that acts like the library `find` algorithm. The function will need two template type parameters, one to represent the function’s iterator parameters and the other for the type of the value. Use your function to find a given value in a `vector<int>` and in a `list<string>`.*

### [Exercise 16.5](Exercise_05/Ex05.cpp)

*Write a template version of the print function from § 6.2.4 (p. 217) that takes a reference to an `array` and can handle `arrays` of any size and any element type.*

### [Exercise 16.6](Exercise_06/Ex06.cpp)

*How do you think the library `begin` and `end` functions that take an array argument work? Define your own versions of these functions.*

**Answer**
- In order to use as generic function it is implemented as a template. 

```cpp
template<typename T, size_t N>
T *begin(T (&arr)[N])
{
    return arr;
}

template<typename T, size_t N>
T *end(T (&arr)[N])
{
    return arr + N;
}
```

### [Exercise 16.7](Exercise_07/Ex07.cpp)

*Write a `constexpr` template that returns the size of a given array.*

### [Exercise 16.8]()

*In the “Key Concept” box on page 108, we noted that as a matter of habit C++ programmers prefer using `!=` to using `<`. Explain the rationale for this habit.*

**Answer**
- C++ programmers prefer using `!=` instead of `<` when writing loops with iterators because not all iterator types support the `<` (less than) operator. However, all standard iterators support the `==` (equality) and `!=` (inequality) operators. Using `!=` ensures that the code works with all standard containers, including those whose iterators do not have a natural ordering (like `std::list` or `std::unordered_map`).

