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
    double quantity;

public:
    Package(); // Blank constructor
    Package(string carrierName, string receiverName, string destinationBuilding, float weight, double quantity);// Parametrized Constructor
    ~Package(); // Destructor

    //Gettters
    string getCarrierName(); //
    string getReceiverName();
    string getDestinationBuilding();
    float getWeight() ;
    double getQuantity();

    //Setters
    void setCarrierName(const string &name);
    void setReceiverName(const string &name);
    void setDestinationBuilding(const string &building);
    void setWeight(float weight);
    void setQuantity(double quantity);


    friend ostream &operator<<(ostream &os, const Package &pack); // Left as const so that it displays without changing
    friend istream &operator>>(istream &is, Package &pack);

};



#endif //PACKAGE_H
