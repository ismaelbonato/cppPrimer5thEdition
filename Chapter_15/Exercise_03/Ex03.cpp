#include <string>
#include <iostream>

class Quote
{
public:
    Quote() = default;
    Quote(const std::string &book, const double salesPrice)
        : bookNo(book)
        , price(salesPrice)
    {}

    virtual ~Quote() = default;

    const std::string isbn() const { return bookNo; }
    virtual double netPrice(const std::size_t copies) const;

private:
    std::string bookNo;

protected:
    double price = 0.0;
};

double Quote::netPrice(const std::size_t copies) const
{
    return copies * price;
}

double printTotal(std::ostream &os, const Quote &qItem, std::size_t copies)
{
    double ret = qItem.netPrice(copies);
    os << "ISBN: " << qItem.isbn() << " Sold: " << copies << " NetPrice: " << ret << std::endl;

    return ret;
}

int main()
{

    Quote harryPotter{"Harry Poter", 24.99};
    
    printTotal(std::cout, harryPotter, 10);

    return 0;
}