#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>


using Dictionary = std::unordered_map<std::string, std::string>;

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

int main()
{
    //-------------------------- word couting --------------------------------//    
    std::unordered_map<std::string, std::string::size_type> word_count;

    std::string word;
    while (std::cin >> word) {
        ++word_count[word];
    }    

    std::cout << "//-------------------------- word couting" 
                << " --------------------------------//" << std::endl;

    for (const auto &w : word_count) // for each element in the map
        std::cout << w.first 
                    << " occurs " 
                    << w.second 
                    << ((w.second > 1) ? " times" : " time") 
                    << std::endl;
    

    //------------------------- word translation -----------------------------//

   std::cout << "//-------------------------- word translation" 
                << " --------------------------------//" << std::endl;

    std::ifstream mapFile("map");
    std::ifstream inputFile("input");

    wordTransformation(mapFile, inputFile);


    return 0;
}


