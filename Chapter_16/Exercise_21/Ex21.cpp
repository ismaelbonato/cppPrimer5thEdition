#include <iostream>

class DebugDelete
{
public:
    DebugDelete(std::ostream &os = std::cerr)
        : out(os)
    {}

    template<typename T>
    void operator()(T *p)
    {
        out << "deleting the object:" << std::endl;
        delete(p);
    }

private:
    std::ostream &out;
};


int main()
{
    std::string *s{new std::string()};

    DebugDelete()(s);


    return 0;
}