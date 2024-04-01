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

```cpp
list<int> lst1;
list<int>::iterator iter1 = lst1.begin(), iter2 = lst1.end();
while (iter1 != iter2) /* ... */
```