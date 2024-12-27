
### [Back to Chapter 11](../Chapter_11/README.md)

# Chapter 12. Dynamic Memory

### How to compile:

GCC 6.0+ or clang 3.3+

`g++ -std=c++11 app_name.cpp -o target`

`clang++ -std=c++11 app_name.cpp -o target`

## 12.1.1. The shared_ptr Class

### Exercise 12.1: 

*How many elements do `b1` and `b2` have at the end of this code?*
```cpp
StrBlob b1;
{
    StrBlob b2 = {"a", "an", "the"};
    b1 = b2;
    b2.push_back("about");
}
```

**Answer**
- B1 Will have 4 elements.
- B2 will destroyed at the end but the `data` will not.

### [Exercise 12.2:](Exercise_02/Ex_02.cpp)

*Write your own version of the `StrBlob` class including the const versions of front and back.*

### Exercise 12.3:

*Does this class need const versions of `push_back` and `pop_back`? If so, add them. If not, why aren’t they needed?*

**Answer**
- It is possible to use `const` in these functions, but in this case is pointless, the `const` modifier set objects on the stack to read-only, but has no control over objects in heap memory, so it is meaningless to use a compile time modifier on an object in the heap.
- The point of using `const` in this case is to make the the pointer on the stack read-only, but not the object bound by the pointer in heap memory.

### Exercise 12.4: 

*In our check function we didn’t check whether `i` was greater than zero. Why is it okay to omit that check?*

**Answer**
- Since `std::vector<std::string>::size_type` is an `unsigned long` so was `i`.
- `i` cannot be less than zero.

### Exercise 12.5: 

*We did not make the constructor that takes an `initializer_list` explicit (§ 7.5.4, p. 296). Discuss the pros and cons of this design choice.*

**Answer**

- In oder to make the constructor explicit, some changes must be made.
    ```cpp
    // when calling the constructor. the type must match exactly.
    // in order to match a temporary object has to be created.
    StrBlob b2 = StrBlob({"a", "an", "the"});
    // or calling the constructor when the conversion is not required. 
    StrBlob b2{"a", "an", "the"};
    ```

- Pros:
    - The conversion is made by the programer, less prone to bugs. 
    - Force the programmer to use the right constructor.
- Cons:
    - The programer needs to convert manually every time. 
    - An temporary object is required when copy.


## 12.1.2. Managing Memory Directly

### [Exercise 12.6:](Exercise_03/Ex_03.cpp)

*Write a function that returns a dynamically allocated `vector` of `ints`. Pass that `vector` to another function that reads the standard `input` to give values to the elements. Pass the vector to another function to `print` the values that were read. Remember to delete the vector at the appropriate time.*

### [Exercise 12.7:](Exercise_04/Ex_04.cpp)

*Redo the previous exercise, this time using shared_ptr.*

### Exercise 12.8: 

*Explain what if anything is wrong with the following function.*

```cpp
bool b() {
    int* p = new int;
    // ...
    return p;
}
```

**Answer**
- The function return should be a `pointer` to an `int`.
- The `pointer` to an `int` will be converted to a bool, data will be lost,
- After the data lost, the reference to the memory location will be also lost, as the capability to be freed from memory.

### Exercise 12.9: 

*Explain what happens in the following code:*

```cpp
int *q = new int(42); 
int *r = new int(100);
r = q;
auto q2 = make_shared<int>(42);
auto r2 = make_shared<int>(100);
r2 = q2;
```

**Answer**
```cpp
r = q;
```
- The process of copying from `q` to `r` results in a memory leak, which effectively eliminates the ability to delete the old `r` address.

```cpp
r2 = q2;
```
- Copy the `q2` shared_ptr to `r2`, adding +1 to the internal q2 counter.

## 12.1.3. Using shared_ptrs with new

### [Exercise 12.10:](Exercise_10/Ex_10.cpp)

*Explain whether the following call to the process function defined on page 464 is correct. If not, how would you correct the call?*
```cpp
shared_ptr<int> p(new int(42));
process(shared_ptr<int>(p));
```

**Answer**
- The code is not wrong, but it does not make sense.
- As an argument to the process function, it calls the share_ptr constructor by copy to create a temporary share_ptr. Why not pass `p` directly by value, it will also make a copy, not a copy of a copy. 

```cpp
shared_ptr<int> p(new int(42));
process(p);
```

### Exercise 12.11: 

*What would happen if we called process as follows?*

```cpp
process(shared_ptr<int>(p.get()));
```
**Answer**
- It is an `Error`, the pointer bound by share_ptr `p` will be freed at the end of function.

### [Exercise 12.12:](Exercise_12/Ex_12.cpp)

*Using the declarations of p and sp explain each of the following calls to process.  the call is legal, explain what it does. If the call is illegal, explain why:*
```cpp
auto p = new int();
auto sp = make_shared<int>();
(a) process(sp);
(b) process(new int());
(c) process(p);
(d) process(shared_ptr<int>(p));
```

**(a)**: Legal.
**(b)**: Illegal `shared_ptr` does not accept implicit conversion.
**(c)**: Illegal `shared_ptr` does not accept implicit conversion.
**(d)**: Legal but, it is an error, `p` will be freed at the end of the function, making `p` invalid.

### [Exercise 12.13:](Exercise_13/Ex_13.cpp)

*What happens if we execute the following code?*

```cpp
auto sp = make_shared<int>();
auto p = sp.get();
delete p;
```

**Answer**
- As `p` will be freed, the `shared_ptr` object will point to a freed pointer.
- When `sp` goes out of scope it will be deleted, double free will rise an exception.

**Output**
```bash
~/repo/cppPrimer5thEdition/Chapter_12/Exercise_13$ ./a.out 
double free or corruption (out)
Aborted (core dumped)
```

## 12.1.4. Smart Pointers and Exceptions

### [Exercise 12.14:](Exercise_14/Ex_14.cpp)

*Write your own version of a function that uses a shared_ptr to manage a connection.*

**Answer**
- With `shared_ptr`
    - **Code**
        ```cpp
        void f(destination &d)
        {
            try {
                connection *c = connect(d);
                std::shared_ptr<connection> sp(c, endConnection);
                
                throw std::invalid_argument("exception");
                
                endConnection(c);
            } catch (...) {}
        }
        ```
    - **Output Valgrind**
        ```shell
        ==594744== Memcheck, a memory error detector
        ==594744== Copyright (C) 2002-2022, and GNU GPL, by Julian Seward et al.
        ==594744== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
        ==594744== Command: ./a.out
        ==594744== 
        Disconnected
        ==594744== 
        ==594744== HEAP SUMMARY:
        ==594744==     in use at exit: 0 bytes in 0 blocks
        ==594744==   total heap usage: 6 allocs, 6 frees, 74,963 bytes allocated
        ==594744== 
        ==594744== All heap blocks were freed -- no leaks are possible
        ==594744== 
        ==594744== For lists of detected and suppressed errors, rerun with: -s
        ==594744== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
        ```
- With no `shared_ptr`
    - **Code**
        ```cpp
        void f(destination &d)
        {
            try {
                connection *c = connect(d);
                
                throw std::invalid_argument("exception");
                
                endConnection(c);
            } catch (...) {}
        }
        ```
     - **Output Valgrind**
        ```shell
        ==604207== Memcheck, a memory error detector
        ==604207== Copyright (C) 2002-2022, and GNU GPL, by Julian Seward et al.
        ==604207== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
        ==604207== Command: ./a.out
        ==604207== 
        ==604207== 
        ==604207== HEAP SUMMARY:
        ==604207==     in use at exit: 1 bytes in 1 blocks
        ==604207==   total heap usage: 4 allocs, 3 frees, 73,907 bytes allocated
        ==604207== 
        ==604207== LEAK SUMMARY:
        ==604207==    definitely lost: 1 bytes in 1 blocks
        ==604207==    indirectly lost: 0 bytes in 0 blocks
        ==604207==      possibly lost: 0 bytes in 0 blocks
        ==604207==    still reachable: 0 bytes in 0 blocks
        ==604207==         suppressed: 0 bytes in 0 blocks
        ==604207== Rerun with --leak-check=full to see details of leaked memory
        ==604207== 
        ==604207== For lists of detected and suppressed errors, rerun with: -s
        ==604207== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
        ```

### [Exercise 12.15:](Exercise_15/Ex_15.cpp)

*Rewrite the first exercise to use a lambda (§ 10.3.2, p. 388) in place of the  function.*

**Answer**
```cpp
void f(destination &d)
{
    try {
        connection *c = connect(d);
        std::shared_ptr<connection> sp(c, 
        [] (connection *c) {
            std::cout << "Disconnected" << std::endl;
            delete c;
        });
        
        throw std::invalid_argument("exception");
    } catch (...) {}
}
```

## 12.1.5. unique_ptr

### [Exercise 12.16:](Exercise_16/Ex_16.cpp)

*Compilers don’t always give easy-to-understand error messages if we attempt to copy or assign a `unique_ptr`. Write a program that contains these errors to see how your compiler diagnoses them.*

**Output**

```shell
Chapter_12/Exercise_16$ g++ Ex_16.cpp 
Ex_16.cpp: In function ‘int main()’:
Ex_16.cpp:10:31: error: use of deleted function ‘std::unique_ptr<_Tp, _Dp>::unique_ptr(const std::unique_ptr<_Tp, _Dp>&) [with _Tp = int; _Dp = std::default_delete<int>]’
   10 |     std::unique_ptr<int> u3(u2);
      |                               ^
In file included from /usr/include/c++/13/memory:78,
                 from Ex_16.cpp:4:
/usr/include/c++/13/bits/unique_ptr.h:522:7: note: declared here
  522 |       unique_ptr(const unique_ptr&) = delete;
      |       ^~~~~~~~~~
Ex_16.cpp:12:10: error: use of deleted function ‘std::unique_ptr<_Tp, _Dp>& std::unique_ptr<_Tp, _Dp>::operator=(const std::unique_ptr<_Tp, _Dp>&) [with _Tp = int; _Dp = std::default_delete<int>]’
   12 |     u1 = u2;
      |          ^~
/usr/include/c++/13/bits/unique_ptr.h:523:19: note: declared here
  523 |       unique_ptr& operator=(const unique_ptr&) = delete;
      |                   ^~~~~~~~
```

### Exercise 12.17: 

*Which of the following `unique_ptr` declarations are illegal or likely to result in subsequent program error? Explain what the problem is with each one.*

```cpp
int ix = 1024, *pi = &ix, *pi2 = new int(2048);
typedef unique_ptr<int> IntP;

(a) IntP p0(ix);
(b) IntP p1(pi);
(c) IntP p2(pi2);
(d) IntP p3(&ix);
(e) IntP p4(new int(2048));
(f) IntP p5(p2.get());
```

**Answer**

- **(a)**: Illegal `ix` is not a pointer.
- **(b)**: Legal, depending the order of the destruction it can raise a double free exception or make a pointer invalid.
- **(c)**: Legal,  depending the order of the destruction it can raise a double free exception or make a pointer invalid.
- **(d)**: Legal, if `ix` goes out of scope `p3` will handle a freed pointer or if `p3` goes out of scope, it will throw an exception, the program will try to free a non-pointer non-heap object. 
- **(e)**: Legal, 
- **(f)**: Legal. it will cause double free exception.

### Exercise 12.18: 

*Why doesn’t `shared_ptr` have a release member?*

**Answer**
- Because pointer handled by `shared_ptr` can be shared, unlike `unique_ptr`.

## 12.1.6. weak_ptr

### [Exercise 12.19:](Exercise_19/Ex_19.cpp)

*Define your own version of `StrBlobPtr` and update your `StrBlob` class with the appropriate friend declaration and begin and end members.*

### [Exercise 12.20:](Exercise_20/Ex_20.cpp)

*Write a program that reads an input file a line at a time into a `StrBlob` and uses a `StrBlobPtr` to print each element in that `StrBlob`.*

### Exercise 12.21: 

*We could have written `StrBlobPtr’s` deref member as follows:*

```cpp
std::string& deref() const
{ return (*check(curr, "dereference past end"))[curr]; }
```

*Which version do you think is better and why?*

### Exercise 12.22: 

*What changes would need to be made to `StrBlobPtr` to create a class that can be used with a `const StrBlob`? Define a class named `ConstStrBlobPtr` that can point to a `const StrBlob`.*

----------------------------
### [Back to Chapter 11](../Chapter_11/README.md) - [Next to Chapter 13](../Chapter_13/README.md)