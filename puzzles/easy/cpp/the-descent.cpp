#include <iostream>
// https://www.codingame.com/training/easy/the-descent

int main()
{
    while (1) {
        int out = 0;
        int highestMountainHeight = 0;
        int currentMountainHeight = 0;
        for (int i = 0; i < 8; i++) {
            std::cin >> currentMountainHeight; std::cin.ignore();
            if (currentMountainHeight > highestMountainHeight){
                out = i;
                highestMountainHeight = currentMountainHeight;
            }            
        }
        std::cout << out << std::endl;
    }
}