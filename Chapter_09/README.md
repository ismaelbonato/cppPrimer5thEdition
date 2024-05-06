### [Back to Chapter 8](../Chapter_08/README.md)

# 9.1. Overview of the Sequential Containers

### How to compile:

GCC 6.0+ or clang 3.3+

`g++ -std=c++11 app_name.cpp -o target`

`clang++ -std=c++11 app_name.cpp -o target`

## 9.1. Overview of the Sequential Containers

### Exercise 9.1: 

*Which is the most appropriate: a `vector`, a `deque`, or a `list` for the following program tasks? Explain the rationale for your choice. If there is no reason to prefer one or another container, explain why not.*

- (a) Read a fixed number of words, inserting them in the container
alphabetically as they are entered. We’ll see in the next chapter that
associative containers are better suited to this problem.
- (b) Read an unknown number of words. Always insert new words at the
back. Remove the next value from the front.
- (c) Read an unknown number of integers from a file. Sort the numbers and
then print them to standard output.

**Answer**
- (a) In order to insert a word in any position, the `list` container is better suited, a `list` the random access is faster.
- (b) In this case a `deque` is better suited for the job, `deque` container is fast to remove objects from the front and the back;
- (c) A `vector` can be used to store all the integers in the container then using the internal algorithm to sort the output. The `vector` container is faster when push back.


## 9.2. Container Library Overview

### Exercise 9.2: 

*Define a `list` that holds elements that are `deques` that hold `ints`.

**Answer**
```cpp
std::list<std::deque<int>> listOfDequesOfInt;
```

## 9.2.1. Iterators


### Exercise 9.3: 

*What are the constraints on the iterators that form iterator ranges?*

**Answer**
- The iterators must refer to the same container.
- begin and end cannot be equal = empty range.
- Incrementing begin, the iterator will arrive to end.
- End must not precede begin.

### Exercise 9.4: 

*Write a function that takes a pair of iterators to a `vector<int>` and an `int` value. Look for that value in the range and return a bool indicating whether it was found.*

**Answer**
```cpp
const bool isThereAValue(const std::vector<int>::const_interator newBegin,             
                            const std::vector<int>::const_interator newEnd,
                                const int value); 
{
    while (newBegin != newEnd) {
        if (*newBegin == value) {
            return true;
        }
        ++newBegin;
    }

    return false;
}
```

### Exercise 9.5: 

*Rewrite the previous program to return an iterator to the requested element. Note that the program must handle the case where the element is not found.*

**Answer**
```cpp
#include <vector>
#include <iterator>

using constIt = std::vector<int>::const_iterator;
using it = std::vector<int>::iterator;

it getItByValue(constIt newBegin,
                                constIt newEnd,
                                    const int value)
{
    while (newBegin != newEnd) {
        if (*newBegin == value) {
            return newBegin;
        }
        ++newBegin;
    }

    return newEnd;
}
```

### Exercise 9.6: 

*What is wrong with the following program? How might you correct it?*

```cpp
list<int> lst1;
list<int>::iterator iter1 = lst1.begin(),
iter2 = lst1.end();
while (iter1 < iter2) /* ... */
```

**Answer**
- A list is a container that is implemented as a linked list, it is not contiguous, so there is no meaning in using relational operators.
```cpp
while (iter1 != iter2) /* ... */
```

## 9.2.2. Container Type Members

### Exercise 9.7: 

*What type should be used as the index into a vector of `ints`?*
**Answer**
```cpp
sd::vector<int>::size_type idx;
```

### Exercise 9.8: 

*What type should be used to read elements in a list of strings? To write them?*

**Answer**
- To read elements from a list of string: 
    ```cpp
    std::list<std::string>::const_reference; 
    std::list<std::string>::const_iterator; 
    ``` 
- To read elements from a list of string:
    ```cpp
    std::list<std::string>::reference;
    std::list<std::string>::value_type;
    std::list<std::string>::iterator;
    ```

## 9.2.3. begin and end Members

### Exercise 9.9: 

*What is the difference between the `begin` and `cbegin` functions?*

**Answer**
- **begin**: There are two begin functions, It is an overload function, if the object is a const it returns the `const_iterator` type, if not, it returns the `iterator` type.
- **begin**: It always returns a `const_iterator` object.

### Exercise 9.10: 

*What are the types of the following four objects?*
```cpp
vector<int> v1;
const vector<int> v2;
auto it1 = v1.begin(), it2 = v2.begin();
auto it3 = v1.cbegin(), it4 = v2.cbegin();
```
**Answer**
- **it1**: `iterator`.
- **it2**: `const_iterator`.
- **it3**: `const_iterator`.
- **it4**: `const_iterator`.

- Note: There is an error in this exercise, as `it1` and `it2` differs in type they cannot be aggregated int the same auto.

```cpp
auto it1 = v1.begin();
auto it2 = v2.begin(), it3 = v1.cbegin(), it4 = v2.cbegin();
```

## 9.2.4. Defining and Initializing a Container

### Exercise 9.11: 

*Show an example of each of the six ways to create and initialize a vector. Explain what values each vector contains.*

**Answer**
- Create a empty vector.
    ```cpp
    std::vector<int> iVec;
    ```
- Create a vector with ten `int`s default value initialized.
    ```cpp
    std::vector<int> iVec(10);
    ```
- Create a vector with ten `int`s initialized to 0.   
    ```cpp
    std::vector<int> iVec(10, 0);
    ```
- Create a vector with six `int`s list initialized.
    ```cpp
    std::vector<int> iVec{0, 1, 2, 3, 4, 5};
    ```
- Create a vector that is a copy of tVec.
    ```cpp
    std::vector<int> tVec{0, 1, 2, 3, 4, 5};
    std::vector<int> iVec(tVec);
    ```
- Create a vector within the range is defined by the iterators.
    ```cpp
    std::vector<int> tVec{0, 1, 2, 3, 4, 5};
    std::vector<int> iVec(tVec.begin, tVec.end);
    ```

### Exercise 9.12: 

*Explain the differences between the constructor that takes a container to copy and the constructor that takes two iterators.*

**Answer**
- A container initialized by another container makes use of the default copy constructor, it will be the  exact copy of the object as long as the types of both containers are the same.
- A container initialized by range iterators(explicit constructor) can be a copy o all objects in this range, it is not required the objects in the range to be the exactly same type of the container as long as the objects can be directly converted to this type.

### [Exercise 9.13:](Exercise_13/Ex_13.cpp)

*How would you initialize a `vector<double>` from a `list<int>`? From a `vector<int>`? Write code to check your answers.*

**Answer**

```cpp
std::list<int> iList;
std::vector<int> iVec

std::vector<double> dVec1(iVec.begin(), iVec.end());
std::vector<double> dVec2(iList.begin(), iList.end());
```

## 9.2.5. Assignment and swap

### [Exercise 9.14:](Exercise_14/Ex_14.cpp)

*Write a program to assign the elements from a list of `char*` pointers to `C-style` character strings to a vector of `strings`.*

## 9.2.7. Relational Operators

### [Exercise 9.15:](Exercise_15/Ex_15.cpp)

*Write a program to determine whether two `vector<int>`s are equal.*

### [Exercise 9.16:](Exercise_16/Ex_16.cpp)

*Repeat the previous program, but compare elements in a `list<int>` to a `vector<int>`.*

### Exercise 9.17: 

*Assuming c1 and c2 are containers, what (if any) constraints does the following usage place on the types of c1 and c2? if (c1 < c2)*

**Answer**
- The relational operators require both c1 and c2 to be the same type of container.
- The type within the container holds must have support for relational operators.
- All the containers except the unordered associative containers also support the relational operators.

## 9.3.1. Adding Elements to a Sequential Container

### [Exercise 9.18:](Exercise_18/Ex_18.cpp)

*Write a program to read a sequence of strings from the standard input into a `deque`. Use iterators to write a loop to print the elements in the `deque`.*

### [Exercise 9.19:](Exercise_19/Ex_19.cpp) 

*Rewrite the program from the previous exercise to use a `list`. List the changes you needed to make.*

### [Exercise 9.20:](Exercise_20/Ex_20.cpp) 

*Write a program to copy elements from a `list<int>` into two `deque`s. The even-valued elements should go into one deque and the odd ones into the other.*

### Exercise 9.21: 

*Explain how the loop from page 345 that used the return from insert to add elements to a list would work if we inserted into a vector instead.*

### [Exercise 9.22:](Exercise_22/Ex_22.cpp) 

*Assuming iv is a vector of `ints`, what is wrong with the following program? How might you correct the problem(s)?*

```cpp
vector<int> iv{1,2,3,4,5,6,7,8,9,10};
vector<int>::iterator iter = iv.begin(), mid = iv.begin() + iv.size()/2;

while (iter != mid) {
    if (*iter == some_val)
        iv.insert(iter, 2 * some_val);
}
```

**Answer**

- There is no incrent on the `iter`.
- The size of `iv` changes when a value is inserted, so the `iterator mid & iter`  are not valid anymore.
- to fix these issues you must recalculate `mid` and read `iter` from `insert` every time a value is inserted in the vector.

```cpp
    std::vector<int> iv{1,2,3,4,5,6,7,8,9,10};
    std::vector<int>::iterator iter = iv.begin(), mid = iv.begin() + iv.size()/2;

    while (iter != mid) {
        if (*iter == some_val) {
            iter = iv.insert(iter, 2 * some_val);
            mid = iv.begin() + iv.size()/2;
            iter++;
        }
        ++iter;
    }

    for (auto number : iv) {
        std::cout << number << ", "; 
    }

```


----------------------------
### [Back to Chapter 8](../Chapter_08/README.md) - [Next to Chapter 10](../Chapter_10/README.md)