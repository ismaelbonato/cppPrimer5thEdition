# Chapter 5. Statements

### How to compile:

GCC 6.0+ or clang 3.3+

`g++ -std=c++11 app_name.cpp -o target`

`clang++ -std=c++11 app_name.cpp -o target`

## 5.1. Simple Statements

### Exercise 5.1:

*What is a null statement? When might you use a null statement?*

**Answer**

- A Null Statement is an empty statement, it means it has just a semi colon `;`.
    ```cpp
    ; // a null statement.
    ```
- Usually a null statement is used with loops when whe just need to find a object in a list but with any interaction. As example:
    ```cpp
    while (...)
    ;
    ```

- As alternative I prefer using a  empty compound statement also known as block statement. As example.
    ```cpp
    while (...) {}
    ```

### Exercise 5.2: 

*What is a block? When might you might use a block?*

**Answer**

- A block is a compound statement, it means it is sequence of statements in order to form a block of statements in between curly braces.
- It is used when we need a new scope or with some types of statements like loops and conditional statements that can hold just one statement (simple statement or compound statement).

### [Exercise 5.3:](Exercise_03/Ex03.cpp)

*Use the comma operator (§ 4.10, p. 157) to rewrite the `while` loop from § 1.4.1 (p. 11) so that it no longer requires a `block`. Explain whether this rewrite improves or diminishes the readability of this code.*

**Answer**

- Using comma operator diminishes the readability, but it is always better than using logical `&&` and `||`  operator, as you can see above.

    ```cpp
    //Using logical AND operator
    (sum += val) &&  (++val);
    //Using logical OR operator
    (sum += val) ||  (++val);
    //Using Comma operator    
    sum += val,  ++val; // Comma has lowest precedence
    ```

## 5.2. Statement Scope

### Exercise 5.4: 

*Explain each of the following examples, and correct any problems you detect.*

```cpp
(a) while (string::iterator iter != s.end()) { /* . . . */ }
(b) while (bool status = find(word)) { /* . . . */ }
if (!status) { /* . . . */ }
```

- **(a)** - You can only initialize a variable inside a scope using the equal `=` operator, for using a control expression a variable needs to be previously initialized.
    ```cpp
    std::string::iterator iter = s.begin();
    while (iter != s.end()) { /* . . . */ }
    ```

- **(b)** - There is an error with the second part of the code, `status` is not declared in the `if` scope just in the `while` scope.
    ```cpp
    bool status;
    while (status = find(word)) { /* . . . */ }
    if (!status) { /* . . . */ }
    ```

## 5.3.1. The if Statement

### [Exercise 5.5:](Exercise_05/Ex05.cpp) 

*Using an if–else statement, write your own version of the program to generate the letter grade from a numeric grade.*

### [Exercise 5.6:](Exercise_06/Ex06.cpp)

*Rewrite your grading program to use the conditional operator (§ 4.7, p. 151) in place of the if–else statement.*

### Exercise 5.7: 

*Correct the errors in each of the following code fragments:*

```cpp
(a) if (ival1 != ival2)
        ival1 = ival2
    else ival1 = ival2 = 0;
```
```cpp
(b) if (ival < minval)
        minval = ival;
    occurs = 1;
```
```cpp
(c) if (int ival = get_value())
        cout << "ival = " << ival << endl;
    if (!ival)
        cout << "ival = 0\n";
```
```cpp
(d) if (ival = 0)
        ival = get_value();
```

**Answer**


```cpp
(a) if (ival1 != ival2)
        ival1 = ival2; // missing the semicolon
    else ival1 = ival2 = 0;
```
```cpp
(b) if (ival < minval) { // missing the courly braces
        minval = ival;
        occurs = 1;
    }
```
```cpp
(c) if ( int ival = get_value()) // using else you don't need to declare `ival` in a parent scope.
        cout << "ival = " << ival << endl;
    else
        cout << "ival = 0\n";
```
```cpp
(d) if (ival == 0) // this code is meaningless without using the equality operator.
        ival = get_value();
```

### Exercise 5.8: 

*What is a “dangling else”? How are else clauses resolved in C++?*

**Answer**

- A dangling else an else wrongly placed, It can appears when we use nested `if` without using curly braces, in this case an `else` may not respect the indentation of the code, when it happens the compiler combine the `else` with the nearest `if`. An example bellow.

    ```cpp
    // as the programer coded
    if (...) 
        if (...)
            // code
    else
        // code

    // as the compiler read
    if (...) {
        if (...) {
            // code
        } else {
            // code
        }
    }
    ```

## 5.3.2. The switch Statement

### [Exercise 5.9:](Exercise_09/Ex09.cpp) 

*Write a program using a series of if statements to count the number of vowels in text read from cin.*

### [Exercise 5.10:](Exercise_10/Ex10.cpp) 

*There is one problem with our vowel-counting program as
we’ve implemented it: It doesn’t count capital letters as vowels. Write a program that counts both lower- and uppercase letters as the appropriate vowel—that is, your program should count both `'a'` and `'A'` as part of aCnt, and so forth.*


### [Exercise 5.11:](Exercise_11/Ex11.cpp) 

*Modify our vowel-counting program so that it also counts the number of blank spaces, tabs, and newlines read.*

### [Exercise 5.12:](Exercise_12/Ex12.cpp) 

*Modify our vowel-counting program so that it counts the
number of occurrences of the following two-character sequences: ff, fl, and fi.*

### Exercise 5.13: 

*Each of the programs in the highlighted text on page 184 contains a common programming error. Identify and correct each error.*

```cpp
(a) unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
    char ch = next_text();

    switch (ch) {
        case 'a': aCnt++; 
        case 'e': eCnt++;
        default: iouCnt++;
    }

(b) unsigned index = some_value();

    switch (index) {
        case 1:
            int ix = get_value();
            ivec[ ix ] = index;
            break;
        default:
            ix = ivec.size()-1;
            ivec[ ix ] = index;
    }

(c) unsigned evenCnt = 0, oddCnt = 0;
    int digit = get_num() % 10;
    
    switch (digit) {
        case 1, 3, 5, 7, 9:
            oddcnt++;
            break;
        case 2, 4, 6, 8, 10:
            evencnt++;
            break;
    }

(d) unsigned ival=512, jval=1024, kval=4096;
    unsigned bufsize;
    unsigned swt = get_bufCnt();

    switch(swt) {
        case ival:
            bufsize = ival * sizeof(int);
            break;
        case jval:
            bufsize = jval * sizeof(int);
            break;
        case kval:
            bufsize = kval * sizeof(int);
            break;
    }
```

**Answer**

```cpp
(a) unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
    char ch = next_text();

    switch (ch) {
        case 'a': 
            aCnt++;
            break; // missing break
        case 'e': 
            eCnt++;
            break; // missing break
        default: 
            iouCnt++;
    }
```

```cpp
(b) unsigned index = some_value();
    
    // The declaration will be skipped, in order to
    // declare a variable you need to use 
    // curly braces, the compound statement operator.
    // switch statement is just labels and jumps.
    switch (index) {
        case 1:
        {
            int ix = get_value();
            ivec[ ix ] = index;
            break;
        }
        default:
        {    
            int ix = ivec.size()-1;
            ivec[ ix ] = index;
        }
    }
```

```cpp
(c) // error: case expression must be a constant.
    unsigned evenCnt = 0, oddCnt = 0;
    int digit = get_num() % 10;
    
    switch (digit) {
        case 1: case 3: case 5: case 7: case 9:
            oddcnt++;
            break;
        case 2: case 4: case 6: case 8: case 10:
            evencnt++;
            break;
    }
```

```cpp
(d) // error: case expression must be a constant.
    constexpr unsigned ival = 512, jval = 1024, kval = 4096;
    unsigned bufsize;
    unsigned swt = get_bufCnt();
    
    switch(swt) {
        case ival:
            bufsize = ival * sizeof(int);
            break;
        case jval:
            bufsize = jval * sizeof(int);
            break;
        case kval:
            bufsize = kval * sizeof(int);
            break;
    }
```
## 5.4.1. The while Statement

### [Exercise 5.14:](Exercise_14/Ex14.cpp) 

*Write a program to read strings from standard input looking for duplicated words. The program should find places in the input where one word is followed immediately by itself. Keep track of the largest
number of times a single repetition occurs and which word is repeated. Print the maximum number of duplicates, or else print a message saying that no word was repeated. For example, if the input is
`how now now now brown cow cow` the output should indicate that the word now occurred three times.*

## 5.4.2. Traditional for Statement

### Exercise 5.15: 

*Explain each of the following loops. Correct any problems you detect.*

```cpp
(a) for (int ix = 0; ix != sz; ++ix) { /* . . . */ }
    if (ix != sz)
        // . . .
```
```cpp
(b) int ix;
    for (ix != sz; ++ix) { /* . . . */ }
```
```cpp
(c) for (int ix = 0; ix != sz; ++ix, ++ sz) { /* . . . */ }
```

**Answer**

- **(a)** - `ix` only exist in the for statement.
    ```cpp
    int ix;
    for (ix = 0; ix != sz; ++ix) { /* . . . */ }
    if (ix != sz)
        // . . .
    ```

- **(b)** - Semi colon is missing.
    ```cpp
    int ix;
    for (/* null */; ix != sz;++ix) { /* . . . */ }
    ```

- **(b)** - This loop will never fail (stop) because of the increment of `sz` as a condition.
    ```cpp
    for (int ix = 0; ix != sz; ++ix) { /* . . . */ }
    ```

### Exercise 5.16: 

*The while loop is particularly good at executing while some condition holds; for example, when we need to read values until end-of-file. The for loop is generally thought of as a step loop: An index steps through a range of values in a collection. Write an idiomatic use of each loop and then rewrite each using the other loop construct. If you could use only one loop, which would you choose? Why?*

**Answer**

```cpp
// while idiomatic
std::string str;
while (std::cin >> str) {
    /* ... */
}
// for
for (std::string str; std::cin >> str; /* null */) {
    /* ... */
}
```
```cpp
// for idiomatic
for (unsigned int x = 0; x != sizeof(); ++x) {
    /* ... */
}
// while
unsigned int x = 0;
while (x ! = sizeof()) {
    /* ... */
    ++x;
}

```
- I think each loop has its place, but I prefer the loop `for` because it is easier to control iteration. 

### [Exercise 5.17:](Exercise_17/Ex17.cpp)

*Given two `vectors` of `ints`, write a program to determine whether one vector is a prefix of the other. For vectors of unequal length, compare the number of elements of the smaller vector. For example, given the vectors containing `0, 1, 1, and 2` and `0, 1, 1, 2, 3, 5, 8,` respectively your program should return true.*


## 5.4.4. The do while Statement

### Exercise 5.18: 

*Explain each of the following loops. Correct any problems you detect.*
```cpp
(a) do
        int v1, v2;
        cout << "Please enter two numbers to sum:" ;
        if (cin >> v1 >> v2)
        cout << "Sum is: " << v1 + v2 << endl;
    while (cin);

(b) do {
        // . . .
    } while (int ival = get_response());

(c) do {
        int ival = get_response();
    } while (ival);
```
**Answer**
- It is missing the scope operator for compound statements.
    ```cpp
    do {
        int v1, v2;
        cout << "Please enter two numbers to sum:" ;
        if (cin >> v1 >> v2)
        cout << "Sum is: " << v1 + v2 << endl;
    } while (cin);
    ```
- It is illegal to initialize a variable inside a condition of the `do while`.
    ```cpp
        int ival
        do {
            // . . .
        } while (ival = get_response());
    ```
- A variable defined in the do while loop cannot be used by itself as condition.
    ```cpp
        do {
            int ival = get_response();
        } while (ival);
    ```

### [Exercise 5.19:](Exercise_19/Ex19.cpp)

*Write a program that uses a `do while` loop to repetitively request two strings from the user and report which string is less than the other.*

## 5.5.1. The break Statement

### [Exercise 5.20:](Exercise_20/Ex20.cpp) 

*Write a program to read a sequence of strings from the standard input until either the same word occurs twice in succession or all the words have been read. Use a while loop to read the text one word at a time. Use the break statement to terminate the loop if a word occurs twice in succession. Print the word if it occurs twice in succession, or else print a message saying that no word was repeated.*

## 5.5.2. The continue Statement

### [Exercise 5.21:](Exercise_21/Ex21.cpp) 

*Revise the program from the exercise in § 5.5.1 (p. 191) so that it looks only for duplicated words that start with an uppercase letter.*

## 5.5.3. The goto Statement

### Exercise 5.22: 

*The last example in this section that jumped back to begin could be better written using a loop. Rewrite the code to eliminate the goto.*

```cpp
begin:
    int sz = get_size();
    if (sz <= 0) {
        goto begin;
}
```

**Answer**

```cpp
int sz;
while ((sz = get_size()) <= 0) {}
```

## 5.6.3. Standard Exceptions


### [Exercise 5.23:](Exercise_23/Ex23.cpp) 

*Write a program that reads two integers from the standard input and prints the result of dividing the first number by the second.*

### [Exercise 5.24:](Exercise_24/Ex24.cpp) 

*Revise your program to throw an exception if the second number is zero. Test your program with a zero input to see what happens on your system if you don’t catch an exception.*

### [Exercise 5.25:](Exercise_25/Ex24.cpp) 

*Revise your program from the previous exercise to use a try block to catch the exception. The catch clause should print a message to the user and ask them to supply a new number and repeat the code inside
the try.*