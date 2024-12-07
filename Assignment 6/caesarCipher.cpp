#include <iostream>
#include <fstream>
using namespace std;

void caesarCipher(string& text, int encodeValue) {
    for(char& character : text)
        character = (character + encodeValue) % 256;
}

void decodeCaesarCipher(string& text, int encodeValue) {
    for(char& character : text)
        character = (character - encodeValue) % 256;
}

int main() {
    // define input output file streams
    ifstream fin("../caesarCipherInput.txt");
    ofstream fout("../caesarCipherOutput.txt");

    // read all piped input into a string
    // this is better than getline, since it can save whitespaces into a string, allowing us to encode the whitespaces too
    // you can not encode whitespaces with getline
    istreambuf_iterator<char> begin(fin), end;
    string text(begin, end);

    caesarCipher(text, -6);

    fout << text;

    fin.close();
    fout.close();

    /* Test decoding
    fin.open("../caesarCipherOutput.txt");
    istreambuf_iterator<char> begin2(fin), end2;
    string text2(begin2, end2);
    decodeCaesarCipher(text2, -6);
    cout << text2;
     /**/

    return 0;
}