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
