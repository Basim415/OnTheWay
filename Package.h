//
// Created by Basim Shahzad on 12/15/24.
//

#ifndef PACKAGE_H
#define PACKAGE_H
#include <string>

using namespace std;


class Package {
private:
    string carrierName;
    string reciverName;
    string destinationBuilding;
    float weight;
public:
    Package(); // Blank constructor
    Package(string carrierName, string reciverName, string destinationBuilding, float weight);



};






#endif //PACKAGE_H