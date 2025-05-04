#include <vector>
#include <algorithm>
#include <iostream>

class Foo
{
public:
    Foo sorted() &&;
    Foo sorted() const &; // may run on any kind of Foo
    // other members of Foo
private:
    std::vector<int> data;
};
// this object is an rvalue, so we can sort in place
Foo Foo::sorted() &&
{
    sort(data.begin(), data.end());
    std::cout << "Foo::sorted() &&" << std::endl;
    return *this;
}
// this object is either const or it is an lvalue; either way we can't sort in place
/*Foo Foo::sorted() const &
{
    std::cout << "Foo::sorted() const &" << std::endl;
    Foo ret(*this);
    sort(ret.data.begin(), ret.data.end()); // sort the copy
    return ret;
}
*/
/*
// Exercise 13.56
Foo Foo::sorted() const & {
    std::cout << "Foo::sorted() const &" << std::endl;
    Foo ret(*this);
    return ret.sorted();
}
*/

// Exercise 13.57
Foo Foo::sorted() const & 
{ 
    std::cout << "Foo::sorted() const &" << std::endl;
    return Foo(*this).sorted(); 
}

int main()
{
    Foo foo;
    foo.sorted();

    Foo(foo).sorted();

    return 0;
}