//
// Created by Basim Shahzad on 12/15/24.
//

#ifndef PACKAGE_H
#define PACKAGE_H
#include <string>
#include <cctype>

using namespace std;


class Package {
private:
    string carrierName;
    string receiverName;
    string destinationBuilding;
    float weight;
    double quantity;
    bool isDelivered = false;

public:
    Package() = default; // Blank constructor
    Package(string carrierName, string receiverName, string destinationBuilding, float weight, double quantity);// Parametrized Constructor
    ~Package()= default; // Destructor

    //Getters
    string getCarrierName() const;
    string getReceiverName() const;
    string getDestinationBuilding() const;
    float getWeight() const;
    double getQuantity() const;

    //Setters
    void setCarrierName(const string &name);
    void setReceiverName(const string &name);
    void setDestinationBuilding(const string &building);
    void setWeight(float weight);
    void setQuantity(double quantity);


    friend ostream &operator<<(ostream &os, const Package &pack); // Left as const so that it displays without changing
    friend istream &operator>>(istream &is, Package &pack);
    friend bool operator==(const Package &pack1, const Package &pack2);
    bool markAsDelivered();

};



#endif //PACKAGE_H
