### [Back to Chapter 14](../Chapter_14/README.md)

# Chapter 15. Object-Oriented Programming

### How to compile:

GCC 6.0+ or clang 3.3+

`g++ -Wall -Wextra -pedantic -std=c++11 target`

`clang++ -Wall -Wextra -pedantic -std=c++11 target`

## 15.2. Defining Base and Derived Classes

### Exercise 15.1: 

*What is a `virtual` member?*

**Answer**
- A `virtual` member is a function declared with the `virtual` keyword, this indicates that the function can be `overridden` in a derived class.
- An `overridden` function can be executed through a `base` class `reference` or `pointer`. That mechanism is called `Dynamic Binding` or `Runtime Polymorphism` , It is executed during runtime.

### Exercise 15.2: 

*How does the `protected` access specifier differ from `private`?*

**Answer**
- `Protected`: Members declared as protected are accessible within the class itself and by derived classes, but not from outside the class hierarchy.
- `Private`: Members declared as private are accessible only within the class itself, and not by derived classes or from outside the class.

### [Exercise 15.3:](Exercise_03/Ex03.cpp)

*Define your own versions of the `Quote` class and the `print_total` function.*


## 15.2.2. Defining a Derived Class

### Exercise 15.4: 

*Which of the following declarations, if any, are incorrect? Explain why.*

```cpp
class Base { ... };
(a) class Derived : public Derived { ... };
(b) class Derived : private Base { ... };
(c) class Derived : public Base;
```

**Answer**
- (a) It is incorrect, the base class must be defined before using to avoid self derivation.
- (b) It is correct.
- (c) It is incorrect, the derivation list must be defined in the derived definition, the declaration must not contain the derivation list.


### [Exercise 15.5:](Exercise_05/Ex05.cpp)

*Define your own version of the `Bulk_quote` class.*

### [Exercise 15.6:](Exercise_06/Ex06.cpp)

*Test your `print_total` function from the exercises in § 15.2.1 (p. 595) by passing both `Quote` and `Bulk_quote` objects o that function.*

### [Exercise 15.7:](Exercise_07/Ex07.cpp)

*Define a class that implements a limited discount strategy, which applies a discount to `books` purchased up to a given limit. If the number of copies exceeds that limit, the normal price applies to those purchased beyond the limit.*

## 15.2.3. Conversions and Inheritance

### Exercise 15.8: 

*Define `static type` and `dynamic type`.*

**Answer**
- `Static Type` is the type of a variable or expression defined in compilation time.
- `Dynamic type` is the type of a variable or expression as known at runtime.
- `Static Type` and `Dynamic Type` can differ in some cases like when the code in a derived class is executed through a base class reference or pointer, that mechanism is called `dynamic binding` `runtime polymorphism`.
- That difference in typing makes object-oriented programming and polymorphism possible in C++.

### Exercise 15.9: 

*When is it possible for an expression’s `static type` to differ from its `dynamic type`? Give three examples in which the `static` and `dynamic type` differ.*

**Answer**
- `Static Type` and `Dynamic Type` can differ only when the code in a derived class is executed through a base class reference or pointer, that mechanism is called `dynamic binding` of `runtime polymorphism`.
- That difference in typing makes object-oriented programming and polymorphism possible in C++.

```cpp
void function(const BaseClass &base) {}

DerivedClass derived;
BaseClass &baseRef = derived;
BaseClass *basePtr = &derived;

function(derived);
```

### Exercise 15.10: 

*Recalling the discussion from §8.1 (p. 311), explain how the program on page 317 that passed an `ifstream` to the `Sales_data` read function works.*

```cpp
std::istream &read(std::istream &inputStream, SalesData &item);
```

**Answer**
- The hierarchy of `std::ifstream.
```
// 
std::ifstream
   └── std::istream
         └── std::ios
               └── std::ios_base
```

- As the object `std::ifstream` is a derived class of `std::istream` there is no conversion, the base class can act like the derived class through `subtype polymorphism` (inheritance), the type of the object will be inferred at Runtime,this will enables polymorphic behavior. 


