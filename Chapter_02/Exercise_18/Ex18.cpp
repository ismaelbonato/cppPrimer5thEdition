#include <iostream>

int main() {

    int obj = 1, obj2 = 2, *pObj = nullptr, *pObj2 = nullptr, *pTmp = nullptr;

    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "pObj: " << pObj << " pObj2: " << pObj2 << std::endl;
    std::cout << "obj: " << obj << " obj2: " << obj2 << std::endl;

    pObj  = &obj;
    pObj2 = &obj2;

    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "pObj: " << pObj << " pObj2: " << pObj2 << std::endl;
    std::cout << "obj: " << obj << " obj2: " << obj2 << std::endl;

    pTmp = pObj;

    pObj = pObj2;
    pObj2 = pTmp;

    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "pObj: " << pObj << " pObj2: " << pObj2 << std::endl;
    std::cout << "*pObj: " << *pObj << " *pObj2: " << *pObj2 << std::endl;
    std::cout << "obj: " << obj << " obj2: " << obj2 << std::endl;

    *pObj = obj2;
    *pObj2 = obj;

    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "pObj: " << pObj << " pObj2: " << pObj2 << std::endl;
    std::cout << "*pObj: " << *pObj << " *pObj2: " << *pObj2 << std::endl;
    std::cout << "obj: " << obj << " obj2: " << obj2 << std::endl;
    return 0;
}
