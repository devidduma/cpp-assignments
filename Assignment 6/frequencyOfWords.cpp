#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct WordsWithFrequency {
    string word;
    int frequency{};
};

int main() {
    vector<WordsWithFrequency> words;

    // input file stream
    ifstream fin("../frequencyOfWords.txt");

    // input stuff and update frequency
    string inputWord;
    while(fin >> inputWord) {
        int i;
        for(i = 0; i < words.size(); i++) {
            if(words[i].word == inputWord)
                break;
        }

        // if word does not exist in the vector
        if(i == words.size()) {
            words.emplace_back();
            words[i].word = inputWord;
        }
        // update frequency
        words[i].frequency++;
    }

    for(const WordsWithFrequency& wordWithFrequency : words) {
        cout << wordWithFrequency.word << ": " << wordWithFrequency.frequency << endl;
    }

    return 0;
}