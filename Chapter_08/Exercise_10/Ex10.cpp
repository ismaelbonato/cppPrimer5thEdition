#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>

using fileElements = std::vector<std::string>;

int getFileContent(const std::string &fileName, fileElements &elements)
{
    std::string lineBuf;

    std::ifstream file(fileName);
    if(!file) {
        std::cerr << "error reading " << fileName << std::endl;
        return -1;
    } 

    while (getline(file, lineBuf)) {
        elements.push_back(lineBuf);
    }

    return 0;
}

int main()
{
    fileElements elements;
    std::string word;

    if (getFileContent("file.txt", elements)) {
        std::cerr << "error in getFileContent " << std::endl;
        return -1;
    }

    for (auto line : elements) {
        std::istringstream lineStream(line);
        
        while(lineStream >> word) {
            std::cout << word << std::endl;
        }
    }

    return 0;
}