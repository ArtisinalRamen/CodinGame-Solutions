#include <iostream>
#include <string>
// https://www.codingame.com/training/easy/ascii-art

int main()
{
    const int ASCII_UPPERCASE_ALPHABET_OFFSET = 65; // Uppercase 'A' has an ASCII value of 65
    int length; // Length of the ASCII art representations of an alphabetical character or '?'
    int height; // Height of the ASCII art representations of an alphabetical character or '?'
    std::cin >> length; std::cin.ignore();
    std::cin >> height; std::cin.ignore();
    std::string text; // The text to convert in to a piece of pristine ASCII art
    std::getline(std::cin, text);
    std::string row;
    std::string rowStrings[27]; // strings of current row of ASCII art representations of alphabetical characters or '?'
    int index; // 0 = A, 1 = B ... 25 = Z, 26 = ?
    std::string output;


    for (int i = 0; i < height; i++) {
        getline(std::cin, row);
        // set the value at the correct index in the array to the current row of ascii art input
        for (int j = 0; j < 27; j++) {
            rowStrings[j] = row.substr(j*length, length);
        }

        output.clear();
        for (char &c : text) {
            if (!std::isalpha(c)) {
                index = 26;
            }
            else {
                c = std::toupper(c);
                index = int(c) % ASCII_UPPERCASE_ALPHABET_OFFSET;
            }
            output.append(rowStrings[index].substr(0, length));
        }
        std::cout << output << std::endl;            
    }
}