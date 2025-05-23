#include <algorithm>
#include <fstream>
#include <iostream>
#include <memory>
#include <ostream>
#include <string>
#include <vector>

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

private:
    Query(std::shared_ptr<QueryBase> query)
        : q(query)
    {}
    std::shared_ptr<QueryBase> q;
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
    std::string queryWord; // word for which to search
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
    return std::shared_ptr<QueryBase>(new NotQuery(operand));
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
    return std::shared_ptr<QueryBase>(new AndQuery(lhs, rhs));
}

class OrQuery : public BinaryQuery
{
    friend Query operator|(const Query &, const Query &);
    OrQuery(const Query &left, const Query &right)
        : BinaryQuery(left, right, "|")
    {}
    QueryResult eval(const TextQuery &) const;
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
    return std::shared_ptr<QueryBase>(new OrQuery(lhs, rhs));
}

void runQueries(std::ifstream &infile)
{
    TextQuery tq(infile);
    Query q = ((Query("fiery") & Query("bird")) | Query("wind"));
    QueryResult ret = q.eval(tq);

    print(std::cout, ret) << std::endl;
}

int main()
{
    std::ifstream file("input");
    runQueries(file);

    return 0;
}
