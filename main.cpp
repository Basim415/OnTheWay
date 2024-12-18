#include <iostream>
#include <sstream>
#include "Package.h"
using namespace std;

int main() {

    //Default constructor is working
    Package A;

    //Parameterized constructor is working
    Package B ("Fedex", "Andrew Murphy", "Student Services", 24);

    cout << B << endl;
    cout << endl;

    cout << A << endl;





    return 0;
}

//test file