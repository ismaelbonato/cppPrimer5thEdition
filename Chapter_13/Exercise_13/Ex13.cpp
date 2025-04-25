#include <iostream>
#include <vector>
#include <string>

struct X {
    X() {std::cout << "X()" << std::endl;};
    X(const X&) {
        std::cout << "X(const X&)" << std::endl;
    };
    ~X() {std::cout << "~X()" << std::endl;};

    X& operator=(const X&) {
        std::cout << "X& operator=(const X&)" << std::endl;
        return *this;
    };
};  

void byReference(X &x) 
{
    std::cout << "byReference" << std::endl;
}

void byValue(X x) 
{
    std::cout << "byValue" << std::endl;
}


int main() {
    {
        X x1;
        std::cout << "Pass them as reference" << std::endl;
        byReference(x1);
        std::cout << "Pass them as non reference" << std::endl;
        byValue(x1);
        std::cout << "Out of the scope" << std::endl;
    }
    
    {
        std::cout << "dynamically allocate them" << std::endl;
        X *x2 = new X;

        std::vector<X> vec;
        vec.reserve(3);
        std::cout << "put them in containers" << std::endl;

        vec.push_back(*x2);
        vec.push_back(*x2);
        vec.push_back(*x2);

        delete x2;
        std::cout << "Out of the scope" << std::endl;
    }

    { 
        std::cout << "Definition" << std::endl;
        X x1;
        X x2 = x1;

        std::cout << "Assignment" << std::endl;

        x1 = x2;
        std::cout << "Out of the scope" << std::endl;
    }

    {
        std::cout << "Definition" << std::endl;
        X *x1 = new X;
        X *x2 = new X(*x1);

        std::cout << "Assignment" << std::endl;

        *x1 = *x2;
        delete x1;
        delete x2;
        std::cout << "Out of the scope" << std::endl;
    }

    {
        std::cout << "call byValue" << std::endl;
        byValue(X());

        std::cout << "Out of the scope" << std::endl;

    }
 
    return 0;
}


