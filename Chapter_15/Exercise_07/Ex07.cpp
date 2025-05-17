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
        , discount(d) {}

    ~BulkQuote() = default;
    double netPrice(const std::size_t copies) const override;

private:
    std::size_t minAmount = 0;
    double discount = 0.0;

protected:
};

class LimitedBulkQuote : public BulkQuote
{
public:
    LimitedBulkQuote() = default;
    LimitedBulkQuote(const std::string &book,
              const double sp,
              const double d,
              const std::size_t nMin,
              const std::size_t nMax)
        : BulkQuote(book, sp, d, nMin),
        maxAmount(nMax) {}

    ~LimitedBulkQuote() = default;
    double netPrice(const std::size_t copies) const override;

private:
    std::size_t maxAmount = 0;
protected:
};

double LimitedBulkQuote::netPrice(const std::size_t copies) const
{
    const auto remaining =  (copies > maxAmount) ? (copies - maxAmount) : 0;
    return BulkQuote::netPrice(copies - remaining) + Quote::netPrice(remaining);
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

    BulkQuote harryPotter{"Harry Potter", 15,  0.20, 3};

    printTotal(std::cout, harryPotter, 1);
    printTotal(std::cout, harryPotter, 2);
    printTotal(std::cout, harryPotter, 3);
    printTotal(std::cout, harryPotter, 4);

    LimitedBulkQuote lordOfTheRings{"Lord Of The Rings", 10,  0.20, 1, 4};

    printTotal(std::cout, lordOfTheRings, 1);
    printTotal(std::cout, lordOfTheRings, 2);
    printTotal(std::cout, lordOfTheRings, 3);
    printTotal(std::cout, lordOfTheRings, 4);
    printTotal(std::cout, lordOfTheRings, 5);
    printTotal(std::cout, lordOfTheRings, 6);
    printTotal(std::cout, lordOfTheRings, 7);

    return 0;
}