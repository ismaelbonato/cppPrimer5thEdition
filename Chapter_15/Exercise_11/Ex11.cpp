#include <iostream>
#include <string>
#include <ostream>

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
    virtual std::ostream &debug(std::ostream &os) const;

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
        , discount(d){};

    ~BulkQuote() = default;
    double netPrice(const std::size_t copies) const override;
    std::ostream &debug(std::ostream &os) const override;

private:
    std::size_t minAmount;

protected:
    double discount = 0.0;

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
        : BulkQuote(book, sp, d, nMin)
        , maxAmount(nMax)
    {}

    ~LimitedBulkQuote() = default;
    double netPrice(const std::size_t copies) const override;
    std::ostream &debug(std::ostream &os) const override;

private:
    std::size_t maxAmount;
protected:
};

std::ostream &LimitedBulkQuote::debug(std::ostream &os) const
{
    os << " LimitedBulkQuote" <<" minAmount: " << maxAmount;
    BulkQuote::debug(os);
    return os;
}

double LimitedBulkQuote::netPrice(const std::size_t copies) const
{
    const auto remaining = (copies > maxAmount) ? (copies - maxAmount) : 0;
    return BulkQuote::netPrice(copies - remaining) + Quote::netPrice(remaining);
}

double BulkQuote::netPrice(const std::size_t copies) const
{
    if (copies >= minAmount) {
        return (copies * ((1 - discount) * price));
    }

    return Quote::netPrice(copies);
}

std::ostream &BulkQuote::debug(std::ostream &os) const
{
    os << " BulkQuote"<< " minAmount: " << minAmount << " discount: " << discount; 
    Quote::debug(os);
    return os;
}

double Quote::netPrice(const std::size_t copies) const
{
    return copies * price;
}

std::ostream &Quote::debug(std::ostream &os) const
{
    os << " Quote" << " ISBN: " << bookNo << " Price: " << price;
    return os;
}

double printTotal(std::ostream &os, const Quote &qItem, std::size_t copies)
{
    double ret = qItem.netPrice(copies);
    os << "sISBN: " << qItem.isbn() << " Sold: " << copies << " NetPrice: " << ret
       << std::endl;

    return ret;
}

int main()
{
    Quote dune{"Dune", 25};

    printTotal(std::cout, dune, 4);

    BulkQuote harryPotter{"Harry Poter", 15, 0.20, 3};

    printTotal(std::cout, harryPotter, 1);
    printTotal(std::cout, harryPotter, 2);
    printTotal(std::cout, harryPotter, 3);
    printTotal(std::cout, harryPotter, 4);

    LimitedBulkQuote lordOfTheRings{"Lord Of The Rings", 10, 0.20, 1, 4};

    printTotal(std::cout, lordOfTheRings, 1);
    printTotal(std::cout, lordOfTheRings, 2);
    printTotal(std::cout, lordOfTheRings, 3);
    printTotal(std::cout, lordOfTheRings, 4);
    printTotal(std::cout, lordOfTheRings, 5);
    printTotal(std::cout, lordOfTheRings, 6);
    printTotal(std::cout, lordOfTheRings, 7);

    std::cout << lordOfTheRings.debug(std::cout).rdbuf() << std::endl;

    return 0;
}