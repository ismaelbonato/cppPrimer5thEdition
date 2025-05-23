#ifndef TEXTQUERY_H
#define TEXTQUERY_H

#include "StrVec.h"
#include <cstddef>
#include <fstream>
#include <map>
#include <memory>
#include <ostream>
#include <set>
#include <string>

class QueryResult;

class TextQuery
{
    friend class QueryResult;

public:
    using WordsByLine = std::map<std::string, std::shared_ptr<std::set<std::size_t>>>;

    TextQuery(std::ifstream &infile);
    const QueryResult query(const std::string &word) const;

private:
    StrVec data;
    WordsByLine wl;
};

class QueryResult
{
public:
    QueryResult()
        : lines(std::make_shared<std::set<std::size_t>>())
        , word(""){};

    QueryResult(std::shared_ptr<std::set<std::size_t>> l,
                const std::string field,
                StrVec d)
        : lines(l)
        , data(d)
        , word(field){};

    friend std::ostream &print(std::ostream &o,
                               const QueryResult &res,
                               size_t start_line,
                               size_t end_line);

    std::set<std::size_t>::iterator begin() { return lines->begin(); };
    std::set<std::size_t>::iterator end() { return lines->end(); };
    StrVec &get_file() { return data; };

private:
    std::shared_ptr<std::set<std::size_t>> lines;
    StrVec data;
    std::string word;
};

#endif