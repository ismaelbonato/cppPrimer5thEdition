
### [Back to Chapter 10](../Chapter_10/README.md)

# Chapter 11. Associative Containers

### How to compile:

GCC 6.0+ or clang 3.3+

`g++ -std=c++11 app_name.cpp -o target`

`clang++ -std=c++11 app_name.cpp -o target`

## 11.1. Using an Associative Container

### Exercise 11.1: 

*Describe the differences between a map and a vector.*

**Answer**
- Map is a associative container, elements are stored and accessed by key.
- Vector is a sequential container, elements are stored and accessed sequentially by position.

### Exercise 11.2: 

*Give an example of when each of list, vector, deque, map, and set might be most useful.*

**Answer**
- List is more useful when there is a lot of insertion at any position except at the beginning or end of the container.
- Vector is more useful when the insertion is at the end of the container.
- Deque is often used for queues.
- Map is often used in dictionaries. 
- Set is often used when the operator must know if the entry is contained by the set of entries.

### [Exercise 11.3:](Exercise_03/Ex_03.cpp)

*Write your own version of the word-counting program.*

### [Exercise 11.4:](Exercise_04/Ex_04.cpp)

*Extend your program to ignore case and punctuation. For example, “example.” “example,” and “Example” should all increment the same counter.*

## 11.2.1. Defining an Associative Container

### Exercise 11.5: 

Explain the difference between a map and a set. When might you use one or the other?

**Answer**
- A set is an associative container that contains only a value which is also its key, it is often used as an exclusion list or bad_checks.
-  A map is an associative container that contains a pair of value and its respective key. A map is often utilized in dictionaries.

### Exercise 11.6: 

Explain the difference between a set and a list. When might you use one or the other?

**Answer**

- A `list` can contain any value in any order, might be used when
    - Duplicates are allowed.
    - Insertion is made at any position.
- A `set` cannot contain duplicate values and an insert is ordered,  might be used when
    - Each value must be unique.
    - Fast search is a must.

### [Exercise 11.7:](Exercise_07/Ex_07.cpp) 

Define a `map` for which the key is the family’s last name and the value is a `vector` of the children’s names. Write code to add new families and to add new children to an existing family.

### [Exercise 11.8:](Exercise_08/Ex_08.cpp) 

Write a program that stores the excluded words in a `vector` instead of in a `set`. What are the advantages to using a set?

**Answer**
- A `vector` can contain any value, but to use it as a set, you need an algorithm to prevent duplicates. Sets have this built in.

## 11.2.2. Requirements on Key Type

### Exercise 11.9: 

*Define a `map` that associates words with a `list` of line numbers on which the word might occur.*

**Answer**

```cpp
#include <string>
#include <map>
#include <list>

int main (void)
{
    std::map<std::string, std::list<std::size_t>> mStrSize;

    return 0;
}
```

### [Exercise 11.10:](Exercise_10/Ex_10.cpp) 

*Could we define a `map` from `vector<int>::iterator` to `int`? What about from `list<int>::iterator` to `int`? In each case, if not, why not?*

**Answer**
- Both can be defined.


### [Exercise 11.11:](Exercise_11/Ex_11.cpp)

*Redefine bookstore without using `decltype`.*

**Answer**
```cpp

#include <functional>

using pToCompareISBN = std::function<bool(const SalesData &, const SalesData &)>;

std::multiset<SalesData, pToCompareISBN> bookstore(compareISBN);
```

## 11.2.3. The pair Type

### [Exercise 11.12:](Exercise_12/Ex_12.cpp) 

*Write a program to read a sequence of `strings` and `ints`, storing each into a `pair`. Store the `pairs` in a `vector`.*

### Exercise 11.13: 

*There are at least three ways to create the pairs in the program for the previous exercise. Write three versions of that program, creating the pairs in each way. Explain which form you think is easiest to write and understand, and why.*

**Answer**
```cpp
vP.emplace_back(word, value);
vP.push_back({word, value});
vP.push_back(std::pair<std::string, int>(word, value));
vP.push_back(std::make_pair(word, value));
vP.push_back(std::map<string, size_t>::value_type(word, value));
```
- The easiest way to create a pair is to use the emplace_back() method, this gives the container the responsibility to create the object.

### [Exercise 11.14:](Exercise_14/Ex_14.cpp) 

*Extend the `map` of children to their family name that you wrote for the exercises in § 11.2.1 (p. 424) by having the `vector` store a `pair` that holds a child’s name and birthday.*

## 11.3.1. Associative Container Iterators

### Exercise 11.15: 

*What are the `mapped_type`, `key_type`, and `value_type` of a `map` from `int` to `vector<int>`?

**Answer**
```cpp
std::map<int, vector<int>> mV;
```

- `mapped_type` = `std::vector<int>` 
- `key_type` = `int`
- `value_type` = `std::pain<const int, std::vector<int>>`

### Exercise 11.16: 

*Using a `map` `iterator` write an expression that assigns a value to an element.*

**Answer**
```cpp
std::map<std::string, int> m{{"first", 1}};

auto mapIt = m.begin(); 

mapIt->second = 2;
```


### Exercise 11.17: 

*Assuming `c` is a `multiset` of `strings` and `v` is a `vector` of `strings`, explain the following calls. Indicate whether each call is legal:*
```cpp
a) copy(v.begin(), v.end(), inserter(c, c.end()));
b) copy(v.begin(), v.end(), back_inserter(c));
c) copy(c.begin(), c.end(), inserter(v, v.end()));
d) copy(c.begin(), c.end(), back_inserter(v));
```

**Answer**
- a: Legal;
- b: Illegal, associative containers does not implement push_back(); 
- c: Legal;
- d: Legal.


### Exercise 11.18: 

Write the type of map_it from the loop on page 430 without using auto or `decltype`.

```cpp
std::map<string, size_t> word_count;
auto map_it = word_count.cbegin();
```
**Answer**
```cpp
std::map<string, size_t> word_count;
std::map<std::string, size_t>::::const_iterator =  word_count.cbegin();
```

### Exercise 11.19: 

*Define a variable that you initialize by calling `begin()` on the `multiset` named `bookstore` from § 11.2.2 (p. 425). Write the variable’s type without using `auto` or `decltype`.*

**Answer**

```cpp
using siType = const Sales_item &;

using compISBNType = std::function<bool(siType lhs, siType rhs)>;
using BookstoreType = std::multiset<Sales_item, compISBNType>;

compISBNType compareISBN; 

bookstoreType bookstore(compareISBN);
bookstoreType::iterator bsIt = bookstore.begin();
```

## 11.3.2. Adding Elements

### [Exercise 11.20:](Exercise_20/Ex_20.cpp)

*Rewrite the word-counting program from § 11.1 (p. 421) to use `insert` instead of `subscripting`. Which program do you think is easier to write and read? Explain your reasoning.*

**Answer**
- Using subscription is more readable and it is shorter to write.

### Exercise 11.21: 

*Assuming `word_count` is a `map` from `string` to `size_t` and word is a `string`, explain the following loop:

```cpp
std::map<std::string, size_t> word_count;
std::string word; 

while (cin >> word) {
    ++word_count.insert({word, 0}).first->second;
}
```

**Answer**
- It does the same thing the exercise 20, but wiser.
- Explaining this expression with 2 steps: 

- `auto ret = word_count.insert({word, 0});`
    - The first part returns a pair comprising an `iterator` to the object in question, whether it has been newly inserted into the map or is already present.
-  `++(ret.first->second);`
    - The second part increments the `mapped_type`, if it was insert the value is 0 + 1, otherwise, if the value has already been  inserted the value is `previous value` + 1. 

### Exercise 11.22: 

*Given a `map<string, vector<int>>`, write the types used as an argument and as the return value for the version of insert that inserts one element.*

**Answer**
```cpp
//Argument type
insert(std::pair<std::string, std::vector<int>>);

//Return type
std::pair<map<std::string,std::vector<int>>::iterator, bool>
```

### [Exercise 11.23:](Exercise_23/Ex_23.cpp)

*Rewrite the map that stored vectors of children’s names with a key that is the family last name for the exercises in § 11.2.1 (p. 424) to use a multimap.*

## 11.3.4. Subscripting a map

### Exercise 11.24: 

*What does the following program do?*

```cpp
map<int, int> m;
m[0] = 1;
```

**Answer**
- This program creates an empty map and insert a key `0` with value `1`;


### Exercise 11.25: 

*Contrast the following program with the one in the previous exercise*

```cpp
vector<int> v;
v[0] = 1;
```
**Answer**
- This program will crash due to a buffer overflow. As the object `v` is empty, the program attempts to access a memory position that has not yet been allocated.


### Exercise 11.26: 

*What type can be used to `subscript` a `map`? What type does the `subscript` operator return? Give a concrete example—that is, define a `map` and then write the types that can be used to `subscript` the `map` and the type that would be returned from the `subscript` operator.*

**Answer**
- To subscribe a `map` a key_type is required.
- The subscript operator returns an `lvalue` to `Mapped_type`. 


```cpp
    using MappedValue = std::map<std::string, size_t>; 
    
    MappedValue mapped;

    MappedValue::mapped_type mappedValue = mapped["Answer"/*std::string*/] = 42; 

    std::cout << mappedValue << std::endl;
```

## 11.3.5. Accessing Elements

### Exercise 11.27: 

*What kinds of problems would you use `count` to solve? When might you use `find` instead?*

**Answer**
- `count` is usually used to count how many keys contains in a `multiset` or `multimap`. 
- `find` is usually used to verify if a key is present in a unique dataset without the requirement of creating a new key as `subscription`.  
 
### Exercise 11.28: 

*Define and initialize a variable to hold the result of calling find on a `map` from `string` to `vector` of `int`.*

**Answer**
```cpp
std::map<std::string, std::vector<int>> mapV;
std::map<std::string, std::vector<int>>::iterator ret = mapV.find();
```

### Exercise 11.29: 

What do `upper_bound`, `lower_bound`, and `equal_range` return when you pass them a key that is not in the container?*

**Answer**
- `upper_bound` & `lower_bound`  If the element is not in the multimap, then lower_bound and
upper_bound will return equal iterators; both will refer to the point at which the key
can be inserted without disrupting the order. 
- `equal_range` If no matches are found, the range returned has a length of zero, with both iterators refers to the point at which the key can be inserted without disrupting the order.

### Exercise 11.30: 

*Explain the meaning of the operand `pos.first->second` used in the output expression of the final program in this section.*

**Answer**
- `pos` is a pair of iterators, those iterators contains the range in witch the key was found. 
- `pos.first` is the first iterator where points to a pair with the key and the value.
- `pos.first-second` this points to the mapped_type of the first pair with the matching key.

### [Exercise 11.31:](Exercise_31/Ex_31.cpp)

*Write a program that defines a `multimap` of authors and their works. Use find to find an element in the `multimap` and erase that element. Be sure your program works correctly if the element you look for is not in the map.*

### [Exercise 11.32:](Exercise_32/Ex_32.cpp) 

*Using the `multimap` from the previous exercise, write a program to print the list of authors and their works alphabetically.*

## 11.3.6. A Word Transformation Map

### [Exercise 11.33:](Exercise_33/Ex_33.cpp)

*Implement your own version of the word-transformation program.*

### [Exercise 11.34:](Exercise_34/Ex_34.cpp) 

*What would happen if we used the subscript operator instead of find in the transform function?*

**Answer**
```cpp
Ex_34.cpp: In function ‘const std::string translate(Dictionary&, const std::string&)’:
Ex_34.cpp:13:31: error: expected unqualified-id before ‘[’ token
   13 |     auto meaning = dictionary.[rawWord];
      |                               ^
```
- It will rise a exception.
- Subscription returns the mapped_type value.
- Find returns a pair of iterators. 


### [Exercise 11.35:](Exercise_35/Ex_35.cpp)

*In buildMap, what effect, if any, would there be from rewriting `trans_map[key] = value.substr(1);` as `trans_map.insert({key, value.substr(1)})`?

**Answer**
- It will work as normal, but it is crucial to be aware of some significant differences.
    - Subscription will overwrite if a key already exist.
    - Insert or emplace will not overwrite if a key already exist. 


### [Exercise 11.36:](Exercise_36/Ex_36.cpp)

*Our program does no checking on the validity of either input file. In particular, it assumes that the rules in the transformation file are all sensible. What would happen if a line in that file has a key, one space, and then the end of the line? Predict the behavior and then check it against your version of the program.*

**Answer**
```
...
u you
asap 
pic picture
...
```
- Prediction: It will work as normal.
    - The source code uses `getline`, so the map will have a key `asap` but without translation.

**Output**

```
where are you 
why dont you send me a picture 
okay? thanks! later 
```
- Prof: it behaviors as the prediction.

## 11.4. The Unordered Containers

### Exercise 11.37: 

*What are the advantages of an unordered container as compared to the ordered version of that container? What are the advantages of the ordered version?*

**Answer**
- Advantages:
    - Finding by hash gives better performance depending of the size of object to compare.
    - It is better suited when the objects can not be ordered.
    - It is better suited when ordering objects can be CPU-intensive.
- Disadvantages:
    - It is unordered by default.
    - Objects outside of the built-in types must implement hash and comparison functions.

### [Exercise 11.38:](Exercise_38/Ex_38.cpp)

*Rewrite the word-counting (§ 11.1, p. 421) and word-transformation (§ 11.3.6, p. 440) programs to use an unordered_map.*

**Output**
```shell
./a.out < wordcounting 
//-------------------------- word couting --------------------------------//
how occurs 1 time
matter occurs 1 time
not occurs 1 time
is occurs 1 time
enough occurs 3 times
//-------------------------- word translation --------------------------------//
where are you 
why dont you send me a picture 
okay? thanks! later 
```

----------------------------
### [Back to Chapter 10](../Chapter_10/README.md) - [Next to Chapter 12](../Chapter_12/README.md)