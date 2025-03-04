#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <math.h>
#include <limits>
// https://www.codingame.com/training/easy/defibrillators


double NumStringToDouble(std::string num) {
    int indexOfComma = num.find_last_of(',');
    if (indexOfComma != std::string::npos) {
        num.replace(indexOfComma, 1, ".");
    }
    return std::stod(num);
}

double DegreesToRadians(double deg) {
    return deg * (M_PI / 180);
}

std::vector<std::string> SplitStringByDelim(std::string str, char delimiter) {
    std::vector<std::string> result;
    std::stringstream ss(str);
    std::string element;

    while(getline(ss, element, delimiter)) {
        result.push_back(element);
    }
    return result;
}

class Position {
    private:
        double longitude;
        double latitude;
    public:
        void SetLongitude(double num) { longitude = num; }
        void SetLatitude(double num) { latitude = num; }
        void SetLongitudeFromString(std::string num){
            longitude = NumStringToDouble(num);
         }
        void SetLatitudeFromString(std::string num){
            latitude = NumStringToDouble(num);
         }
        double GetLongitudeDeg() { return longitude; }
        double GetLatitudeDeg() { return latitude; }
        double GetLongitudeRad() { return DegreesToRadians(longitude); }
        double GetLatitudeRad() { return DegreesToRadians(latitude); }
};

double CalcDistance(Position a, Position b) {
    const int RADIUS_OF_EARTH_KM = 6371;
    double x = (b.GetLongitudeRad() - a.GetLongitudeRad()) * std::cos((a.GetLatitudeRad() + b.GetLatitudeRad()) / 2);
    double y = b.GetLatitudeRad() - a.GetLatitudeRad();
    double result = std::sqrt(std::pow(x, 2) + std::pow(y, 2)) * RADIUS_OF_EARTH_KM;
    return result;
}

int main() {
    struct Defibrillator {
        int id;
        std::string name;
        std::string address;
        std::string telephone;
        Position location;
    };

    std::string lon;
    std::cin >> lon; std::cin.ignore();
    std::string lat;
    std::cin >> lat; std::cin.ignore();
    int n;
    std::cin >> n; std::cin.ignore();
    Position user;
    user.SetLongitudeFromString(lon);
    user.SetLatitudeFromString(lat);
    std::string defibInput;
    std::vector<std::string> defibData;
    double closestDistance = std::numeric_limits<double>::infinity();
    double currDistance;
    Defibrillator closestDefib;
    Defibrillator currentDefib;

    for (int i = 0; i < n; i++) {
        getline(std::cin, defibInput);
        defibData = SplitStringByDelim(defibInput, ';');
        currentDefib.id = std::stoi(defibData[0]);
        currentDefib.name = defibData[1];
        currentDefib.address = defibData[2];
        currentDefib.telephone = defibData[3];
        currentDefib.location.SetLongitudeFromString(defibData[4]);
        currentDefib.location.SetLatitudeFromString(defibData[5]);
        currDistance = CalcDistance(user, currentDefib.location);
        if (currDistance < closestDistance) {
            closestDistance = currDistance;
            closestDefib = currentDefib;
        }
    }
    std::cout << closestDefib.name << std::endl;
}