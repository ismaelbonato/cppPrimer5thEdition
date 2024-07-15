#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <ostream>

int main(int argc, char *argv[]) {

    if (argc != 4) {
        std::cerr << "error" << std::endl;
        exit(-1);
    } 

    std::ifstream is(argv[1]);
    std::ofstream osOdd(argv[2]), osEven(argv[3]);

    std::istream_iterator<int> numIter(is), eof;
    std::ostream_iterator<int> outOddIter(osOdd, " ");
    std::ostream_iterator<int> outEvenIter(osEven, "\n");

    std::for_each(numIter, eof, 
                        [&outOddIter, &outEvenIter]
                        (const int &i)
                        { (i % 2) ? (outEvenIter = i) :  (outOddIter = i); });     

    return 0;
}