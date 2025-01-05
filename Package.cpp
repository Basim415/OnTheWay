//
// Created by Basim Shahzad on 12/15/24.
//

#include<iostream>
#include <iomanip>
#include<string>
#include<cctype>
#include <cmath>
#include "Package.h"

#include <__ranges/elements_view.h>
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
    if (recname.empty()) {
        cout << "Receiver name must be recorded" << endl;
        return;
    }
    for (int i = 0; i < recname.size(); i++) {
        if (!isalpha(recname[i]) && recname[i] != ' ' && recname[i] != '-') {
            cout << "Receiver name must be a valid character" << endl;
            return;
        }
    }
    receiverName = recname;
}

void Package::setDestinationBuilding(const string &building) {
    if (building.empty()) {
        cout << "Destination name must be recorded" << endl;
        return;
    }
    for (int i = 0; i < building.size(); i++) {
        if (!isalpha(building[i]) && building[i] != ' ' && building[i] != '-') {
            cout << "Destination name must be a valid destination" << endl;
            return;
        }
        destinationBuilding = building;
    }
}

void Package::setWeight(float weight) {
    float max_wt = 1000.0;
    float min_wt = 0.0;

    if (isnan(weight) || isinf(weight)) {
        cout << "Weight must be a finite numeric value." << endl;
        return;
    }
    if (weight <= min_wt) {
        cout << "Weight must be at least the minimum weight. " << endl;
        return;
    }
    if (weight >= max_wt) {
        cout << "Weight cannot exceed the maximum weight. " << endl;
        return;
    }

    this -> weight = weight;
}

void Package::setQuantity(double quantity) {
    double max_qt = 100.0;
    double min_qt = 0.0;

    if (isnan(quantity) || isinf(quantity)) {
        cout << "Quantity must be a finite numeric value." << endl;
        return;
    }
    if (quantity <= min_qt) {
        cout << "Quantity must be at least the minimum quantity. " << endl;
        return;
    }
    if (quantity >= max_qt) {
        cout << "Quantity must be at least the maximum quantity. " << endl;
    }

    this->quantity = quantity;

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

bool operator==(const Package &p1, const Package &p2) {
    return (p1.carrierName == p2.carrierName &&
            p1.receiverName == p2.receiverName &&
            p1.destinationBuilding == p2.destinationBuilding &&
            p1.weight == p2.weight &&
            p1.quantity == p2.quantity);
}

bool Package::markAsDelivered() {
    this -> isDelivered = true;
    return isDelivered;

}