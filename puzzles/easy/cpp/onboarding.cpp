#include <iostream>
#include <string>
// https://www.codingame.com/training/easy/onboarding

int main()
{
	std::string enemy_1; // name of enemy 1
	std::string enemy_2; // name of enemy 2
	int dist_1; // distance to enemy 1
	int dist_2; // distance to enemy 2
    while (true) {
        std::cin >> enemy_1; std::cin.ignore();
        std::cin >> dist_1; std::cin.ignore();
        std::cin >> enemy_2; std::cin.ignore();
        std::cin >> dist_2; std::cin.ignore();
        std::cout << (dist_1 <= dist_2 ? enemy_1 : enemy_2) << std::endl;
    }
}