//
// Created by Basim Shahzad on 2/11/25.
//

#ifndef UTIL_H
#define UTIL_H

void display_menu() {
    cout << "\n1 - Add a package" << endl;
    cout << "2 - View Current Packages " << endl;
    cout << "3 - View Route" << endl;
    cout << "4 - Remove Package from Route" << endl;
    cout << "5 - Mark As Delivered" << endl;
    cout << "0 - Quit" << endl;
    cout << "===============================================\n";
}


void display_packlist(const list<Package> &packlist, const Package &current_pack) {
    if (packlist.empty()) {
        cout << "There are no packages in the list." << endl;
        return;
    }

    cout << "Added Packages: " << endl;
    for (auto const& i : packlist) {
        if (i == current_pack) {
            cout << "-> Recently added: " << i << endl;
        } else {
            cout << "   " << i << endl;
        }
    }
    cout << endl;
}

void remove_package(list<Package> &packlist) {
    string tempCarrierName;
    string tempRecieverName;
    string tempDestination;
    float tempWt;
    double tempQt;

    if(packlist.empty()) {
        cout << "There are no packages in the list." << endl;
        return;
    }
    cout << "Enter the details of the package to remove:" << endl;
    cout << "\nEnter carrier name: ";
    getline(cin, tempCarrierName);
    cout << "\nEnter receiver: ";
    getline(cin, tempRecieverName);
    cout << "\nEnter destination build: ";
    getline(cin, tempDestination);
    cout << "\nEnter weight: ";
    cin >> tempWt;
    cout << "\nEnter quantity: ";
    cin >> tempQt;

    Package tempPack (tempCarrierName, tempRecieverName, tempDestination, tempWt, tempQt);

    for (auto it = packlist.begin(); it != packlist.end(); it++) {
        if (*it == tempPack) {
            packlist.erase(it);
            cout << "Package removed successfully." << endl;
            return;
        }
    }
    cout << "Package not found." << endl;
}

void delivered(list<Package> &packlist) {
    // Temporary variables to store user input
    string tempCarrierName;
    string tempReceiverName;
    string tempDestination;
    float tempWt;
    double tempQt;

    // Check if the list is empty
    if (packlist.empty()) {
        cout << "There are no packages in the list." << endl;
        return;
    }

    // Prompt the user for package details
    cout << "Enter the details of the package to mark as delivered:" << endl;
    cout << "\nEnter carrier name: ";
    getline(cin, tempCarrierName);
    cout << "\nEnter receiver: ";
    getline(cin, tempReceiverName);
    cout << "\nEnter destination building: ";
    getline(cin, tempDestination);
    cout << "\nEnter weight: ";
    cin >> tempWt;
    cout << "\nEnter quantity: ";
    cin >> tempQt;

    // Create a temporary package object
    Package tempPack(tempCarrierName, tempReceiverName, tempDestination, tempWt, tempQt);

    // Traverse the list to find the matching package
    for (auto &package : packlist) {
        if (package == tempPack) {
            package.markAsDelivered();  // Mark the package as delivered
            cout << "Package marked as delivered successfully." << endl;
            return;
        }
    }

    // If no match was found
    cout << "No matching package found." << endl;
}

void menu_logic(list<Package> &packlist, list<Package>::iterator &current_pack) {
    int user_choice;
    string car_name, rec_name, dest_build;
    float wt;
    double qt;

    do {
        display_menu();
        cout << "Enter a selection (0 to quit):" << endl;
        cin >> user_choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

        switch (user_choice) {
            case 1:
                cout << "Adding a new package" << endl;
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

                packlist.emplace_back(car_name, rec_name, dest_build, wt, qt);
                cout << "Package Added Successfully!" << endl;
                break;

            case 2:
                if (!packlist.empty()) {
                    display_packlist(packlist, *packlist.begin()); // Use first package as default
                } else {
                    cout << "No packages to display." << endl;
                }
                break;

            case 3:
                if (packlist.empty()) {
                    cout << "There is no route." << endl;
                } else {
                    cout << "Route displayed here." << endl;
                }
                break;

            case 4:
                remove_package(packlist);
                break;

            case 5:
                delivered(packlist);
                break; // Missing break added here

            case 0:
                cout << "Great work!" << endl;
                break;

            default:
                cout << "Unknown selection. Please try again." << endl;
                break;
        }
    } while (user_choice != 0); // Loop until 0 is entered
}




#endif //UTIL_H
