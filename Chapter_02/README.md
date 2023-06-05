# Chapter 2. Variables and Basic Types

### How to compile:

GCC 6.0+ or clang 3.3+

`g++ -std=c++11 app_name.cpp -o target`

`clang++ -std=c++11 app_name.cpp -o target`

### Exercise 2.1:

*What are the differences between `int`, `long`, `long long`, and `short`? Between an `unsigned` and a `signed` type? Between a `float` and a `double`?*

**Answer:**
- The differences between `int`, `long`, `long long`, and `short` are the amount o bytes to describe each data type, those data type are are often described as int = 32 Bits (4 bytes), long = 32 bits (4 bytes), long long = 64 bits (8 bytes) and short = 16 bits (2 bytes)

- The difference between `unsigned` and a `signed` is that Unsigned data types only represents positive values end signed represent negative and positive.

    - `signed char`: represent -127 to 127
    - `unsigned char`: represent 0 to 255

- The difference between `float` and a `double` is the precision of the floating point number described.
    - `float`has Single Precision.
    - `double has Double Precision.  

### Exercise 2.2:

*To calculate a mortgage payment, what types would you use for the rate, principal, and payment? Explain why you selected each type.*

**Answer**

- In order to calculate the rate, principal and payment I would use the types float or double, all those values have just 2 decimals digits of precision.

### Exercise 2.3:

*What output will the following code produce?*

```cpp
unsigned u = 10, u2 = 42;
std::cout << u2 - u << std::endl;
std::cout << u - u2 << std::endl;
int i = 10, i2 = 42;
std::cout << i2 - i << std::endl;
std::cout << i - i2 << std::endl;
std::cout << i - u << std::endl;
std::cout << u - i << std::endl;
```
**Answer:**

- `u2 - u` = 32
- `u - u2`      = 2^32 - 32 = 4294967264
- `i2 - i` = 32
- `i - i2` = -32
- `i - u` = 0
- `u - i` = 0

### [Exercise 2.4:](Exercise_04/Ex04.cpp)

*Write a program to check whether your predictions were correct. If not, study this section until you understand what the problem is.*

**Output**
```cpp
32
4294967264
32
-32
0
0
```
### Exercise 2.5:

*Determine the type of each of the following literals. Explain the differences among the literals in each of the four examples*

**Answer:**

```cpp
(a) 'a',   // Char literal 8 bits
    L'a',  // Wide char literal literal 32bits
    "a",   // String literal 8 bits
    L"a"   // string Wide char literal utf-32
```
```cpp
(b) 10,    // Integer literal
    10u,   // Unsigned Integer literal
    10L,   // long Unsigned Integer literal
    10uL,  // long Unsigned Integer literal
    012,   // Unsigned Integer in Octal literal
    0xC    // Unsigned Integer in Hexadecimal literal
```
```cpp
(c) 3.14,  // double literal
    3.14f, // float literal
    3.14L  // Long double literal
```
```cpp
(d) 10,    // Integer literal
    10u,   // Unsigned Integer literal
    10.,   // Float literal
    10e-2  // Double
```

### Exercise 2.6:

*What, if any, are the differences between the following definitions:*

```cpp
(a) int month = 9, day = 7;
(b) int month = 09, day = 07;
```
**Answer:**

- **(a)** - The values are decimal

- **(b)** - The values are Octal, but the number 9 in octal does not exist. the compiler will rise an error.        

### Exercise 2.7:
*What values do these literals represent? What type does each have?*

```cpp
(a) "Who goes with F\145rgus?\012"
(b) 3.14e1L
(c) 1024f
(d) 3.14L
```
**Answer:**

- **(a)** - `\145` is a letter and `\012` is the line feed code. both are octal character literals
- **(b)** - Double precision. Long double - Floating point literal
- **(c)** - Single precision. Float - Floating point literal
- **(d)** - Double precision. Long double - Floating point literal


### [Exercise 2.8:](Exercise_08/Ex08.cpp)

*Using escape sequences, write a program to print 2M followed by a newline. Modify the program to print 2, then a tab, then an M,  followed by a newline.*

### [Exercise 2.9:](Exercise_09/Ex09.cpp)

*Explain the following definitions. For those that are illegal, explain what’s wrong and how to correct it.*

```cpp
(a) std::cin >> int input_value;
(b) int i = { 3.14 };
(c) double salary = wage = 9999.99;
(d) int i = 3.14;
```
**Answer:**

- **(a)** - An stream needs a variable defined beforehand 
```cpp
    int input_value;
    std::cin >> input_value;
```
- **(b)** - When a variable is initialized with curly braces the compiler verifies if there is no data loss on casting conversion.
```cpp
    int i = { (int)3.14 };
```
or
```cpp
    float i = { 3.14 };
```
- **(c)** -  There is no a previous declaration of `wage`.
```cpp
    double wage;
    double salary = wage = 9999.99;
```
- **(d)** - It is `legal` but the compiler will perform a casting conversion and data may be lost.

### [Exercise 2.10:](Exercise_10/Ex10.cpp)

*What are the initial values, if any, of each of the following variables?*

```cpp
std::string global_str;
int global_int;

int main()
{
    int local_int;
    std::string local_str;
}
```
**Answer**

- `global_str` - Global `String` is empty
- `global_str` - Global `Integer` is 0
- `local_int` -  Local `Integer` is undefined
- `local_str` - Local `String` is empty

**Output**
```cpp
global_str = 
global_int = 0
local_int = 32556
local_str = 
```
### [Exercise 2.11:](Exercise_11/Ex11.cpp)

*Explain whether each of the following is a declaration or a definition:*

```cpp
(a) extern int ix = 1024;
(b) int iy;
(c) extern int iz;
```
**Answer**

- **(a)** - Definition of a extern variable, it's Illegal.
- **(b)** - Definition.
- **(c)** - Only declaration without definition, extern defined elsewhere.

### [Exercise 2.12:](Exercise_12/Ex12.cpp)

*Which, if any, of the following names are invalid?*

```cpp
(a) int double = 3.14;
(b) int _;
(c) int catch-22;
(d) int 1_or_2 = 1;
(e) double Double = 3.14;
```
**Answer**

- **(a)** - `Invalid`: identifier `double` is keyword of the language.
- **(b)** - `Valid` or `Invalid`: A Global variable identifier can not begin with underscore.  it's useless without any indication of its meaning. it's not consistent with the convention.
- **(c)** - `Invalid`: `catch` is a keyword of the language.
- **(d)** - `Invalid`: Identifiers cannot begin with a number.
- **(e)** - `Valid`: It's not consistent with the convention.

### [Exercise 2.13:](Exercise_13/Ex13.cpp)

 *What is the value of j in the following program?*

```cpp
int i = 42;

int main()
{
    int i = 100;
    int j = i;
}
```

**Answer**

- j is equal to 100

### [Exercise 2.14:](Exercise_14/Ex14.cpp)

*Is the following program legal? If so, what values are*

```cpp
int i = 100, sum = 0;
for (int i = 0; i != 10; ++i)
sum += i;
std::cout << i << " " << sum << std::endl;
```
**Answer**

- i = 100 and sum is 9! factorial = 45

**Output**

```cpp
100 45
```
### [Exercise 2.14:](Exercise_15/Ex15.cpp)

*Which of the following definitions, if any, are invalid? Why?*

```cpp
(a) int ival = 1.01;
(b) int &rval1 = 1.01;
(c) int &rval2 = ival;
(d) int &rval3;
```
- **(a)** - `Valid`: but it's an assignment of an Floating point double literal to an Integer, the compiler will perform a type conversion.
- **(b)** - `Invalid`: a reference needs a object to be initialized.
- **(c)** - `Valid`: `rval2` will be a reference to `ival` = 1.
- **(d)** - `Invalid`: a reference needs an object to be initialized.

### [Exercise 2.16:](Exercise_16/Ex16.cpp)

*Which, if any, of the following assignments are invalid? If they are valid, explain what they do.*

```cpp
int i = 0, &r1 = i; double d = 0, &r2 = d;
(a) r2 = 3.14159;
(b) r2 = r1;
(c) i = r2;
(d) r1 = d;
```
**Answer**

- **(a)** - `Valid`: `d` will be assigned with the value 3.14159.
- **(b)** - `Valid`: `d` `double` will be assigned with the value of `i` `integer`.
- **(c)** - `Valid`: `i` `integer` will be assigned with the value of `d` `double` ,`conversion will be performed`
- **(d)** - `Valid`: `i` `integer` will be assigned with the value of `d` `double` ,`conversion will be performed`

### [Exercise 2.17:](Exercise_17/Ex17.cpp)

*What does the following code print?*

```cpp
int i, &ri = i;
i = 5; ri = 10;
std::cout << i << " " << ri << std::endl;
```
**Answer**

- It will print `10 10`.

### [Exercise 2.18:](Exercise_18/Ex18.cpp)

*Write code to change the value of a pointer. Write code to change the value to which the pointer points.*

### Exercise 2.19:

*Explain the key differences between pointers and references.*

**Answer**

- **Reference**:

    A reference is not an object it's an Alias to another object, once it was created a reference to bound an object it cannot be changed.

- **Pointer**:

    A pointer is an object who has the address of an object, it can be changed in runtime execution.

### Exercise 2.20:

### *What does the following program do?*

```cpp
int i = 42;
int *p1 = &i;
*p1 = *p1 * *p1;
```

**Answer**

- This program do de calculation of square of i (`i^2`) using the pointer to the i address.

### Exercise 2.21:

*Explain each of the following definitions. Indicate whether any are illegal and, if so, why.*

```cpp
int i = 0;

(a) double* dp = &i;
(b) int *ip = i;
(c) int *p = &i;
```
**Answer**

- **(a)** - Illegal: type of `dp` and `i` does not match.
- **(b)** - Illegal: `i` is not a address type, operator `&` is missing.
- **(c)** - Legal:

### Exercise 2.22:

*Assuming p is a pointer to int, explain the following code:*
```cpp
(a) if (p) // ...
(b) if (*p) // ...
```
**Answer:**

- **(a)** - This statement verifies if the pointer `p` has an address different of zero (if it was initialized), however, it does not verify if the address is valid or not, because it's not even possible.
- **(b)** - This statement verifies if the object pointed by `p` is true or false.

### [Exercise 2.23:](Exercise_23/Ex23.cpp)

*Given a pointer p, can you determine whether p points to a valid object? If so, how? If not, why not?*

**Answer**

- You cannot determine if p is pointed to an valid or a invalid address. In memory we can't distinguish a valid or invalid address.

### Exercise 2.24:

*Why is the initialization of `p` legal but that of `lp` illegal?*

```cpp
int i = 42; 
void *p = &i; 
long *lp = &i;
```
- The initialization of `p` is legal because the type `void*` is a type Unknown and so it can hold any other type.
- The initialization of `lp` is illegal because a pointer can only hold an object of the same type.

#### Exercise 2.25:

*Determine the types and values of each of the following variables.*

```cpp
(a) int* ip, &r = ip;
(b) int i, *ip = 0;
(c) int* ip, ip2;
```
**Answer**
- **(a)** - Illegal: the pointer `ip` is a `int` non initialized it means its value it's value depends on the scope. `r` is a reference to this pointer address, it's illegal, because `r`is a reference to an `int` type but `ip` without an address modifier `&` is an `address` type, the types does not match.
- **(b)** - Legal: `i` is an `int` non initialized it means its value depends on the scope. `ip` is pointer to an `int` with value equal zero.
- **(c)** - Legal: `* ip` is a pointer to an integer. `ip2` is an integer.

#### Exercise 2.26:

*Which of the following are legal? For those that are illegal, explain why.*
```cpp
(a) const int buf;
(b) int cnt = 0;
(c) const int sz = cnt;
(d) ++cnt; ++sz;
```
**Answer**

- **(a)** - Illegal: `const` needs to be initialized.
- **(b)** - Legal:
- **(c)** - Legal:
- **(d)** - Illegal: `++sz` is Illegal, the value of a `const` cannot be changed.

#### Exercise 2.27:

*Which of the following initializations are legal? Explain why.*

```cpp
(a) int i = -1, &r = 0;
(b) int *const p2 = &i2;
(c) const int i = -1, &r = 0;
(d) const int *const p3 = &i2;
(e) const int *p1 = &i2;
(f) const int &const r2;
(g) const int i2 = i, &r = i;
```
**Answer**

- **(a)** - Illegal: there is no object in witch `r` can hold a reference, a reference cannot hold a number as reference unless it is a const reference.
- **(b)** - Legal: `p2` is a const pointer to an `int`, so `i2` needs to be an `int`.
- **(c)** - Legal: `r` is a reference to a  `const int` temporary variable of value 0.
- **(d)** - Legal: `p3` is a const pointer to an `const int`, it means, you can't change the value of both, the object address it holds and value of the pointed object.
- **(e)** - Legal: `p1`is a pointer to an object of type `const int`.
- **(f)** - Illegal: the reference `r2`has to be initialized.
- **(g)** - Legal: `r` is a reference to a `const int`.

#### Exercise 2.28: 
*Explain the following definitions. Identify any that are illegal.*

```cpp
(a) int i, *const cp;
(b) int *p1, *const p2;
(c) const int ic, &r = ic;
(d) const int *const p3;
(e) const int *p;
```
**Answer**

- **(a)** - Illegal: a `const` pointer has to be initialized.
- **(b)** - Illegal: a `const` pointer has to be initialized.
- **(c)** - Illegal: a `const int` variable has to be initialized.
- **(d)** - Illegal: it's a `const` pointer has to be initialized.
- **(e)** - Legal: it's a pointer to a `const int`.

#### Exercise 2.29:

*Using the variables in the previous exercise, which of the following assignments are legal? Explain why.*

```cpp
(a) i = ic;
(b) p1 = p3;
(c) p1 = &ic;
(d) p3 = &ic;
(e) p2 = p1;
(f) ic = *p3;
```
**Answer**

- **(a)** - Legal: `ic` is a `const int`and `i`is an `int`.
- **(b)** - Illegal: `p1` is a pointer to an `int` and `p3`is a top-level `const int` pointer, so the qualifiers mismatch, you cannot change the value of a `const`.
- **(c)** - Illegal: a pointer to `const int` cannot be pointed to a `int`.
- **(d)** - Illegal: a top-level `const` pointer cannot be modified after its initialization.
- **(e)** - Illegal: a top-level `const` pointer cannot be assigned.
- **(f)** - Illegal: a `const int` cannot be assigned.

#### Exercise 2.30:

*For each of the following declarations indicate whether the object being declared has top-level or low-level const.*

```cpp
const int i = 0, v2 = 0; 
int v1 = v2;
int *p1 = &v1, &r1 = v1;
const int *p2 = &v2, *const p3 = &i, &r2 = v2;
```
**Answer**
- **`v2`** - Top-level
- **`p1`** - Low-level
- **`r1`** - Low-level
- **`p2`** - Low-level
- **`p3`** - Top-level & Low-level

#### Exercise 2.31:

*Given the declarations in the previous exercise determine whether the following assignments are legal. Explain how the top-level or low-level const applies in each case.*

```cpp
(a) r1 = v2;
(b) p1 = p2; 
(c) p1 = p3;
(d) p2 = p1;
(e) p2 = p3;
```
**Answer**

- **(a)** - Legal: `v2` has a top-level `const` and it will be converted so `const` will be ignored.
- **(b)** - Illegal: `p2` has a Low-level `const`, `p1` has not.
- **(c)** - Illegal: `p3` has a low-level `const`, `p1` has not.
- **(d)** - Legal: `p2` has a low-level `const`, `p1` has not, but it will be converted to an `const int`.
- **(e)** - Legal: `p2` and `p3` have a low-level `const`.

#### Exercise 2.32:

*Is the following code legal or not? If not, how might you make it legal?*

```cpp
int null = 0, *p = null; 
```
**Answer**

- It's Illegal, a pointer can only be initialized with a `literal` `0` or an address, an constexpr pointer can only be initialized with `literal` `0` and an address from global scope.
    - 1 Using the literal `nullptr`.
        ```cpp
        int null = 0, *p = nullptr;
        ```

    - 2º Initializing `*p` with `0` Using `#define`.
        ```cpp
        #define null 0;
        int *p = null;
        ```

    - 3º Initializing `*p` with an address.
        ```cpp
        int null = 0, *p = &null;
        ```

#### Exercise 2.33:

*Using the variable definitions from this section, determine what happens in each of these assignments:*

```cpp
a = 42; b = 42; c = 42; d = 42; e = 42; g = 42;
```
**Answer**

- **(a)** - Assign the literal value 42 to a `int`.
- **(b)** - Assign the literal value 42 to a `int`.
- **(c)** - Assign the literal value 42 to a `int`.
- **(d)** - Illegal: `d` is a pointer to an `int`, `*d = 42` to fix the assignment.
- **(e)** - Illegal: `e` is a pointer to an `const int`, pointer can only point to and address or a literal `nullptr`.
- **(g)** - Illegal: `g` is a reference to an `const int`, `const` cannot be assigned.

#### [Exercise 2.34:](Exercise_34/Ex34.cpp)

*Write a program containing the variables and assignments from the previous exercise. Print the variables before and after the assignments to check whether your predictions in the previous exercise were correct. If not, study the examples until you can convince yourself you know what led you to the wrong conclusion.*

#### [Exercise 2.35:](Exercise_35/Ex35.cpp) 

*Determine the types deduced in each of the following definitions. Once you’ve figured out the types, write a program to see whether you were correct.*

```cpp
const int i = 42; auto j = i; 
const auto &k = i; auto *p = &i;
const auto j2 = i, &k2 = i;
```
**Answer**

- **`j`** - is an `int`.
- **`k`** - is a reference `const int&`.  
- **`p`** - is a pointer `const int*`.
- **`j2`** - is a `const int`.  
- **`k2`** - is a reference `const int&`.

#### Exercise 2.36:

*In the following code, determine the type of each variable and the value each variable has when the code finishes:*

```cpp
int a = 3, b = 4;
decltype(a) c = a;
decltype((b)) d = a;
++c;
++d;
```
**Answer**

- **`a`** - is an `int` with value equal to 4.
- **`b`** - is an `int` with value equal to 4.
- **`c`** - is an `int` with value equal to 4
- **`d`** - is an reference `int&`  to `a` with value equal to 4

#### Exercise 2.37: 

*Assignment is an example of an expression that yields a reference type. The type is a reference to the type of the left-hand operand. That is, if i is an `int`, then the type of the expression `i = x is int&`. Using that knowledge, determine the type and value of each variable in this code:*

```cpp
int a = 3, b = 4;
decltype(a) c = a;
decltype(a = b) d = a;
```
**Answer**

- **`a`** - is an `int` with value equal to 3.
- **`b`** - is an `int` with value equal to 4.
- **`c`** - is an `int` with value equal to 3
- **`d`** - is an reference `int&` to `a` with value equal to 3


#### Exercise 2.38: 

*Describe the differences in type deduction between `decltype` and `auto`. Give an example of an expression where auto and decltype will deduce the same type and an example where they will deduce differing types.*

**Answer**

both use the returned type of an arithmetics expression to deduce right type to be used, but while `auto` specifier use this returned value in its initialization, `decltype` use the returned value just to deduce the type. The deduction method is a little different, as `decltype` deduction method saves the const and reference information, `auto` in some cases just ignore them.

```cpp
  int i = 0, &a = i;
```
- Different Type:
    ```cpp
    auto b = a;         // int
    decltype(a) b = a;  // int&
    ```
- Same Type:
    ```cpp
    auto c = i;         // int
    decltype(i) c = i;  // int
    ```
#### [Exercise 2.39:](Exercise_39/Ex39.cpp) 

*Compile the following program to see what happens when you forget the semicolon after a class definition. Remember the message for future reference.*

```cpp
struct Foo { /* empty */ } // Note: no semicolon
int main()
{
return 0;
}
```
**Output**

```cpp
Ex39.cpp:1:27: error: expected ‘;’ after struct definition
    1 | struct Foo { /* empty */ } // Note: no semicolon
      |                           ^
      |                           ;
```

#### [Exercise 2.40:](Exercise_39/Ex39.cpp)

*Write your own version of the Sales_data class.*

**Answer**
```cpp
struct SalesData {
    std::string bookNo;
    std::string bookName;
    unsigned units_sold = 0;
    double price = 0.0;
    double discount = 0.0; //in %
    double revenue = 0.0;
};
```

#### [Exercise 2.41:](Exercise_41)

*Use your Sales_data class to rewrite the exercises in § 1.5.1 (p. 22), § 1.5.2 (p. 24), and § 1.6 (p. 25). For now, you should define your Sales_data class in the same file as your main function.*

- [Exercise 1.20](Exercise_41/Ex41_20.cpp) 
- [Exercise 1.21](Exercise_41/Ex41_21.cpp) 
- [Exercise 1.22](Exercise_41/Ex41_22.cpp) 
- [Exercise 1.21](Exercise_41/Ex41_23.cpp)
- [Exercise 1.24](Exercise_41/Ex41_25.cpp) 


#### [Exercise 2.42:](Exercise_42)

*Write your own version of the Sales_data.h header and use it to rewrite the exercise from § 2.6.2 (p. 76).*

- [Exercise 1.20](Exercise_42/Ex42_20.cpp) 
- [Exercise 1.21](Exercise_42/Ex42_21.cpp) 
- [Exercise 1.22](Exercise_42/Ex42_22.cpp) 
- [Exercise 1.21](Exercise_42/Ex42_23.cpp)
- [Exercise 1.24](Exercise_42/Ex42_25.cpp) 