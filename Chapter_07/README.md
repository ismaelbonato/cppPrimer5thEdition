### [Back to Chapter 6](../Chapter_06/README.md)

# Chapter 7. Classes

### How to compile:

GCC 6.0+ or clang 3.3+

`g++ -std=c++11 app_name.cpp -o target`

`clang++ -std=c++11 app_name.cpp -o target`

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

## [Exercise 7.31:](Exercise_31/Ex31.cpp) 

*Define a pair of classes X and Y, in which X has a pointer to Y, and Y has an object of type X.*








----------------------------
### [Back to Chapter 6](../Chapter_06/README.md) - [Next to Chapter 8](../Chapter_08/README.md)