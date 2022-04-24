#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue>

std::string lowerCase(std::string string) {
    for(std::string::iterator it = string.begin(); it != string.end(); it++) {
        if(*it >= 'A' && *it <= 'Z') {
            *it = *it - 'A' +  'a';
        }
    }
    return string;
}

struct CompareWords {
    bool operator() (const std::pair<std::string, int>& P1, const std::pair<std::string, int>& P2) const {
        return P1.second < P2.second;
    }
};

int main() {
    std::ifstream file;
    file.open("../name.txt");
    std::string sentence;
    if(file.is_open()) {
       char ch;
       while(file.good()) {
           ch = file.get();
           sentence += ch;
       }
    }

    std::string separators = " ,?!.";
    std::map<std::string, int> words;

    int pos1 = 0, len;
    for(std::string::iterator it = sentence.begin(); it != sentence.end(); it++) {
        for(std::string::iterator it2 = separators.begin(); it2 != separators.end(); it2++) {
            if(*it == *it2) {
                len = it - sentence.begin() - pos1;
                std::string word = sentence.substr(pos1, len);
                word = lowerCase(word);
                if(words.find(word) == words.end() && len != 0) {
                    std::pair<std::string, int> newWord;
                    newWord.first = word;
                    newWord.second = 1;
                    words.insert(newWord);
                } else {
                    words.find(word)->second++;
                }
                pos1 += len + 1;
                break;
            }
        }
    }
//    for(std::map<std::string, int>::iterator it = words.begin(); it != words.end(); it++) {
//        std::cout << it->first << ": " << it->second << std::endl;
//    }

    std::priority_queue<std::pair<std::string, int>, std::vector<std::pair<std::string, int>>, CompareWords> sortedWords;
    for(std::map<std::string, int>::iterator it = words.begin(); it != words.end(); it++) {
        sortedWords.push(*it);
    }
    while(!sortedWords.empty()) {
        std::cout << sortedWords.top().first << " => " << sortedWords.top().second << '\n';
        sortedWords.pop();
    }
    return 0;
}
