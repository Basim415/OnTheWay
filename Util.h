// Created by Basim Shahzad on 2/11/25.
//

#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <list>
#include "Package.h"

using namespace std;

// Function Declarations
void displayMenu();
void addPackage(list<Package> &packlist);
void displayPacklist(const list<Package> &packlist);
void removePackage(list<Package> &packlist);
void delivered(list<Package> &packlist);
void menuLogic(list<Package> &packlist, list<Package>::iterator &current_pack);

#endif // UTIL_H
