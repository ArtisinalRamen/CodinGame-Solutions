#include <iostream>
// https://www.codingame.com/training/easy/temperatures
int main() {
    int n; // the number of temperatures to analyse
    std::cin >> n; std::cin.ignore();
    
    if (n == 0) { // early out if number of temperatures is 0
        std::cout << 0 << std::endl;
        return 0;
    }

    int t; // a temperature expressed as an integer ranging from -273 to 5526
    int closest = 9999;
    for (int i = 0; i < n; i++) {
        std::cin >> t; std::cin.ignore();
        if (abs(t) < abs(closest) || (t > 0 && abs(t) == abs(closest))) {
            closest = t;
        }
    }
    std::cout << closest << std::endl;
    return closest;
}