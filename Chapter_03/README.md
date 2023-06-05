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
