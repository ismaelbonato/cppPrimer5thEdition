#include <algorithm>
#include <fstream>
#include <iostream>
#include <memory>
#include <ostream>
#include <string>
#include <vector>
#include <typeinfo>

#include "TextQuery.h"

class QueryBase
{
    friend class Query;
protected:
    using lineNo = std::vector<std::string>::size_type;
    virtual ~QueryBase() = default;

private:
    virtual QueryResult eval(const TextQuery &) const = 0;
    virtual std::string rep() const = 0;
    virtual QueryBase* clone() const = 0;
};

class Query
{
    friend Query operator~(const Query &);
    friend Query operator|(const Query &, const Query &);
    friend Query operator&(const Query &, const Query &);

public:
    Query(const std::string &);

    QueryResult eval(const TextQuery &t) const { return q->eval(t); }
    std::string rep() const { return q->rep(); }

    Query(const Query& other)
        : q(other.q ? other.q->clone() : nullptr) {}

    Query& operator=(const Query& other) {
        if (this != &other) {
            delete q;
            q = other.q ? other.q->clone() : nullptr;
        }
        return *this;
    }

    Query(Query&& other) noexcept
        : q(other.q) {
        other.q = nullptr;
    }

    Query& operator=(Query&& other) noexcept {
        if (this != &other) {
            delete q;
            q = other.q;
            other.q = nullptr;
        }
        return *this;
    }

    ~Query() {
        delete(q);
        q = nullptr;
    }
private:
    Query(QueryBase *query)
        : q(query)
    {}
    QueryBase *q;

};

std::ostream &operator<<(std::ostream &os, const Query &query)
{
    return os << query.rep();
}

class WordQuery : public QueryBase
{
    friend class Query;
    WordQuery(const std::string &s)
        : queryWord(s)
    {}
    QueryResult eval(const TextQuery &t) const override { return t.query(queryWord); }
    std::string rep() const override { return queryWord; }
    std::string queryWord;
    QueryBase* clone() const override { return new WordQuery(*this); }
};

inline Query::Query(const std::string &s)
    : q(new WordQuery(s))
{}

class NotQuery : public QueryBase
{
    friend Query operator~(const Query &);
    NotQuery(const Query &q)
        : query(q)
    {}

    std::string rep() const { return "~(" + query.rep() + ")"; }

    QueryResult eval(const TextQuery &) const;
    Query query;
    QueryBase* clone() const override { return new NotQuery(*this); }
};

QueryResult NotQuery::eval(const TextQuery &text) const
{
    auto result = query.eval(text);
    auto ret_lines = std::make_shared<std::set<lineNo>>();

    auto beg = result.begin(), end = result.end();
    auto sz = result.get_file().size();

    for (size_t n = 0; n != sz; ++n) {
        if (beg == end || *beg != n)
            ret_lines->insert(n);
        else if (beg != end)
            ++beg;
    }
    return QueryResult(ret_lines, rep(), result.get_file());
}

inline Query operator~(const Query &operand)
{

    return new NotQuery(operand);
}

class BinaryQuery : public QueryBase
{
protected:
    BinaryQuery(const Query &l, const Query &r, std::string s)
        : lhs(l)
        , rhs(r)
        , opSym(s)
    {}
    std::string rep() const
    {
        return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";
    }
    Query lhs, rhs;    // right- and left-hand operands
    std::string opSym; // name of the operator
};

class AndQuery : public BinaryQuery
{
    friend Query operator&(const Query &, const Query &);
    AndQuery(const Query &left, const Query &right)
        : BinaryQuery(left, right, "&")
    {}

    QueryResult eval(const TextQuery &) const;
    QueryBase* clone() const override { return new AndQuery(*this); }
};

QueryResult AndQuery::eval(const TextQuery &text) const
{
    auto left = lhs.eval(text), right = rhs.eval(text);
    auto ret_lines = std::make_shared<std::set<lineNo>>();

    std::set_intersection(left.begin(),
                          left.end(),
                          right.begin(),
                          right.end(),
                          inserter(*ret_lines, ret_lines->begin()));

    return QueryResult(ret_lines, rep(), left.get_file());
}

inline Query operator&(const Query &lhs, const Query &rhs)
{
    return new AndQuery(lhs, rhs);
}

class OrQuery : public BinaryQuery
{
    friend Query operator|(const Query &, const Query &);
    OrQuery(const Query &left, const Query &right)
        : BinaryQuery(left, right, "|")
    {}
    QueryResult eval(const TextQuery &) const;
    QueryBase* clone() const override { return new OrQuery(*this); }
};

QueryResult OrQuery::eval(const TextQuery &text) const
{
    QueryResult right = rhs.eval(text);
    QueryResult left = lhs.eval(text);
    auto ret_lines = std::make_shared<std::set<lineNo>>(left.begin(), left.end());
    ret_lines->insert(right.begin(), right.end());

    return QueryResult(ret_lines, rep(), left.get_file());
}

inline Query operator|(const Query &lhs, const Query &rhs)
{
    return new OrQuery(lhs, rhs);
}

void runQueries(std::ifstream &infile)
{
    TextQuery tq(infile);
    Query q = ((Query("fiery") & Query("bird")) | Query("wind"));
    
    //Query q = Query("Daddy");
    QueryResult ret = q.eval(tq);

    print(std::cout, ret) << std::endl;
}

int main()
{
    std::ifstream file("input");
    runQueries(file);

    

    return 0;
}
