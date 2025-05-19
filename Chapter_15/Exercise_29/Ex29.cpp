#include <iostream>
#include <ostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <set>
#include <algorithm>

class Quote
{
public:
    Quote() = default;
    Quote(const std::string &book, const double salesPrice)
        : bookNo(book)
        , price(salesPrice)
    {
        //std::cout << "Constructor: Base " << bookNo << std::endl;
    }

    Quote(const Quote &origin)
        : bookNo(origin.bookNo)
        , price(origin.price)
    {
        //std::cout << "Copy Constructor Quote(const Quote &origin) " << std::endl;
    }

    Quote(Quote &&origin)
        : bookNo(std::move(origin.bookNo))
        , price(origin.price)
    {
        origin.bookNo = "valid state.";
        //std::cout << "Move Constructor Quote(const Quote &&origin) " << std::endl;
    }

    Quote &operator=(const Quote &rhs)
    {
        //std::cout << "Copy Operator &operator=(const Quote &rhs) " << std::endl;
        bookNo = rhs.bookNo;
        price = rhs.price;
        return *this;
    }
    Quote &operator=(Quote &&rhs)
    {
        //std::cout << "Move Operator &operator=(const Quote &rhs) " << std::endl;
        bookNo = std::move(rhs.bookNo);
        rhs.bookNo = "valid state.";
        price = rhs.price;
        return *this;
    }

    virtual ~Quote() 
    {
        //std::cout << "Destructor virtual ~Quote(): " << bookNo  << std::endl;
    };

    const std::string isbn() const { return bookNo; }
    virtual double netPrice(const std::size_t copies) const;
    virtual std::ostream &debug(std::ostream &os) const;

private:
    std::string bookNo;

protected:
    double price = 0.0;
};

class DiscQuote : public Quote
{
public:
    DiscQuote() = default;
    DiscQuote(const std::string &book,
              const double sp,
              const double d,
              const std::size_t n)
        : Quote(book, sp)
        , discount(d)
        , minAmount(n)
    {
        //std::cout << "Constructor: DiscQuote" << std::endl;
    }

    DiscQuote(const DiscQuote &origin)
        : Quote(origin)
        , discount(origin.discount)
        , minAmount(origin.minAmount)
    {
        //std::cout << "Copy Constructor DiscQuote(const DiscQuote &origin) " << std::endl;
    }

    DiscQuote(DiscQuote &&origin)
        : Quote(std::move(origin))
        , discount(origin.discount)
        , minAmount(origin.minAmount)
    {
        //std::cout << "Move Constructor DiscQuote(const DiscQuote &&origin) " << std::endl;
    }

    DiscQuote &operator=(const DiscQuote &rhs)
    {
        //std::cout << "Copy Operator &operator=(const DiscQuote &rhs) " << std::endl;
        Quote::operator=(rhs);
        discount = rhs.discount;
        minAmount = rhs.minAmount;
        return *this;
    }
    DiscQuote &operator=(DiscQuote &&rhs)
    {
        //std::cout << "Move Operator &operator=(const DiscQuote &rhs) " << std::endl;
        Quote::operator=(std::move(rhs));
        discount = rhs.discount;
        minAmount = rhs.minAmount;
        return *this;
    }

    double netPrice(const std::size_t copies) const = 0;
    ~DiscQuote() {
        //std::cout << "Destructor ~DiscQuote()" << std::endl;
    };

protected:
    double discount = 0.0;
    std::size_t minAmount = 0;
};

class BulkQuote : public DiscQuote
{
public:
    using DiscQuote::DiscQuote;

    BulkQuote(const BulkQuote &origin)
        : DiscQuote(origin)
    {
        //std::cout << "Copy Constructor BulkQuote(const BulkQuote &origin) " << std::endl;
    }

    BulkQuote(BulkQuote &&origin)
        : DiscQuote(std::move(origin))
    {
        //std::cout << "Move Constructor BulkQuote(const BulkQuote &&origin) " << std::endl;
    }

    BulkQuote &operator=(const BulkQuote &rhs)
    {
        ////std::cout << "Copy Operator &operator=(const BulkQuote &rhs) " << std::endl;
        DiscQuote::operator=(rhs);
        return *this;
    }
    BulkQuote &operator=(BulkQuote &&rhs)
    {
        ////std::cout << "Move Operator &operator=(const BulkQuote &rhs) " << std::endl;
        DiscQuote::operator=(std::move(rhs));
        return *this;
    }

    ~BulkQuote() 
    {
        //std::cout << "Destructor ~BulkQuote() " << std::endl;
    };
    double netPrice(const std::size_t copies) const override;
    std::ostream &debug(std::ostream &os) const override;
};

class LimitedBulkQuote : public DiscQuote
{
public:
    LimitedBulkQuote() = default;
    LimitedBulkQuote(const std::string &book,
                     const double sp,
                     const double d,
                     const std::size_t nMin,
                     const std::size_t nMax)
        : DiscQuote(book, sp, d, nMin)
        , maxAmount(nMax)
    {}

    ~LimitedBulkQuote() = default;
    double netPrice(const std::size_t copies) const override;
    std::ostream &debug(std::ostream &os) const override;

private:
    std::size_t maxAmount = 0;

protected:
};

std::ostream &LimitedBulkQuote::debug(std::ostream &os) const
{
    os << " LimitedBulkQuote" << " minAmount: " << maxAmount;
    Quote::debug(os);
    return os;
}

double LimitedBulkQuote::netPrice(const std::size_t copies) const
{
    const auto remaining = (copies > maxAmount) ? (copies - maxAmount + (minAmount-1)) : 0;
    return ((copies - remaining) * ((1 - discount) * price)) + Quote::netPrice(remaining);
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
    os << " BulkQuote" << " minAmount: " << minAmount << " discount: " << discount;
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


std::string findFirst(const std::string &s)
{
    for (auto it = s.begin(); it != s.end(); it = std::upper_bound(s.begin(), s.end(), *it) ) 
    {   
        if (std::count(it, s.end(), *it) == 1) 
            return std::string(1, *it);
    }

    return std::string();
}

int main()
{
//    auto ret  = findFirst("aaabbbcccdddeeefg");
//    std::cout << "char found: " << ret << std::endl;

//    ret = findFirst("aabb");
//    std::cout << "char found: " << ret << std::endl;

    std::vector<std::shared_ptr<Quote>> Quotes;

    Quotes.emplace_back(new Quote("Dune", 25));
    Quotes.push_back(std::make_shared<BulkQuote>("Harry Potter", 10, 0.20, 3));
    Quotes.push_back(std::make_shared<LimitedBulkQuote>("The Hobbit", 15, 0.20, 3, 4));

    double acc = 0.0;
    for (auto quote : Quotes)
    {
        acc += quote->netPrice(5);
    }

    std::cout << "The total accumulated: " << acc << std::endl;

    return 0;


}