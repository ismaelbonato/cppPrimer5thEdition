### [Back to Chapter 8](../Chapter_08/README.md)

# Chapter 9. Sequential Containers

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

```cpp
list<string> 1st;
auto iter = 1st.begin();
while (cin >> word)
iter = 1st.insert(iter, word); // same as calling push_front
```
**Answer**

- It will work as expected using the `std::vector.insert()` but, as `std::vector` is a contiguous container, it will take time to perform all the required operations to allocate and move all objects that follow the object inserted.

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

- There is no increment on `iter`.
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

## 9.3.2. Accessing Elements

### Exercise 9.23: 

*In the first program in this section on page 346, what would the values of `val`, `val2`, `val3`, and `val4` be if `c.size()` is 1?*

**Answer**

- `val1`": will get the iterator to the first position on `c`.
- `val2`": will get a copy of the first position on `c`.
- `val3`": will get the iterator to the first position on `c`.
- `val4`": will get a copy of the first position on `c`.


### [Exercise 9.24:](Exercise_24/Ex_24.cpp) 

*Write a program that fetches the first element in a vector using at, the subscript operator, front, and begin. Test your program on an empty vector.*

**Output**

- **at**
    ```shell
    terminate called after throwing an instance of 'std::out_of_range'
    what():  vector::_M_range_check: __n (which is 0) >= this->size() (which is 0)
    Aborted
    ```
- **the subscript operator**
    ```shell
    Segmentation fault
    ```
- **front**
    ```shell
    Segmentation fault
    ```
- **begin**
    ```shell
    Segmentation fault
    ```


## 9.3.3. Erasing Elements

### Exercise 9.25:

*In the program on page 349 that erased a range of elements, what happens if `elem1` and `elem2` are equal? What if `elem2` or both `elem1` and `elem2` are the off-the-end iterator?*

```cpp
elem1 = slist.erase(elem1, elem2);
```
**Answer**
- If elem1 and elem2 are equal nothing will be erased and the erase method will return the iterator to `elem2`.
- If `elem2` is an off-the-end iterator it will erase all elements starting from`elem1` to the end of the container, it will return the iterator to the off-the-end `.end()` iterator.
- If `elem1` and `elem2` are off-the-end iterator, nothing will be erased and the erase method will return the iterator to off-the-end `.end()` iterator.


### [Exercise 9.26:](Exercise_26/Ex_26.cpp)

*Using the following definition of `ia`, copy ia into a `vector` and into a `list`. Use the `single-iterator` form of erase to remove the elements with odd values from your `list` and the even values from your `vector`.*

```cpp
int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
```

## 9.3.4. Specialized forward_list Operations

### [Exercise 9.27:](Exercise_27/Ex_27.cpp)

*Write a program to find and remove the odd-valued elements in a `forward_list<int>`.*

### [Exercise 9.28:](Exercise_28/Ex_28.cpp)

*Write a function that takes a `forward_list<string>` and two additional string arguments. The function should find the first string and insert the second immediately following the first. If the first string is not found, then insert the second string at the end of the list.*

## 9.3.5. Resizing a Container

### Exercise 9.29: 

*Given that vec holds 25 elements, what does `vec.resize(100)` do? What if we next wrote `vec.resize(10)`?*

**Answer**
- The command `vec.resize(100)` creates 75 new elements at the end of the list, all value initialized.
- The command `vec.resize(10)` will shrink the list to only 10 elements, all other elements will be discarded.


### Exercise 9.30: 

*What, if any, restrictions does using the version of resize that takes a single argument place on the element type?*

**Answer**
- If the list holds class objects types that do not have a default constructor, it will be required to define the default initialization in the resize function.

## 9.3.6. Container Operations May Invalidate Iterators

### [Exercise 9.31:](Exercise_31/Ex_31.cpp)


*The program on page 354 to remove even-valued elements and duplicate odd ones will not work on a list or forward_list. Why? Revise the program so that it works on these types as well.*

**Answer**
- For a `std::list` this example will not work, as it is a linked list the iterator can only perform -- ou ++ operations, each object in a double linked list only know its previous and next object on the list.
- For a `std::forward_list` this example will not work, a `std::forward_list` has the same problem of the `std::list` but as it is a single linked list the iterator can only perform the ++ operation. For this component there is not exist such member as `insert()` or `erease()`, the only way to insert or remove an object is using the members `insert_after()` and `erase_after()`. 

### Exercise 9.32:

*In the program onpage 354 would it be legal to write the call to insert as follows? If not, why not?*
```cpp
iter = vi.insert(iter, *iter++);
```
**Answer**
- It is legal, but unsafe, iter is used twice in the function and there is no guarantee witch of them will be processed first, especially because postfix has priority over deference.

### [Exercise 9.33:](Exercise_33/Ex_33.cpp)

*In the final example in this section what would happen if we did not assign the result of insert to begin? Write a program that omits this assignment to see if your expectation was correct.*

```cpp
// safer: recalculate end on each trip whenever the loop adds/erases elements
while (begin != v.end()) {
// do some processing
    ++begin; // advance begin because we want to insert after this element
    begin = v.insert(begin, 42); // insert the new value
    ++begin; // advance begin past the element we just added
}
```
**Answer**
- It leads to an invalid iterator, the iterator will lead to the position in the memory where the container was located before the insertion.

**Output**
```cpp
~/repo/cppPrimer5th/Chapter_09/Exercise_33$ ./a.out 
munmap_chunk(): invalid pointer
Aborted
```

### [Exercise 9.34:](Exercise_34/Ex_34.cpp)

*Assuming `vi` is a container of `ints` that includes even and odd values, predict the behavior of the following loop. After you’ve analyzed this loop, write a program to test whether your expectations were correct.*
```cpp
iter = vi.begin();
while (iter != vi.end())
    if (*iter % 2)
        iter = vi.insert(iter, *iter);
    ++iter;
```

**Answer**
- When an Odd value is found the code will duplicate the odd value and it will stuck in this process forever, this loop will never end.

## 9.4. How a vector Grows

### Exercise 9.35: 

*Explain the difference between a vector’s capacity and
its size.*

**Answer**
- Size: is the amount of elements in the Vector.
- Capacity: is the amount of space allocated in the memory for this vector, it can be equal or larger than Size.

### Exercise 9.36: 

*Can a container have a capacity less than its size?*

**Answer**
- The capacity of the container can be equal or larger than the size. Assuming that a due container has its capacity less than the size it is a buffer overflow.

Exercise 9.37: Why don’t list or array have a capacity member?

**Answer**
- The Array container has its size fixed in its creation, so capacity is meaningless in this case.
- The List container is a double linked list, so memory allocation and deallocation are fast than the contiguous containers.

### [Exercise 9.38:](Exercise_38/Ex_38.cpp)

*Write a program to explore how vectors grow in the library you use.*

### Exercise 9.39: 

*Explain what the following program fragment does:
```cpp
std::vector<string> svec;
svec.reserve(1024);
std::string word;
while (cin >> word) {
    svec.push_back(word);
}
svec.resize(svec.size()+svec.size()/2);

```
**Answer**
- An Vector of strings is created and 1024 spaces are allocated in memory for this Vector. 
- After that there is a loop for pushing to the back of the container the standard input. 
- In the end the Vector is resized to accommodate another  "vector.size()/2" in default initialized elements.

### Exercise 9.40: 

*If the program in the previous exercise reads 256 words, what is its likely capacity after it is resized? What if it reads 512? 1,000? 1,048?*

**Answer**
- 256: The capacity will be 1024 before and after the resize. 
- 512: The capacity will be 1024 before and after the resize.
- 1000: The capacity will be 1024 before and 2048 after the resize.
- 1048: The capacity will be 2048 before and 2048 after the resize.


## 9.5.1. Other Ways to Construct strings

### [Exercise 9.41:](Exercise_41/Ex_41.cpp)

*Write a program that initializes a string from a `vector<char>`.*

### Exercise 9.42: 

*Given that you want to read a character at a time into a string, and you know that you need to read at least 100 characters, how might you improve the performance of your program?*

**Answer**
- A would create and reserve memory for at least for 128 elements in that string. 

## 9.5.2. Other Ways to Change a string

### [Exercise 9.43:](Exercise_43/Ex_43.cpp)

*Write a function that takes three strings, s, oldVal, and newVal. Using iterators, and the insert and erase functions replace all instances of oldVal that appear in s by newVal. Test your function by using it to replace common abbreviations, such as “tho” by “though” and “thru” by “through”.*

### [Exercise 9.44:](Exercise_44/Ex_44.cpp)

*Rewrite the previous function using an index and replace.*

### [Exercise 9.45:](Exercise_45/Ex_45.cpp)

*Write a function that takes a string representing a name and two other strings representing a prefix, such as “Mr.” or “Ms.” and a suffix, such as “Jr.” or “III”. Using iterators and the insert and append functions, generate and return a new string with the suffix and prefix added to the given name.*

### [Exercise 9.46:](Exercise_46/Ex_46.cpp)

*Rewrite the previous exercise using a position and length to manage the strings. This time use only the insert function.*

## 9.5.3. string Search Operations

### [Exercise 9.47:](Exercise_47/Ex_47.cpp)

*Write a program that finds each numeric character and then each alphabetic character in the string `"ab2c3d7R4E6"`. Write two versions of the program. The first should use `find_first_of`, and the second `find_first_not_of`.*

### Exercise 9.48:

*Given the definitions of name and numbers on page 365, what does numbers.find(name) return?*

**Answer**
- It will return `std::string::npos`.

### [Exercise 9.49:](Exercise_49/Ex_49.cpp)

*A letter has an ascender if, as with d or f, part of the letter extends above the middle of the line. A letter has a descender if, as with p or g, part of the letter extends below the line. Write a program that reads a file containing words and reports the longest word that contains neither ascenders nor descenders.*

## 9.5.5. Numeric Conversions

### [Exercise 9.50:](Exercise_50/Ex_50.cpp)

*Write a program to process a `vector<string>s` whose elements represent integral values. Produce the sum of all the elements in that vector. Change the program so that it sums of strings that represent floating-point values.*

### [Exercise 9.51:](Exercise_51/Ex_51.cpp)

*Write a class that has three unsigned members representing year, month, and day. Write a constructor that takes a string representing a date. Your constructor should handle a variety of date formats, such as January 1, 1900, 1/1/1900, Jan 1, 1900, and so on.*

## 9.6. Container Adaptors

### [Exercise 9.52:](Exercise_52/Ex_52.cpp)

*Use a stack to process parenthesized expressions. When you see an open parenthesis, note that it was seen. When you see a close parenthesis after an open parenthesis, pop elements down to and including the open parenthesis off the stack. push a value onto the stack to indicate that a parenthesized expression was replaced.*

----------------------------
### [Back to Chapter 8](../Chapter_08/README.md) - [Next to Chapter 10](../Chapter_10/README.md)