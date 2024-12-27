#include <memory>
int main()
{
    std::unique_ptr<int> u1(new int());
    std::unique_ptr<int> u2(new int());

    return 0;
}