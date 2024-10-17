#include <functional>
#include <iostream>
#include "Sales_item.h"
#include <iterator>
#include <set>
#include <vector>
#include <algorithm>
#include <numeric>



int main()
{


using siType = const Sales_item &;

using compISBNType = std::function<bool(siType lhs, siType rhs)>;
using bookstoreType = std::multiset<Sales_item, compISBNType>;

compISBNType compareISBN; 

bookstoreType bookstore(compareISBN);
bookstoreType::iterator bsIt = bookstore.begin();


    return 0;
}
