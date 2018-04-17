//
//  main.cpp
//  CodeSprintLA
//
//  Created by Christopher Aziz on 1/28/17.
//  Copyright © 2017 Christopher Aziz. All rights reserved.
//

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

struct Node {
    bool isStop = false;
    int connects[100];
    int numEdges;
};

Node* nodes;

int visit(int n, Node node) {
    int maxPokeStops = 0;
    for (int i = 0; i < node.numEdges; i++) {
        Node next = nodes[node.connects[i]];
        next.numEdges--;
        int j;
        for (j = 0; next.connects[j] != n; j++);
        for (int k = j; k < next.numEdges; k++) {
            next.connects[k] = next.connects[k+1];
        }
        int x = visit(node.connects[i], next);
        if (x > maxPokeStops)
            maxPokeStops = x;
    }
    return node.isStop + maxPokeStops;
}


int main() {
    int numTestCases;
    cin >> numTestCases;
    for (int i = 0; i < numTestCases; i++) {
        //each test case
        int numNodes, numStops, numEdges;
        cin >> numNodes;
        cin >> numStops;
        cin >> numEdges;
        nodes = new Node[numNodes];
        for (int j = 0; j < numStops; j++) {
            int stop;
            cin >> stop;
            nodes[stop].isStop = true;
        }
        for (int j = 0; j < numEdges; j++) {
            int n1, n2;
            cin >> n1;
            cin >> n2;
            nodes[n1].connects[nodes[n1].numEdges] = n2;
            nodes[n1].numEdges++;
            nodes[n2].connects[nodes[n2].numEdges] = n1;
            nodes[n2].numEdges++;
        }
        cout << visit(0, nodes[0]) << endl;
    }
}


