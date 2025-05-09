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

## 14.2.2. Overloading the Input Operator >>

### [Exercise 14.9:](Exercise_09/Ex09.cpp)

*Define an input operator for your Sales_data class.*

### Exercise 14.10: 

*Describe the behavior of the Sales_data input operator if given the following input:*

```cpp
(a) 0-201-99999-9 10 24.95
(b) 10 24.95 0-210-99999-9
```

**Answer**
- The input `0-201-99999-9 10 24.95` will work as expected.
- The input `10 24.95 0-210-99999-9` will not rise an error in the input stream, but the price `0-210-99999-9` as a string will be converted in an double.
- SalesData state is inconsistent.
- All conversions above.

```cpp
10              // will be converted in an string "10".
24.94           // will be converted in an unsigned int 24.
0-210-99999-9   // will be converted in a double 0.95
```
**Output**
```shell
0-201-99999-9 10 249.5 24.95
10 24 22.8 0.95
```

### [Exercise 14.11:](Exercise_11/Ex11.cpp)

*What, if anything, is wrong with the following `Sales_data input operator`? What would happen if we gave this operator the data in the previous exercise?*

```cpp
istream& operator>>(istream& in, Sales_data& s)
{
    double price;
    in >> s.bookNo >> s.units_sold >> price;
    s.revenue = s.units_sold * price;
    return in;
}
```

**Answer**
- Price for `SalesData item` is not set, instead a local was created, but since the price is not printed in the output, it will hide the error.

**Output**

```shell
0-201-99999-9 10 249.5 24.95
10 24 22.8 0.95
```

### [Exercise 14.12:](Exercise_12/Ex12.cpp)

*Define an `input operator` for the class you used in exercise 7.40 from § 7.5.1 (p. 291). Be sure the `operator` handles `input errors`.*

## 14.3. Arithmetic and Relational Operators

### Exercise 14.13: 

*Which other `arithmetic operators` (Table 4.1 (p. 139)), if any, do you think `Sales_data` ought to support? Define any you think the class should include.*

**Answer**
- *(SalesData * int), +(SalesData + SalesData, SalesData + int), subtraction(SalesData - int), +=, -=;

### Exercise 14.14: 

*Why do you think it is more efficient to define `operator+` to call `operator+=` rather than the other way around?*

**Answer**
- To avoids not necessary copies.

### Exercise 14.15:

*Should the class you chose for exercise 7.40 from § 7.5.1 (p. 291) define any of the arithmetic operators? If so, implement them. If not, explain why not.*

**Answer**
- There is no need to add any `arithmetic operators`, since the internal data of the Vehicle is just descriptive data.
- If the Vehicle class includes measurable or numeric data, such as mileage, fuel consumption, or load capacity, arithmetic operators could be useful.

## 14.3.1. Equality Operators

#### [Exercise 14.16:](Exercise_16/Ex16.cpp)

*Define `equality` and `inequality` `operators` for your `StrBlob` (§ 12.1.1, p. 456), `StrBlobPtr` (§ 12.1.6, p. 474), `StrVec` (§ 13.5, p. 526), and `String` (§ 13.5, p. 531) classes.*

### [Exercise 14.17:](Exercise_17/Ex17.cpp)

*Should the class you chose for exercise 7.40 from § 7.5.1 (p. 291) define the `equality operators`? If so, implement them. If not, explain why not.*

## 14.3.2. Relational Operators

### [Exercise 14.18:](Exercise_18/Ex18.cpp)

*Define `relational operators` for your `StrBlob`, `StrBlobPtr`, `StrVec`, and `String` classes.*

### Exercise 14.19: 

*Should the class you chose for exercise 7.40 from § 7.5.1 (p. 291) define the relational operators? If so, implement them. If not, explain why not.*

**Answer**
- The class `Vehicle` does not define the `relational` operators because it cannot be consistent with the `equality` operator.

## 14.4. Assignment Operators

### [Exercise 14.20:](Exercise_20/Ex20.cpp)

*Define the addition and `compound-assignment operators` for your `Sales_data` class.*

### [Exercise 14.21:](Exercise_21/Ex21.cpp)

*Write the `Sales_data` operators so that `+` does the actual addition and `+=` calls `+`. Discuss the disadvantages of this approach compared to the way these operators were defined in § 14.3 (p. 560) and § 14.4 (p. 564).*

**Answer**
- This approach is ineffective and inefficient, requiring additional operations.

- The use of the `compound operator` creates a `sum` that calls the `sum operator` This process generates two temporary objects: one at the beginning with the name `sum` and another `rvalue` as the return. Subsequently, it calls the `assign operator`.
- The use of the `Compound operator` ensures that no temporary object is created. It relies on the `sum compound operators` from the built-in types, thereby eliminating the need for additional function calls.

- Correct way:
    - Function Calls: 0(built-in types);
    - Temporary objects: 0;
- wrong way:
    - Function Calls: 2(operator+, operator=);
    - Temporary objects: 2(sum, return);

### [Exercise 14.22:](Exercise_22/Ex22.cpp)

*Define a version of the `assignment operator` that can assign a `string` representing an `ISBN` to a `Sales_data`.*

### [Exercise 14.23:](Exercise_23/Ex23.cpp)

*Define an `initializer_list assignment operator` for your version of the `StrVec` class.*

### Exercise 14.24:

*Decide whether the class you used in exercise 7.40 from § 7.5.1 (p. 291) needs a `copy- and move-assignment operator`. If so, define those operators.*

**Answer**
- The Vehicle class does not need any custom `copy or move assignment operator`, all data members are standard types, the synthesized operators can handle.

### Exercise 14.25: 

*Implement any other `assignment operators` your class should define. Explain which types should be used as operands and why.*

**Answer**
- The Vehicle class does not need any `custom assignment operator`, all data members are standard types, the synthesized operators can handle.


## 14.5. Subscript Operator

### [Exercise 14.26:](Exercise_26/Ex26.cpp)

*Define subscript operators for your StrVec, String, StrBlob, and StrBlobPtr classes.*

## 14.6. Increment and Decrement Operators

### [Exercise 14.27:](Exercise_27/Ex27.cpp)
*Add `increment` and `decrement` operators to your `StrBlobPtr` class.*

### [Exercise 14.28:](Exercise_28/Ex28.cpp)

*Define `addition` and `subtraction` for `StrBlobPtr` so that these operators implement `pointer arithmetic` (§ 3.5.3, p. 119).*


### Exercise 14.29: 

*We did not define a `const` version of the `increment` and `decrement` operators. Why not?*

**Answer**
- it change the internal state of the object, that is why it is a `member operator`. 

## 14.7. Member Access Operators

### [Exercise 14.30:](Exercise_30/Ex30.cpp)

*Add `dereference` and `arrow operators` to your `StrBlobPtr` class and to the `ConstStrBlobPtr` class that you defined in  exercise 12.22 from § 12.1.6 (p. 476). Note that the operators in `constStrBlobPtr` must return `const references` because the data member in `constStrBlobPtr` points to a `const vector`.*

### Exercise 14.31: 

*Our `StrBlobPtr` class does not define the `copy constructor`, `assignment operator`, or a `destructor`. Why is that okay?*

**Answer**
- the class `StrBlobPtr` does not directly manage any resources allocated, the synthesized versions can handle all internal data made of standard types.

### [Exercise 14.32:](Exercise_32/Ex32.cpp)

*Define a class that holds a pointer to a StrBlobPtr. Define the overloaded arrow operator for that class.*