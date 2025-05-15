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

*Define a class that holds a pointer to a `StrBlobPtr`. Define the overloaded `arrow operator` for that class.*

## 14.8. Function-Call Operator

### Exercise 14.33: 

*How many operands may an overloaded `function-call` operator take?*

**Answer**
- A function-call operator can take any number of operands and types.

### [Exercise 14.34:](Exercise_34/Ex34.cpp)

*Define a `function-object` class to perform an `if-then-else operation`: The call operator for this class should take three parameters. It should test its first parameter and if that test succeeds, it should return its second parameter; otherwise, it should return its third parameter.*

### [Exercise 14.35:](Exercise_35/Ex35.cpp)

*Write a class like `PrintString` that reads a line of input from an `istream` and returns a `string` representing what was read. If the read fails, return the empty `string`.*

### [Exercise 14.36:](Exercise_36/Ex36.cpp)

*Use the class from the previous exercise to read the `standard input`, storing each line as an element in a `vector`.*

### [Exercise 14.37:](Exercise_37/Ex37.cpp)

*Write a class that tests whether two values are equal. Use that object and the library `algorithms` to write a program to replace all instances of a given value in a sequence.*

## 14.8.1. Lambdas Are Function Objects

### [Exercise 14.38:](Exercise_38/Ex38.cpp)

*Write a class that tests whether the length of a given `string` matches a given bound. Use that object to write a program to report how many words in an input file are of sizes 1 through 10 inclusive.*

### [Exercise 14.39:](Exercise_39/Ex39.cpp)

*Revise the previous program to report the count of words that are sizes 1 through 9 and 10 or more.*

### [Exercise 14.40:](Exercise_40/Ex40.cpp)

*Rewrite the `biggies` function from § 10.3.2 (p. 391) to use `function-object classes` in place of `lambdas`.*

### Exercise 14.41: 

*Why do you suppose the new `standard` added `lambdas`? Explain when you would use a `lambda` and when you would write a class instead.*

**Answer**
- The new standard introduced the `lambda` function to facilitate the use of algorithms.
- Declaring a `function object` is advantageous when it can be reused in multiple places or it is a complex object.


## 14.8.2. Library-Defined Function Objects

### [Exercise 14.42:](Exercise_42/Ex42.cpp)

*Using library function objects and adaptors, define an expression to*

```cpp
(a) Count the number of values that are greater than 1024
(b) Find the first string that is not equal to pooh
(c) Multiply all values by 2
```

### [Exercise 14.43:](Exercise_43/Ex43.cpp) 

*Using library function objects, determine whether a given `int` value is divisible by any element in a container of `ints`.*

## 14.8.3. Callable Objects and function

### [Exercise 14.44:](Exercise_44/Ex44.cpp) 

*Write your own version of a simple desk calculator that can handle binary operations.*

## 14.9.1. Conversion Operators

### [Exercise 14.45:](Exercise_45/Ex45.cpp) 

*Write `conversion operators` to convert a `Sales_data` to `string` and to `double`. What values do you think these operators should return?*

**Answer**
- For `std::string` it returns `bookNo`, as for `double` the `revenue`.

### [Exercise 14.46:](Exercise_46/Ex46.cpp) 

*Explain whether defining these `Sales_data` conversion operators is a good idea and whether they should be `explicit`.*

**Answer**
- It is not advisable to use this method, as it has the potential to cause more harm than good. Using it without `explicitly casting` the type can lead to confusion.

### Exercise 14.47: 

*Explain the difference between these two `conversion operators`:*

```cpp
struct Integral {
    operator const int();
    operator int() const;
};
```

**Answer**
```cpp
operator const int(); // it is a conversion operator for a `int` the const qualifier will be ignored..
operator int() const; // it is a conversion operator for a `int` but as it is a class member the const protect *this for any modifications, it is called `const member function qualifier`.
```

### Exercise 14.48:

*Determine whether the class you used in exercise 7.40 from § 7.5.1 (p. 291) should have a conversion to `bool`. If so, explain why, and explain whether the operator should be `explicit`. If not, explain why not.*

**Answer**
- It is not good idea to implement  `non-explicit bool operator` version. `Implicit` conversions to `bool` can lead to ambiguity and unexpected behavior, especially in expressions where automatic type conversions occur. Making the conversion operator `explicit` ensures that the user is aware of the conversion and must intentionally use it, such as in an `if statement`. This helps prevent misuse and makes the code more readable and safe.

### [Exercise 14.49:](Exercise_49/Ex49.cpp)

*Regardless of whether it is a good idea to do so, define a conversion to `bool` for the class from the previous exercise.*

## 14.9.2. Avoiding Ambiguous Conversions

### Exercise 14.50:

*Show the possible `class-type` conversion sequences for the initializations of `ex1` and `ex2`. Explain whether the initializations are legal or not.*

```cpp
struct LongDouble {
    LongDouble(double = 0.0);
    operator double();
    operator float();
};

LongDouble ldObj;
int ex1 = ldObj;
float ex2 = ldObj;
```

**Answer**

```cpp
int ex1 = ldObj; // Error, Ambiguous conversion.
float ex2 = ldObj; // It works, float is a perfect match.
```


### [Exercise 14.51:](Exercise_51/Ex51.cpp)

*Show the conversion sequences (if any) needed to call each version of `calc` and explain why the best viable function is selected.*

```cpp
void calc(int);
void calc(LongDouble);
double dval;
calc(dval); // which calc?
```

**Answer**
- `calc(dval)` calls `void calc(int)`.
- Standard conversions are preferred over `class-type` conversions.

## 14.9.3. Function Matching and Overloaded Operators

### Exercise 14.52: 

*Which `operator+`, if any, is selected for each of the addition expressions? List the candidate functions, the viable functions, and the `type` conversions on the arguments for each viable function:*

```cpp
class SmallInt {
    friend SmallInt operator+(const SmallInt&, const SmallInt&);
public:
    SmallInt(int = 0);                   // conversion from int
    operator int() const { return val; } // conversion to int
private:
    std::size_t val;
};

struct LongDouble {
    LongDouble(double = 0.0);
    // member operator+ for illustration purposes; + is usually a nonmember
    LongDouble operator+(const SmallInt&);
    operator double();
    operator float();
};

LongDouble operator+(LongDouble&, double);

SmallInt si;
LongDouble ld;

ld = si + ld; 
ld = ld + si;
```

**Answer**
- `ld = si + ld;`
    - si + (ld converted to float or double and to int)
        - SmallInt operator+(const SmallInt&, const SmallInt&);
        - result cannot be converted to LongDouble; 
    - si + (ld converted to float or double and converted in int through the smallInt constructor)
        - SmallInt(int = 0)
        - result cannot be converted to LongDouble;
    -  (si converted to built-in type) + (ld converted to built-in type)
        - result cannot be converted to LongDouble;
    
- `ld = ld + si;`
    - ld + si
        - LongDouble operator+(const SmallInt&)
        - Result can be converted in LongDouble to make the assignment. ***
    - (ld can be converted in double or float) + (si converted in int)
        - use built-in arithmetics.
        - result cannot be converted to LongDouble; 

**Conclusion**
- `ld = si + ld;` is illegal, There is no way to convert `smallInt` to `LongDouble`.
- `ld = ld + si;` will it use the `LongDouble operator+(const SmallInt&)`. It is legal.

###Exercise 14.53: 

*Given the definition of SmallInt on page 588, determine whether the following addition expression is legal. If so, what addition operator is used? If not, how might you change the code to make it legal?*

```cpp
class SmallInt {
    friend SmallInt operator+(const SmallInt&, const SmallInt&);
public:
    SmallInt(int = 0);                   // conversion from int
    operator int() const { return val; } // conversion to int
private:
    std::size_t val;
};

SmallInt s1;
double d = s1 + 3.14;
```

**Answer**
- It is Legal.
- the 3.14 will be converted to `smallInt` thought the `smallInt` constructor.
- The operator+ will be used.
- The result (3) will be converted in an double and assigned to d.
- d = 3.0;

----------------------------
### [Back to Chapter 13](../Chapter_13/README.md) - [Next to Chapter 15](../Chapter_15/README.md)