#include <iostream>
#include <string>

// return the plural version of word if ctr is greater than 1
std::string make_plural(size_t ctr, 
                    const std::string &word, 
                    const std::string &ending = "s")
{
    return (ctr > 1) ? word + ending : word;
}

int main ()
{   
    std::cout << "Singular: " << make_plural(1, "success", "es") << std::endl;
    std::cout << "Plural: "  << make_plural(2, "success", "es") << std::endl;
    std::cout << "Singular: " <<  make_plural(1, "failure", "s") << std::endl;
    std::cout << "Plural: "  << make_plural(2, "failure", "s") << std::endl;

    return 0;
}