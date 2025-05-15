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

class LimitedBulkQuote : public Quote
{
public:
    LimitedBulkQuote() = default;
    LimitedBulkQuote(const std::string &book,
              const double sp,
              const double d,
              const std::size_t nMax)
        : Quote(book, sp),
        maxAmount(nMax),
        discount(d) {};

    ~LimitedBulkQuote() = default;
    double netPrice(const std::size_t copies) const override;

private:
    std::size_t maxAmount;
    double discount;
protected:
};

double LimitedBulkQuote::netPrice(const std::size_t copies) const
{
    const auto remaining =  (copies > maxAmount) ? (copies - maxAmount) : 0;

    return ((copies - remaining) * (1 - discount) * price) + (remaining * price);
}

double BulkQuote::netPrice(const std::size_t copies) const
{
    if (copies >= minAmount) {
        return (copies * ((1 - discount) * price));
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
    Quote dune{"Dune", 25};

    printTotal(std::cout, dune, 4);

    BulkQuote harryPotter{"Harry Poter", 15,  0.20, 3};

    printTotal(std::cout, harryPotter, 1);
    printTotal(std::cout, harryPotter, 2);
    printTotal(std::cout, harryPotter, 3);
    printTotal(std::cout, harryPotter, 4);

    LimitedBulkQuote lordOfTheRings{"Lord Of The Rings", 10,  0.20, 5};

    printTotal(std::cout, lordOfTheRings, 2);
    printTotal(std::cout, lordOfTheRings,3);
    printTotal(std::cout, lordOfTheRings, 4);
    printTotal(std::cout, lordOfTheRings, 5);
    printTotal(std::cout, lordOfTheRings, 6);

    return 0;
}