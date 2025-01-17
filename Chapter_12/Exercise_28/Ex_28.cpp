#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <ostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using Result = std::shared_ptr<std::map<int, std::string>>;

std::ostream &print(std::ostream &o, std::string &word, Result res)
{
    o << word << " occurs " << res->size() << " times." << std::endl;

    for(auto line: *res) {
        o << "(Line " << line.first << ") " << line.second << std::endl;
    }

    return o;
}

Result query(const std::string &word, std::vector<std::string> &data)
{
    std::string w;
    std::set<int> lines;
    auto res = std::make_shared<std::map<int, std::string>>();

    for (auto idx = 0; idx < data.size(); ++idx) {
        std::stringstream s(data.at(idx));

        while (s >> w) {
            if (w == word) lines.insert(idx);
        }
    }

    for (auto line : lines) {
        res->emplace(line, data.at(line));
    }

    return res;
}

void runQueries(std::ifstream &infile)
{
    std::string line;
    std::vector<std::string> data;

    while(std::getline(infile,line)) {
        data.push_back(line);
    }

    while (true) {
        std::cout << "enter word to look for, or q to quit: ";
        std::string s;
        if (!(std::cin >> s) || s == "q") break;
        print(std::cout, s, query(s, data)) << std::endl;
    }  
}

int main()
{
    std::ifstream file("input");
    runQueries(file);

    return 0;
}
