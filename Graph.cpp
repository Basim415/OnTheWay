//
// Created by Basim Shahzad on 12/15/24.
//
#include "Graph.h"

#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

Graph::Graph(int numBuildings) {
    this->numBuildings = numBuildings;

    // Resize adjacency matrix to be numBuildings x numBuildings and initialize with 0
    adjMatrix.resize(numBuildings, vector<int>(numBuildings, 0));
}

void Graph::insertNode(string name) {
    // Check if node is already in graph
    if (find(buildingList.begin(), buildingList.end(), name) == buildingList.end()) {
        buildingList.push_back(name);
        this->Resize(buildingList.size()); // Resize adjacency matrix
    }
}

void Graph::removeNode(string name) {
    // Check if node exists and remove only if true
    auto it = find(buildingList.begin(), buildingList.end(), name);

    if (it != buildingList.end()) {
        // Find the index of this name in the buildingList
        int index = distance(buildingList.begin(), it);

        // Remove all columns at index in adjacency matrix
        for (auto &row : adjMatrix) {
            row.erase(row.begin() + index);
        }

        // Remove the row at index in adjacency matrix
        adjMatrix.erase(adjMatrix.begin() + index);

        // Remove the label from the building list
        buildingList.erase(it);
    }
}

void Graph::Resize(size_t newSize) {
    // Resize the adjacency matrix and copy in the old values
    vector<vector<int>> oldMatrix = adjMatrix;
    adjMatrix = vector<vector<int>>(newSize, vector<int>(newSize, 0));

    for (size_t row = 0; row < min(newSize, oldMatrix.size()); ++row) {
        for (size_t col = 0; col < min(newSize, oldMatrix[row].size()); ++col) {
            adjMatrix[row][col] = oldMatrix[row][col];
        }
    }
}

vector<string>::iterator Graph::searchNode(string name) {
    return find(buildingList.begin(), buildingList.end(), name);
}

void Graph::insertEdge(string fromNode, string toNode) {
    // Ensure both nodes exist in the graph
    if (searchNode(toNode) == buildingList.end()) {
        insertNode(toNode);
    }

    if (searchNode(fromNode) == buildingList.end()) {
        insertNode(fromNode);
    }

    int fromNodeIndex = distance(buildingList.begin(), searchNode(fromNode));
    int toNodeIndex = distance(buildingList.begin(), searchNode(toNode));

    // Update the adjacency matrix to have a path between two nodes
    adjMatrix[fromNodeIndex][toNodeIndex] = 1;
}

void Graph::removeEdge(string fromNode, string toNode) {
    // Ensure both nodes exist before accessing adjacency matrix
    auto fromNodeIt = searchNode(fromNode);
    auto toNodeIt = searchNode(toNode);

    if (fromNodeIt != buildingList.end() && toNodeIt != buildingList.end()) {
        int fromNodeIndex = distance(buildingList.begin(), fromNodeIt);
        int toNodeIndex = distance(buildingList.begin(), toNodeIt);

        // Remove the path between two nodes
        adjMatrix[fromNodeIndex][toNodeIndex] = 0;
    }
}

bool Graph::searchEdge(string fromNode, string toNode) {
    // Ensure both nodes exist before accessing adjacency matrix
    auto fromNodeIt = searchNode(fromNode);
    auto toNodeIt = searchNode(toNode);

    if (fromNodeIt != buildingList.end() && toNodeIt != buildingList.end()) {
        int fromNodeIndex = distance(buildingList.begin(), fromNodeIt);
        int toNodeIndex = distance(buildingList.begin(), toNodeIt);
        return adjMatrix[fromNodeIndex][toNodeIndex] == 1;
    }
    return false;
}

void Graph::printGraph() {
    size_t numNodes = buildingList.size();
    int fieldWidth = 10;

    cout << setw(fieldWidth) << " ";
    for (size_t col = 0; col < numNodes; ++col) {
        cout << setw(fieldWidth) << buildingList[col];
    }
    cout << endl;

    // Print the adjacency matrix with a label before each row
    for (size_t row = 0; row < numNodes; ++row) {
        // Print row label
        cout << setw(fieldWidth) << buildingList[row];

        // Print each row - one column at a time
        for (size_t col = 0; col < numNodes; ++col) {
            cout << setw(fieldWidth) << adjMatrix[row][col];
        }
        cout << endl;
    }
}
