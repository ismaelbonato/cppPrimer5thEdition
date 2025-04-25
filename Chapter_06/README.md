### [Back to Chapter 5](../Chapter_05/README.md)

# Chapter 6. Functions

### How to compile:

GCC 6.0+ or clang 3.3+

`g++ -Wall -Wextra -pedantic -std=c++11 target`

`clang++ -Wall -Wextra -pedantic -std=c++11 target`


## 6.1. Function Basics

### Exercise 6.1: 

*What is the difference between a parameter and an argument?*

**Answer**

- Arguments are the inputs of the function, they are used to initialize the function's parameters.

- Parameters are the objects locally created and initialized by the arguments given to the function. 

### Exercise 6.2: 

*Indicate which of the following functions are in error and why. Suggest how you might correct the problems.*

```cpp
(a) int f() {
        string s;
        // ...
        return s;
    }
(b) f2(int i) { /* ... */ }
(c) int calc(int v1, int v1) /* ... */ }
(d) double square(double x) return x * x;
```

**Answer**

- (a) The return of the function is an `int` but `s` is a `string`.
    ```cpp
    string f() {
        string s;
        // ...
        return s;
    }
    ```

- (b) The function `f2` has no return type `void`.
    ```cpp
    void f2(int i) { /* ... */ }
    ```
- (c) The first compound statement operator curly braces is used to begin the statement is missing.
    ```cpp
    int calc(int v1, int v1) { /* ... */ }
    ```

- (d) The both compound statement operator curly braces is missing.
    ```cpp
    double square(double x) { return x * x; }
    ```

### [Exercise 6.3:](Exercise_03/Ex03.cpp)

*Write and test your own version of `fact`.*

### [Exercise 6.4:](Exercise_04/Ex04.cpp)

*Write a function that interacts with the user, asking for a number and generating the factorial of that number. Call this function from main.*

### [Exercise 6.5:](Exercise_05/Ex05.cpp)

*Write a function to return the absolute value of its argument.*

## 6.1.1. Local Objects

### Exercise 6.6: 

*Explain the differences between a `parameter`, a `local variable`, and a `local static variable`. Give an example of a function in which each
might be useful.*

**Answer**

- A **Parameter** is a local variable that is initialized by an function's argument. Its lifetime begin when the function starts and it's destroyed in the end of the function.
- A **Local Variable** is a variable defined in the function's scope, if not initialized and if it's a built in type its value is undefined.  Its lifetime begin when the function starts and it's destroyed in the end of the function.
- A **Local Static Variable** is a variable defined in the function's scope but its life time is the same of the global scope.

### [Exercise 6.7:](Exercise_07/Ex07.cpp)

*Write a function that returns `0` when it is first called and then generates numbers in sequence each time it is called again.*

## 6.1.2. Function Declarations

### [Exercise 6.8:](Exercise_08/Chapter6.h)

*Write a header file named `Chapter6.h` that contains declarations for the functions you wrote for the exercises in § 6.1 (p. 205).*

## 6.1.3. Separate Compilation

### [Exercise 6.9:](Exercise_09/Ex09.cpp)

*Write your own versions of the `fact.cc` and `factMain.cc` files. These files should include your `Chapter6.h` from the exercises in the previous section. Use these files to understand how your compiler supports separate compilation.*

## 6.2.1. Passing Arguments by Value

### [Exercise 6.10:](Exercise_10/Ex10.cpp)

*Using pointers, write a function to swap the values of two `ints`. Test the function by calling it and printing the swapped values.*

## 6.2.2. Passing Arguments by Reference

### [Exercise 6.11:](Exercise_11/Ex11.cpp)

*Write and test your own version of reset that takes a reference.*

### [Exercise 6.12:](Exercise_12/Ex12.cpp)

*Rewrite the program from exercise 6.10 in § 6.2.1 (p. 210) to use references instead of pointers to swap the value of two `ints`. Which version do you think would be easier to use and why?*

### Exercise 6.13: 

*Assuming `T` is the name of a type, explain the difference between a function declared as `void f(T)` and `void f(T&)`.*

**Answer**

- In the first function `void f(T)`, a new object of type `T` will be created in the function's scope and initialized by the argument passed to this function. As a copy of another object, all changes to this new object will be restrict to the local scope and this object will be destroyed within the end of the scope.
- In the second function `void f(&t)`, a new reference will be created in the function's scope, this reference is bound to the object passed as argument. The life time of this reference begins with the beginning of the function and ends within the function ending, but the object that the reference is bound continue to exist.

### Exercise 6.14: 

*Give an example of when a parameter should be a reference type. Give an example of when a parameter should not be a reference.*

**Answer**

- Should use reference type to avoid copy:
    ```cpp
    int handleString(const std::vector<string> &value);
    
    int main () {
        std::vector<string> list = getWholeList();

        handleString(tmp);
    } 
    ```

- The use of reference is not needed:
    ```cpp
    int handleValue(int value);
    
    int main () {
        int tmp = getValue();

        handleValue(tmp);
    } 
    ```

### Exercise 6.15: 

*Explain the rationale for the type of each of `find_char`’s parameters In particular, why is `s` a reference to `const` but `occurs` is a plain reference? Why are these parameters references, but the char parameter `c` is not? What would happen if we made `s` a plain reference? What if we made `occurs` a reference to `const`?*

```cpp
// returns the index of the first occurrence of c in s
// the reference parameter occurs counts how often c occurs
string::size_type find_char(const string &s, 
                            char c,
                            string::size_type &occurs)
{
    auto ret = s.size(); // position of the first occurrence, if any
    occurs = 0; // set the occurrence count parameter
    for (decltype(ret) i = 0; i != s.size(); ++i) {
        if (s[i] == c) {
            if (ret == s.size())
                ret = i; // remember the first occurrence of c
            ++occurs; // increment the occurrence count
        }
    }
    return ret; // count is returned implicitly in occurs
}

```

**Answer**

- Why is `s` a reference to `const` but `occurs` is a plain reference?
    - Because we don't know the size of `s`, it can be bigger and to avoid create a copy it's better to use a reference, even when we don't want to modify the object that `s` is bound, in this case we use the qualifier `const`.
    - In order to return more than just one value we need to use pointers or references as parameters to change the original object that it was bound or pointed by. that's why in this case `occurs` is not `const`. 


- Why are these parameters references, but the char parameter `c` is not?
    - `s` is a `const` reference just to avoid memory copy.
    - `occurs` is an `integer` in order to enable the function to return more than one value.
    - `c` is a `char's` parameter in order to be able to use a literal char as argument.

- What would happen if we made `s` a plain reference?
    - The function would be free to change the object value that was bound to `s`.

-  What if we made `occurs` a reference to `const`?
    - It will raise an compiler error due to the fact the function is trying to change the value of a const object.


## 6.2.3. const Parameters and Arguments

### Exercise 6.16: 

*The following function, although legal, is less useful than it might be. Identify and correct the limitation on this function:*

```cpp
bool is_empty(string& s) { return s.empty(); }
```

**Answer**

- This function does not intend to change the string's value, so it's better to use the qualifier `const` to be able to use `const string` as argument in this function due to the high level `const`.

### [Exercise 6.17:](Exercise_17/Ex17.cpp) 

*Write a function to determine whether a `string` contains any capital letters. Write a function to change a `string` to all lowercase. Do the parameters you used in these functions have the same type? If so, why?
If not, why not?*

**Answer**

- they are not exactly the same type, the first one is `const string&` to be able to use `string`, `const string` or a literal `string` as argument. The second is a plain reference to `string`, so it can be used just with `string` as argument.

### Exercise 6.18:

*Write declarations for each of the following functions. When you write these declarations, use the name of the function to indicate what the function does.*

- (a) A function named compare that returns a `bool` and has two parameters that are references to a class named `matrix`.
- (b) A function named `change_val` that returns a `vector<int> iterator` and takes two parameters: One is an `int` and the other is an iterator for a `vector<int>`.

**Answer**

- First:
    ```cpp
    bool compare(const matrix &first, const matrix &second);
    ```
- Second
    ```cpp
    std::vector<int>::iterator change_val(int value, std::vector<int>::iterator it);
    ```
### Exercise 6.19: 

*Given the following declarations, determine which calls are legal and which are illegal. For those that are illegal, explain why.*

```cpp
double calc(double);
int count(const string &, char);
int sum(vector<int>::iterator, vector<int>::iterator, int);
vector<int> vec(10);

(a) calc(23.4, 55.1);
(b) count("abcda", 'a');
(c) calc(66);
(d) sum(vec.begin(), vec.end(), 3.8);
```

**Answer**

- **(a)** - Illegal: There are two arguments but this function has only one parameter.
- **(b)** - Legal.
- **(c)** - Legal: A conversion will be performed from `int` to `double`.
- **(d)** - Legal:   

### Exercise 6.20: 

*When should reference parameters be references to const? What happens if we make a parameter a plain reference when it could be a reference to const?*

**Answer**

- A parameter should be a reference to `const` when the function does not change the value of the object in which the reference is bound.
- Being a reference to `const` the function can receive more type of objects as argument to initialize its parameters, like a plain reference, `const` reference or a literal value.
- Being a plain reference a function can only get as argument to initialize its parameters a plain reference.

## 6.2.4. Array Parameters

### [Exercise 6.21:](Exercise_21/Ex21.cpp)

*Write a function that takes an `int` and a pointer to an `int` and returns the larger of the `int` value or the value to which the pointer points. What type should you use for the pointer?*

### [Exercise 6.22:](Exercise_22/Ex22.cpp)

*Write a function to swap two `int` pointers.*

**Answer**

- Function using Pointer to pointer:
    ```cpp
    void swapperByPointerToPointer(const int **x, const int **y)
    {
        const int *tmp = *x;

        *x = *y;
        *y = tmp;
    }
    ```

- Function using reference to a pointer:
    ```cpp
    void swapperByRef(const int* &x, const int* &y ) 
    {
        const int *tmp = x;

        x = y;
        y = tmp;

    }
    ```

### [Exercise 6.23:](Exercise_23/Ex23.cpp)

Write your own versions of each of the print functions presented in this section. Call each of these functions to print `i` and `j` defined as follows:

```cpp
int i = 0, j[2] = {0, 1};
```

### Exercise 6.24: 

*Explain the behavior of the following function. If there are problems in the code, explain what they are and how you might fix them.*

```cpp
void print(const int ia[10])
{
    for (size_t i = 0; i != 10; ++i)
    cout << ia[i] << endl;
}
```

**Answer**

- The purpose of this function is to iterate through the array and print each value.
- Arrays cannot be passed by value, it will be converted in a pointer to the first element, in this case `const int ia[10]` will be converted int `const int*` and data type will be lost in the process, the `Subscript` operator will be discarded. This is not an error but can be misleading.
- The right way to implement this kind of function behavior is using references.

```cpp
void print(const int (&ia)[10])
{
    for (size_t i = 0; i != (sizeof(ia)/sizeof(ia[0])); ++i)
    std::cout << ia[i] << std::endl;
}
```

## 6.2.5. main: Handling Command-Line Options

### [Exercise 6.25:](Exercise_25/Ex25.cpp) 

*Write a main function that takes two arguments. Concatenate the supplied arguments and print the resulting string.*

### [Exercise 6.26:](Exercise_26/Ex26.cpp) 

*Write a program that accepts the options presented in this section. Print the values of the arguments passed to main.*

## 6.2.6. Functions with Varying Parameters

### [Exercise 6.27:](Exercise_27/Ex27.cpp) 

*Write a function that takes an `initializer_list<int>` and produces the sum of the elements in the list.*

### Exercise 6.28: 

*In the second version of error_msg that has an ErrCode parameter, what is the type of elem in the for loop?*

```cpp
void error_msg(ErrCode e, initializer_list<string> il)
{
    cout << e.msg() << ": ";
    for (const auto &elem : il)
        cout << elem << " " ;
    cout << endl;
}
```

**Answer**

- `Elem` is a reference to a `const string`: `const string&`.

### Exercise 6.29: 

When you use an initializer_list in a range for would you ever use a reference as the loop control variable? If so, why? If not, why not?*

**Answer**

- It is not an obligation to use a reference as a loop control, but it is a good practice to use references to avoid a memory copying due the fact that we don't know either the size of the `initializer_list` or the size of each object. 

## 6.3.2. Functions That Return a Value

### [Exercise 6.30:](Exercise_30/Ex30.cpp) 

*Compile the version of `str_subrange` as presented on page 223 to see what your compiler does with the indicated errors.*

**Output**

- With error #1.
    ```cpp
    Ex30.cpp: In function ‘bool str_subrange(const string&, const string&)’:
    Ex30.cpp:16:13: error: return-statement with no value, in function returning ‘bool’ [-fpermissive]
    16 |             return; // error #1: no return value; compiler should detect this error
       |             ^~~~~~
    ```

- With error #1 fixed `return false`.

    ```cpp
    Ex30.cpp: In function ‘bool str_subrange(const string&, const string&)’:
    Ex30.cpp:21:1: warning: control reaches end of non-void function [-Wreturn-type]
    21 | }
       | ^
    ```

### Exercise 6.31: 

*When is it valid to return a reference? A reference to const?*

**Answer**

- It is valid to return a reference when the object in witch the reference is bound is not a local temporary object, it means there is a pre-existing object before the function call

### [Exercise 6.32:](Exercise_32/Ex32.cpp)

*Indicate whether the following function is legal. If so, explain what it does; if not, correct any errors and then explain it.*

```cpp
int &get(int *arry, int index) { return arry[index]; }

int main() 
{
    int ia[10];
    for (int i = 0; i != 10; ++i) {
        get(ia, i) = i;
    }
}
```
**Answer**

- This function is legal, it returns a reference to an int `int &` and reference to an `int` is a L and R value, then its return can be assigned with another `int` object.

### [Exercise 6.33:](Exercise_33/Ex33.cpp) 

*Write a recursive function to print the contents of a vector.*

### Exercise 6.34: 

*What would happen if the stopping condition in factorial were*
```cpp
if (val != 0)
```

**Answer**

- The result will be same although it will call the function one more time so that it will take more time to perform the same result as before.
- Using `if (val != 0)` it will create a problem whhttps://revistaoeste.com/politica/exclusivo-veja-a-pericia-do-padre-julio-lancellotti/argument in this function, it will create an infinite loop, until an exception will be raised.


### Exercise 6.35: 

*In the call to fact, why did we pass `val - 1` rather than `val--`?*

**Answer**

- It is forbidden to change an object if there is another reference to this object in the same expression.
- There is no guarantee witch side of the expression will be evaluated first, so if we change one of the `val` the behavior is undefined.

## 6.3.3. Returning a Pointer to an Array

### [Exercise 6.36:](Exercise_36/Ex36.cpp) 

*Write the declaration for a function that returns a reference to an array of ten strings, without using either a trailing return, decltype, or a type alias.*

### [Exercise 6.37:](Exercise_37/Ex37.cpp) 

*Write three additional declarations for the function in the previous exercise. One should use a type alias, one should use a trailing return, and the third should use decltype. Which form do you prefer and why?*

### [Exercise 6.38:](Exercise_38/Ex38.cpp) 

*Revise the `arrPtr` function on to return a reference to the array.*

## 6.4. Overloaded Functions

### Exercise 6.39: 

*Explain the effect of the second declaration in each one of the following sets of declarations. Indicate which, if any, are illegal.*

```cpp
(a) int calc(int, int);
    int calc(const int, const int);

(b) int get();
    double get();

(c) int *reset(int *);
    double *reset(double *);
```

**Answer**

- **(a)** - It is legal: the second function has `const int` as arguments. 
- **(b)** - It is illegal: It is an error when both function only differ by the return type.
- **(c)** - It is legal: Both functions have different types of arguments.

## 6.5.1. Default Arguments

### Exercise 6.40:

*Which, if either, of the following declarations are errors? Why?*
```cpp
(a) int ff(int a, int b = 0, int c = 0);
(b) char *init(int ht = 24, int wd, char bckgrnd);
```

**Answer**

- Letter **b** is an error, all parameter following the first parameter with default argument must have default arguments.

### Exercise 6.41:

*Which, if any, of the following calls are illegal? Why? Which, if any, are legal but unlikely to match the programmer’s intent? Why?*
```cpp
char *init(int ht, int wd = 80, char bckgrnd = ' ');

(a) init();
(b) init(24,10);
(c) init(14, '*');
```
**Answer**

- **(a)** - It is illegal because `ht` must be initialized in the funcion call.
- **(b)** - It is legal and match the developer needs.
- **(c)** - It is legal but it will not match the programer intention, it will be equivalent to `ht` = 14, `wd` = '\*\' and `bckgrnd` = ' ' with '\*\' being converted the number 42.


### [Exercise 6.42:](Exercise_42/Ex42.cpp) 

*Give the second parameter of make_plural (§ 6.3.2, p.224) a default argument of 's'. Test your program by printing singular and plural versions of the words success and failure.*

## 6.5.2. Inline and constexpr Functions

### Exercise 6.43:

*Which one of the following declarations and definitions would you put in a header? In a source file? Explain why.*

```cpp
(a) inline bool eq(const BigInt&, const BigInt&) {...}
(b) void putValues(int *arr, int size);
```

**Answer**

- **(a)** - `Inline` functions can be defined multiple times in different source files, but, its declaration and definition must must match exactly. To avoid compilation errors it's advisable to define and declare `inline` functions in header files.

- **(b)** - Normal functions are advisable to define in the source files and declare on header files.

### [Exercise 6.44:](Exercise_44/Ex44.cpp) 

*Rewrite the isShorter function from § 6.2.2 (p. 211) to be inline.*

### Exercise 6.45: 

*Review the programs you’ve written for the earlier exercises and decide whether they should be defined as inline. If so, do so. If not, explain why they should not be inline.*

**Answer**

- The function `isShorter` can be used as an `inline`, but there is no advantage in this case. Usually `inline` functions are used when they are recurrent and the execution of its content take not much more time then the calling process, It is called an function calling overhead.

### [Exercise 6.46:](Exercise_46/Ex46.cpp) 

*Would it be possible to define `isShorter` as a `constexpr`? If so, do so. If not, explain why not.*

**Answer**
- It is not possible to define `isShorter` as a `constexpr`, `std::string` is not a literal type, only a `char` is an `literal` type and it does not implement de method `size()`.

**Output**

```cpp
Ex46.cpp: In function ‘constexpr bool isShorter(const string&, const string&)’:
Ex46.cpp:7:19: error: call to non-‘constexpr’ function ‘std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size() const [with _CharT = char; _Traits = std::char_traits<char>; _Alloc = std::allocator<char>; std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type = long unsigned int]’
    7 |     return s1.size() < s2.size();
      |            ~~~~~~~^~
In file included from /usr/include/c++/11/string:55,
                 from /usr/include/c++/11/bits/locale_classes.h:40,
                 from /usr/include/c++/11/bits/ios_base.h:41,
                 from /usr/include/c++/11/ios:42,
                 from /usr/include/c++/11/ostream:38,
                 from /usr/include/c++/11/iostream:39,
                 from Ex46.cpp:1:
/usr/include/c++/11/bits/basic_string.h:920:7: note: ‘std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size() const [with _CharT = char; _Traits = std::char_traits<char>; _Alloc = std::allocator<char>; std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::size_type = long unsigned int]’ declared here
  920 |       size() const _GLIBCXX_NOEXCEPT
      |       ^~~~
```

## 6.5.3. Aids for Debugging

### [Exercise 6.47:](Exercise_47/Ex47.cpp)

*Revise the program you wrote in the exercises in § 6.3.2 (p. 228) that used recursion to print the contents of a vector to conditionally print information about its execution. For example, you might print the size of the `vector` on each call. Compile and run the program with debugging turned on and again with it turned off.*

### Exercise 6.48: 

*Explain what this loop does and whether it is a good use of `assert`:*

```cpp
string s;
while (cin >> s && s != sought) { } // empty body
assert(cin);
```

**Answer**
- This loop does look for a word `sought` from `std::cin`, once the word was found, it will terminate the `while` loop and the `std::cin` in the `assert` will return the integer literal 0, therefore the program will be terminated. 
- It is not a good use of `assert` because it was create only to debug the program and not to be used as internal logic.
- The best way of doing this logic is:
    ```cpp
    string s;
    while (cin >> s && s != sought) { } // empty body
    std::exit(EXIT_SUCCESS);
    ```

## 6.6. Function Matching

### Exercise 6.49: 

*What is a candidate function? What is a viable function?*

**Answer**

- A function called candidate is a function that has the same name and its declaration are visible in the scope of the call.

### Exercise 6.50: 

*Given the declarations for `f` from page 242, list the viable functions, if any for each of the following calls. Indicate which function is the best match, or if the call is illegal whether there is no match or why the call is ambiguous.*

```cpp
(a) f(2.56, 42)
(b) f(42)
(c) f(42, 0)
(d) f(2.56, 3.14)
```
**Answer**

- **(a)** - It is illegal, this function call is ambiguous, there are two possible matches `void f(double, double = 3.14)` and `void f(int, int)`.
- **(b)** - The best match for this function is `void f(int)`.
- **(c)** - The best match for this function is `void f(int, int)`.
- **(d)** - The best match for this function is `void f(double, double = 3.14)`.


## [Exercise 6.51:](Exercise_51/Ex51.cpp) 

*Write all four versions of f. Each function should print a distinguishing message. Check your answers for the previous exercise. If your answers were incorrect, study this section until you understand why your answers were wrong.*


## 6.6.1. Argument Type Conversions

### Exercise 6.52: 

*Given the following declarations,*
```cpp
void manip(int, int);
double dobj;
```
w*hat is the rank (§ 6.6.1, p. 245) of each conversion in the following calls?*
```cpp
(a) manip('a', 'z');
(b) manip(55.4, dobj);
```

**Answer**

- **(a)** - 3: Match through a promotion.
- **(b)** - 4: Match through an arithmetic.

### Exercise 6.53: 

*Explain the effect of the second declaration in each one of the following sets of declarations. Indicate which, if any, are illegal.*

```cpp
(a) int calc(int&, int&);
int calc(const int&, const int&);

(b) int calc(char*, char*);
int calc(const char*, const char*);

(c) int calc(char*, char*);
int calc(char* const, char* const);
```

**Answer**

- **(a)** - It is legal, a reference to `char` is a perfect match with the first declaration, it does not need a const conversion. A reference to a `const char` cannot be converted to char, hence the second declarion will be used by the compiler.
- **(b)** - It is legal, a pointer to `char` is a perfect match with the first declaration, it does not need a const conversion. A pointer to a `const char` cannot be converted to char, hence the second declarion will be used by the compiler.
- **(c)** - It is illegal, a pointer to a `char` and const pointer to a `char` are the same thing (high level const). It is not a function overload, it is a redefinition.
    ```cpp
    Ex51.cpp:21:5: error: redefinition of ‘int calc(char*, char*)’
    21 | int calc(char* const, char* const)
          |     ^~~~
    Ex51.cpp:17:5: note: ‘int calc(char*, char*)’ previously defined here
    17 | int calc(char*, char*)
          |     ^~~~
    ```

## 6.7. Pointers to Functions

### [Exercise 6.54:](Exercise_54/Ex54.cpp) 

*Write a declaration for a function that takes two int parameters and returns an int, and declare a vector whose elements have this function pointer type.*

**Answer**

```cpp
typedef int func(int, int);
std::vector<decltype(func) *> pVec;
```

### [Exercise 6.55:](Exercise_55/Ex55.cpp)

*Write four functions that add, subtract, multiply, and divide two int values. Store pointers to these functions in your vector from the previous exercise.*


### [Exercise 6.56:](Exercise_56/Ex56.cpp)

*Call each element in the vector and print their result.*

----------------------------
### [Back to Chapter 5](../Chapter_05/README.md) - [Next to Chapter 7](../Chapter_07/README.md)