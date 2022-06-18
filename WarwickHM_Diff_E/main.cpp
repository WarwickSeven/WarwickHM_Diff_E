#include <iostream>
#include <string>
#include <algorithm>
#include <map>

std::string getSentence(std::string &s) {
    std::string punctuationMarks { ".?!" };
    std::string temp;
    for (const char &c : s) {
        temp.push_back(c);
        if (punctuationMarks.find(c) != std::string::npos) {
            s.erase(0, temp.size());
            if (temp[0] == ' ') {
                temp.erase(0, 1);
            }
            return temp;
        }
    }
    return {};
}

int main() {
    std::multimap<int, std::string> sentences;
    std::string currentString, tempString;
    do {
        std::cout << "Text plz (or press Enter to continue): "<< std::endl;
        std::getline(std::cin, currentString);
        if (!currentString.empty()) {
            tempString += (currentString + ' ');
            while (true) {
                std::string sentence(getSentence(tempString));
                if (sentence.empty()) {
                    break;
                }
                sentences.insert({std::count(sentence.begin(), sentence.end(), ' ') + 1, sentence});
            }
        }
    } while (!currentString.empty());
    
    for_each(sentences.begin(), sentences.end(),[](std::pair<int, std::string> item) {
          std::cout << item.first << " " << item.second << "\n";});
    return 0;
}
