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
    string receiverName;
    string destinationBuilding;
    float weight;
public:
    Package(); // Blank constructor
    Package(string carrierName, string receiverName, string destinationBuilding, float weight);// Parametrized Constructor
    ~Package(); // Destructor

    //Gettters
    string getCarrierName(); //
    string getReceiverName();
    string getDestinationBuilding();
    float getWeight() const;

    //Setters
    void setCarrierName(const string &name);
    void setReceiverName(const string &name);
    void setDestinationBuilding(const string &building);
    void setWeight(float weight);

    friend ostream &operator<<(ostream &os, const Package &pack);

};



#endif //PACKAGE_H
