#include <algorithm>
#include <fstream>
#include <iostream>
#include <istream>
#include <string>
#include <vector>
#include <iterator>

int main ()
{
    std::ifstream in("input");
    std::istream_iterator<std::string> str_it(in);
    std::istream_iterator<std::string> eof; 
    
    std::vector<std::string> sVec(str_it, eof);
    
    std::for_each(sVec.begin(), sVec.end(), 
                                [] 
                                (const std::string &s) 
                                {std::cout << s << std::endl;});           
                                
    return 0;
}