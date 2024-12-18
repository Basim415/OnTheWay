//
// Created by Basim Shahzad on 12/15/24.
//

#include<iostream>
#include<string>
#include "Package.h"
using namespace std;

Package::Package() {
    carrierName = "No name";
    receiverName= "No name";
    destinationBuilding = "No destination";
    weight = 0.0;

    cout << "Default constructor called" << endl;
}

Package::Package(string carrierName, string receiverName, string destinationBuilding, float weight) {
    this->carrierName = carrierName;
    this->receiverName = receiverName;
    this->destinationBuilding = destinationBuilding;
    this->weight = weight;

    cout << "Paramterized constructor called" << endl;
}

Package::~Package() {
    cout << "Destructor called" << endl;
}

string Package::getCarrierName() {
    return carrierName;
}

string Package::getReceiverName() {
    return receiverName;
}

string Package::getDestinationBuilding() {
    return destinationBuilding;
}

float Package::getWeight() const {
    return weight;
}

void Package::setCarrierName(const string &name) {
    if (name == "") {
        cout << "Carrier name must be recorded" << endl;
    } else {
        carrierName = name;
    }

}

void Package::setReceiverName(const string &name) {
}

void Package::setDestinationBuilding(const string &building) {
}

//void Package::setWeight(float weight) {
   // if {weight < 0.0) {
       // cout << "Invalid weight" << endl;
    //}

    //}
//}

ostream &operator<<(std::ostream &os, const Package &pack) {
    os << "Carrier: " << pack.carrierName << "\n"
       << "Receiver: " << pack.receiverName << "\n"
       << "Destination: " << pack.destinationBuilding << "\n"
       << "Weight: " << pack.weight << " lbs";
    return os;
}

