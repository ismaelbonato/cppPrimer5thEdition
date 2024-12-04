
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
int *q = new int(42); // int pointer to an address with the value: 42 
int *r = new int(100); // int pointer to an address with the value: 100 
// Warning
r = q; // The process of copying from q to r results in a memory leak, which effectively eliminates the ability to delete the old r address.
auto q2 = make_shared<int>(42); // Creates an int shared_ptr with the value 42
auto r2 = make_shared<int>(100); // Creates an int shared_ptr with the value 100
r2 = q2; // Copy the q2 shared_ptr to r2, adding +1 to the internal q2 counter.
```



----------------------------
### [Back to Chapter 11](../Chapter_11/README.md) - [Next to Chapter 13](../Chapter_13/README.md)