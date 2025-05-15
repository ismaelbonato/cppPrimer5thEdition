#include <iostream>
#include <string>

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

class BulkQuote : public Quote
{
public:
    BulkQuote() = default;
    BulkQuote(const std::string &book,
              const double sp,
              const double d,
              const std::size_t n)
        : Quote(book, sp)
        , minAmount(n)
        , discount(d) {};

    ~BulkQuote() = default;
    double netPrice(const std::size_t copies) const override;

private:
    std::size_t minAmount;
    double discount = 0.0;

protected:
};

double BulkQuote::netPrice(const std::size_t copies) const
{
    if (copies >= minAmount) {
        return (copies * (price * (1 - discount)));
    } 

    return Quote::netPrice(copies);
}

double Quote::netPrice(const std::size_t copies) const
{
    return copies * price;
}

double printTotal(std::ostream &os, const Quote &qItem, std::size_t copies)
{
    double ret = qItem.netPrice(copies);
    os << "ISBN: " << qItem.isbn() << " Sold: " << copies << " NetPrice: " << ret
       << std::endl;

    return ret;
}

int main()
{

    return 0;
}