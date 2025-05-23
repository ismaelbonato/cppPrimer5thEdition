#include <fstream>
#include <iostream>
#include <memory>
#include <ostream>
#include <string>
#include <vector>

//#include "TextQuery.h"

class QueryBase
{
    friend class Query;

protected:
    using line_no = std::vector<std::string>::size_type;
    virtual ~QueryBase() = default;

private:
    //virtual QueryResult eval(const TextQuery &) const = 0;
    virtual std::string rep() const = 0;
};

class Query
{
    friend Query operator~(const Query &);
    friend Query operator|(const Query &, const Query &);
    friend Query operator&(const Query &, const Query &);

public:
    Query(const std::string &);

    //QueryResult eval(const TextQuery &t) const { return q->eval(t); }
    std::string rep() const 
    { 
        std::cout << "Query::rep()" << std::endl;    
        return q->rep(); 
    }

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
    {
        std::cout << "WordQuery::WordQuery(" << queryWord << ")" << std::endl;
    }
    std::string rep() const 
    { 
        std::cout << "WordQuery::rep(" << queryWord << ")" << std::endl;        
        return queryWord; 
    }
    std::string queryWord; // word for which to search
};

inline Query::Query(const std::string &s): q(new WordQuery(s)) 
{
    std::cout << "Query::Query()" << std::endl;

}

class NotQuery : public QueryBase
{
    friend Query operator~(const Query &);
    NotQuery(const Query &q)
        : query(q)
    {
        std::cout << "NotQuery::NotQuery()" << std::endl;
    }

    std::string rep() const { 
        std::cout << "NotQuery::rep()" << std::endl;        
        return "~(" + query.rep() + ")"; 
    }

    //QueryResult eval(const TextQuery &) const;
    Query query;
};

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
    {
        std::cout << "BinaryQuery::BinaryQuery(" << opSym << ")" << std::endl;
    }
    // abstract class: BinaryQuery doesn't define eval
    std::string rep() const
    {       
        std::cout << "BinaryQuery::rep(" << opSym << ")" << std::endl;        
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
    {
        std::cout << "AndQuery::AndQuery()" << std::endl;
    }
    // concrete class: AndQuery inherits rep and defines the remaining pure virtual
    //QueryResult eval(const TextQuery &) const;
};

inline Query operator&(const Query &lhs, const Query &rhs)
{
    return std::shared_ptr<QueryBase>(new AndQuery(lhs, rhs));
}

class OrQuery : public BinaryQuery
{
    friend Query operator|(const Query &, const Query &);
    OrQuery(const Query &left, const Query &right)
        : BinaryQuery(left, right, "|")
    {
        std::cout << "OrQuery::OrQuery()" << std::endl;
    }
    //QueryResult eval(const TextQuery &) const;
};

inline Query operator|(const Query &lhs, const Query &rhs)
{
    return std::shared_ptr<QueryBase>(new OrQuery(lhs, rhs));
}

int main()
{
    Query q = (Query("fiery") & Query("bird")) | Query("wind");

    std::cout << q << std::endl;

    return 0;
}
