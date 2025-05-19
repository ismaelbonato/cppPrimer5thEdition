#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <ostream>
#include <set>
#include <string>
#include <vector>

class Quote
{
public:
    Quote() = default;
    Quote(const std::string &book, const double salesPrice)
        : bookNo(book)
        , price(salesPrice)
    {}

    Quote(const Quote &origin)
        : bookNo(origin.bookNo)
        , price(origin.price)
    {}

    Quote(Quote &&origin)
        : bookNo(std::move(origin.bookNo))
        , price(origin.price)
    {
        origin.bookNo = "valid state.";
    }

    Quote &operator=(const Quote &rhs)
    {
        bookNo = rhs.bookNo;
        price = rhs.price;
        return *this;
    }
    Quote &operator=(Quote &&rhs)
    {
        bookNo = std::move(rhs.bookNo);
        rhs.bookNo = "valid state.";
        price = rhs.price;
        return *this;
    }

    virtual Quote *clone() const & { return new Quote(*this); }
    virtual Quote *clone() && { return new Quote(std::move(*this)); }

    virtual ~Quote() = default;

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
    {}

    DiscQuote(const DiscQuote &origin)
        : Quote(origin)
        , discount(origin.discount)
        , minAmount(origin.minAmount)
    {}

    DiscQuote(DiscQuote &&origin)
        : Quote(std::move(origin))
        , discount(origin.discount)
        , minAmount(origin.minAmount)
    {}

    DiscQuote &operator=(const DiscQuote &rhs)
    {
        Quote::operator=(rhs);
        discount = rhs.discount;
        minAmount = rhs.minAmount;
        return *this;
    }
    DiscQuote &operator=(DiscQuote &&rhs)
    {
        Quote::operator=(std::move(rhs));
        discount = rhs.discount;
        minAmount = rhs.minAmount;
        return *this;
    }

    double netPrice(const std::size_t copies) const = 0;
    ~DiscQuote() = default;

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
    {}

    BulkQuote(BulkQuote &&origin)
        : DiscQuote(std::move(origin))
    {}

    BulkQuote &operator=(const BulkQuote &rhs)
    {
        DiscQuote::operator=(rhs);
        return *this;
    }
    BulkQuote &operator=(BulkQuote &&rhs)
    {
        DiscQuote::operator=(std::move(rhs));
        return *this;
    }

    BulkQuote *clone() const & override { return new BulkQuote(*this); }
    BulkQuote *clone() && override { return new BulkQuote(std::move(*this)); }

    ~BulkQuote() = default;
    double netPrice(const std::size_t copies) const override;
    std::ostream &debug(std::ostream &os) const override;
};

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

class Basket
{
    using ConstSharedQuote = const std::shared_ptr<Quote>;
    using SharedQuote = std::shared_ptr<Quote>;

public:
    Basket(/* args */) = default;
    ~Basket() = default;

    void addItem(ConstSharedQuote &sale) { items.insert(sale); }
    void addItem(const Quote &sale) { items.insert(SharedQuote(sale.clone())); }
    void addItem(Quote &&sale) { items.insert(SharedQuote(std::move(sale).clone())); }
    double totalRecept(std::ostream &os);

private:
    static bool compare(ConstSharedQuote &l, ConstSharedQuote &r)
    {
        return l->isbn() < r->isbn();
    }

    std::multiset<std::shared_ptr<Quote>, decltype(compare) *> items{compare};
};

double Basket::totalRecept(std::ostream &os)
{
    double sum = 0.0;
    for (auto it = items.cbegin(); it != items.cend(); it = items.upper_bound(*it)) {
        std::cout << "item: " << (**it).isbn() << " copies: " << items.count(*it)
                  << std::endl;
        sum += printTotal(os, **it, items.count(*it));
    }
    os << "Total: " << sum << std::endl;

    return sum;
}

int main()

{
    Basket basket;

    Quote dune("Dune", 25);
    basket.addItem(dune);
    basket.addItem(Quote("Dune", 25));

    BulkQuote harryPotter("Harry Potter", 10, 0.20, 3);
    basket.addItem(harryPotter);
    basket.addItem(BulkQuote("Harry Potter", 10, 0.20, 3));

    auto acc = basket.totalRecept(std::cout);

    std::cout << "The total accumulated: " << acc << std::endl;

    return 0;
}