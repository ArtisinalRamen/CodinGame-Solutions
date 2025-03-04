#include <iostream>
#include <string>
// https://www.codingame.com/training/medium/shadows-of-the-knight-episode-1

int main() {
    int w; // width of the building.
    int h; // height of the building.
    std::cin >> w >> h; std::cin.ignore();
    int n; // maximum number of turns before game over.
    std::cin >> n; std::cin.ignore();
    int x0;
    int y0;
    std::cin >> x0 >> y0; std::cin.ignore();
    int xOut = x0;
    int yOut = y0;
    int xMax = w;
    int xMin = 0;
    int yMax = h;
    int yMin = 0;
    std::string bomb_dir; // the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)

    // game loop
    while (1) {
        std::cin >> bomb_dir; std::cin.ignore();
        x0 = xOut;
        y0 = yOut;
        
        for (char &c : bomb_dir) {
            switch(c) {
                case 'R':
                    xMin = x0;
                    break;
                case 'L':
                    xMax = x0;
                    break;
                case 'D':
                    yMin = y0;
                    break;
                case 'U':
                    yMax = y0;
                    break;
            }
        }

        xOut = (xMax + xMin) / 2;
        yOut = (yMin + yMax) / 2;

        // the location of the next window Batman should jump to.
        std::cout << xOut << " " << yOut << std::endl;
    }
}