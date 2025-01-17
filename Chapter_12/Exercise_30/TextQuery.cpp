#include "TextQuery.h"
#include <cstddef>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

TextQuery::TextQuery(std::ifstream &infile) 
        : data(std::make_shared<std::vector<std::string>>())
{
    std::string line;
    std::string word;
    std::size_t idx = 1;
    
    while(std::getline(infile,line)) {
        data->push_back(line);
    
        std::stringstream s(line);
        while (s >> word) {
            auto &l = wl[word];
            if (l == nullptr) l = std::make_shared<std::set<std::size_t>>();
            l->insert(idx);
        }
        ++idx;
    }
}

const QueryResult TextQuery::query(const std::string &word) const
{
    auto l = wl.find(word);
    auto notFound = std::make_shared<std::set<std::size_t>>();

    if (l == wl.end()) {
        return QueryResult(notFound, word, data);
    }

    return QueryResult(l->second, word, data);
}

std::ostream &print(std::ostream &o, const QueryResult &res)
{
    try {
        o << res.word << " occurs " << res.lines->size() << " times." << std::endl;
        for(const auto line: *res.lines) {
            o << "(Line " << line << ") " << res.data->at(line -1) << std::endl;
        }
    } catch (...) {
        std::cout << "exception" << std::endl;
    }
    return o;
}
