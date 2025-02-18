#include "Package.h"
#include "Graph.h"
#include "Util.h"
#include <iostream>
#include <list>
#include <iomanip>
#include <algorithm>

using namespace std;

int main() {
    // Step 1: Create a Graph with predefined buildings
    Graph schoolGraph(23);  // Assume 24 buildings & locations
    schoolGraph.insertNode("Receiving");
    schoolGraph.insertNode("Maintenance");
    schoolGraph.insertNode("Mail Room");
    schoolGraph.insertNode("Core 2nd Floor");
    schoolGraph.insertNode("Core 3rd Floor");
    schoolGraph.insertNode("Core 4th Floor");
    schoolGraph.insertNode("ETEC");
    schoolGraph.insertNode("PTEC");
    schoolGraph.insertNode("Child Study Center");
    schoolGraph.insertNode("Music Building");
    schoolGraph.insertNode("Library");
    schoolGraph.insertNode("Nursing Department");
    schoolGraph.insertNode("Veterans Resource Center");
    schoolGraph.insertNode("Marketplace");
    schoolGraph.insertNode("Student Services");
    schoolGraph.insertNode("Student Union");
    schoolGraph.insertNode("Book Store");
    schoolGraph.insertNode("Math Building");
    schoolGraph.insertNode("Science Building");
    schoolGraph.insertNode("IT Department");
    schoolGraph.insertNode("Tool Room");
    schoolGraph.insertNode("Kinesiology & Athletics Complex");
    schoolGraph.insertNode("Journalism Building");
    schoolGraph.insertNode("Art Building");

    // Step 2: Insert paths (edges) between buildings
    schoolGraph.insertEdge("Receiving", "Mail Room");
    schoolGraph.insertEdge("Receiving", "Maintenance");
    schoolGraph.insertEdge("Receiving", "Core 2nd Floor");

    schoolGraph.insertEdge("Core 2nd Floor", "Library");
    schoolGraph.insertEdge("Core 2nd Floor", "Child Study Center");
    schoolGraph.insertEdge("Core 2nd Floor", "Marketplace");
    schoolGraph.insertEdge("Core 2nd Floor", "Core 3rd Floor");

    schoolGraph.insertEdge("Core 3rd Floor", "Nursing Department");
    schoolGraph.insertEdge("Core 3rd Floor", "Veterans Resource Center");
    schoolGraph.insertEdge("Core 3rd Floor", "Art Building");
    schoolGraph.insertEdge("Core 3rd Floor", "Journalism Building");
    schoolGraph.insertEdge("Core 3rd Floor", "Tool Room");
    schoolGraph.insertEdge("Core 3rd Floor", "Music Building");
    schoolGraph.insertEdge("Core 3rd Floor", "PTEC");
    schoolGraph.insertEdge("Core 3rd Floor", "Core 4th Floor");
    schoolGraph.insertEdge("Core 3rd Floor", "Student Services");

    schoolGraph.insertEdge("Student Services", "Math Building");
    schoolGraph.insertEdge("Math Building", "Student Union");
    schoolGraph.insertEdge("Math Building", "Science Building");



    schoolGraph.insertEdge("Music Building", "ETEC");
    schoolGraph.insertEdge("Child Study Center", "Library");
    schoolGraph.insertEdge("Library", "IT Department");
    schoolGraph.insertEdge("Library", "Science Building");
    schoolGraph.insertEdge("Student Union", "Kinesiology & Athletics Complex");
    schoolGraph.insertEdge("Science Building", "Kinesiology & Athletics Complex");
    schoolGraph.insertEdge("Science Building", "Student Union");
    schoolGraph.insertEdge("Student Union", "Cafeteria");





    // Step 3: Create a list of packages for delivery
    list<Package> packlist;
    packlist.emplace_back("UPS", "Erica Messenger", "Nursing Department", 40.0, 2);
    packlist.emplace_back("FedEx", "John Doe", "Library", 5.0, 2);
    packlist.emplace_back("UPS", "Jane Smith", "Science Building", 10.0, 1);


    // Step 4: Run the menu logic for user interaction
    menuLogic(schoolGraph, packlist);

    return 0;
}
