//
// Created by Basim Shahzad on 12/15/24.
//

#ifndef GRAPH_H
#define GRAPH_H
#include "Package.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;

class Graph {
private:
    //List of labels or building names in graph
    vector<string> buildingList;

    //Number of buildings for the map
    int numBuildings;

    //Adjacency matrix: vector containing a vector of integers (Dynamic 2D Array)
    // for directed graph rows fill be from, columns will be to
    vector<vector<int>> adjMatrix; //
public:
    Graph(int numBuildings);
    ~Graph() = default;

    void insertNode(string name);
    void removeNode(string name);
    void insertEdge(string fromNode, string toNode);
    void removeEdge(string fromNode, string toNode);
    void Resize(size_t newSize);
    bool searchEdge(string fromNode, string toNode);
    void printGraph();
    vector<string>:: iterator searchNode(string name);
    vector<string> findOptimalRoute(const list<Package> &packages);


};

#endif //GRAPH_H