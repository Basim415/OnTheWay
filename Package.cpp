//
// Created by Basim Shahzad on 12/15/24.
//

#include<iostream>
#include<string>
#include<cctype>
#include "Package.h"
using namespace std;

Package::Package() {
    carrierName = "No name";
    receiverName= "No name";
    destinationBuilding = "No destination";
    weight = 0.0;
    quantity = 0;

    cout << "Default constructor called" << endl;
}

Package::Package(string carrierName, string receiverName, string destinationBuilding, float weight, double quantity) {
    this->carrierName = carrierName;
    this->receiverName = receiverName;
    this->destinationBuilding = destinationBuilding;
    this->weight = weight;
    this->quantity = quantity;

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

float Package::getWeight() {
    return weight;
}

double Package::getQuantity() {
    return quantity;
}

void Package::setCarrierName(const string &name) {
    if (name.empty()) {
        cout << "Carrier name must be recorded" << endl;
        return;
    }
    for (int i = 0; i < name.size(); i++) {
        if (!isalpha(name[i]) && name[i] != ' ' && name[i] != '-') {
            cout << "Carrier name must be a valid character" << endl;
            return;
        }
    }
    carrierName = name;
}


void Package::setReceiverName(const string &recname) {
    if (recname == "") {
        cout << "Receiver name must be recorded" << endl;
    } else {
        receiverName = recname;
    }
}

void Package::setDestinationBuilding(const string &building) {
    if (building == "") {
        cout << "Building needed to complete delivery" << endl;
    } else {
        destinationBuilding = building;
    }
}

void Package::setWeight(float weight) {
    if (weight <= 0.0) {
        cout << "Weight must be positive" << endl;
    } else {
        this->weight = weight;
    }
}

void Package::setQuantity(double quantity) {
    if (quantity <= 0.0) {
        cout << "Quantity must be positive" << endl;
    } else {
        this->quantity = quantity;
    }
}

ostream &operator<<(std::ostream &os, const Package &pack) {
    os << "Carrier: " << pack.carrierName << "\n"
       << "Receiver: " << pack.receiverName << "\n"
       << "Destination: " << pack.destinationBuilding << "\n"
       << "Weight: " << pack.weight << " lbs" <<"\n"
       << "Quantity: " << pack.quantity << endl;

    return os;
}

istream &operator>>(std::istream &is, Package &pack) {
    // Read all input fields in order
    getline(is, pack.carrierName);
    getline(is, pack.receiverName);
    getline(is, pack.destinationBuilding);
    is >> pack.weight >> pack.quantity;

    // Check for invalid input
    if (is.fail() || pack.weight <= 0 || pack.quantity < 0) {
        cerr << "Invalid input for Package.\n";
        is.setstate(ios::failbit);  // Mark the stream as failed
    }

    // Clear the input buffer to handle any leftover characters
    is.ignore(numeric_limits<streamsize>::max(), '\n');

    return is;
}



