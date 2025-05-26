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

### Exercise 16.8

*In the “Key Concept” box on page 108, we noted that as a matter of habit C++ programmers prefer using `!=` to using `<`. Explain the rationale for this habit.*

**Answer**
- C++ programmers prefer using `!=` instead of `<` when writing loops with iterators because not all iterator types support the `<` (less than) operator. However, all standard iterators support the `==` (equality) and `!=` (inequality) operators. Using `!=` ensures that the code works with all standard containers, including those whose iterators do not have a natural ordering (like `std::list` or `std::unordered_map`).

## 16.1.2. Class Templates

### Exercise 16.9
*What is a function template? What is a class template?*

**Answer**
- Templates are the foundation behind generic programming in c++. It allows to generate code that works with any type, enabling the reuse of code and type safety in compilation time.
    - Generic Programming (Templates) is a way to reuse code in compilation time.
    - Object-oriented programming (Subtype polymorphism) is a way to reuse code Runtime.

- Function template is modern way to create generic functions, it is a recipe to generate functions the can work with different types deduced in compilation time.
- Class template is modern way to create generic objects, it is a recipe to generate classes the can work with different types deduced in compilation time.

### Exercise 16.10
*What happens when a class template is instantiated?*

**Answer**
- The compiler deduces the type and the code for that class is generated.

### Exercise 16.11
*The following definition of `List` is incorrect. How would you fix it?*

```cpp
template <typename elemType> class ListItem;
template <typename elemType> class List {
public:
    List<elemType>();
    List<elemType>(const List<elemType> &);
    List<elemType>& operator=(const List<elemType> &);
    ~List();
    void insert(ListItem *ptr, elemType value);
private:
    ListItem<int> *front, *end;
};
```

**Answer**
- `ListItem` is a template, it requires the type to instantiate `ListItem` properly: 

```cpp
template <typename elemType> class ListItem;
template <typename elemType> class List {
public:
    List<elemType>();
    List<elemType>(const List<elemType> &);
    List<elemType>& operator=(const List<elemType> &);
    ~List();
    void insert(ListItem<elemType> *ptr, elemType value);
private:
    ListItem<elemType> *front, *end;
};
```

### [Exercise 16.12](Exercise_12/Ex12.cpp)
*Write your own version of the `Blob` and `BlobPtr` templates, including the various `const` members that were not shown in the text.*

### Exercise 16.13
*Explain which kind of friendship you chose for the `equality` and `relational` operators for `BlobPtr`.*

**Answer**
- Because these operators are inherently linked to the type T, specific instantiation was selected to ensure type safety and encapsulation.

### [Exercise 16.14](Exercise_11/Ex11.cpp)
*Write a `Screen` class template that uses `nontype` parameters to define the height and width of the `Screen`.*

### Exercise 16.15
*Implement input and output operators for your Screen template. Which, if any, friends are necessary in class Screen to make the input and output operators work? Explain why each friend declaration, if any, was needed.*

### Exercise 16.16
*Rewrite the `StrVec` class (§ 13.5, p. 526) as a template named `Vec`.*