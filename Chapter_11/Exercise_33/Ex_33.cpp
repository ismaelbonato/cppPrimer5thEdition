#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using Dictionary = std::map<std::string, std::string>;

const std::string translate(Dictionary &dictionary , const std::string &rawWord)
{ 
    auto meaning = dictionary.find(rawWord); 
    if (meaning != dictionary.end()) {
        return meaning->second;    
    } 
    
    return rawWord;
}

Dictionary buildDictionary(std::ifstream &mapStream)
{
    Dictionary dictionary;

    std::string word;
    std::string meaning;

    while (mapStream >> word && std::getline(mapStream, meaning)) {
        dictionary[word] = meaning.substr(1);
    }

    return dictionary;
}

void wordTransformation(std::ifstream &mapStream, std::ifstream &inputStream)
{ 
    auto dictionary =  buildDictionary(mapStream);
   
    std::vector<std::string> text;
    std::string rawText;

    while (std::getline(inputStream, rawText)) {
        std::stringstream streamOut(rawText);
        std::string strTmp;
        std::string word;

        while(streamOut >> word) {
           word = translate(dictionary, word);
            std::cout << word << " ";
        }
        std::cout << std::endl;
    }
}

int main ()
{

    std::ifstream mapFile("map");
    std::ifstream inputFile("input");

    wordTransformation(mapFile, inputFile);

    return 0;
}