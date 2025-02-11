//
// Created by Basim Shahzad on 2/11/25.
//

#include "util.h"

void displayMenu() {
    cout << "\n1 - Add a package" << endl;
    cout << "2 - View Current Packages" << endl;
    cout << "3 - View Route" << endl;
    cout << "4 - Remove Package from Route" << endl;
    cout << "5 - Mark As Delivered" << endl;
    cout << "0 - Quit" << endl;
    cout << "===============================================\n";
}

void addPackage(list<Package> &packlist) {
    string car_name, rec_name, dest_build;
    float wt;
    double qt;

    cout << "Enter carrier name: ";
    getline(cin, car_name);
    cout << "Enter receiver: ";
    getline(cin, rec_name);
    cout << "Enter destination build: ";
    getline(cin, dest_build);
    cout << "Enter weight: ";
    cin >> wt;
    cout << "Enter quantity: ";
    cin >> qt;
    cin.ignore(); // Clear newline from input buffer

    packlist.emplace_back(car_name, rec_name, dest_build, wt, qt);
    cout << "Package Added Successfully!" << endl;
}

void displayPacklist(const list<Package> &packlist) {
    if (packlist.empty()) {
        cout << "There are no packages in the list." << endl;
        return;
    }

    cout << "Added Packages:" << endl;
    for (const auto &pkg : packlist) {
        cout << pkg << endl;  // Assuming `Package` has `operator<<` overload
    }
}

void removePackage(list<Package> &packlist) {
    string tempCarrierName, tempReceiverName, tempDestination;
    float tempWt;
    double tempQt;

    if (packlist.empty()) {
        cout << "There are no packages in the list." << endl;
        return;
    }

    cout << "Enter the details of the package to remove:" << endl;
    cout << "Enter carrier name: ";
    getline(cin, tempCarrierName);
    cout << "Enter receiver: ";
    getline(cin, tempReceiverName);
    cout << "Enter destination building: ";
    getline(cin, tempDestination);
    cout << "Enter weight: ";
    cin >> tempWt;
    cout << "Enter quantity: ";
    cin >> tempQt;
    cin.ignore(); // Clear newline from input buffer

    Package tempPack(tempCarrierName, tempReceiverName, tempDestination, tempWt, tempQt);

    for (auto it = packlist.begin(); it != packlist.end(); ++it) {
        if (*it == tempPack) {  // Assuming `Package` has `operator==` defined
            packlist.erase(it);
            cout << "Package removed successfully." << endl;
            return;
        }
    }
    cout << "Package not found." << endl;
}

void delivered(list<Package> &packlist) {
    string tempCarrierName, tempReceiverName, tempDestination;
    float tempWt;
    double tempQt;

    if (packlist.empty()) {
        cout << "There are no packages in the list." << endl;
        return;
    }

    cout << "Enter the details of the package to mark as delivered:" << endl;
    cout << "Enter carrier name: ";
    getline(cin, tempCarrierName);
    cout << "Enter receiver: ";
    getline(cin, tempReceiverName);
    cout << "Enter destination building: ";
    getline(cin, tempDestination);
    cout << "Enter weight: ";
    cin >> tempWt;
    cout << "Enter quantity: ";
    cin >> tempQt;
    cin.ignore(); // Clear newline from input buffer

    Package tempPack(tempCarrierName, tempReceiverName, tempDestination, tempWt, tempQt);

    for (auto &package : packlist) {
        if (package == tempPack) {
            package.markAsDelivered();  // Assuming `Package` has a `markAsDelivered()` function
            cout << "Package marked as delivered successfully." << endl;
            return;
        }
    }

    cout << "No matching package found." << endl;
}

void menuLogic(list<Package> &packlist, list<Package>::iterator &current_pack) {
    int user_choice;
    do {
        displayMenu();
        cout << "Enter a selection (0 to quit): ";
        cin >> user_choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

        switch (user_choice) {
            case 1:
                addPackage(packlist);
                break;

            case 2:
                displayPacklist(packlist);
                break;

            case 3:
                if (packlist.empty()) {
                    cout << "There is no route." << endl;
                } else {
                    cout << "Route displayed here." << endl;  // Placeholder for future logic
                }
                break;

            case 4:
                removePackage(packlist);
                break;  // Fixed missing break

            case 5:
                delivered(packlist);
                break;

            case 0:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Unknown selection. Please try again." << endl;
                break;
        }
    } while (user_choice != 0);
}

