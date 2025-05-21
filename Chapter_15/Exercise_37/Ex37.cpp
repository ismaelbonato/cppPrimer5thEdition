#include <fstream>
#include <iostream>
#include <memory>
#include <ostream>
#include <string>
#include <vector>

class QueryBase;

using Query = std::shared_ptr<QueryBase>;

class QueryBase
{
public:
    virtual std::string rep() const = 0;

protected:
    using line_no = std::vector<std::string>::size_type;
    virtual ~QueryBase() = default;

private:
    //virtual QueryResult eval(const TextQuery &) const = 0;
};



std::ostream &operator<<(std::ostream &os, const Query &query)
{
    return os << query->rep();
}

class WordQuery : public QueryBase
{
public:
    WordQuery(const std::string &s)
        : queryWord(s)
    {
        std::cout << "WordQuery::WordQuery(" << queryWord << ")" << std::endl;
    }
private:
    std::string rep() const 
    { 
        std::cout << "WordQuery::rep(" << queryWord << ")" << std::endl;        
        return queryWord; 
    }
    std::string queryWord; // word for which to search
};

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
        return "~(" + query->rep() + ")"; 
    }

    //QueryResult eval(const TextQuery &) const;
    Query query;
};

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
        return "(" + lhs->rep() + " " + opSym + " " + rhs->rep() + ")";
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


inline Query operator&(const Query &lhs, const Query &rhs)
{
    return std::shared_ptr<QueryBase>(new AndQuery(lhs, rhs));
}

inline Query operator|(const Query &lhs, const Query &rhs)
{
    return std::shared_ptr<QueryBase>(new OrQuery(lhs, rhs));
}

inline Query operator~(const Query &operand)
{
    return std::shared_ptr<QueryBase>(new NotQuery(operand));
}

int main()
{
    Query q = (Query(new WordQuery("fiery"))) & Query(new WordQuery("bird")) | Query(new WordQuery("wind"));

    std::cout << q << std::endl;

    return 0;
}
