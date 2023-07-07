#include <iostream>


unsigned int counterFunction()
{
    static int counter = 0;

    return counter++;
}

int main ()
{
    std::cout << counterFunction() << std::endl;
    std::cout << counterFunction() << std::endl;
    std::cout << counterFunction() << std::endl;
    std::cout << counterFunction() << std::endl;
    std::cout << counterFunction() << std::endl;
    std::cout << counterFunction() << std::endl;
    std::cout << counterFunction() << std::endl;
    std::cout << counterFunction() << std::endl;
    std::cout << counterFunction() << std::endl;
    std::cout << counterFunction() << std::endl;

    return 0;
}