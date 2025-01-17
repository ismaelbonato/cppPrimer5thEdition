#ifndef TEXTQUERY_H
#define TEXTQUERY_H

#include <cstddef>
#include <fstream>
#include <map>
#include <memory>
#include <ostream>
#include <set>
#include <string>
#include "StrBlob.h"

class QueryResult;

class TextQuery {
    friend class QueryResult;
public:
    using WordsByLine = std::map<std::string, std::shared_ptr<std::set<std::size_t>>>;

    TextQuery(std::ifstream &infile);
    const QueryResult query(const std::string &word) const;
private:
    StrBlob data;
    WordsByLine wl;
};

class QueryResult {
public:
    QueryResult() : lines(std::make_shared<std::set<std::size_t>>()) {};

    QueryResult(std::shared_ptr<std::set<std::size_t>> l,
                                const std::string field, 
                                StrBlob d) 
                                : lines(l), word(field), data(d) {};

    friend std::ostream &print(std::ostream &o, const QueryResult &res);
private:
    std::shared_ptr<std::set<std::size_t>> lines;
    StrBlob data;
    std::string word;
};

#endif