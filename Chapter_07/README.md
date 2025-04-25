### [Back to Chapter 6](../Chapter_06/README.md)

# Chapter 7. Classes

### How to compile:

GCC 6.0+ or clang 3.3+

`g++ -Wall -Wextra -pedantic -std=c++11 target`

`clang++ -Wall -Wextra -pedantic -std=c++11 target`

## 7.1.1. Designing the Sales_data Class

### [Exercise 7.1:](Exercise_01/Ex01.cpp)

*Write a version of the transaction-processing program from §1.6 (p. 24) using the Sales_data class you defined for the exercises in § 2.6.1 (p. 72).*

## 7.1.2. Defining the Revised Sales_data Class

### [Exercise 7.2:](Exercise_02/Ex02.cpp)

*Add the combine and `isbn` members to the Sales_data class you wrote for the exercises in § 2.6.2 (p. 76).*

### [Exercise 7.3:](Exercise_03/Ex03.cpp)

*Revise your transaction-processing program from § 7.1.1 (p.256) to use these members.*

### [Exercise 7.4:](Exercise_04/Ex04.cpp) 

*Write a class named Person that represents the name and address of a person. Use a string to hold each of these elements. Subsequent exercises will incrementally add features to this class.*

### [Exercise 7.5:](Exercise_05/Ex05.cpp) 

*Provide operations in your Person class to return the name and address. Should these functions be const? Explain your choice.*

**Answer**

- In order to make this more flexible and secure it is better to use `const` in all cases possible. In this case, the object `Jhon` is `nonConst` and can be converted in a `const` object, but the inverse is not possible, if `Jhon` is a `const Person Jhon` and the function is not a `const` it will be illegal.

## 7.1.3. Defining Nonmember Class-Related Functions

### [Exercise 7.6:](Exercise_06/Ex06.cpp)

*Define your own versions of the add, read, and print functions.*

### [Exercise 7.7:](Exercise_07/Ex07.cpp)

*Rewrite the transaction-processing program you wrote for the exercises in § 7.1.2 (p. 260) to use these new functions.*

### Exercise 7.8:

*Why does read define its `Sales_data` parameter as a plain reference and print define its parameter as a reference to `const`*

**Answer**
- It is simple, the `read` function is a `write` function, it must have access to write the object. The `print` function is `read` function, it does not need access to `write` the object, then, we can use the modifier `const` to protect the object.

### [Exercise 7.9:](Exercise_09/Ex09.cpp)

*Add operations to `read` and `print` Person objects to the code you wrote for the exercises in § 7.1.2 (p. 260).*

### Exercise 7.10:

*What does the condition in the following `if` statement do?*
```cpp
if (read(read(cin, data1), data2))
```

**Answer**
- The first `read(cin, data1)` will read the input and will return the reference to the last character read + 1, then the next `read(cin, data2)` will continue reading where the `read(cin, data1)` read stopped.
- The `if` statement will be false if a null character is found before both read functions finished, in another words, this if will execute only when there is enough data in the input stream to populate the objects inside those functions.

## 7.1.4. Constructors

### [Exercise 7.11:](Exercise_11/Ex11.cpp)

*Add constructors to your Sales_data class and write a program to use each of the constructors.*

### [Exercise 7.12:](Exercise_12/Ex12.cpp)

*Move the definition of the Sales_data constructor that takes an `istream` into the body of the Sales_data class.*

### [Exercise 7.13:](Exercise_13/Ex13.cpp)

*Rewrite the program from page 255 to use the `istream constructor`.*

### [Exercise 7.14:](Exercise_14/Ex14.cpp)

*Write a version of the default constructor that explicitly initializes the members to the values we have provided as `in-class initializers`.*

### [Exercise 7.15:](Exercise_15/Ex15.cpp) 

*Add appropriate constructors to your Person class.*

## 7.2. Access Control and Encapsulation

### Exercise 7.16: 

*What, if any, are the constraints on where and how often an access specifier may appear inside a class definition? What kinds of members should be defined after a public specifier? What kinds should be private?*

**Answer**

- There is no constraints of where and how much an access specifier can appear.
- Usually public members of a class are get's and set's or any other function that not change the behavior of the object.
- In general private members of a class are objects and functions that can change the internal behavior of the object.

### Exercise 7.17: 

*What, if any, are the differences between using class or struct?*

**Answer**

- Both keywords are almost the same, the only difference being in access level, all members of a struct are public by default and in a class all members are private by default.

### Exercise 7.18: 

*What is encapsulation? Why is it useful?*

**Answer**

- Encapsulation is when we hide information about the behavior of the class from outside of the class, we can hide members and methods using the Access Control keyword private. 
- It is used to protect members of the class from changes outside of the scope of the class, changing the objects can lead to errors in the internal behavior of the object.

### Exercise 7.19: 

*Indicate which members of your Person class you would declare as public and which you would declare as private. explain your choice.*

**Answer**

```cpp
struct Person {
private:
    std::string name;
    std::string address;

    Person(std::istream &in) { read(in, *this); };
public:
    const std::string getName() const { return name; };
    const std::string getAddress() const { return address; };
};
```

- `Private:` - the objects `name` and `address` will be private in order to protect the data, data cannot be exposed outside of the scope of the function.
- `Public:` - the methods `getName()` and `getAddress()` will be public, as they are get and set, they are part of the interface.


## 7.2.1. Friends

### Exercise 7.20: 

*When are friends useful? Discuss the pros and cons of using friends.*

**Answer**
- Friend specifier is useful when you need to share private members of a class with another class or function without turn this private members in to public members.
- The pros: it can share private members with a select number of classes or functions, it is more secure than just turn private in public.
- The cons: it can change the internals of the object, it can be prone to errors.

### [Exercise 7.21:](Exercise_21/Ex21.cpp)

*Update your Sales_data class to hide its implementation. The programs you’ve written to use Sales_data operations should still continue to work. Recompile those programs with your new class definition to verify that they still work.*

### [Exercise 7.22:](Exercise_22/Ex22.cpp)

*Update your Person class to hide its implementation.*

## 7.3.1. Class Members Revisited

### [Exercise 7.23:](Exercise_23/Ex23.cpp)

*Write your own version of the Screen class.*

### [Exercise 7.24:](Exercise_24/Ex24.cpp)

*Give your Screen class three constructors: a default constructor; a constructor that takes values for height and width and initializes the contents to hold the given number of blanks; and a constructor that takes values for height, width, and a character to use as the contents of the screen.*

### [Exercise 7.25:](Exercise_25/Ex25.cpp)

*Can Screen safely rely on the default versions of copy and assignment? If so, why? If not, why not?*

**Answer**
- It is not entire safe to rely on default versions of copy and assignment operators, specially in cases when the object members of the class have no operation defined and its resources are created outside of the scope of the class, using allocated memory or something else.
- Is safe rely on the default operators with `std::vector`, `std::string`, `std::list` etc..., even though those objects allocate memory dynamically those objects implement those operations.

### [Exercise 7.26:](Exercise_26/Ex26.cpp)

Define `Sales_data::avg_price` as an inline function.

## 7.3.2. Functions That Return *this

###  [Exercise 7.27:](Exercise_27/Ex27.cpp)

*Add the move, set, and display operations to your version of Screen. Test your class by executing the following code:*

```cpp
Screen myScreen(5, 5, 'X');
myScreen.move(4,0).set('#').display(cout);
cout << "\n";
myScreen.display(cout);
cout << "\n";
```

### Exercise 7.28: 

*What would happen in the previous exercise if the return type of move, set, and display was `Screen` rather than `Screen&?`*

**Answer**
```cpp
myScreen.move(4,0).set('#').display(cout);
```
- Move will execute and will return a temporary copy of `myScreen`, set will execute and will return a temporary copy of a copy of `myScreen`, display will execute and will return temporary a copy of copy of copy of `myScreen`.

```cpp
myScreen.display(cout);
```
- Display will print 25 'X' characters, only the the temporary copies of `myScreen` will be modified.

**Improvement**
```cpp
myScreen = myScreen.move(4,0).set('#').display(cout);
```
- In order to apply those modifications, we need to assign the the last copy to `myScreen` as we can se above.

### [Exercise 7.29:](Exercise_29/Ex29.cpp) 

*Revise your Screen class so that move, set, and display functions return Screen and check your prediction from the previous exercise.*

**Output**
```cpp
Exercise_29$ ./a.out 
XXXXXXXXXXXXXXXXXXXX#XXXX

XXXXXXXXXXXXXXXXXXXXXXXXX
```

### Exercise 7.30: 

*It is legal but redundant to refer to members through the `this` pointer. Discuss the pros and cons of explicitly using the this pointer to access members.*

**Answer**
- The pros: A function can return a pointer or a reference to itself, other benefit when the local objects in a function have the same name of those defined on the class.
- The cons: In general using this is useless, so it make the code less readable.

## 7.3.3. Class Types

### [Exercise 7.31:](Exercise_31/Ex31.cpp) 

*Define a pair of classes X and Y, in which X has a pointer to Y, and Y has an object of type X.*

## 7.3.4. Friendship Revisited

### [Exercise 7.32:](Exercise_32/Ex32.cpp) 

Define your own versions of Screen and Window_mgr in which clear is a member of Window_mgr and a friend of Screen. 

## 7.4. Class Scope

### [Exercise 7.33:](Exercise_33/Ex33.cpp) 

*What would happen if we gave Screen a size member defined as follows? Fix any problems you identify.*

```cpp
pos Screen::size() const
{
    return height * width;
}
```

**Output**

```cpp
$ g++ Ex33.cpp 
In file included from Ex33.cpp:2:
Screen.h:52:1: error: ‘position’ does not name a type
   52 | position Screen::size() const
      | ^~~~~~~~
Screen.h:38:21: warning: inline function ‘Screen::position Screen::size() const’ used but never defined
   38 |     inline position size() const;
      |                     ^~~~
```

**Answer**
```cpp
Screen::position Screen::size() const
{
    return height * width;
}
```


## 7.4.1. Name Lookup and Class Scope

### Exercise 7.34: 

*What would happen if we put the `typedef` of pos in the `Screen` class on page 285 as the last line in the class?*
**Answer**
- Because `pos does not name a type` in the time when those all definitions appear, the compiler will raise errors on: 
    - void dummy_fcn(`pos height`)
    - `pos`s cursor = 0;
    - `pos` height = 0, width = 0;

### Exercise 7.35:

*Explain the following code, indicating which definition of `Type` or `initVal` is used for each use of those names. Say how you would fix any errors.*

```cpp
typedef string Type;

Type initVal();

class Exercise {
public:
    typedef double Type;
    Type setVal(Type);
    Type initVal();
private:
    int val;
};

Type Exercise::setVal(Type parm) {
    val = parm + initVal();
    return val;
}
```

**Answer**
- There is a class scope operator in the function `setval()`, in this case the compiler looks first for the naming definition in the class scope, the internal definitions of the objects are used.
- The only problem in this function is the return type is outside of the class scope, so you have to define the true scope of the name used.

```cpp
Exercise::Type Exercise::setVal(Type parm) {
    val = parm + initVal();
    return val;
}
```
## 7.5.1. Constructor Initializer List

### Exercise 7.36: 

*The following initializer is in error. Identify and fix the problem.*
```cpp
struct X {
    X (int i, int j): base(i), rem(base % j) { }
    int rem, base;
};
```
**Answer**
- The first member to initialize is `rem`, but depends of `base` that was not initialize yet.
```cpp
struct X {
    X (int i, int j): rem(i % j), base(i) { }
    int rem, base;
};
```

### Exercise 7.37: 

*Using the version of Sales_data from this section, determine which constructor is used to initialize each of the following variables and list the values of the data members in each object:*

```cpp
Sales_data first_item(cin);

int main() {
    Sales_data next;
    Sales_data last("9-999-99999-9");
}
```
**Answer**

- `Sales_data first_item(cin);` uses `Sales_data(std::istream &is)` constructor:
    - b`ookNo`, `cnt` and `rev` are defined by user input.
- `Sales_data next` uses the default constructor `Sales_data(std::string s = "")` constructor:
    - `bookNo` = "", `cnt` = 0 and `rev` = 0.0.
- `Sales_data last("9-999-99999-9")` uses `Sales_data(std::string s = "")` constructor:
    - `bookNo` = "9-999-99999-9", `cnt` = 0 and `rev` = 0.0.

### Exercise 7.38:

*We might want to supply cin as a default argument to the constructor that takes an `istream&`. Write the constructor declaration that uses cin as a default argument.*

**Answer**
```cpp
class SalesData {
public:
    SalesData(std::istream &in = std::cin) {read(is, *this);}
};
```

### Exercise 7.39: 

*Would it be legal for both the constructor that takes a string and the one that takes an `istream&` to have default arguments? If not, why not?*

**Answer**
- No it is not possible, it is a ambiguous situation, the compiler does not know witch function to call.

**Output**
```cpp
teste.cpp: In function ‘int main()’:
teste.cpp:19:16: error: call of overloaded ‘Sales_data()’ is ambiguous
   19 |     Sales_data sl;
      |                ^~
teste.cpp:10:5: note: candidate: ‘Sales_data::Sales_data(std::istream&)’
   10 |     Sales_data(std::istream &in = std::cin);
      |     ^~~~~~~~~~
teste.cpp:9:5: note: candidate: ‘Sales_data::Sales_data(std::string)’
    9 |     Sales_data(std::string s = "");
      |     ^~~~~~~~~~
```

### [Exercise 7.40:](Exercise_40/Ex_40.cpp)

*Choose one of the following abstractions (or an abstraction of your own choosing). Determine what data are needed in the class. Provide an appropriate set of constructors. Explain your decisions.*

```cpp
(a) Book
(b) Date
(c) Employee
(d) Vehicle  <<---- myChoice
(e) Object
(f) Tree
```

## 7.5.2. Delegating Constructors

### [Exercise 7.41:](Exercise_41/Ex_41.cpp)

*Rewrite your own version of the Sales_data class to use delegating constructors. Add a statement to the body of each of the constructors that prints a message whenever it is executed. Write declarations to construct a Sales_data object in every way possible. Study the output until you are certain you understand the order of execution among delegating constructors.*


### [Exercise 7.42:](Exercise_42/Ex_42.cpp)

*For the class you wrote for exercise 7.40 in § 7.5.1 (p. 291), decide whether any of the constructors might use delegation. If so, write the delegating constructor(s) for your class. If not, look at the list of abstractions and choose one that you think would use a delegating constructor. Write the class definition for that abstraction.*

## 7.5.3. The Role of the Default Constructor

### [Exercise 7.43:](Exercise_43/Ex_43.cpp)

*Assume we have a class named NoDefault that has a constructor that takes an int, but has no default constructor. Define a class C that has a member of type NoDefault. Define the default constructor for C.*

### Exercise 7.44: 

*Is the following declaration legal? If not, why not?*
```cpp
vector<NoDefault> vec(10);
```
**Answer**
- `vec(10)` means it will create 10 NoDefault objects with the default value initialized, in this case it becomes illegal due to the fact that there is no default constructor that match the initialization type of `vec(10)`.
- In order to work properly it is necessary to define a default constructor or change `vec` to initialize the object with the constructor that takes an int.
    ```cpp
    std::vector<NoDefault> vec(1,10);
    ``` 
**Output**
```cpp
$ g++ Ex_43.cpp 
In file included from /usr/include/c++/11/vector:65,
                 from Ex_43.cpp:1:
/usr/include/c++/11/bits/stl_construct.h: In instantiation of ‘void std::_Construct(_Tp*, _Args&& ...) [with _Tp = NoDefault; _Args = {}]’:
/usr/include/c++/11/bits/stl_uninitialized.h:579:18:   required from ‘static _ForwardIterator std::__uninitialized_default_n_1<_TrivialValueType>::__uninit_default_n(_ForwardIterator, _Size) [with _ForwardIterator = NoDefault*; _Size = long unsigned int; bool _TrivialValueType = false]’
/usr/include/c++/11/bits/stl_uninitialized.h:640:20:   required from ‘_ForwardIterator std::__uninitialized_default_n(_ForwardIterator, _Size) [with _ForwardIterator = NoDefault*; _Size = long unsigned int]’
/usr/include/c++/11/bits/stl_uninitialized.h:704:44:   required from ‘_ForwardIterator std::__uninitialized_default_n_a(_ForwardIterator, _Size, std::allocator<_Tp>&) [with _ForwardIterator = NoDefault*; _Size = long unsigned int; _Tp = NoDefault]’
/usr/include/c++/11/bits/stl_vector.h:1606:36:   required from ‘void std::vector<_Tp, _Alloc>::_M_default_initialize(std::vector<_Tp, _Alloc>::size_type) [with _Tp = NoDefault; _Alloc = std::allocator<NoDefault>; std::vector<_Tp, _Alloc>::size_type = long unsigned int]’
/usr/include/c++/11/bits/stl_vector.h:512:9:   required from ‘std::vector<_Tp, _Alloc>::vector(std::vector<_Tp, _Alloc>::size_type, const allocator_type&) [with _Tp = NoDefault; _Alloc = std::allocator<NoDefault>; std::vector<_Tp, _Alloc>::size_type = long unsigned int; std::vector<_Tp, _Alloc>::allocator_type = std::allocator<NoDefault>]’
Ex_43.cpp:16:34:   required from here
/usr/include/c++/11/bits/stl_construct.h:119:7: error: no matching function for call to ‘NoDefault::NoDefault()’
  119 |       ::new((void*)__p) _Tp(std::forward<_Args>(__args)...);
      |       ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Ex_43.cpp:5:5: note: candidate: ‘NoDefault::NoDefault(int)’
    5 |     NoDefault(int x): i(x) {};
      |     ^~~~~~~~~
Ex_43.cpp:5:5: note:   candidate expects 1 argument, 0 provided
Ex_43.cpp:4:8: note: candidate: ‘constexpr NoDefault::NoDefault(const NoDefault&)’
    4 | struct NoDefault {
      |        ^~~~~~~~~
Ex_43.cpp:4:8: note:   candidate expects 1 argument, 0 provided
Ex_43.cpp:4:8: note: candidate: ‘constexpr NoDefault::NoDefault(NoDefault&&)’
Ex_43.cpp:4:8: note:   candidate expects 1 argument, 0 provided
```

### [Exercise 7.45:](Exercise_45/Ex_45.cpp)

*What if we defined the vector in the previous exercise to hold objects of type C?*

**Answer**
- It will happen the same problem in the `Exercise 7.44`.
- There is no default constructor for `NoDefault` in the class `C` to call.;

### Exercise 7.46:

*Which, if any, of the following statements are untrue? Why?*

- (a) A class must provide at least one constructor.
- (b) A default constructor is a constructor with an empty parameter list.
- (c) If there are no meaningful default values for a class, the class should not provide a default constructor.
- (d) If a class does not define a default constructor, the compiler generates one that initializes each data member to the default value of its associated type.

**Answer**
- (a) - `Untrue:` If a constructor is not defined the compiler will create a default constructor.
- (b) - `Untrue:` A default constructor is a constructor that does not require a single argument to be used, in this case when a default argument is used in all parameters.
- (c) - `Untrue:` The compiler will create a default constructor if any is present.
- (d) - `Untrue:` If any constructor is defined the compiler will not create a default constructor.

## 7.5.4. Implicit Class-Type Conversions

### Exercise 7.47: 

*Explain whether the Sales_data constructor that takes a string should be explicit. What are the benefits of making the constructor explicit? What are the drawbacks?*

**Answer**
- There is no need to use the modifier in this constructor, the conversion can be used to add a null book or whatever, it means it is not meaningless.
    - Benefits: The developer of this class has more control in its use, the developer can denied other forms of initialization other than the direct initialization, it means, the user can only use the conversions explicitly using type cast. 
    - Drawbacks: After using the `Explicit` modifier it is not possible to initialize an object by copy, only direct initialization is possible.


### Exercise 7.48: 

*Assuming the Sales_data constructors are not explicit, what operations happen during the following definitions*
```cpp
string null_isbn("9-999-99999-9");
Sales_data item1(null_isbn);
Sales_data item2("9-999-99999-9");
```
**Answer**

```cpp
string null_isbn("9-999-99999-9");
Sales_data item1(null_isbn); // ok: it works(only one conversion)
Sales_data item2("9-999-99999-9"); // error: it require two convertion.
```

*What happens if the Sales_data constructors are explicit?*

**Answer**

```cpp
string null_isbn("9-999-99999-9");
Sales_data item1(null_isbn); // error: explicit constructor
Sales_data item2("9-999-99999-9"); // error: explicit constructor
```

### Exercise 7.49: 

*For each of the three following declarations of combine, explain what happens if we call i.combine(s), where i is a Sales_data and s is a string:*
```cpp
(a) Sales_data &combine(Sales_data);
(b) Sales_data &combine(Sales_data&);
(c) Sales_data &combine(const Sales_data&) const;
```
**Answer**
- (a) `Sales_data &combine(Sales_data)`;
    - Ok: It works as expected, the string `s` is converted in an Sales_Data;
- (b) `Sales_data &combine(Sales_data&)`;
    - Error: it does not work, thins function requires a reference;
- (c) `Sales_data &combine(const Sales_data&) const`;
    - Error: in this function `*this` is a `const` object, os it can not return a `non const` object. The function combine must have access to eh internal members in order to combine both objects.

### Exercise 7.50: 

*Determine whether any of your Person class constructors should be explicit.*

**Answer**
- The constructor that receives a `istream` should be `Explicit` because once it reads from `std::cin` and do the proper operation this object is discarded, and the reference to the standard input points to the next object on the list.

### Exercise 7.51:

*Why do you think vector defines its single-argument constructor as explicit, but string does not?*

**Answer**
- `Vector` is a container, it does not know what kind of object it will contain, so it can not do the convertion to all possible objects.
- A `String` contain itself, it is simple to the compiler to make the implicit conversion.
- In another words a `Vector` is not what it contains.

## 7.5.5. Aggregate Classes

### Exercise 7.52: 

*Using our first version of Sales_data from § 2.6.1 (p. 72), explain the following initialization. Identify and fix any problems.*
```cpp
struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
```
```cpp
Sales_data item = {"978-0590353403", 25, 15.99};
```

**Answer**
- In order to create an aggregate class it is required to remove the in class initialization.
    ```cpp
    struct Sales_data {
        std::string bookNo;
        unsigned units_sold;
        double revenue;
    };
    ```
- In this copy initialized aggregate class the initialization process will be performed like this:

    ```cpp
    item {
        .bookNo = "978-0590353403", 
        .units_sold = 25,
        .revenue = 15.99,
    }
    ```
- There is an error in the revenue initialization, price is different of revenue:
    ```cpp
    Sales_data item = {"978-0590353403", 25, 25 * 15.99};
    ```

## 7.5.6. Literal Classes

### [Exercise 7.53:](Exercise_53/Ex_53.cpp)

*Define your own version of Debug.*

### Exercise 7.54: 

*Should the members of Debug that begin with set_ be declared as `constexpr`? If not, why not?*

**Answer**
- `constexpr` functions in C++11 are `const member function`, so that is not possible to change the members value of the object, the `*this` is converted in a `const pointer`. In C++14 this behavior was changed, in C++14 a `constexpr` function is no more a `const member function`

> **constexpr specifier (since C++11)**
>> A constexpr specifier used in an object declaration or non-static member function(until C++14) implies const. A constexpr specifier used in a function or static data member(since C++17) declaration implies inline. If any declaration of a function or function template has a constexpr specifier, then every declaration must contain that specifier.

https://en.cppreference.com/w/cpp/language/constexpr


### Exercise 7.55: 

*Is the Data class from § 7.5.5 (p. 298) a literal class? If not, why not? If so, explain why it is literal.*
```cpp
struct Data {
    int ival;
    std::string s;
};
```
**Answer**
- If all members of an aggregate class are literal types, it is called a literal class.
- This class is not a literal type, a `std::string` is not a literal type, in order to fix that we need to use the C-style string.  
    ```cpp
    struct Data {
        int ival;
        char s[size];
    };
    ```
## 7.6. static Class Members

### Exercise 7.56: 

*What is a `static` class member? What are the advantages of `static` members? How do they differ from ordinary members?*

**Answer**
- A `static` class member is an object that belongs to the class not the object and its life time begin and end with the program. 
- As its scope lives outside of the object it can be used to shared data between all objects of this class, it can be used to synchronize data in all instancies of this class.
- It cannot be class initialized or in the constructor, it require to be initialized outside of the scope of the class. It can contain an instance of the same class of itself. It also can be used as default argument. a static data member can have incomplete type.

### [Exercise 7.57:](Exercise_57/Ex_57.cpp)

*Write your own version of the Account class.*

### Exercise 7.58: 

*Which, if any, of the following static data member declarations and definitions are errors? Explain why.
```cpp
// example.h
class Example {
public:
    static double rate = 6.5;
    static const int vecSize = 20; 
    static vector<double> vec(vecSize);
};

// example.C
#include "example.h"
double Example::rate;
vector<double> Example::vec;
```
**Answer**
- Only `static` members `const` or `constexpr` can be class initialized.
- A static data member can have incomplete type.

```cpp
#include <vector>

class Example {
public:
    static constexpr double rate = 6.5;
    static const int vecSize = 20; 
    static std::vector<double> vec;
};

constexpr double Example::rate;
std::vector<double> Example::vec(Example::vecSize);

```

----------------------------
### [Back to Chapter 6](../Chapter_06/README.md) - [Next to Chapter 9](../Chapter_09/README.md)

