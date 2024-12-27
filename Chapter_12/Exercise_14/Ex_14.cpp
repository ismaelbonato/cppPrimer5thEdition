
#include <exception>
#include <iostream>
#include <memory>

struct connection{};
struct destination{};

connection* connect(destination &d)
{
    return new connection;
}

void endConnection(connection *c)
{
    std::cout << "Disconnected" << std::endl;
    delete c;
}

void f(destination &d)
{
    try {
        connection *c = connect(d);
        //std::shared_ptr<connection> sp(c, endConnection);
        
        throw std::invalid_argument("exception");
        
        endConnection(c);
    } catch (...) {

    }
}

int main()
{
    destination d;

    f(d);

    return 0;
}