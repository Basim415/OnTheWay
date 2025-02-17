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
    Graph schoolGraph(7);  // Assume 7 buildings
    schoolGraph.insertNode("Maintenance/Utility");
    schoolGraph.insertNode("Library");
    schoolGraph.insertNode("Student Services");
    schoolGraph.insertNode("Gym");
    schoolGraph.insertNode("Math Building");
    schoolGraph.insertNode("Science Building");
    schoolGraph.insertNode("Cafeteria");

    // Step 2: Insert paths (edges) between buildings
    schoolGraph.insertEdge("Maintenance/Utility", "Library");
    schoolGraph.insertEdge("Library", "Student Services");
    schoolGraph.insertEdge("Student Services", "Gym");
    schoolGraph.insertEdge("Gym", "Math Building");
    schoolGraph.insertEdge("Math Building", "Science Building");
    schoolGraph.insertEdge("Science Building", "Cafeteria");

    // Step 3: Create a list of packages for delivery
    list<Package> packlist;
    packlist.emplace_back("FedEx", "John Doe", "Library", 5.0, 2);
    packlist.emplace_back("UPS", "Jane Smith", "Science Building", 10.0, 1);
    packlist.emplace_back("DHL", "Mark Brown", "Cafeteria", 7.5, 3);

    // Step 4: Run the menu logic for user interaction
    menuLogic(schoolGraph, packlist);

    return 0;
}
