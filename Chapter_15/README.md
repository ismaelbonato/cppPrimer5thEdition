### [Back to Chapter 14](../Chapter_14/README.md)

# Chapter 15. Object-Oriented Programming

### How to compile:

GCC 6.0+ or clang 3.3+

`g++ -Wall -Wextra -pedantic -std=c++11 target`

`clang++ -Wall -Wextra -pedantic -std=c++11 target`

## 15.2. Defining Base and Derived Classes

### Exercise 15.1: 

*What is a `virtual` member?*

**Answer**
- A `virtual` member is a function declared with the `virtual` keyword, this indicates that the function can be `overridden` in a derived class.
- An `overridden` function can be executed through a `base` class `reference` or `pointer`. That mechanism is called `Dynamic Binding` or `Runtime Polymorphism` , It is executed during runtime.

### Exercise 15.2: 

*How does the `protected` access specifier differ from `private`?*

**Answer**
- `Protected`: Members declared as protected are accessible within the class itself and by derived classes, but not from outside the class hierarchy.
- `Private`: Members declared as private are accessible only within the class itself, and not by derived classes or from outside the class.

### [Exercise 15.3:](Exercise_03/Ex03.cpp)

*Define your own versions of the `Quote` class and the `print_total` function.*


## 15.2.2. Defining a Derived Class

### Exercise 15.4: 

*Which of the following declarations, if any, are incorrect? Explain why.*

```cpp
class Base { ... };
(a) class Derived : public Derived { ... };
(b) class Derived : private Base { ... };
(c) class Derived : public Base;
```

**Answer**
- (a) It is incorrect, the base class must be defined before using to avoid self derivation.
- (b) It is correct.
- (c) It is incorrect, the derivation list must be defined in the derived definition, the declaration must not contain the derivation list.


### [Exercise 15.5:](Exercise_05/Ex05.cpp)

*Define your own version of the `Bulk_quote` class.*

### [Exercise 15.6:](Exercise_06/Ex06.cpp)

*Test your `print_total` function from the exercises in § 15.2.1 (p. 595) by passing both `Quote` and `Bulk_quote` objects o that function.*

### [Exercise 15.7:](Exercise_07/Ex07.cpp)

*Define a class that implements a limited discount strategy, which applies a discount to `books` purchased up to a given limit. If the number of copies exceeds that limit, the normal price applies to those purchased beyond the limit.*

## 15.2.3. Conversions and Inheritance

### Exercise 15.8: 

*Define `static type` and `dynamic type`.*

**Answer**
- `Static Type` is the type of a variable or expression defined in compilation time.
- `Dynamic type` is the type of a variable or expression as known at runtime.
- `Static Type` and `Dynamic Type` can differ in some cases like when the code in a derived class is executed through a base class reference or pointer, that mechanism is called `dynamic binding` `runtime polymorphism`.
- That difference in typing makes object-oriented programming and polymorphism possible in C++.

### Exercise 15.9: 

*When is it possible for an expression’s `static type` to differ from its `dynamic type`? Give three examples in which the `static` and `dynamic type` differ.*

**Answer**
- `Static Type` and `Dynamic Type` can differ only when the code in a derived class is executed through a base class reference or pointer, that mechanism is called `dynamic binding` of `runtime polymorphism`.
- That difference in typing makes object-oriented programming and polymorphism possible in C++.

```cpp
void function(const BaseClass &base) {}

DerivedClass derived;
BaseClass &baseRef = derived;
BaseClass *basePtr = &derived;

function(derived);
```

### Exercise 15.10: 

*Recalling the discussion from §8.1 (p. 311), explain how the program on page 317 that passed an `ifstream` to the `Sales_data` read function works.*

```cpp
std::istream &read(std::istream &inputStream, SalesData &item);
```

**Answer**
- The hierarchy of `std::ifstream.
```
// 
std::ifstream
   └── std::istream
         └── std::ios
               └── std::ios_base
```

- As the object `std::ifstream` is a derived class of `std::istream` there is no conversion, the base class can act like the derived class through `subtype polymorphism` (inheritance), the type of the object will be inferred at Runtime,this will enables polymorphic behavior. 

## 15.3. Virtual Functions

### [Exercise 15.11:](Exercise_11/Ex11.cpp)

*Add a `virtual` debug function to your `Quote` class hierarchy that displays the data members of the respective classes.*

### Exercise 15.12: 

*Is it ever useful to declare a member function as both `override` and `final`? Why or why not?*

**Answer**
- Declaring a member function as both override and final is useful when you want to ensure that you are correctly overriding a virtual function from a base class (override), and you also want to prevent any further derived classes from overriding this function (final).
- This is very helpful in library code, where you want to provide a specific implementation and prevent users from changing critical or sensitive behavior in further derived classes.

### Exercise 15.13: 

*Given the following classes, explain each print function:*

```cpp
class base {
public:
   string name() { return basename; }
   virtual void print(ostream &os) { os << basename; }
private:
   string basename;
};
class derived : public base {
public:
   void print(ostream &os) { print(os); os << " " << i; }
private:
   int i;
};
```
*If there is a problem in this code, how would you fix it?*

**Answer**
- `virtual void print(ostream &os) { os << basename;}`
    - Will print basename from base class.
- `void print(ostream &os) { print(os); os << " " << i;}`
    - There are two errors: the `override` qualifier is missing and the function print inside can cause infinite recursion. 

- Fixed version:
```cpp
class base {
public:
   string name() { return basename; }
   virtual void print(ostream &os) { os << basename; }
private:
   std::string basename;
};

class derived : public base {
public:
   void print(ostream &os) override {base::print(os); os << " " << i; }
private:
   int i;
};
```

### Exercise 15.14: 

*Given the classes from the previous exercise and the following objects, determine which function is called at run time:*

```cpp
base bobj;     base *bp1 = &bobj;   base &br1 = bobj;
derived dobj;  base *bp2 = &dobj;   base &br2 = dobj;

(a) bobj.print();
(b) dobj.print();
(c) bp1->name();
(d) bp2->name();
(e) br1.print();
(f) br2.print();
```

**Answer**
```cpp
(a) bobj.print(); // Base::print()
(b) dobj.print(); // Derived::print()
(c) bp1->name();  // Base::name()
(d) bp2->name();  // Base::name()
(e) br1.print();  // Base::print()
(f) br2.print();  // Derived::print()
```

## 15.4. Abstract Base Classes

### [Exercise 15.15:](Exercise_15/Ex15.cpp)

*Define your own versions of `Disc_quote` and `Bulk_quote`.*

### [Exercise 15.16:](Exercise_16/Ex16.cpp)

*Rewrite the class representing a `limited` discount strategy, which you wrote for the exercises in § 15.2.2 (p. 601), to `inherit` from `Disc_quote`.*

### [Exercise 15.17:](Exercise_17/Ex17.cpp)

*Try to define an object of type `Disc_quote` and see what errors you get from the compiler.

**Output**

```shell
Ex17.cpp:162:15: error: variable type 'DiscQuote' is an abstract class
  162 |     DiscQuote discount;
      |               ^
Ex17.cpp:40:12: note: unimplemented pure virtual method 'netPrice' in 'DiscQuote'
   40 |     double netPrice(const std::size_t copies) const = 0;
      |            ^
1 error generated.
```

## 15.5. Access Control and Inheritance

### Exercise 15.18: 

*Given the classes from page 612 and page 613, and assuming each object has the type specified in the comments, determine which of these assignments are legal. Explain why those that are illegal aren’t allowed:*

```cpp
Base *p = &d1;  //  d1 has type Pub_Derv
p = &d2;        //  d2 has type Priv_Derv
p = &d3;        //  d3 has type Prot_Derv
p = &dd1;       //  dd1 has type Derived_from_Public
p = &dd2;       //  dd2 has type Derived_from_Private
p = &dd3;       //  dd3 has type Derived_from_Protected
```

**Answer**

```cpp
Base *p = &d1;  //  Legal.
p = &d2;        //  Illegal, Derived-to-Base conversion is only permitted with public inheritance.
p = &d3;        //  Illegal, Derived-to-Base conversion is only permitted with public inheritance.
p = &dd1;       //  Legal.
p = &dd2;       // Illegal, Derived-to-Base conversion is only permitted with public inheritance. 
p = &dd3;       //  Illegal, Derived-to-Base conversion is only permitted with public inheritance. 
```

### Exercise 15.19: 

*Assume that each of the classes from page 612 and page 613 has a member function of the form:*

```cpp
void memfcn(Base &b) { b = *this; }
```

*For each class, determine whether this function would be legal.*

**Answer**
```cpp
class Base: // Legal
struct Pub_Derv: // Legal
struct Priv_Derv: // Legal
struct Prot_Derv: // Legal
struct Derived_from_Public: // Legal
struct Derived_from_Private: // Illegal, that class has no access to base because Priv_Derv class inherits base class privately.
struct Derived_from_Protected // Legal
```

### [Exercise 15.20:](Exercise_20/Ex20.cpp)

*Write code to test your answers to the previous two exercises.*

**Output**
- Exercise 15.18
    ```shell
    Ex20.cpp:74:9: error: cannot cast 'Priv_Derv' to its private base class 'Base'
    74 |     p = &d2;
        |         ^
    Ex20.cpp:39:20: note: declared private here
    39 | struct Priv_Derv : private Base
        |                    ^~~~~~~~~~~~
    Ex20.cpp:75:9: error: cannot cast 'Prot_Derv' to its protected base class 'Base'
    75 |     p = &d3;
        |         ^
    Ex20.cpp:44:20: note: declared protected here
    44 | struct Prot_Derv : protected Base
        |                    ^~~~~~~~~~~~~~
    Ex20.cpp:77:9: error: cannot cast 'Derived_from_Private' to its private base class 'Base'
    77 |     p = &dd2;
        |         ^
    Ex20.cpp:39:20: note: declared private here
    39 | struct Priv_Derv : private Base
        |                    ^~~~~~~~~~~~
    Ex20.cpp:78:9: error: cannot cast 'Derived_from_Protected' to its protected base class 'Base'
    78 |     p = &dd3;
        |         ^
    Ex20.cpp:44:20: note: declared protected here
    44 | struct Prot_Derv : protected Base
        |                    ^~~~~~~~~~~~~~
    ```

- Exercise 15.19
    ```shell
    Ex20.cpp:65:17: error: 'Base' is a private member of 'Base'
    65 |     void memfcn(Base &b) { b = *this; }
        |                 ^
    Ex20.cpp:43:20: note: constrained by private inheritance here
    43 | struct Priv_Derv : private Base
        |                    ^~~~~~~~~~~~
    Ex20.cpp:3:7: note: member is declared here
        3 | class Base
        |       ^
    Ex20.cpp:65:32: error: cannot cast 'const Derived_from_Private' to its private base class 'const Base'
    65 |     void memfcn(Base &b) { b = *this; }
        |                                ^
    Ex20.cpp:43:20: note: declared private here
    43 | struct Priv_Derv : private Base
        |                    ^~~~~~~~~~~~
    ```

### Exercise 15.21: 

*Choose one of the following general `abstractions` containing a family of `types` (or choose one of your own). Organize the types into an `inheritance hierarchy`:*

- (a) Graphical file formats (such as gif, tiff, jpeg, bmp)
- (b) Geometric primitives (such as box, circle, sphere, cone)
- (c) C++ language types (such as class, function, member function)

**Answer**

- Vehicles
```cpp

struct Vehicle {}

struct TerrainVehicle: public Vehicle {};

struct AirVehicle: public Vehicle {};

struct AquaticVehicle: public Vehicle {};

struct AquaticAircraft: public AirVehicle, public AquaticVehicle {};

struct Seaplanes: public AquaticAircraft {};
struct FloatPlanes: public AquaticAircraft {};

struct AirCraft: public AirVehicle, public TerrainVehicle {};

struct Car: public TerrainVehicle {};             
```

### Exercise 15.22: 

*For the class you chose in the previous exercise, identify some of the likely virtual functions as well as public and protected members.*

**Answer**

```cpp
struct Vehicle {
    std::string name();
    virtual int speed() const = 0;
    int name;

protected:
    int passengers;
    int horsePower;
};

struct TerrainVehicle: virtual public Vehicle {
      TerrainVehicle(const std::string& n, int hp, int pass, int tyres)
        : Vehicle(n, hp, pass), tyresAmount(tyres) {}
    int speed() const override { /* ... */ return 0; }

protected:
    int tyresAmount;
};

struct AirVehicle: virtual public Vehicle {
    int speed() const override;
protected:
    int wingAmount;
};

struct AquaticVehicle: virtual public Vehicle {
    int speed() const override;
protected:
float waterDisplacement;
    
};

struct AquaticAircraft: public AirVehicle, public AquaticVehicle {};

struct Seaplanes: public AquaticAircraft {};
struct FloatPlanes: public AquaticAircraft {};

struct AirCraft: public AirVehicle, public TerrainVehicle {};

struct Car : public TerrainVehicle {
    Car(const std::string& n, int hp, int pass, int tyres)
        : TerrainVehicle(n, hp, pass, tyres) {}
};
```

## 15.6. Class Scope under Inheritance

### Exercise 15.23: 

*Assuming class `D1` on page 620 had intended to `override` its inherited `fcn` function, how would you fix that class? Assuming you fixed the class so that `fcn` matched the definition in `Base`, how would the calls in that section be resolved?*

```cpp
class Base {
public:
    virtual int fcn();
};
class D1 : public Base {
public:
    // hides fcn in the base; this fcn is not virtual
    // D1 inherits the definition of Base::fcn()
    int fcn(int);      // parameter list differs from fcn in Base
    virtual void f2(); // new virtual function that does not exist in Base
};
class D2 : public D1 {
public:
    int fcn(int); // nonvirtual function hides base::fcn(int)
    int fcn();    // overrides virtual fcn from Base
    void f2();    // overrides virtual f2 from D1
};
```

**Answer**
- It is fixed just removing the `int` parameter of the function.
```cpp
class D1 : public Base {
public:
    int fcn() override;
    virtual void f2(); 
};
```

- The calls:
```cpp
cBase bobj; D1 d1obj; D2 d2obj;
Base *bp1 = &bobj, *bp2 = &d1obj, *bp3 = &d2obj;
bp1->fcn(); // virtual call, will call Base::fcn at run time
bp2->fcn(); // virtual call, will call D1::fcn at run time
bp3->fcn(); // virtual call, will call D2::fcn at run time
D1 *d1p = &d1obj; D2 *d2p = &d2obj;
bp2->f2(); // error: Base has no member named f2
d1p->f2(); // virtual call, will call D1::f2() at run time
d2p->f2(); // virtual call, will call D2::f2() at run time

Base *p1 = &d2obj; D1 *p2 = &d2obj; D2 *p3 =  &d2obj;
p1->fcn(42);  // error: Base has no version of fcn that takes an int
p2->fcn(42);  // error: Base has no version of fcn that takes an int
p3->fcn(42);  // statically bound, calls D2::fcn(int)
```

## 15.7.1. Virtual Destructors

### Exercise 15.24: 

*What kinds of classes need a virtual destructor? What operations must a virtual destructor perform?*

**Answer**
- All base classes must have a virtual destructor for two reasons.
- To make sure that a derived class can replace the destructor to manage objects that are dynamically allocated.
- To make sure the right destructor is called when the derived class is called in runtime through a base class reference or pointer, if the destructor is not virtual the behavior is undefined.

## 15.7.2. Synthesized Copy Control and Inheritance

### Exercise 15.25: 

*Why did we define a default `constructor` for `Disc_quote`? What effect, if any, would removing that `constructor` have on the behavior of `Bulk_quote`?*

**Answer**
- The default constructor allow the user to create an object of a derived class with no arguments, it will work as the defined constructor, but all static object will be default initialized.
- When the class provide a constructor with more than one argument, the default constructor is not synthesized, it will rise an error since it disrupt the chain of default construction in the hierarchy.

## 15.7.3. Derived-Class Copy-Control Members

### [Exercise 15.26:](Exercise_26/Ex26.cpp)

*Define the `Quote` and `Bulk_quote` `copy-control` members to do the same job as the `synthesized` versions. Give them and the other `constructors` print statements that identify which function is running. Write programs using these classes and predict what objects will be created and destroyed. Compare your predictions with the output and continue experimenting until your predictions are reliably correct.*

## 15.7.4. Inherited Constructors

### [Exercise 15.27:](Exercise_27/Ex27.cpp)

*Redefine your `Bulk_quote` class to inherit its `constructors`.*

## 15.8. Containers and Inheritance

### [Exercise 15.28:](Exercise_28/Ex28.cpp)

*Define a vector to hold `Quote` objects but put `Bulk_quote` objects into that vector. Compute the total `net_price` of all the elements in the vector.*

### [Exercise 15.29:](Exercise_29/Ex29.cpp)

*Repeat your program, but this time store `shared_ptrs` to objects of type `Quote`. Explain any discrepancy in the sum generated by the this version and the previous program. If there is no discrepancy, explain why there isn’t one.*

**Answer**
- The discrepancy is due to how `std::vector<Quote>` works, it makes a copy of the object, it does not create a reference or a pointer, this way, the call to `net_price` is defined at Compile time. In order to use `subtype polymorphism` the `vector` must be a `vector` of references or pointers, in this case using `shared_ptr` is safer.   

## 15.8.1. Writing a Basket Class

### [Exercise 15.30:](Exercise_30/Ex30.cpp) 

*Write your own version of the `Basket` class and use it to compute prices for the same transactions as you used in the previous exercises.*

## 15.9.1. An Object-Oriented Solution

### Exercise 15.31:

*Given that `s1`, `s2`, `s3`, and `s4` are all strings, determine what objects are created in the following expressions:*

```cpp
(a) Query(s1) | Query(s2) & ~Query(s3);
(b) Query(s1) | (Query(s2) & ~Query(s3));
(c) (Query(s1) & (Query(s2)) | (Query(s3) & Query(s4)));
```

**Answer**

```cpp
(a) OrQuery(
        WordQuery(s1), 
        WordQuery(
            AndQuery(
                WordQuery(s2), 
                NotQuery(WordQuery(s3))
            )
        )
    )

(b) OrQuery(
        WordQuery(s1), 
        WordQuery(
            AndQuery(
                WordQuery(s2), 
                NotQuery(WordQuery(s3))
            )
        )
    )

(c) OrQuery(
        AndQuery(
            WordQuery(s1), 
            WordQuery(s2)), 
        WordQuery(
            AndQuery(
                WordQuery(s3), 
                WordQuery(s4))
        )
    )

```

## 15.9.2. The Query_base and Query Classes

### Exercise 15.32:

*What happens when an object of type `Query` is copied, moved, assigned, and destroyed?*

**Answer**
- `Copy`: All the member objects are copied. The `shared_ptr` share the ownership between the the original and copied version as `shared_ptr` has the pointer like behavior.
- `Move`:  All the member objects will be moved. The ownership of the `shared_ptr` will be moved to the new owner and the old object will be kept in an valid state waiting to be destroyed.
- `Assign`: All the member objects will be assigned. The left hand `shared_ptr` will release the ownership of the actual value to receive the ownership of the right hand operator, as `shared_ptr` has the pointer like behavior.
- `Destruction`: It will destruct all objects `bult-in` and all destructor of the class type will be called. The `shared_ptr` will be decremented by 1 once it will have the ownership removed. 

### Exercise 15.33:

*What about objects of type `Query_base`?*

**Answer**
- The `Query_base` class cannot be constructed directly. It is an abstract class that can only be constructed through derived classes. In this case, only derived classes can be `destructed`, `copied`, `moved`, and `assigned`, especially when it is through an `Query_base` reference or pointer. This is known as `subtype polymorphism`.

