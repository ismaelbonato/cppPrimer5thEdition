
### [Back to Chapter 11](../Chapter_11/README.md)

# Chapter 12. Dynamic Memory

### How to compile:

GCC 6.0+ or clang 3.3+

`g++ -std=c++11 app_name.cpp -o target`

`clang++ -std=c++11 app_name.cpp -o target`

## 12.1.1. The shared_ptr Class

### Exercise 12.1: 

*How many elements do b1 and b2 have at the end of this code?*
```cpp
StrBlob b1;
{
StrBlob b2 = {"a", "an", "the"};
b1 = b2;
b2.push_back("about");
}
```

### Exercise 12.2: 

*Write your own version of the StrBlob class including the const versions of front and back.*

### Exercise 12.3: 

*Does this class need const versions of push_back and pop_back? If so, add them. If not, why aren’t they needed?*

### Exercise 12.4: 

*In our check function we didn’t check whether i was greater than zero. Why is it okay to omit that check?*

### Exercise 12.5: 

*We did not make the constructor that takes an initializer_list explicit (§ 7.5.4, p. 296). Discuss the pros and cons of this design choice.*




----------------------------
### [Back to Chapter 11](../Chapter_11/README.md) - [Next to Chapter 13](../Chapter_13/README.md)