# Chapter 3. Strings, Vectors, and Arrays

### How to compile:

GCC 6.0+ or clang 3.3+

`g++ -std=c++11 app_name.cpp -o target`

`clang++ -std=c++11 app_name.cpp -o target`

### [Exercise 3.1:](Exercise_01)

*Rewrite the exercises from § 1.4.1 (p. 13) and § 2.6.2 (p. 76) with appropriate using declarations.*

**Answer**:

- [Exercise 1.09](Exercise_01/Ex01_09.cpp)
- [Exercise 1.10](Exercise_01/Ex01_10.cpp)
- [Exercise 1.11](Exercise_01/Ex01_11.cpp)
- [Exercise 1.21](Exercise_01/Ex01_20.cpp)
- [Exercise 1.22](Exercise_01/Ex01_21.cpp)
- [Exercise 1.23](Exercise_01/Ex01_23.cpp)
- [Exercise 1.25](Exercise_01/Ex01_25.cpp)

### [Exercise 3.2:](Exercise_02) 

*Write a program to read the standard input a line at a time. Modify your program to read a word at a time.*

**Answer**

- [Exercise 3.2A](Exercise_02/Ex02A.cpp)
- [Exercise 3.2B](Exercise_02/Ex02B.cpp)

### Exercise 3.3:

*Explain how whitespace characters are handled in the string input operator and in the `getline` function.*

**Answer**

- **String**: In `string` operator `stream` a whitespace is handled as a newline, when a whitespace is found the stream is finalized but without the whitespace.
- **Getline**: In this function a whitespace is handled like any other character, it copies te whole line until a `newline` is found.

### [Exercise 3.4:](Exercise_04) 

*Write a program to read two strings and report whether the strings are equal. If not, report which of the two is larger. Now, change the program to report whether the strings have the same length, and if not, report which is longer.*

**Answer**
- [Exercise 3.4A](Exercise_04/Ex04A.cpp)
- [Exercise 3.4B](Exercise_04/Ex04B.cpp)


### [Exercise 3.5:](Exercise_03) 

*Write a program to read strings from the standard input, concatenating what is read into one large string. Print the concatenated string. Next, change the program to separate adjacent input strings by a space.*

**Answer**
- [Exercise 3.5A](Exercise_05/Ex05A.cpp)
- [Exercise 3.5B](Exercise_05/Ex05B.cpp)


### [Exercise 3.6:](Exercise_06/Ex06.cpp)

*Use a range `for` to change all the characters in a `string` to X.*

### [Exercise 3.7:](Exercise_07/Ex07.cpp)

*What would happen if you define the loop control variable in the previous exercise as type `char`? Predict the results and then change your program to use a `char` to see if you were right.*

**Answer**

- Changing to `char&` it will work in the same way, because this auto variable is already specified as a char by the compiler.
- Changing to `char` although, the program will not work anymore as intended, the iterator will be just a copy of the value defined the `string`.

### Exercise 3.8: 

*Rewrite the program in the first exercise, first using a while and again using a traditional for `loop`. Which of the three approaches do you prefer and why?*

**Answer**

I prefer the range `for` statement from [exercise 07](Exercise_07/Ex07.cpp). It's easier, simpler and elegant in that way.

- [Exercise 3.8 with While:](Exercise_08/Ex08While.cpp)
- [Exercise 3.8 with For:](Exercise_08/Ex08For.cpp)


### Exercise 3.9: 

*What does the following program do? Is it valid? If not, why not? 

```cpp
string s;
cout << s[0] << endl;
```
**Answer**

- This program is invalid, its behavior is unknown since the string `s` is empty, its value is undefined. 

### [Exercise 3.10:](Exercise_10/Ex10.cpp)

*Write a program that reads a `string` of characters including punctuation and writes what was read but with the punctuation removed.*


### Exercise 3.11: 

*Is the following range `for` legal? If so, what is the type of c?*

```cpp
const string s = "Keep out!";
for (auto &c : s) { /* ... */ }
```
**Answer**

- It will be **Illegal** if type `c` perform an any kind of assignment, because it's a reference to a `const char`.

### Exercise 3.12: 

*Which, if any, of the following vector definitions are in error? For those that are legal, explain what the definition does. For those that are not legal, explain why they are illegal.*

```cpp
(a) vector<vector<int>> ivec;
(b) vector<string> svec = ivec;
(c) vector<string> svec(10, "null");
```
**Answer**

- **(a)** - **Legal**: it instantiates an empty `vector` that can hold a `vector` of the type `int`.
- **(b)** - **Illegal**: it's illegal, `ivec` is a `int` and a `string vector` cannot be initialized with an `int` value.
- **(c)** - **legal**: it instantiates an `string vector` with 10 `strings` initialized with `"null"` .




### Exercise 3.13: 

*How many elements are there in each of the following vectors? What are the values of the elements?*

```cpp
(a) vector<int> v1;
(b) vector<int> v2(10);
(c) vector<int> v3(10, 42);
(d) vector<int> v4{10};
(e) vector<int> v5{10, 42};
(f) vector<string> v6{10};
(g) vector<string> v7{10, "hi"};
```

**Answer**

- **(a)** - `v1` is an empty `int vector`. 
- **(b)** - `v2` is a `vector` with size of 10 `int` objects.
- **(c)** - `v3` is a `vector` with 10 `int` objects initialized with literal 42 each.
- **(d)** - `v4` is a `vector` in witch holds just one `int` object initialized with the literal 10.
- **(e)** - `v5` is a `vector` with two `int` objects initialized with the `int` literal 10 and 42 respectively.
- **(f)** - `v6` is a `vector` that holds 10 empty `string` objects.
- **(g)** - `v7` is a `vector` with 10 strings initialized each with the `string` literal "hi".

### [Exercise 3.14:](Exercise_14/Ex14.cpp)

*Write a program to read a sequence of `ints` from `cin` and store those values in a `vector`.*


### [Exercise 3.15:](Exercise_15/Ex15.cpp)

*Repeat the previous program but read `strings` this time.*



### [Exercise 3.16:](Exercise_16/Ex16.cpp)

*Write a program to print the size and contents of the vectors from exercise 3.13. Check whether your answers to that exercise were correct. If not, restudy § 3.3.1 (p. 97) until you understand why you were wrong.*

**Output**

```cpp
vector v1: sizeof= 0 value= 
vector v2: sizeof= 10 value= 0 0 0 0 0 0 0 0 0 0 
vector v3: sizeof= 10, value= 42 42 42 42 42 42 42 42 42 42 
vector v4: sizeof= 1, value= 10 
vector v5: sizeof= 2 value= 10 42 
vector v6: sizeof= 10 value=           
vector v7: sizeof= 10 value= hi hi hi hi hi hi hi hi hi hi
```

### [Exercise 3.17:](Exercise_17/Ex17.cpp)

*Read a sequence of words from cin and store the values a vector. After you’ve read all the words, process the vector and change each word to uppercase. Print the transformed elements, eight words to a line.*

### Exercise 3.18:

*Is the following program legal? If not, how might you fix it?*

```cpp
vector<int> ivec;
ivec[0] = 42;
```
**Answer**

- This program is **Illegal**, the vector is empty, therefore the assignment is illegal. In order to fix this assignment `ivec` has to be previously initialized, like the example below.

```cpp
vector<int> ivec{0}; //ivec holds an object with the literal value 0;
ivec[0] = 42;
```

### Exercise 3.19:

*List three ways to define a vector and give it ten elements, each with the value 42. Indicate whether there is a preferred way to do so and why.*

**Answer**

```cpp
// 1º
vector<int> i(10, 42);
// 2º
vector<int> i{42, 42, 42, 42, 42, 42, 42, 42, 42, 42};

// 3º
vector<int> i;

for (int idx = 0; idx < 10; idx++) {
    i.push_back(42);    
}

// 4º
vector<int> i(10);

for (&v : i) {
    v = 42;
}
```

- I prefer the third one, because it's not required to know the size of the vector in advance and despite the fact it's using push_back function protect against buffer overflow.

### [Exercise 3.20:](Exercise_20)

*Read a set of integers into a vector. Print the sum of each pair of adjacent elements. Change your program so that it prints the sum of the first and last elements, followed by the sum of the second and second-to- last, and so on.*

**Answer**

- [Exercise 3.20A:](Exercise_20/Ex20A.cpp)
- [Exercise 3.20B:](Exercise_20/Ex20B.cpp)


### [Exercise 3.21:](Exercise_21/Ex21.cpp)
*Redo the first exercise from § 3.3.3 (p. 105) using iterators.*

**Answer**

```cpp
vector v1: sizeof= 0 value= 
vector v2: sizeof= 10 value= 0 0 0 0 0 0 0 0 0 0 
vector v3: sizeof= 10, value= 42 42 42 42 42 42 42 42 42 42 
vector v4: sizeof= 1, value= 10 
vector v5: sizeof= 2 value= 10 42 
vector v6: sizeof= 10 value=           
vector v7: sizeof= 10 value= hi hi hi hi hi hi hi hi hi hi
```

### [Exercise 3.22:](Exercise_22/Ex22.cpp) 

*Revise the loop that printed the first paragraph in text to instead change the elements in text that correspond to the first paragraph to all uppercase. After you’ve updated text, print its contents.*


### [Exercise 3.23:](Exercise_23/Ex23.cpp)

*Write a program to create a vector with ten int elements. Using an iterator, assign each element a value that is twice its current value. Test your program by printing the vector.*

### [Exercise 3.24:](Exercise_24) 

*Redo the last exercise from § 3.3.3 (p. 105) using iterators.*

- [Exercise 3.24A:](Exercise_24/Ex24A.cpp)
- [Exercise 3.24B:](Exercise_24/Ex24B.cpp)


### [Exercise 3.25:](Exercise_25/Ex25.cpp) 

*Rewrite the grade clustering program from § 3.3.3 (p. 104) using iterators instead of subscripts.*

```cpp
vector<int> v{1,2,3,4,5,6,7,8,9};
for (auto &i : v) // for each element in v (note: i is a reference)
i *= i; // square the element value
for (auto i : v) // for each element in v
cout << i << " "; // print the element
cout << endl;
```

### Exercise 3.26: 

*In the binary search program on page 112, why did we write `mid = beg + (end - beg) / 2;` instead of `mid = (beg + end) /2;`?*

**Answer**

- The result of `(beg + end)` will be an index value, we need to sum this up with a valid address to find the address of the iterator as we need, furthermore `Mid` is a iterate type, the result of the arithmetic has to be a valid pointer to this data structure.

### Exercise 3.27: 

*Assuming txt_size is a function that takes no arguments and returns an int value, which of the following definitions are illegal? Explain why.*

```cpu
unsigned buf_size = 1024;
(a) int ia[buf_size];
(b) int ia[4 * 7 - 14];
(c) int ia[txt_size()];
(d) char st[11] = "fundamental";
```

**Answer**

- **(a)** - Illegal: the size definition is not a `constexpr`.
- **(b)** - Legal: the arithmetic operation will be performed because it is a `constant expression`.
- **(c)** - Illegal: the function `txt_size()` is not a `constexpr` function.
- **(d)** - Illegal: a `char` array assigned with an `string` literal has to have enough space to hold the `string` literal + a newline defined by the compiler. 

### Exercise 3.28: 

*What are the values in the following arrays?*

```cpp
string sa[10];
int ia[10];
int main() 
{
    string sa2[10];
    int ia2[10];
}
```

**Answer**

- **`sa`** - 10 empty objects.
- **`ia`** - 10 objects initialized with 0.
- **`sa2`** - 10 empty objects.
- **`oa2`** - 10 empty non initialized it means it is undefined.

### Exercise 3.29: 

*List some of the drawbacks of using an array instead of a vector.*

- Arrays has fixed size when defined and its size cannot be increased.
- Arrays are built in types, therefore can not perform operations like `push_back()`, `cbegin()`, `size()` and so on.
- Working with arrays can be risk, it has not the same protection that other containers made of templates in the Standard Library.

### Exercise 3.30: 

*Identify the indexing errors in the following code:*

```cpp
constexpr size_t array_size = 10;
int ia[array_size];
for (size_t ix = 1; ix <= array_size; ++ix)
ia[ix] = ix;
```

**Answer**

- The fist index error is in the for statement, `size_t ix = 1` in c++ vectors begin in position 0.
- The `ia` array begin from 0 to 9, in this case, the arithmetic expression `ix <= array_size` will count up to 10, it will cause a buffer overflow. In order to fix this error, the iterator has to count up to 9, as result `ix` has to be `less` than `array_size` = `ix < array_size`.

### [Exercise 3.31:](Exercise_31/Ex31.cpp)

*Write a program to define an array of ten `ints`. Give each element the same value as its position in the array.*

### [Exercise 3.32:](Exercise_32/Ex32.cpp) 

*Copy the `array` you defined in the previous exercise into another `array`. Rewrite your program to use vectors.*

### Exercise 3.33:

*What would happen if we did not initialize the scores `array` in the program on page 116?*

**Answer**

- Inside a scope an `int` type is not initialized, that so, its value is unknown, it can show false answers.

### Exercise 3.34: 

*Given that p1 and p2 point to elements in the same array, what does the following code do? Are there values of p1 or p2 that make this code illegal?*

```cpp
p1 += p2 - p1;
```

**Answer**

- The following piece of code assign the address of `p2` to `p1`, p2 has to be greater or equal to `p1` to make this code work properly.

### [Exercise 3.35:](Exercise_35/Ex35.cpp) 

*Using pointers, write a program to set the elements in an array to zero.*

### [Exercise 3.36:](Exercise_36/Ex36.cpp) 

*Write a program to compare two arrays for equality. Write a similar program to compare two vectors.*

### Exercise 3.37:

*What does the following program do?

```cpp
const char ca[] = {'h', 'e', 'l', 'l', 'o'};
const char *cp = ca;
while (*cp) {
cout << *cp << endl;
++cp;
}
```
**Answer**

- This program has a bug, the array `ca` has not a `null`  at the end, as a result, the while wil iterate through the memory until find a `null` character `\0`. there is a buffer overflow and the result will be undetermined.

### Exercise 3.38:

*In this section, we noted that it was not only illegal but meaningless to try to add two pointers. Why would adding two pointers be meaningless?*

**Answer**

- Usually we use add a index in to a pointer, in order to get a specific value in an array. adding up to pointer is meaningless because it will point to a unknown memory position.

### [Exercise 3.39:](Exercise_39/Ex39.cpp)

*Write a program to compare two strings. Now write a program to compare the values of two C-style character strings.*

### [Exercise 3.40:](Exercise_40/Ex40.cpp)

*Write a program to define two character arrays initialized from string literals. Now define a third character array to hold the concatenation of the two arrays. Use `strcpy` and `strcat` to copy the two arrays into the third.*

### [Exercise 3.41:](Exercise_41/Ex41.cpp)
*Write a program to initialize a vector from an array of `ints`.*

### [Exercise 3.42:](Exercise_42/Ex42.cpp)

*Write a program to copy a vector of `ints` into an array of `ints`.*

### [Exercise 3.43:](Exercise_43/Ex43.cpp)

*Write three different versions of a program to print the elements of ia. One version should use a range for to manage the iteration, the other two should use an ordinary for loop in one case using subscripts and in the other using pointers. In all three programs write all the types directly. That is, do not use a type alias, auto, or decltype to simplify the code.*

### [Exercise 3.44:](Exercise_44/Ex44.cpp)

*Rewrite the programs from the previous exercises using a type alias for the type of the loop control variables.*

### [Exercise 3.45:](Exercise_45/Ex45.cpp)

*Rewrite the programs again, this time using auto.*