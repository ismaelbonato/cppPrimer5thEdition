#include <memory>
#include <iostream>
#include <string>

class DebugDelete
{
public:
    DebugDelete(std::ostream &os = std::cerr)
        : out(os)
    {}

    template<typename T>
    inline void operator()(T *p) const 
    {
        out << "deleting the object:" << std::endl;
        delete(p);
    }

private:
    std::ostream &out;
};

int main()
{
    std::unique_ptr<std::string, DebugDelete> us(new std::string(), DebugDelete());

    return 0;
}