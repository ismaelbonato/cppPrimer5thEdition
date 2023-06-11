# Chapter 4. Expressions

### How to compile:

GCC 6.0+ or clang 3.3+

`g++ -std=c++11 app_name.cpp -o target`

`clang++ -std=c++11 app_name.cpp -o target`

### Exercise 4.1:

*What is the value returned by 5 + 10 * 20/2?*

**Answer**

- Result is equal to 105.

```cpp
x = 5 + ((10 * 20)/2);
```

### Exercise 4.2: 

*Using Table 4.12 (p. 166), parenthesize the following expressions to indicate the order in which the operands are grouped:*

```cpp
(a) * vec.begin()
(b) * vec.begin() + 1
```
**Answer**

```cpp
(a) *( vec.begin() )
(b) ( *( vec.begin() ) + ( 1 ) )
```

### Exercise 4.3: 

*Order of evaluation for most of the binary operators is left undefined to give the compiler opportunities for optimization. This strategy presents a trade-off between efficient code generation and potential pitfalls in the use of the language by the programmer. Do you consider that an acceptable trade-off? Why or why not?*

**Answer**

- I don't think it worth it to bring if instability and unknown behaviors in order to optimize a code, it can become very difficult to find and handle those problems.

### [Exercise 4.4:](Exercise_04/Ex04.cpp)

Parenthesize the following expression to show how it is
evaluated. Test your answer by compiling the expression (without
parentheses) and printing its result.

```cpp
12 / 3 * 4 + 5 * 15 + 24 % 4 / 2
```
**Answer**

- The result is equal to: 91 

```cpp
( ((12 / 3) * 4) + (5 * 15) + ((24 % 4) / 2) )
```

**Output**

```cpp
./a.out 
91
```

### Exercise 4.5:

*Determine the result of the following expressions.*

```cpp
(a) -30 * 3 + 21 / 5
(b) -30 + 3 * 21 / 5
(c) 30 / 3 * 21 % 5
(d) -30 / 3 * 21 % 4
```
**Answer**

```cpp
(a) ( -(30 * 3) + (21 / 5) )  // result = -86
(b) (-30 + ( (3 * 21) / 5 ) ) // result = -18
(c) ( ((30 / 3) * 21) % 5 )   // result = 0
(d) ( (-(30 / 3) * 21) % 4)   // result = -2
```

### [Exercise 4.6:](Exercise_06/Exl06.cpp) 

*Write an expression to determine whether an int value is even or odd.

**Answer**
```cpp
( (n % 2) == 0) //if true it`s odd if not even 
```

### Exercise 4.7: 

*What does overflow mean? Show three expressions that will overflow.*

**Answer**

- Overflow means the number is greater than its type representation.

```cpp
// first: a char can represent a number from 0 to 254
unsigned char x = 254; // x = 0
x += 1; 

// Second:
unsigned char y = 26; // y = 5
y *= 10;

unsigned char z = 0; // z = 254
z -= 1;
```

### Exercise 4.8: 

*Explain when operands are evaluated in the logical `AND`, logical `OR`, and equality operators.*

**Answer**
- The evaluation order of `AND` operator begin from the left to right, the right side of this operation will be evaluated only if the left side is `true`.
- The evaluation order of `OR` operator begin from the left to right, the right side of this operation will be evaluated only if the left side is `false`.
- The evaluation order of `==` operator is not defined by the language.


### Exercise 4.9: 

*Explain the behavior of the condition in the following if:

```cpp
const char *cp = "Hello World";
if (cp && *cp)
```
**Answer**

- In this condition the left `cp` and right side `*cp` will be converted to `bool`, the left side will be tested, if false, the right side of this will be ignored.
- As result, it will be always true, because `cp` is an address to some point in the memory.

### Exercise 4.10: 

*Write the condition for a `while` loop that would read `ints` from the standard input and stop when the value read is equal to 42.*

**Answer**

```cpp
while ( (std::cin >> x) && (x == 42) ) {}
```

### Exercise 4.11: 

*Write an expression that tests four values, `a`, `b`, `c`, and `d`, and ensures that `a` is greater than `b`, which is greater than `c`, which is greater than `d`.*

**Answer**

```cpp
if (a > b && b > c && c > d) {}
```

### Exercise 4.12:

*Assuming `i`, `j`, and `k` are all `ints`, explain what `i != j < k` means.*

**Answer**

- First the precedence is `( i != (j < k) )`.
- The result of `j < k` expression is a `bool` that will be converted in an `int` of value `1` or `0` and it will be compared with an `int i`. If `i` is different of `0` or `1` this expression will not work as intended, any value for `i` different of `0` or `1` will give an meaningless result equal to  `true`.

### Exercise 4.13: 

*What are the values of i and d after each assignment?*
```cpp
int i; double d;
(a) d = i = 3.5;
(b) i = d = 3.5;
```

### Exercise 4.14: 

*Explain what happens in each of the if tests:*

```cpp
if (42 = i) // ...
if (i = 42) // ...
```

### Exercise 4.15: 

*The following assignment is illegal. Why? How would you correct it?*

```cpp
double dval; int ival; int *pi;
dval = ival = pi = 0;
```

### Exercise 4.16: 

*Although the following are legal, they probably do not behave as the programmer expects. Why? Rewrite the expressions as you think they should be.*
```cpp
(a) if (p = getPtr() != 0)
(b) if (i = 1024)
```
