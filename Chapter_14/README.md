### [Back to Chapter 13](../Chapter_13/README.md)

# Chapter 14. Overloaded Operations and Conversions

### How to compile:

GCC 6.0+ or clang 3.3+

`g++ -Wall -Wextra -pedantic -std=c++11 target`

`clang++ -Wall -Wextra -pedantic -std=c++11 target`


## 14.1. Basic Concepts

### Exercise 14.1: 

*In what ways does an `overloaded operator` differ from a `built-in operator`? In what ways are `overloaded operators` the same as the `built-in operators`?*

**Answer**
- The built-in types and the Overloaded versions of these operators do not preserve order of evaluation and/or short-circuit evaluation. Overladed operators allow the customization of the behavior for specific types.
- The built-in types and the overloaded versions keep the same precedence and associative behavior.

### [Exercise 14.2:](Exercise_02/Ex02.cpp) 

*Write declarations for the `overloaded` `input`, `output`, `addition`, and `compound-assignment` operators for `Sales_data`.*

### Exercise 14.3:

*Both `string` and `vector` define an `overloaded ==` that can be used to compare objects of those types. Assuming `svec1` and `svec2` are `vectors` that hold `strings`, identify which version of `==` is applied in each of the following expressions:*

```cpp
(a) "cobble" == "stone"
(b) svec1[0] == svec2[0]
(c) svec1 == svec2
(d) svec1[0] == "stone"
```

**Answer**
```cpp
(a) "cobble" == "stone";     //built-in C-style string literals type operator
(b) svec1[0] == svec2[0];    //String operator
(c) svec1 == svec2;          //Vector<string> operator
(d) svec1[0] == "stone";     //String operator
```

### Exercise 14.4: 

*Explain how to decide whether the following should be class members:*

```cpp
(a) %
(b) %=
(c) ++
(d) ->
(e) <<
(f) &&
(g) ==
(h) ()
```

**answer**
```cpp
(a) %   // Nonmember Implementation
(b) %=  // Member Implementation
(c) ++  // Member Implementation
(d) ->  // Member Implementation
(e) <<  // Nonmember Implementation
(f) &&  // Nonmember Implementation
(g) ==  // Nonmember Implementation
(h) ()  // Member Implementation
```

**Answer**
- When the operator changes the object it would be better to use membership.

### Exercise 14.5: 

*In exercise 7.40 from § 7.5.1 (p. 291) you wrote a sketch of one of the following classes. Decide what, if any, overloaded operators your class should provide.*

```cpp
(a) Book
(b) Date
(c) Employee
(d) Vehicle 
(e) Object
(f) Tree
```

**Answer**
- Vehicle should have the following overloaded operators: Input/Output, comparison, assign.

## 14.2.1. Overloading the Output Operator <<

### [Exercise 14.6:](Exercise_06/Ex06.cpp)

*Define an `output operator` for your `Sales_data class`.*

### [Exercise 14.7:](Exercise_07/Ex07.cpp)

*Define an `output operator` for you `String class` you wrote for the exercises in § 13.5 (p. 531).*

### [Exercise 14.8:](Exercise_08/Ex08.cpp)

*Define an `output operator` for the `class` you chose in exercise 7.40 from § 7.5.1 (p. 291).*