### [Back to Chapter 15](../Chapter_15/README.md)

# Chapter 16. Templates and Generic Programming

### How to compile:

GCC 6.0+ or clang 3.3+

`g++ -Wall -Wextra -pedantic -std=c++11 target`

`clang++ -Wall -Wextra -pedantic -std=c++11 target`

## 16.1.1. Function Templates

### Exercise 16.1
*Define instantiation.*

**Answer**
- Instantiation is the process by which the compiler generates a specific version of the template. This occurs when the template is used in the code at compile time. At this point, the compile uses deduction to determine the types used in that version.

### [Exercise 16.2](Exercise_02/Ex02.cpp)

*Write and test your own versions of the compare functions.*

### [Exercise 16.3](Exercise_03/Ex03.cpp)

*Call your compare function on two `Sales_data` objects to see how your compiler handles errors during instantiation.*

**Output**
- GCC
```shell
Ex03.cpp: In instantiation of ‘int compare(const T&, const T&) [with T = SalesData]’:
Ex03.cpp:17:12:   required from here
Ex03.cpp:6:11: error: no match for ‘operator<’ (operand types are ‘const SalesData’ and ‘const SalesData’)
    6 |     if (a < b) return -1;
      |         ~~^~~
Ex03.cpp:7:11: error: no match for ‘operator>’ (operand types are ‘const SalesData’ and ‘const SalesData’)
    7 |     if (a > b) return 1;
      |         ~~^~~
```
- CLANG
```shell
Ex03.cpp:6:11: error: invalid operands to binary expression ('const SalesData' and 'const SalesData')
    6 |     if (a < b) return -1;
      |         ~ ^ ~
Ex03.cpp:17:5: note: in instantiation of function template specialization 'compare<SalesData>' requested here
   17 |     compare(sales1, sales2);    
      |     ^
Ex03.cpp:7:11: error: invalid operands to binary expression ('const SalesData' and 'const SalesData')
    7 |     if (a > b) return 1;
      |         ~ ^ ~
2 errors generated.
```

### [Exercise 16.4](Exercise_04/Ex04.cpp)

*Write a template that acts like the library `find` algorithm. The function will need two template type parameters, one to represent the function’s iterator parameters and the other for the type of the value. Use your function to find a given value in a `vector<int>` and in a `list<string>`.*

### [Exercise 16.5](Exercise_05/Ex05.cpp)

*Write a template version of the print function from § 6.2.4 (p. 217) that takes a reference to an `array` and can handle `arrays` of any size and any element type.*

### [Exercise 16.6](Exercise_06/Ex06.cpp)

*How do you think the library `begin` and `end` functions that take an array argument work? Define your own versions of these functions.*

**Answer**
- In order to use as generic function it is implemented as a template. 

```cpp
template<typename T, size_t N>
T *begin(T (&arr)[N])
{
    return arr;
}

template<typename T, size_t N>
T *end(T (&arr)[N])
{
    return arr + N;
}
```

### [Exercise 16.7](Exercise_07/Ex07.cpp)

*Write a `constexpr` template that returns the size of a given array.*

### Exercise 16.8

*In the “Key Concept” box on page 108, we noted that as a matter of habit C++ programmers prefer using `!=` to using `<`. Explain the rationale for this habit.*

**Answer**
- C++ programmers prefer using `!=` instead of `<` when writing loops with iterators because not all iterator types support the `<` (less than) operator. However, all standard iterators support the `==` (equality) and `!=` (inequality) operators. Using `!=` ensures that the code works with all standard containers, including those whose iterators do not have a natural ordering (like `std::list` or `std::unordered_map`).

## 16.1.2. Class Templates

### Exercise 16.9

*What is a function template? What is a class template?*

**Answer**
- Templates are the foundation behind generic programming in c++. It allows to generate code that works with any type, enabling the reuse of code and type safety in compilation time.
    - Generic Programming (Templates) is a way to reuse code in compilation time.
    - Object-oriented programming (Subtype polymorphism) is a way to reuse code Runtime.

- Function template is modern way to create generic functions, it is a recipe to generate functions the can work with different types deduced in compilation time.
- Class template is modern way to create generic objects, it is a recipe to generate classes the can work with different types deduced in compilation time.

### Exercise 16.10

*What happens when a class template is instantiated?*

**Answer**
- The compiler deduces the type and the code for that class is generated.

### Exercise 16.11

*The following definition of `List` is incorrect. How would you fix it?*

```cpp
template <typename elemType> class ListItem;
template <typename elemType> class List {
public:
    List<elemType>();
    List<elemType>(const List<elemType> &);
    List<elemType>& operator=(const List<elemType> &);
    ~List();
    void insert(ListItem *ptr, elemType value);
private:
    ListItem<int> *front, *end;
};
```

**Answer**
- `ListItem` is a template, it requires the type to instantiate `ListItem` properly: 

```cpp
template <typename elemType> class ListItem;
template <typename elemType> class List {
public:
    List<elemType>();
    List<elemType>(const List<elemType> &);
    List<elemType>& operator=(const List<elemType> &);
    ~List();
    void insert(ListItem<elemType> *ptr, elemType value);
private:
    ListItem<elemType> *front, *end;
};
```

### [Exercise 16.12](Exercise_12/Ex12.cpp)

*Write your own version of the `Blob` and `BlobPtr` templates, including the various `const` members that were not shown in the text.*

### Exercise 16.13

*Explain which kind of friendship you chose for the `equality` and `relational` operators for `BlobPtr`.*

**Answer**
- Because these operators are inherently linked to the type T, specific instantiation was selected to ensure type safety and encapsulation.

### [Exercise 16.14](Exercise_14/Ex14.cpp)

*Write a `Screen` class template that uses `nontype` parameters to define the height and width of the `Screen`.*

### [Exercise 16.15](Exercise_15/Ex15.cpp)

*Implement `input` and `output` operators for your `Screen` template. Which, if any, `friends` are necessary in class `Screen` to make the `input` and `output` operators work? Explain why each `friend` declaration, if any, was needed.*

**Answer**
- Friendship is not strictly necessary if the operators leverage public members to achieve the objective. However, it simplifies processes, ensures efficiency, and optimizes performance by utilizing objects directly and creating a customized version of the operator.

### [Exercise 16.16](Exercise_16/Ex16.cpp)

*Rewrite the `StrVec` class (§ 13.5, p. 526) as a template named `Vec`.*

## 16.1.3. Template Parameters

### Exercise 16.17

*What, if any, are the differences between a type parameter that is declared as a `typename` and one that is declared as a `class`? When must `typename` be used?*

**Answer**
- There is no difference between `class` or `typename` int the declaration of a `template`. However, `typename` must be used inside the template to inform the compiler that such name is a type that depends on the type used int the instantiation.

### Exercise 16.18

*Explain each of the following function `template` declarations and identify whether any are illegal. Correct each error that you find.*

```cpp
(a) `template <typename T, U, typename V> void f1(T, U, V);`  
(b) `template <typename T> T f2(int &T);`  
(c) `inline template <typename T> T foo(T, unsigned int*);`  
(d) `template <typename T> f4(T, T);`  
(e) typedef char Ctype; template <typename Ctype> Ctype f5(Ctype a);
```

**Answer**
- (a) Illegal: `<typename T, U, typename V>` `typename` keyword for `U` is missing.
- (b) Legal.
- (c) Illegal: the keyword `inline` refer to the function not the `template`.
- (d) Legal.
- (e) Illegal: `Ctype` is a type name, it will be hidden in the scope of the template. However if the object ot it, is to be passed as a `nontype` parameter, it needs represents a value not a `typename`.

```cpp
(a) `template <typename T, typename U, typename V> void f1(T, U, V);`  
(b) `template <typename T> T f2(int &T);`  
(c) `template <typename T> inline T foo(T, unsigned int*);`  
(d) `template <typename T> f4(T, T);`  
(e) typedef char Ctype; template <Ctype > Ctype f5(Ctype a);
```

### [Exercise 16.19](Exercise_19/Ex19.cpp)

*Write a function that takes a reference to a container and prints the elements in that container. Use the container’s `size_type` and `size` members to control the loop that prints the elements.*

### [Exercise 16.20](Exercise_20/Ex20.cpp)

*Rewrite the function from the previous exercise to use iterators returned from `begin` and `end` to control the loop.*

## 16.1.4. Member Templates

### [Exercise 16.21](Exercise_21/Ex21.cpp)

*Write your own version of `DebugDelete`.*

### [Exercise 16.22](Exercise_22/Ex22.cpp)

*Revise your `TextQuery` programs from § 12.3 (p. 484) so that the `shared_ptr` members use a `DebugDelete` as their `deleter` (§ 12.1.4, p. 468).*

### Exercise 16.23

*Predict when the call operator will be executed in your main query program. If your expectations and what happens differ, be sure you understand why.*

### [Exercise 16.24](Exercise_24/Ex24.cpp)

*Add a constructor that takes two iterators to your `Blob` template.*

## 16.1.5. Controlling Instantiations

### Exercise 16.25

*Explain the meaning of these declarations:*

```cpp
extern template class vector<string>;
template class vector<Sales_data>;
```

**Answer**
- To avoid multiple instantiation of the same class or function the new standard implements the the keyword `extern` for templates.
- `extern template class vector<string>;`: Inform the compiler to not instantiate that template version here, the definition of such template is elsewhere in the code.
- `template class vector<Sales_data>;`: Inform the compiler to instantiate that template version only here, all uses of such class version must use this instantiation.

### [Exercise 16.26](Exercise_26/Ex26.cpp)

*Assuming `NoDefault` is a class that does not have a default constructor, can we explicitly instantiate `vector<NoDefault>`? If not, why not?*

```cpp
template class vector<NoDefault>;
```

**Answer**
- It is not possible to instantiate such a vector in the compilation unit explicitly as it forces the compiler to instantiate the template as a whole.
- As you can see bellow the only way to create such object is to remove the explicit instantiation.

```cpp
class NoDefaultConstructor {
public:
    // Constructor that requires an argument
    explicit NoDefaultConstructor(const int value) : data(value) {}

    // Method to display the value
    void display() const {
        std::cout << "Value: " << data << std::endl;
    }

private:
    int data;
};

//template class std::vector<NoDefaultConstructor>;

int main() {    
    NoDefaultConstructor noDefault(5);
    std::vector<NoDefaultConstructor> x(1, noDefault);

    return 0;
}
```
- Template instantiation only generates code for the functions that are actually used in your program unless you explicitly request instantiation for all members.
- That is why it is possible to create a `vector` for an `non Default constructor` object.

### Exercise 16.27

*For each labeled statement explain what, if any, instantiations happen. If a template is instantiated, explain why; if not, explain why not.*

```cpp
template <typename T> class Stack { };
void f1(Stack<char>);                   // (a)
class Exercise {
    Stack<double> &rsd;                 // (b)
    Stack<int>    si;                   // (c)
};
int main() {
    Stack<char> *sc;                    // (d)
    f1(*sc);                            // (e)
    int iObj = sizeof(Stack<string>);   // (f)
}
```

**Answer**
- (a) As it is just a declaration it does not instantiate unless there is a use.
- (b) A reference is declared, and references do not require instantiation. However, as it is a reference, it will be instantiated if an Exercise object is created.
- (c) it will be instantiated if an Exercise object is created.
- (d) As it is a pointer it does not require instantiation unless it is used.
- (e) It instantiates the those `Stack<char>` members that are used.
- (f) It instantiates the those `Stack<string>` members that are used.

## 16.1.6. Efficiency and Flexibility

### [Exercise 16.28](Exercise_28/Ex28.cpp)

*Write your own versions of `shared_ptr` and `unique_ptr`.*

### [Exercise 16.29](Exercise_29/Ex29.cpp)

*Revise your `Blob` class to use your version of `shared_ptr` rather than the library version.*

### Exercise 16.30

*Rerun some of your programs to verify your `shared_ptr` and revised `Blob` classes. (Note: Implementing the `weak_ptr` type is beyond the scope of this Primer, so you will not be able to use the `BlobPtr` class with your revised `Blob`.)*

### [Exercise 16.31](Exercise_31/Ex31.cpp)

*Explain how the compiler might `inline` the call to the `deleter` if we used `DebugDelete` with `unique_ptr`.*

**Answer**
- The compiler can `inline` the call to the `deleter` (such as DebugDelete) with `unique_ptr` because the type of the `deleter` is known at compile time. If the `deleter` is a functor or a function defined in a header (including `template` functions), the compiler can see its definition and may replace the call with the actual code (inline it) for optimization. This is possible because `unique_ptr` stores the `deleter` as part of its type, allowing the compiler to optimize away the function call overhead. In contrast, `shared_ptr` uses type erasure for its `deleter`, so the call is resolved at runtime and cannot be inlined as easily.

## 16.2.1. Conversions and Template Type Parameters

### Exercise 16.32: 

*What happens during template argument deduction?*

**Answer**
- It is the process by witch the compile tries to deduce from the arguments witch types of parameters the template must be instantiated.
- The number of type conventions are very limited and strict compared to a normal functions, rather than converting the arguments the compiles generates code for the type directly.
- Conversions made are: `const conversions`, array to pointer and function to pointers.
- As the process is made in compilation time rather than runtime, `subtype polymorphism` will not work as expected.

### Exercise 16.33: 

*Name two type conversions allowed on function arguments involved in template argument deduction.*

**Answer**
- `Const` conversion.
- Function to pointer conversion.
- Array to pointer conversion.

### Exercise 16.34: 

*Given only the following code, explain whether each of these calls is legal. If so, what is the type of T? If not, why not?*

```cpp
template <class T> int compare(const T&, const T&);
(a) compare("hi", "world");
(b) compare("bye", "dad");
```

**Answer**
- (a) Illegal: Both are `literal` `C-style` `strings`, but their size differs (`const char [3]` and `const char [6]`). Because the types are different, they do not match the template type.
- (b) Legal: They are literal C-style strings (`const char [3]`). Both types match exactly to one another, as well as to the type of the template.

### Exercise 16.35: 

*Which, if any, of the following calls are errors? If the call is legal, what is the type of T? If the call is not legal, what is the problem?*

```cpp
template <typename T> T calc(T, int);
template <typename T> T fcn(T, T);
double d;    
float f;    
char c;

(a) calc(c, 'c');
(b) calc(d, f);
(c) fcn(c, 'c');
(d) fcn(d, f);
```
**Answer**
- (a) Legal: T is a `char`.
- (b) Legal: T is a `double`.
- (c) Legal: T is a `char`.
- (d) Illegal: the types does not match.

### Exercise 16.36: 

*What happens in the following calls:*

```cpp
template <typename T> f1(T, T);
template <typename T1, typename T2) f2(T1, T2);

int i = 0, j = 42, *p1 = &i, *p2 = &j;
const int *cp1 = &i, *cp2 = &j;

(a) f1(p1, p2);
(b) f2(p1, p2);
(c) f1(cp1, cp2);
(d) f2(cp1, cp2);
(e) f1(p1, cp1);
(f) f2(p1, cp1);
```

**Answer**

```cpp
(a) f1(p1, p2);     // Legal: T = int *;
(b) f2(p1, p2);     // Legal: T1 = int *, T2 = int *;
(c) f1(cp1, cp2);   // Legal: T = const int *;
(d) f2(cp1, cp2);   // Legal: T1 = const int *, T2 = const int *;
(e) f1(p1, cp1);    // Illegal: f1(int *, const int *) types does not match;
(f) f2(p1, cp1);    // Legal: T1 = int *, T2 = const int *;
```


## 16.2.2. Function-Template Explicit Arguments

### Exercise 16.37: 

*The library `max` function has two function parameters and returns the larger of its arguments. This function has one template type parameter. Could you call `max` passing it an `int` and a `double`? If so, how? If not, why not?*

**Answer**
- It is possible through the use of explicit template arguments, but a type conversion must be made. The most effective method for achieving this is to promote `int` to `double`.

```cpp
int x = 42;
double d = 42.0

auto ret = std::max<double>(x, d);
```

### Exercise 16.38: 

*When we call `make_shared` (§ 12.1.1, p. 451), we have to provide an explicit template argument. Explain why that argument is needed and how it is used.*

**Answer**

```cpp
template<typename _Tp, typename... _Args>
inline shared_ptr<_NonArray<_Tp>> make_shared(_Args&&... __args)
{
    using _Alloc = allocator<void>;
    _Alloc __a;
    return shared_ptr<_Tp>(_Sp_alloc_shared_tag<_Alloc>{__a},
                std::forward<_Args>(__args)...);
}
```
- Because the first template parameter is used as the return's type, not as argument type in the function.
- As we can see in the `make_shared` code above, only `args` wil be deduced, so the first template argument type must be explicitly specified.

### [Exercise 16.39:](Exercise_39/Ex39.cpp)

*Use an `explicit template` argument to make it sensible to pass two `string literals` to the original version of `compare` from § 16.1.1 (p.652).*


## 16.2.3. Trailing Return Types and Type Transformation

### Exercise 16.40:

*Is the following function legal? If not, why not? If it is legal, what, if any, are the restrictions on the argument type(s) that can be passed, and what is the return type?*

```cpp
template <typename It>
auto fcn3(It beg, It end) -> decltype(*beg + 0)
{
    // process the range
    return *beg;  // return a copy of an element from the range
}
```

**Answer**
- `Decltype` will return the type of the expression `*beg + 0`, but only if the arithmetic operation can be performed.
- The dereferenced beg must be an arithmetic type capable of performing that kind of arithmetic operation, as well as type conversion or promotion. Otherwise, an error will result if the it cannot perform that expression; for example, `std::string`.

### [Exercise 16.41:](Exercise_41/Ex41.cpp)

*Write a version of `sum` with a return type that is guaranteed to be large enough to hold the result of the addition.*

## 16.2.5. Template Argument Deduction and References

### Exercise 16.42:

*Determine the type of `T` and of `val` in each of the following calls:*

```cpp
template <typename T> void g(T&& val);
int i = 0; 
const int ci = i;

(a) g(i);
(b) g(ci);
(c) g(i * ci);
```

**Answer**
- (a) int&
- (b) const int&
- (c) int&&

### Exercise 16.43: 

*Using the function defined in the previous exercise, what would the template parameter of `g` be if we called `g(i = ci)`?*

**Answer**
- `int&` because the result of `(i = ci)` is a reference to `i`.

### Exercise 16.44: 

*Using the same three calls as in the first exercise, determine the types for `T` if `g`’s function parameter is declared as `T` (`not T&&`). What if `g`’s function parameter is `const T&`?*

**Answer**

- `template <typename T> void g(T val);`:
    - (a) int
    - (b) int
    - (c) int
- `template <typename T> void g(const T& val);`
    - (a) int
    - (b) int
    - (c) int.

### Exercise 16.45: 

*Given the following template, explain what happens if we call `g` on a literal value such as `42`. What if we call `g` on a variable of type `int`?*

```cpp
template <typename T> 
void g(T&& val)
{
    vector<T> v; 
}

//(a) g(42). T
//(b) g(int).
```

**Answer**
- (a) T = int, val becomes int&&, vector<int> v.
- (b) T = int&, val becomes int&, vector<int&> v.

## 16.2.6. Understanding std::move

### Exercise 16.46:

*Explain this loop from `StrVec::reallocate` in § 13.5 (p.530):*

```cpp
for (size_t i = 0; i != size(); ++i)
    alloc.construct(dest++, std::move(*elem++));
```

**Answer**
- The loop calls the function construct, that function is responsible for calling the `dest` move constructor on each iteration.
- The `dest` move constructor receives an `rvalue` version of the element.
- The data held by `*elem` is moved to `*dest` on each iteration, leaving `*elem` in a valid but unspecified (moved-from) state.

## 16.2.7. Forwarding

### [Exercise 16.47:](Exercise_47/Ex47.cpp)

*Write your own version of the flip function and test it by calling functions that have `lvalue` and `rvalue` reference parameters.*

## 16.3. Overloading and Templates

### [Exercise 16.48:](Exercise_48/Ex48.cpp)

*Write your own versions of the debug_rep functions.*

### Exercise 16.49: 

*Explain what happens in each of the following calls:
```cpp
template <typename T> void f(T);
template <typename T> void f(const T*);
template <typename T> void g(T);
template <typename T> void g(T*);

int i = 42, *p = &i;
const int ci = 0, *p2 = &ci;

g(42);   g(p);   g(ci);   g(p2);
f(42);   f(p);   f(ci);   f(p2);
```

**Answer**
```cpp
g(42);  // will call void g(T).
g(p);   // Will call void g(T*) as it is more specialized that g(T).
g(ci);  // will call void g(T).
g(p2);  // will call void g(T*) as it is more specialized that g(T).
f(42);  // will call void f(T);
f(p);   // will call void f(T);
f(ci);  // will call void f(T);
f(p2);  // will call void f(const T*) as it is more specialized that g(T)
```

### [Exercise 16.50:](Exercise_50/Ex50.cpp)

*Define the functions from the previous exercise so that they print an identifying message. Run the code from that exercise. If the calls behave differently from what you expected, make sure you understand why.*

## 16.4. Variadic Templates

### Exercise 16.51:

*Determine what `sizeof...(Args)` and `sizeof...(rest)` return for each call to foo in this section.*

```cpp
template <typename T, typename... Args>
void foo(const T &t, const Args& ... rest);

int i = 0; 
double d = 3.14; 
string s = "how now brown cow";

foo(i, s, 42, d);
foo(s, 42, "hi");
foo(d, s);
foo("hi");
```

**Answer**
```cpp
foo(i, s, 42, d);   // sizeof...(Args) = 3, sizeof...(rest) = 3
foo(s, 42, "hi");   // sizeof...(Args) = 2, sizeof...(rest) = 2
foo(d, s);          // sizeof...(Args) = 1, sizeof...(rest) = 1
foo("hi");          // sizeof...(Args) = 0, sizeof...(rest) = 0
```

### [Exercise 16.52:](Exercise_52/Ex52.cpp) 

*Write a program to check your answer to the previous question.*

**Output**
```shell
ARGS: 3 rest: 3
ARGS: 2 rest: 2
ARGS: 1 rest: 1
ARGS: 0 rest: 0
```
## 16.4.1. Writing a Variadic Function Template

### [Exercise 16.53:](Exercise_53/Ex53.cpp) 

*Write your own version of the print functions and test them by printing one, two, and five arguments, each of which should have different types.*

### Exercise 16.54: 

*What happens if we call print on a type that doesn’t have an `<< operator`?*

**Answer**
- An error occurs:

**Output**
```shell
clang++ -Wall -Wextra -pedantic -std=c++11 Ex53.cpp 
Ex53.cpp:15:15: error: invalid operands to binary expression ('std::ostream' (aka 'basic_ostream<char>') and 'const NonOperatorObject')
   15 |     return os << arg;
      |            ~~ ^  ~~~
```

#### [Exercise 16.55:](Exercise_54/Ex54.cpp)

*Explain how the `variadic` version of print would execute if we declared the `nonvariadic` version of print after the definition of the `variadic` version.*

**Answer**
- The `non-variadic` version is selected when there is just one last argument from the pack. If the `non-variadic` version is defined after the `variadic` version, a compilation error will occur because there is no print function with only one argument.

**Output**
```shell
clang++ -Wall -Wextra -pedantic -std=c++11 Ex54.cpp 
Ex54.cpp:8:13: error: no matching function for call to 'print'
    8 |     return  print(os, rest...);
      |             ^~~~~
Ex54.cpp:8:13: note: in instantiation of function template specialization 'print<int>' requested here
Ex54.cpp:8:13: note: in instantiation of function template specialization 'print<int, int>' requested here
Ex54.cpp:8:13: note: in instantiation of function template specialization 'print<int, int, int>' requested here
Ex54.cpp:8:13: note: in instantiation of function template specialization 'print<int, int, int, int>' requested here
Ex54.cpp:8:13: note: in instantiation of function template specialization 'print<int, int, int, int, int>' requested here
Ex54.cpp:8:13: note: in instantiation of function template specialization 'print<int, int, int, int, int, int>' requested here
Ex54.cpp:8:13: note: in instantiation of function template specialization 'print<int, int, int, int, int, int, int>' requested here
Ex54.cpp:8:13: note: in instantiation of function template specialization 'print<int, int, int, int, int, int, int, int>' requested here
Ex54.cpp:19:5: note: in instantiation of function template specialization 'print<int, int, int, int, int, int, int, int, int>' requested here
   19 |     print(std::cout, 1,2,3,4,5,6,7,8, 9) << std::endl;
      |     ^
Ex54.cpp:5:15: note: candidate function template not viable: requires at least 2 arguments, but 1 was provided
    5 | std::ostream &print(std::ostream &os, const T arg, const Args&... rest)
      |               ^     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Ex54.cpp:8:13: error: no matching function for call to 'print'
    8 |     return  print(os, rest...);
      |             ^~~~~
Ex54.cpp:8:13: note: in instantiation of function template specialization 'print<const char *>' requested here
Ex54.cpp:8:13: note: in instantiation of function template specialization 'print<const char *, char[2]>' requested here
Ex54.cpp:8:13: note: in instantiation of function template specialization 'print<const char *, char[6], char[2]>' requested here
Ex54.cpp:8:13: note: in instantiation of function template specialization 'print<char, char[6], char[6], char[2]>' requested here
Ex54.cpp:8:13: note: in instantiation of function template specialization 'print<double, char, char[6], char[6], char[2]>' requested here
Ex54.cpp:20:5: note: in instantiation of function template specialization 'print<int, double, char, char[6], char[6], char[2]>' requested here
   20 |     print(std::cout, 1,2.0,'3', "Hello", "World", "!") << std::endl;
      |     ^
Ex54.cpp:5:15: note: candidate function template not viable: requires at least 2 arguments, but 1 was provided
    5 | std::ostream &print(std::ostream &os, const T arg, const Args&... rest)
      |               ^     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
2 errors generated.
```

## 16.4.2. Pack Expansion

### [Exercise 16.56:](Exercise_56/Ex56.cpp)

*Write and test a `variadic` version of `errorMsg`.*

### Exercise 16.57:

*Compare your `variadic` version of `errorMsg` to the `error_msg` function in § 6.2.6 (p. 220). What are the advantages and disadvantages of each approach?*

```cpp
void error_msg(initializer_list<string> il)
{
    for (auto beg = il.begin(); beg != il.end(); ++beg)
        cout << *beg << " " ;
    cout << endl;
}
```

**Answer**
- errorMsg:
    - Advantages:
        - It can be used with different types. 
        - It is a more generic approach.
        - Type safe(compilations time).
    - Disadvantages:
        - More overhead.
- error_msg:
    - Advantages:
        - Less overhead.
    - Disadvantages:
        - Less generic, all objects must be of the same type.
        - Type not safety
