### [Back to Chapter 12](../Chapter_12/README.md)

# Chapter 13. Copy Control

### How to compile:

GCC 6.0+ or clang 3.3+

`g++ -Wall -Wextra -pedantic -std=c++11 target`

`clang++ -Wall -Wextra -pedantic -std=c++11 target`


## 13.1.1. The Copy Constructor

### Exercise 13.1: 

*What is a copy constructor? When is it used?*

**Answer**

- A copy constructor is a special constructor in C++ that initializes a new object as a copy of an existing object. It takes a reference to a const object of the same type as its parameter.
- It is used in scenarios such as:
  - When an object is passed by value to a function.
  - When an object is returned by value from a function.
  - When an object is explicitly copied using the assignment operator or copy initialization.


### Exercise 13.2: 

*Explain why the following declaration is illegal:*

```cpp
Sales_data::Sales_data(Sales_data rhs);
```
**Answer**
- This is a copy constructor declaration, but there is an error in the declaration that it leads to a recursive loop function call.
- To facilitate understanding, it is advisable to show each step in the process.
    - The copy constructor is called. 
    - The constructor make a copy of the object.
    - In order to make a copy the copy constructor is called.
    - The constructor make a copy of the object.
    - In order to make a copy the copy constructor is called.
    - It leads to a recursive loop never ending.


- To solve that problem, the only way to create a copy constructor in `c++` is using as parameter a reference.
    ```cpp
    Sales_data::Sales_data(Sales_data &rhs);
    ```

### Exercise 13.3:

*What happens when we copy a `StrBlob`? What about `StrBlobPtrs`?*

**Answer**
- The copied version of `StrBlob` will share the ownership of `shared_ptr` and will have the internal counter added by one.
- The copied version of `StrBlobPtrs` as a helper class will return a `shared_ptr` as a `weak_ptr`. Since `weak_ptr` does not own the object, it will not increment the reference count of the shared_ptr.. However, it will continue to point to the `shared_ptr` in the copied version of `StrBlob` because they share ownership.

### Exercise 13.4:

*Assuming Point is a class type with a public copy constructor, identify each use of the copy constructor in this program fragment:*

```cpp
Point global;
Point foo_bar(Point arg)
{
    Point local = arg, 
    Point *heap = new Point(global);
    *heap = local;
    Point pa[ 4 ] = { local, *heap };
    return *heap;
}
```

**Answer**

```cpp
Point global;
Point foo_bar(Point arg) // arg will be copied.
{
    Point local = arg; // Copy
    Point *heap = new Point(global);// global will be copied in the Point constructor and the result as a `rvalue` will be assigned.

    *heap = local; // assign
    Point pa[ 4 ] = { local, *heap }; // copy of local and *heap
    return *heap; //copy of local and *heap
}
```

### Exercise 13.5: 

*Given the following sketch of a class, write a copy constructor that copies all the members. Your constructor should dynamically allocate a new `string` (§ 12.1.2, p. 458) and copy the object to which `ps` points, rather than copying ps itself.*

```cpp
class HasPtr {
public:
    HasPtr(const std::string &s = std::string()):
        ps(new std::string(s)), i(0) { }
private:
    std::string *ps;
    int    i;
};
```

**Answer**

```cpp
HasPtr::HasPtr(const HasPtr &origin) : 
                i(origin.i), 
                ps(new std::string(*(origin.ps))) {};
```

## 13.1.2. The Copy-Assignment Operator

### Exercise 13.6: 

*What is a copy-assignment operator? When is this operator used? What does the synthesized copy-assignment operator do? When is it synthesized?*

**Answer**

*What is a copy-assignment operator?*
- It is the c++ operator `=`, it is used to copy objects of the same type, from the right-hand side to the left-hand side.

*When is this operator used?*
- It is used when the assignment operator `=` is used

*What does the synthesized copy-assignment operator do?*
- It is an operator defined by the compiler when the a overloaded version of the operator is not explicitly defined by the developer.

*When is it synthesized?*
- It is synthesized in the compile time.

### Exercise 13.7: 

*What happens when we assign one `StrBlob` to another? What about `StrBlobPtrs`?*

**Answer**
- It will create a copy of the `StrBlob`, but as long it uses `shared_ptr`, both `StrBlob` objects will share the ownership.
- For `StrBlobPtrs`, which uses `weak_ptr`, it does not share the ownership of the `shared_ptr` in `StrBlob`, the `weak_ptr` will point to the new `StrBlob` created, as a result, the `weak_ptr` will point to the `share_ptr` shared by both of `StrBlob` objects.

### Exercise 13.8: 

*Write the assignment operator for the HasPtr class from exercise 13.5 in § 13.1.1 (p. 499). As with the copy constructor, your assignment operator should copy the object to which ps points.*

```cpp
class HasPtr {
public:
    HasPtr(const std::string &s = std::string()):
        ps(new std::string(s)), i(0) { }
private:
    std::string *ps;
    int    i;
};
```

**Answer**
```cpp
class HasPtr {
public:
    HasPtr(const std::string &s = std::string()):
        ps(new std::string(s)), i(0) { }

    HasPtr(const HasPtr &origin) : i(origin.i), ps(new std::string(*(origin.ps))) {};

    HasPtr& operator=(const HasPtr& origin) {
        if (this == &origin) {
            return *this;  // Handle self-assignment by 
        }
        
        i = origin.i;
        
        delete(ps);
        ps = new std::string(*(origin.ps));    

        return *this;
    };

private:
    std::string *ps;
    int    i;
};
``` 

## 13.1.3. The Destructor

### Exercise 13.9: 

*What is a destructor? What does the synthesized destructor do? When is a destructor synthesized?*

**Answer**

*What is a destructor?*
- A destructor is a special type of member function that is responsible for destroying the object. It is called when using the `delete` keyword or when the object goes out of scope.  

*What does the synthesized destructor do?*
- The primary responsibility of a destructor is to free all resources used by an object and to destroy all `non-static` members. Please note that the synthesized destructor does not release objects dynamically created using `raw pointers`; a destructor must be defined for that.

*When is a destructor synthesized?*
- The process of synthesis occurs during compile time.

### Exercise 13.10: 

*What happens when a `StrBlob` object is destroyed? What about a `StrBlobPtr`?*

**Answer**
- When the StrBlob function exits the scope, it releases all `non-static` resources and reduces all shared_ptr count references by one.
Similarly, when `StrBlobPtr` goes out of scope, all `non-static` objects will be released, along with the `weak_ptr` objects, as it does not own the pointer.  

### Exercise 13.11: 

*Add a destructor to your `HasPtr` class from the previous exercises.*

**Answer**

```cpp
class HasPtr {
public:
    HasPtr(const std::string &s = std::string()):
        ps(new std::string(s)), i(0) {};
    ~HasPtr() {delete ps};
private:
    std::string *ps;
    int    i;
};
```

### Exercise 13.12: 

*How many destructor calls occur in the following code fragment?*

```cpp
bool fcn(const Sales_data *trans, Sales_data accum)
{
    Sales_data item1(*trans), item2(accum);
    return item1.isbn() != item2.isbn();
}
```

**Answer**
- 3 Destructors are called in the fragment:  `accum`, `item1` and `item2`.

### [Exercise 13.13:](Exercise_13/Ex13.cpp) 

*A good way to understand `copy-control` members and `constructors` is to define a simple class with these members in which each member prints its name:*

```cpp
struct X {
    X() {std::cout << "X()" << std::endl;}
    X(const X&) {
        std::cout << "X(const X&)" << std::endl;
    }
};
```

*Add the `copy-assignment` operator and destructor to `X` and write a program using `X` objects in various ways: Pass them as non reference and reference parameters; dynamically allocate them; put them in containers; and so forth. Study the output until you are certain you understand when and why each `copy-control` member is used. As you read the output, remember that the compiler can omit calls to the copy constructor.*

## 13.1.4. The Rule of Three/Five

### Exercise 13.14:

*Assume that numbered is a class with a default constructor that generates a unique serial number for each object, which is stored in a data member named `mysn`. Assuming numbered uses the synthesized `copy-control` members and given the following function:*

```cpp
void f (numbered s) { cout << s.mysn << endl; }
```
what output does the following code produce?

```cpp
numbered a, b = a, c = b;
f(a); f(b); f(c);
```

**Answer**
- The output for all function will be the same, the synthesized `copy-control` will copy the serial number.
- 

### Exercise 13.15: 

*Assume numbered has a copy constructor that generates a new serial number. Does that change the output of the calls in the previous exercise? If so, why? What output gets generated?*

**Answer**
-  Assuming that a `Numbered` object has a explicit copy constructor, each time the function `f` is called, the output will be different, the numbered object has to be passed by reference to avoid that behavior.

```cpp
void f (const numbered &s) { cout << s.mysn << endl; }
```

### Exercise 13.16: 

*What if the parameter in f were const numbered&? Does that change the output? If so, why? What output gets generated?*

**Answer**
- In the case when a `Numbered` object is passed by reference, the copy constructor is not called. In such cases, the correct serial number will be printed.

### [Exercise 13.17:](Exercise_17/Ex17.cpp) 

*Write versions of `numbered` and `f` corresponding to the previous three exercises and check whether you correctly predicted the output.*

**Answer**
- It worked as predicted.

## 13.1.6. Preventing Copies

### [Exercise 13.18:](Exercise_18/Ex18.cpp) 

*Define an `Employee class` that contains an employee name and a unique employee identifier. Give the class a `default constructor` and a `constructor` that takes a string representing the employee’s name. Each constructor should generate a unique ID by incrementing a `static data` member.*

### [Exercise 13.19:](Exercise_19/Ex19.cpp) 

*Does your `Employee class` need to define its own versions of the `copy-control` members? If so, why? If not, why not? Implement whatever `copy-control` members you think Employee needs.*

**Answer**
- To maintain the Unique ID Requirement, a `copy-control` and a `copy-operator` must be implemented.

### Exercise 13.20: 

*Explain what happens when we `copy`, `assign`, or `destroy` objects of our `TextQuery` and `QueryResult` classes from § 12.3 (p. 484).*

**Answer**
- When `copying` or `assigning` the new copy will share the ownership of some internal data from the original object who uses `shared_ptr`.
- Destroying a copied object of both classes will decrement the `shared_ptr` counter which is safer than using raw pointers.
- By sharing the ownership of the data, if a copy changes the the data, the data will be change in all instances.

### Exercise 13.21: 

*Do you think the `TextQuery` and `QueryResult` classes need to define their own versions of the `copy-control` members? If so, why? If not, why not? Implement whichever `copy-control` operations you think these classes require.*

**Answer**
- Because `QueryResult` is the result of the process, it does not require a copy control.Typically, `QueryResult` is a const object.
- As `TextQuery` reads the file in the constructor, it is not possible to change the internal data. Therefore, a `copy-control` is not necessary.


## 13.2. Copy Control and Resource Management

### Exercise 13.22:

*Assume that we want `HasPtr` to behave like a value. That is, each object should have its own copy of the string to which the objects point. We’ll show the definitions of the `copy-control` members in the next section. However, you already know everything you need to know to implement these members. Write the `HasPtr` copy constructor and `copy-assignment operator` before reading on.*

**Answer**

```cpp
class HasPtr {
public:
    HasPtr(const std::string &s = std::string()):
        ps(new std::string(s)), i(0) { }

    ~HasPtr() {delete ps;};

    HasPtr(const HasPtr &origin) : i(origin.i), ps(new std::string(*(origin.ps))) {};

    HasPtr& operator=(const HasPtr& origin) {
        if (this == &origin) {
            return *this;  // Handle self-assignment by 
        }

        i = origin.i;

        delete(ps);
        ps = new std::string(*(origin.ps));    

        return *this;
    };

private:
    std::string *ps;
    int i;
};
```

## 13.2.1. Classes That Act Like Values

### Exercise 13.23: 

*Compare the `copy-control` members that you wrote for the solutions to the previous section’s exercises to the code presented here. Be sure you understand the differences, if any, between your code and ours.*

### Exercise 13.24: 

*What would happen if the version of `HasPtr` in this section didn’t define a destructor? What if `HasPtr` didn’t define the copy constructor?*

**Answer**
- If not defined a `destructor` for `HasPtr` a memory leak will occurs when the object is deleted or goes out of scope.
- Without a `copy constructor` to properly address the raw pointer copy, the pointer `ps` will be copied, resulting in the sharing of data between the original and the copy,  In the event that either one is deleted, the pointer to `ps` will be a `dangling pointer`.

### Exercise 13.25: 

*Assume we want to define a version of `StrBlob` that acts like a value. Also assume that we want to continue to use a `shared_ptr` so that our `StrBlobPtr` class can still use a `weak_ptr` to the `vector`. Your revised class will need a `copy-constructor` and `copy-assignment operator` but will not need a `destructor`. Explain what the `copy constructor` and `copy-assignment operators` must do. Explain why the class does not need a `destructor`.*

**Answer**

- The `copy constructor` and `copy-assignment operators` will ensure that the new copies will not share the `shared_ptr` data members. Each copied version will have its own version of the data.

- The class does not require a `destructor` because it does not use `raw pointers`. The use of smart pointers will suffice.

### [Exercise 13.26:](Exercise_26/Ex26.cpp)

*Write your own version of the `StrBlob` class described in the previous exercise.*

## 13.2.2. Defining Classes That Act Like Pointers

### [Exercise 13.27:](Exercise_27/Ex27.cpp) 

*Define your own reference-counted version of `HasPtr`.*

### [Exercise 13.28:](Exercise_28/Ex28.cpp) 

*Given the following classes, implement a `default constructor` and the necessary `copy-control` members.*

```cpp
(a)
class TreeNode {
private:
    std::string value;
    int         count;
    TreeNode    *left;
    TreeNode    *right;
};
```

```cpp
(b)
class BinStrTree {
private:
    TreeNode *root;
};
```

## 13.3. Swap

### Exercise 13.29: 

*Explain why the calls to `swap` inside `swap(HasPtr&, HasPtr&)` do not cause a recursion loop.*

**Answer**
- The reason for this is that `swap` is an in-line function. In the event of such an occurrence, the compiler will replace the `swap` function call with the code contained within it. As can be observed, the replaced code has an `explicit` Call to `std::swap`, then the `swap(lhs.ps, rhs.ps)` invokes the `string swap` function, while the subsequent `swap(lhs.i, rhs.i)` call, the `int swap` function.

### [Exercise 13.30:](Exercise_30/Ex30.cpp) 

*Write and test a `swap` function for your `valuelike` version of `HasPtr`. Give your `swap` a print statement that notes when it is executed.*

### [Exercise 13.31:](Exercise_31/Ex31.cpp) 

*Give your class a `< operator` and define a `vector` of `HasPtrs`. Give that vector some elements and then sort the `vector`. Note when `swap` is called.*

### Exercise 13.32: 

*Would the `pointerlike` version of `HasPtr` benefit from defining a `swap` function? If so, what is the benefit? If not, why not?*

**Answer**
- The `pointerlike` version will not benefit from the `swap` function because as it has a `pointer string ps` it can use the built-in type `swap` function.


## 13.4. A Copy-Control Example

### Exercise 13.33: 

*Why is the parameter to the `save` and `remove` members of `Message` a `Folder&`? Why didn’t we define that parameter as `Folder`? Or `const Folder&?`*

**Answer**
- The purpose of these functions is to add or delete a `pointer` reference in a `list` of `pointers`.
The parameter is passed by reference to prevent the creation of a local copy. If it were passed by `value`, any changes made to a local copy of the folder would not affect the original.
The contents of the `folder` are subject to change within the function. It is imperative that the `folder` be defined as `non-const`.

### [Exercise 13.34:](Exercise_34/Ex34.cpp) 

*Write the Message class as described in this section.*

### Exercise 13.35: 

*What would happen if Message used the synthesized versions of the `copy-control` members?*

**Answer**
- A bunch of Folder will be out of sync.
- Memory Management issues due to out of sync list of objects.

### [Exercise 13.36:](Exercise_36/Ex36.cpp)

*Design and implement the corresponding `Folder` class. That class should hold a set that points to the Messages in that `Folder`.*

### [Exercise 13.37:](Exercise_37/Ex37.cpp)

*Add members to the Message `class` to `insert` or `remove` a given `Folder*` into folders. These members are analogous to `Folder’s` `addMsg` and `remMsg` operations.*

### Exercise 13.38: 

*We did not use `copy` and `swap` to define the `Message assignment operator`. Why do you suppose this is so?*

**Answer**
- `Copy` and `swap` would bring only performance penalties, since the de left hand data can be overwritten, there is no need to create a temporary object or even remove `folders` from `rhs` and insert `this` to `Folders`.

## 13.5. Classes That Manage Dynamic Memory

### [Exercise 13.39:](Exercise_39/Ex39.cpp)

*Write your own version of `StrVec`, including versions of `reserve`, `capacity` (§ 9.4, p. 356), and `resize` (§ 9.3.5, p. 352).*

### [Exercise 13.40:](Exercise_40/Ex40.cpp)

*Add a `constructor` that takes an `initializer_list<string> `to your `StrVec` class.*

### Exercise 13.41: 

*Why did we use `postfix` increment in the call to construct inside `push_back`? What would happen if it used the `prefix` increment?*

**Answer**
- The `push_bach` function changes the data, the internal pointer pointing to the past of the last added `string` must be updated.

### [Exercise 13.42:](Exercise_42/Ex42.cpp)

*Test your `StrVec` class by using it in place of the `vector<string>` in your `TextQuery` and `QueryResult` classes (§ 12.3,p. 484).*

### [Exercise 13.43:](Exercise_43/Ex43.cpp)

*Rewrite the `free` member to use `for_each` and a `lambda` (§ 10.3.2, p. 388) in place of the for loop to destroy the elements. Which implementation do you prefer, and why?*

**Answer**
- I prefer the `std::for_each` version because it is more modern. Using `reverse_iterator` eliminates the possibility of manually decrementing, which can lead to bugs.

### [Exercise 13.44:](Exercise_44/Ex44.cpp)

*Write a class named `String` that is a simplified version of the library `string` class. Your class should have at least a default `constructor` and a `constructor` that takes a pointer to a `C-style string`. Use an `allocator` to allocate memory that your `String class` uses.*