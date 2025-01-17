#ifndef TEXTQUERY_H
#define TEXTQUERY_H

#include <cstddef>
#include <fstream>
#include <map>
#include <memory>
#include <ostream>
#include <set>
#include <string>
#include <vector>

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