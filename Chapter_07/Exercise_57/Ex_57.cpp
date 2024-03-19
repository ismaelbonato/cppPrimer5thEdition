#include <string>
#include <iostream>

class Account {
public:
    void calculate() { amount += amount * interestRate; }
    static double getRate() { return interestRate; }
    static void setRate(double newRate) {interestRate = newRate;};
private:
    std::string owner;
    double amount;
    static double interestRate;
    static double initRate() {return 10;};
};

double Account::interestRate = initRate();

int main()
{
    Account account;

    std::cout << "the interest rate is " << Account::getRate() << "%" << std::endl;

    Account::setRate(20);
    
    std::cout << "the interest rate is " << Account::getRate() << "%" << std::endl;


    return 0;
}