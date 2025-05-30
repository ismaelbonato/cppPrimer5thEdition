#include <iostream>
#include <vector>

class NoDefaultConstructor {
public:
    // Constructor that requires an argument
    explicit NoDefaultConstructor(const int value) : data(value) {}

    // Method to display the value
    void display() const {
        std::cout << "Value: " << data << std::endl;
    }

private:
    int data;
};

//template class std::vector<NoDefaultConstructor>;

int main() {
    // Create an instance of the class with an argument
    
    NoDefaultConstructor noDefault(5);

    std::vector<NoDefaultConstructor> x(1, noDefault);

    return 0;
}