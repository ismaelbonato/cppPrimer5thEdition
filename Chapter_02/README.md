# Chapter 2: Variables and Basic Types

### How to compile:

GCC 6.0+ or clang 3.3+

`g++ -std=c++11 app_name.cpp -o target`

`clang++ -std=c++11 app_name.cpp -o target`


### Exercise 2.1:

##### *What are the differences between `int`, `long`, `long long`, and `short`? Between an `unsigned` and a `signed` type? Between a `float` and a `double`?*

**Answer:**
- The differences between `int`, `long`, `long long`, and `short` are the amount o bytes to describe each data type, those data type are are often described as int = 32 Bits (4 bytes), long = 32 bits (4 bytes), long long = 64 bits (8 bytes) and short = 16 bits (2 bytes)

- The difference between `unsigned` and a `signed` is that Unsigned data types only represents positive values end signed represent negative and positive.

    - `signed char`: represent -127 to 127
    - `unsigned char`: represent 0 to 255

- The difference between `float` and a `double` is the precision of the floating point number described.
    - `float`has Single Precision.
    - `double has Double Precision.  

### Exercise 2.2:

##### *To calculate a mortgage payment, what types would you use for the rate, principal, and payment? Explain why you selected each type.*

# TO DO

### Exercise 2.3:

##### *What output will the following code produce?*

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

##### *Write a program to check whether your predictions were correct. If not, study this section until you understand what the problem is.*

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

##### *Determine the type of each of the following literals. Explain the differences among the literals in each of the four examples*

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

##### *What, if any, are the differences between the following definitions:*

```cpp
(a) int month = 9, day = 7;
(b) int month = 09, day = 07;
```
**Answer:**

- **(a)** - The values are decimal

- **(b)** - The values are Octal, but the number 9 in octal does not exist. the compiler will rise an error.        

### Exercise 2.7:
##### *What values do these literals represent? What type does each have?*

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

##### *What are the initial values, if any, of each of the following variables?*

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

##### *Explain whether each of the following is a declaration or a definition:*

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

##### *Which, if any, of the following names are invalid?*

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

#####  *What is the value of j in the following program?*

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

##### *Is the following program legal? If so, what values are*

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

##### *Which of the following definitions, if any, are invalid? Why?*

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

##### *Which, if any, of the following assignments are invalid? If they are valid, explain what they do.*

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

##### *What does the following code print?*

```cpp
int i, &ri = i;
i = 5; ri = 10;
std::cout << i << " " << ri << std::endl;
```
**Answer**

- It will print `10 10`.

### [Exercise 2.18:](Exercise_18/Ex18.cpp)

##### *Write code to change the value of a pointer. Write code to change the value to which the pointer points.*

### Exercise 2.19:

##### *Explain the key differences between pointers and references.*

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

##### *Explain each of the following definitions. Indicate whether any are illegal and, if so, why.*

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

##### *Assuming p is a pointer to int, explain the following code:*
```cpp
(a) if (p) // ...
(b) if (*p) // ...
```
**Answer:**

- **(a)** - This statement verifies if the pointer `p` has an address different of zero (if it was initialized), however, it does not verify if the address is valid or not, because it's not even possible.
- **(b)** - This statement verifies if the object pointed by `p` is true or false.

### [Exercise 2.23:](Exercise_23/Ex23.cpp)

##### *Given a pointer p, can you determine whether p points to a valid object? If so, how? If not, why not?*

**Answer**
- You cannot determine if p is pointed to an valid or a invalid address. In memory we can't distinguish a valid or invalid address.

### Exercise 2.24:

##### *Why is the initialization of `p` legal but that of `lp` illegal?*

```cpp
int i = 42; 
void *p = &i; 
long *lp = &i;
```
- The initialization of `p` is legal because the type `void*` is a type Unknown and so it can hold any other type.
- The initialization of `lp` is illegal because a pointer can only hold an object of the same type.

#### Exercise 2.25:

##### *Determine the types and values of each of the following variables.*

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

##### *Which of the following are legal? For those that are illegal, explain why.*
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
- **(d)** - Illegal: ++cnt is legal but `++sz` is Illegal, the value of a `const` cannot changed.


