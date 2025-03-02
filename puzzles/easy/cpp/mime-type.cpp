#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
// https://www.codingame.com/training/easy/mime-type
void convert_str_tolower(std::string *str) {
  std::transform(str->begin(), str->end(), str->begin(), ::tolower);
}

int main() {
  int n; // Number of elements which make up the association table.
  int q; // Number Q of file names to be analyzed.
  std::cin >> n >> q;
  std::cin.ignore();
  std::string ext; // file extension
  std::string mt;  // MIME type.
  std::unordered_map<std::string, std::string> assocTable;
  std::unordered_map<std::string, std::string>::const_iterator
      assocTableIterator;

  for (int i = 0; i < n; i++) {
    std::cin >> ext >> mt;
    std::cin.ignore();
    convert_str_tolower(&ext);
    assocTable.insert({ext, mt});
  }

  std::string fName;
  std::string extension;
  int indexOfExtensionSeperator = -1;
  std::string output = "UNKNOWN";
  std::ostringstream out; //output buffer to optimize printing for large dataset
  for (int i = 0; i < q; i++) {
    output = "UNKNOWN";
    getline(std::cin, fName);
    indexOfExtensionSeperator = fName.find_last_of('.');
    if (indexOfExtensionSeperator > -1) {
      extension = fName.substr(indexOfExtensionSeperator + 1);
      convert_str_tolower(&extension);
      assocTableIterator = assocTable.find(extension);
      if (assocTableIterator != assocTable.end()) {
        output = assocTableIterator->second;
      }
    }
    out << output << "\n";
  }
  std::cout << out.str() << std::flush;
}