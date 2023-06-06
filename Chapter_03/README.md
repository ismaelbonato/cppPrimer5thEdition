# Chapter 3. Strings, Vectors, and Arrays

### How to compile:

GCC 6.0+ or clang 3.3+

`g++ -std=c++11 app_name.cpp -o target`

`clang++ -std=c++11 app_name.cpp -o target`

#### [Exercise 3.1:](Exercise_01)

*Rewrite the exercises from § 1.4.1 (p. 13) and § 2.6.2 (p. 76) with appropriate using declarations.*

**Answer**:

- [Exercise 1.09](Exercise_01/Ex01_09.cpp)
- [Exercise 1.10](Exercise_01/Ex01_10.cpp)
- [Exercise 1.11](Exercise_01/Ex01_11.cpp)
- [Exercise 1.21](Exercise_01/Ex01_20.cpp)
- [Exercise 1.22](Exercise_01/Ex01_21.cpp)
- [Exercise 1.23](Exercise_01/Ex01_23.cpp)
- [Exercise 1.25](Exercise_01/Ex01_25.cpp)

#### [Exercise 3.2:](Exercise_02) 

*Write a program to read the standard input a line at a time. Modify your program to read a word at a time.*

**Answer**

- [Exercise 3.2A](Exercise_02/Ex02A.cpp)
- [Exercise 3.2B](Exercise_02/Ex02B.cpp)

#### Exercise 3.3:

*Explain how whitespace characters are handled in the string input operator and in the `getline` function.*

**Answer**

- **String**: In `string` operator `stream` a whitespace is handled as a newline, when a whitespace is found the stream is finalized but without the whitespace.
- **Getline**: In this function a whitespace is handled like any other character, it copies te whole line until a `newline` is found.

#### [Exercise 3.4:](Exercise_04) 

*Write a program to read two strings and report whether the strings are equal. If not, report which of the two is larger. Now, change the program to report whether the strings have the same length, and if not, report which is longer.*

**Answer**
- [Exercise 3.4A](Exercise_04/Ex04A.cpp)
- [Exercise 3.4B](Exercise_04/Ex04B.cpp)


#### [Exercise 3.5:](Exercise_03) 

*Write a program to read strings from the standard input, concatenating what is read into one large string. Print the concatenated string. Next, change the program to separate adjacent input strings by a space.*

**Answer**
- [Exercise 3.5A](Exercise_05/Ex05A.cpp)
- [Exercise 3.5B](Exercise_05/Ex05B.cpp)


#### [Exercise 3.6:](Exercise_06/Ex06.cpp)

*Use a range `for` to change all the characters in a `string` to X.*

#### [Exercise 3.7:](Exercise_07/Ex07.cpp)

*What would happen if you define the loop control variable in the previous exercise as type `char`? Predict the results and then change your program to use a `char` to see if you were right.*

**Answer**

- Changing to `char&` it will work in the same way, because this auto variable is already specified as a char by the compiler.
- Changing to `char` although, the program will not work anymore as intended, the iterator will be just a copy of the value defined the `string`.

#### Exercise 3.8: 

*Rewrite the program in the first exercise, first using a while and again using a traditional for `loop`. Which of the three approaches do you prefer and why?*

**Answer**

I prefer the range `for` statement from [exercise 07](Exercise_07/Ex07.cpp). It's easier, simpler and elegant in that way.

- [Exercise 3.8 with While:](Exercise_08/Ex08While.cpp)
- [Exercise 3.8 with For:](Exercise_08/Ex08For.cpp)


#### Exercise 3.9: 

*What does the following program do? Is it valid? If not, why not? 

```cpp
string s;
cout << s[0] << endl;
```
**Answer**

- This program is invalid, its behavior is unknown since the string `s` is empty, its value is undefined. 

#### [Exercise 3.10:](Exercise_10/Ex10.cpp)

*Write a program that reads a `string` of characters including punctuation and writes what was read but with the punctuation removed.*


#### Exercise 3.11: 

*Is the following range `for` legal? If so, what is the type of c?*

```cpp
const string s = "Keep out!";
for (auto &c : s) { /* ... */ }
```
**Answer**

- It will be **Illegal** if type `c` perform an any kind of assignment, because it's a reference to a `const char`.

#### Exercise 3.12: 

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




#### Exercise 3.13: 

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

#### [Exercise 3.14:](Exercise_14/Ex14.cpp)

*Write a program to read a sequence of `ints` from `cin` and store those values in a `vector`.*


#### [Exercise 3.15:](Exercise_15/Ex15.cpp)

*Repeat the previous program but read `strings` this time.*



#### [Exercise 3.16:](Exercise_16/Ex16.cpp)

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

#### [Exercise 3.17:](Exercise_17/Ex17)

*Read a sequence of words from cin and store the values a vector. After you’ve read all the words, process the vector and change each word to uppercase. Print the transformed elements, eight words to a line.*

#### Exercise 3.18:

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

#### Exercise 3.19:

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

- I prefer the third one, because it's not required to know the size of the vector in advance and despite the fact it's using a vector it's protected against buffer overflow.

#### [Exercise 3.20:](Exercise_20)

*Read a set of integers into a vector. Print the sum of each pair of adjacent elements. Change your program so that it prints the sum of the first and last elements, followed by the sum of the second and second-to- last, and so on.*

**Answer**

- [Exercise 3.20A:](Exercise_20/Ex20A.cpp)
- [Exercise 3.20B:](Exercise_20/Ex20B.cpp)