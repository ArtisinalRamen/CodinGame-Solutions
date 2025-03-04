#include <bitset>
#include <iostream>
#include <string>
// https://www.codingame.com/training/easy/unary
int main() {
  std::string message;
  getline(std::cin, message);
  std::string binaryChar;
  std::string unaryMessage;
  bool newSeries;
  char lastChar = 'A'; // Just any char that isn't 0 or 1, no significance of A in particular

  for (char c : message) {
    binaryChar = std::bitset<7>(c).to_string();

    for (char bit : binaryChar) {
      newSeries = bit != lastChar;
      lastChar = bit;

      if (newSeries) {
        if (unaryMessage.length() > 0) {
          unaryMessage.append(" ");
        }
        if (bit == '0') {
          unaryMessage.append("00 ");
        } else {
          unaryMessage.append("0 ");
        }
      }
      unaryMessage.append("0");
    }
  }
  std::cout << unaryMessage << std::endl;
}