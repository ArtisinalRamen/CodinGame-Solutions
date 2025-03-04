#include <iostream>
// https://www.codingame.com/training/easy/power-of-thor-episode-1

int Difference(int x, int y) {
    return (x > y) - (x < y);
}

int main() {
    int lightX; // the X position of the light of power
    int lightY; // the Y position of the light of power
    int x; // Thor's X position
    int y; // Thor's Y position
    std::cin >> lightX >> lightY >> x >> y; std::cin.ignore();
    int remainingTurns; // The remaining amount of turns Thor can move.
    std::cin >> remainingTurns; std::cin.ignore();

    while (remainingTurns > 0) {
        int xDiff = Difference(lightX, x);
        int yDiff = Difference(lightY, y);
        if (yDiff < 0) {
            std::cout << "N";
            y--;
        }
        if(yDiff > 0) {
            std::cout << "S";
            y++;
        }
        if (xDiff > 0) {
            std::cout << "E";
            x++;
        }
        if(xDiff < 0) {
            std::cout << "W";
            x--;
        }
        std::cout << std::endl;
        // Assumption is made that remainingTurns will only ever decrement by 1.
        // If this assumption is false then getting remaining turns from
        // std::cin is more likely to be necessary.
        // Avoiding the use of std::cin results in a large speedup.
        remainingTurns--;
    }

}