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

*Explain the behavior of the condition in the following if:*

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
- The result of `j < k` expression has a type a `bool` that will be converted in an `int` of value `1` or `0` and it will be compared with an `int i`. If `i` is different of `0` or `1` this expression will not work as intended, any value for `i` different of `0` or `1` will give an meaningless result equal to  `true`.

### Exercise 4.13: 

*What are the values of i and d after each assignment?*
```cpp
int i; double d;
(a) d = i = 3.5;
(b) i = d = 3.5;
```
**Answer**

- **(a)** - `i = 3`, `d = 3.0`
- **(b)** - `d = 3.5`, `i = 3` 

### Exercise 4.14: 

*Explain what happens in each of the if tests:*

```cpp
(a) if (42 = i) // ...
(b) if (i = 42) // ...
```
**Answer**

- **(a)** - It's ilegal because a literal cannot be an `lvalue`, in another word, a literal cannot be assigned.
- **(b)** - The assignment will be performed the expression `i = 42` will return an `int` value equal to 42, so, this test will never be false, in order to fix for this statement we need to use the compare operator `i == 42` and not the assignment operator.  

### Exercise 4.15: 

*The following assignment is illegal. Why? How would you correct it?*

```cpp
double dval; 
int ival; 
int *pi;

dval = ival = pi = 0;
```

**Answer**
- This assignment is illegal, `pi` is a pointer and there is no such thing as an automatic conversion from `int*` to `int` type.

```cpp
    double dval; 
    int ival; 
    int *pi = nullptr;

    dval = ival = 0;
```


### Exercise 4.16: 

*Although the following are legal, they probably do not behave as the programmer expects. Why? Rewrite the expressions as you think they should be.*

```cpp
(a) if (p = getPtr() != 0)
(b) if (i = 1024)
```
**Answer**

- **(a)** - It will not work as expected because assignment has low precedence, it means that `getPtr() != 0` will be processed before the assignment, in order to fix this exercise the use of of parenthesis is required.
    ```cpp
    if ( (p = getPtr()) != 0)
    ```

- **(b)** - It's legal but it will always give true as result of this statement, the correct way to write this is using the `compare` operator and not the `assignment` operator.
    ```cpp
    if (i == 1024)
    ```

### Exercise 4.17: 

*Explain the difference between prefix and postfix increment.*

**Answer**

- **`Prefix`** has high precedence, it increments or decreases an object by 1, the result is itself.
- **`Postfix`** has also high precedence, it increments or decreases an object by 1 and the result is its old itself, it means it increments or decrease the object by 1, after that, it creates a temporary object to store the old value before de increment and return this object.

### Exercise 4.18: 

*What would happen if the while loop on page 148 that prints the elements from a vector used the prefix increment operator?*

```cpp
auto pbeg = v.begin();
// print elements up to the first negative value
while (pbeg != v.end() && *beg >= 0)
cout << *++pbeg << endl;
```
**Answer**

- If we use the prefix increment operator, it will start to print from the second element in the vector up to the negative number (with the negative number included).

### Exercise 4.19: 

*Given that `ptr` points to an `int`, that `vec` is a `vector<int>`, and that `ival` is an `int`, explain the behavior of each of these expressions. Which, if any, are likely to be incorrect? Why? How might each be corrected?*

```cpp
(a) ptr != 0 && *ptr++
(b) ival++ && ival
(c) vec[ival++] <= vec[ival]
```

- **(a)** - This expression is correct, in this expression `!=` has precedence, so, first `ptr != 0` will be computed. This ensure that the expression `*ptr++` will be performed only if ptr is different of `nulptr`.
It's a great way we can test and use a pointer in the same expression because of the operator `&&` process left side  first.
- **(b)** - This expression verifies first the left side of the arithmetics, if `ival++` is true, the right side will be tested `ival` but incremented by 1. This expression is meaningless, therefore it's incorrect.
    ```cpp
    ival && (ival + 1)
    ```

- **(c)** - It is incorrect, its behavior is undetermined because we don't know what side of the equation will be performed first when using this operator.
    ```cpp
    vec[ival] <= vec[ival + 1]
    ```

### Exercise 4.20: 

*Assuming that `iter` is a `vector<string>::iterator`, indicate which, if any, of the following expressions are legal. Explain the behavior of the legal expressions and why those that aren’t legal are in error.*

```cpp
(a) *iter++;
(b) (*iter)++;
(c) *iter.empty();
(d) iter->empty();
(e) ++*iter;
(f) iter++->empty();
```

**Answer**

- **(a)** - **Legal**: `iter` will be incremented and it will return a copy of it with the value before the increment, the copy will be dereferenced instead of the original and then `iter` will be incremented. 
- **(b)** - **Illegal**: String cannot be incremented.
- **(c)** - **Illegal**: `dot` operator has higher precedence than the dereference operator, that so, `iter` as an `vector<string>::iterator` type has not a member called `empty()`.
- **(d)** - **Legal**: `iter` will be dereferenced and then the result of this will try access the function member `empty()`.
- **(e)** - **Illegal**: it's illegal because it tries to increment and operator. 
- **(f)** - **Legal**: `iter` will be incremented and it will return the old itself as a copy, so, it will be dereferenced and then it will try to access the function member called `empty()`, last `iter` will be incremented.

### [Exercise 4.21:](Exercise_21/Ex21.cpp)

*Write a program to use a conditional operator to find the elements in a `vector<int>` that have odd value and double the value of each such element.*

### Exercise 4.22:

*Extend the program that assigned high pass, pass, and fail grades to also assign low pass for grades between 60 and 75 inclusive. Write two versions: One version that uses only conditional operators; the other should use one or more if statements. Which version do you think is easier to understand and why?*

- [Exercise 4.22A:](Exercise_22/Ex22A.cpp)
- [Exercise 4.22B:](Exercise_22/Ex22B.cpp)

**Answer**

- The version with if statement is easier to write and understand specially when we avoid nested statements.

### Exercise 4.23: 

*The following expression fails to compile due to operator precedence. Using Table 4.12 (p. 166), explain why it fails. How would you fix it?*

```cpp
string s = "word";
string pl = s + s[s.size() - 1] == 's' ? "" : "s" ;
```

**Answer**

- It fails because the operator `+` has more precedence than the operator `==`, that so, the comparison between a `string` and a `char` literal `'s'` is illegal. We can have a better intuition of what's happening when we use Parenthesis to show the precedence.
    ```cpp
    string pl = ( (s + s[s.size() - 1]) == 's') ? "" : "s" ;
    ``` 

- In order to fix this expression we need to use parenthesis in the right place, as we can see below.
    ```cpp
    string pl = s + ( (s[s.size() - 1] == 's') ? "" : "s");
    ``` 

### Exercise 4.24:

*Our program that distinguished between high pass, pass, and fail depended on the fact that the conditional operator is right associative. Describe how that operator would be evaluated if the operator were left associative.*

