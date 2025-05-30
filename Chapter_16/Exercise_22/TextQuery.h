#ifndef TEXTQUERY_H
#define TEXTQUERY_H

#include <cstddef>
#include <fstream>
#include <map>
#include <memory>
#include <iostream>
#include <set>
#include <string>
#include <vector>

class DebugDelete 
{
public:
    DebugDelete(std::ostream &os = std::cerr) : out(os) {}

    template<typename IT> void operator()(IT *it)
    {
        out << "deleting object:";
        delete it;
    }

private:
    std::ostream &out;
};

class QueryResult;

class TextQuery {
    friend class QueryResult;
public:
    TextQuery(std::ifstream &infile);
    const QueryResult query(const std::string &word) const;

private:
    std::vector<std::string> data;
};

class QueryResult {
public:
    QueryResult(std::shared_ptr<std::map<int, std::string>> res, const std::string field) : spRes(res), word(field) {};
    std::shared_ptr<std::map<int, std::string>> spRes;
    std::string word;
    size_t size() {return spRes->size();};
private:

};

#endif