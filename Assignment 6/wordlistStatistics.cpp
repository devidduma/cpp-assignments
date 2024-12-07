#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void printVector(const string& msg, const vector<string>& words) {
    cout << msg << endl;
    for(const string& word : words) {
        cout << word << " ";
    }
    cout << endl << endl;
}

vector<string> wordsEndingIme(const vector<string>& words) {
    vector<string> result;

    for(const string& word : words) {
        if(word.substr(word.size() - 3, 3) == "ime")
            result.push_back(word);
    }

    return result;
}

vector<string> wordsContainingAveFrom2ndChar(const vector<string>& words) {
    vector<string> result;

    for(const string& word : words) {
        if(word.substr(1, 3) == "ave")
            result.push_back(word);
    }

    return result;
}

bool areCharactersInWord(string word, string contains) {
    for(const char& character : word)
        for (const char &containsCharacter : contains)
            if (character == containsCharacter)
                return true;
    return false;
}

vector<string> wordsContainingRstlne(const vector<string>& words) {
    vector<string> result;
    string contains = "rstlne";

    // check if any of the given characters are in the word
    for(const string& word : words) {
        if(areCharactersInWord(word, contains))
            result.push_back(word);
    }

    return result;
}

vector<string> wordsWithNoVowels(vector<string> words) {
    vector<string> result;
    string contains = "euioa";

    // check if any of the given characters are in the word
    for(const string& word : words) {
        if(!areCharactersInWord(word, contains))
            result.push_back(word);
    }

    return result;
}


int main() {
    vector<string> words;

    // input words from file
    ifstream fin("../wordlist.txt");
    while(!fin.eof()) {
        string word;
        fin >> word;
        words.push_back(word);
    }

    vector<string> result;

    result = wordsEndingIme(words);
    printVector("Words ending in \"ime\":", result);

    result = wordsContainingAveFrom2ndChar(words);
    printVector("Words containing \"ave\" from second character: ", result);

    result = wordsContainingRstlne(words);
    cout << "Number of words containing at least one of the characters 'r','s','t','l','n','e': "
        << endl << result.size() << endl << endl;

    result = wordsContainingRstlne(words);
    cout << "Percentage of words containing at least one of the characters 'r','s','t','l','n','e': "
        << endl << double(result.size()) / double(words.size()) * 100 << endl << endl;

    result = wordsWithNoVowels(words);
    printVector("Words containing no vowel: ", result);

    return 0;
}