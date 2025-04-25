#include <iostream>
#include <string>
#include <vector>
#include <random>

class Numbered
{
private:
    int generateRandomNumber() {
        static std::mt19937 gen(std::random_device{}()); 
        static std::uniform_int_distribution<> distrib(1, 10000);
        return distrib(gen);
    }
public:
    int mysn;
    
    Numbered() : mysn(generateRandomNumber()) {
        std::cout << "Default constructor called. mysn: " << mysn << std::endl;
    };

    Numbered(const Numbered &n) : mysn(generateRandomNumber()) {
        std::cout << "Copy constructor called. mysn: " << mysn << std::endl;
    };
};

void f (Numbered s) 
{ 
    std::cout << s.mysn << std::endl; 
}

void fRef (const Numbered &s) 
{ 
    std::cout << s.mysn << std::endl; 
}


int main()
{
    {
        Numbered a, b = a, c = b;
        std::cout << "-------------------- f() non reference " << std::endl;
        f(a); f(b); f(c);
        std::cout << "------------------------" << std::endl;
    }

    {
        Numbered a, b = a, c = b;
        std::cout << "--------------------- fRef() reference" << std::endl;
        fRef(a); fRef(b); fRef(c);
        std::cout << "------------------------" << std::endl;
    }

    return 0;
}