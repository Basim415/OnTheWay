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
    Graph schoolGraph(18);  // Assume 18 buildings
    schoolGraph.insertNode("Receiving");
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
    schoolGraph.insertNode("Athletics Building");
    schoolGraph.insertNode("Journalism Building");
    schoolGraph.insertNode("Art Building");

    // Step 2: Insert paths (edges) between buildings
    schoolGraph.insertEdge("Receiving", "Student Services");
    schoolGraph.insertEdge("Receiving", "Music Building");
    schoolGraph.insertEdge("Music Building", "ETEC");
    schoolGraph.insertEdge("Child Study Center", "Library ");
    schoolGraph.insertEdge("Library", "IT Department");
    schoolGraph.insertEdge("Student Services", "Gym");
    schoolGraph.insertEdge("Gym", "Math Building");
    schoolGraph.insertEdge("Math Building", "Science Building");
    schoolGraph.insertEdge("Student Union", "Cafeteria");

    // Step 3: Create a list of packages for delivery
    list<Package> packlist;
    packlist.emplace_back("FedEx", "John Doe", "Library", 5.0, 2);
    packlist.emplace_back("UPS", "Jane Smith", "Science Building", 10.0, 1);
    packlist.emplace_back("DHL", "Mark Brown", "Cafeteria", 7.5, 3);

    // Step 4: Run the menu logic for user interaction
    menuLogic(schoolGraph, packlist);

    return 0;
}
