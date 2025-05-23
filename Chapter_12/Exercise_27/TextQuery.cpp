#include "TextQuery.h"
#include <memory>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

TextQuery::TextQuery(std::ifstream &infile)
{
    std::string line;
    
    while(std::getline(infile,line)) {
        data.push_back(line);
    }
}

const QueryResult TextQuery::query(const std::string &word) const
{
    std::string w;
    std::set<int> lines;
    auto res = std::make_shared<std::map<int, std::string>>();

    for (auto idx = 0; idx < data.size(); ++idx) {
        std::stringstream s(data.at(idx));

        while (s >> w) {
            auto it = std::remove_if(
                w.begin(), 
                w.end(),
                [](unsigned char c) { return std::ispunct(c); }
                );

            w.erase(it, w.end());
            
            if (w == word) lines.insert(idx);
        }
    }

    for (auto line : lines) {
        res->emplace(line, data.at(line));
    }

    return QueryResult(res, word);
}