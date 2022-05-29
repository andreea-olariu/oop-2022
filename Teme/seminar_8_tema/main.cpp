#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue>

#define freq_priority_queue  std::priority_queue<std::pair<std::string, int>, std::vector<std::pair<std::string, int>>, CompareWords>

std::string lowerCase(std::string string) {
    for(auto& ch : string) {
        if(ch >= 'A' && ch <= 'Z') {
            ch = ch - 'A' +  'a';
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

    int pos1 = 0, len, i = 0;
    for(auto& ch1 : sentence) {
        for(auto& ch2 : separators) {
            if(ch1 == ch2) {
                len = i - pos1;
                std::string word = sentence.substr(pos1, len);
                word = lowerCase(word);
                if(words.find(word) == words.end() && len != 0) {
                    std::pair<std::string, int> newWord;
                    auto& [name, freq] = newWord;
                    name = word;
                    freq = 1;
                    words.insert(newWord);
                } else {
                    words.find(word)->second++;
                }
                pos1 += len + 1;
                break;
            }
        }
        i++;
    }

    freq_priority_queue sortedWords;
    for(auto& word : words) {
        sortedWords.push(word);
    }
    while(!sortedWords.empty()) {
        auto& [name, freq] = sortedWords.top();
        std::cout << name << " => " << freq << '\n';
        sortedWords.pop();
    }

    return 0;
}
