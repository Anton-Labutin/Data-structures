//
//  main.cpp
//  Graph Implementation
//
//  Created by Лабутин Антон Александрович on 04.09.2020.
//  Copyright © 2020 Labutin Anton. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void
FromAdjacencyMatrixToAdjacencyList()
{
    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> adjList;
    char x;

    do {
        cin.get(x);
    } while (isspace(x));

    for (int i = 0; i < n; ++i) {
        int j = 1;

        while (!isspace(x)) {
            if (x == '1') {
                adjList.push(j);
            }
            cin.get(x);
            ++j;
        }

        cout << adjList.size();
        while (adjList.size()) {
            cout << " " << adjList.top();
            adjList.pop();
        }
        cout << endl;
    }
}

void
FromEdgeListToAdjacencyList()
{
    int vertexCnt, edgeCnt;
    cin >> vertexCnt >> edgeCnt;

    vector<priority_queue<int, vector<int>, greater<int>>> adjList(vertexCnt);
    int vertex1, vertex2;

    for (int i = 0; i < edgeCnt; ++i) {
        cin >> vertex1 >> vertex2;
        adjList[vertex1 - 1].push(vertex2);
        adjList[vertex2 - 1].push(vertex1);
    }

    for (int i = 0; i < vertexCnt; ++i) {
        cout << adjList[i].size();
        while (adjList[i].size()) {
            cout << " " << adjList[i].top();
            adjList[i].pop();
        }
        cout << endl;
    }
}

void
FromEdgeListToAdjacencyMatrix()
{
    int vertexCnt, edgeCnt;
    cin >> vertexCnt >> edgeCnt;

    vector<vector<bool>> adjMatrix(vertexCnt, vector<bool>(vertexCnt, 0));
    int vertex1, vertex2;

    for (int i = 0; i < edgeCnt; ++i) {
        cin >> vertex1 >> vertex2;

        adjMatrix[vertex1 - 1][vertex2 - 1] = 1;
        adjMatrix[vertex2 - 1][vertex1 - 1] = 1;
    }

    for (int i = 0; i < vertexCnt; ++i) {
        for (int j = 0; j < vertexCnt; ++j) {
            cout << adjMatrix[i][j];
        }
        cout << endl;
    }
}

void
FromAdjacencyListToAdjacencyMatrix()
{
    int vertexCnt;
    cin >> vertexCnt;

    vector<vector<bool>> adjMatrix(vertexCnt, vector<bool>(vertexCnt, 0));

    int neighbourCnt;
    int neighbour;
    for (int i = 0; i < vertexCnt; ++i) {
        cin >> neighbourCnt;
        while (neighbourCnt) {
            cin >> neighbour;
            adjMatrix[i][neighbour - 1] = 1;
            adjMatrix[neighbour - 1][i] = 1;
            --neighbourCnt;
        }
    }

    for (int i = 0; i < vertexCnt; ++i) {
        for (int j = 0; j < vertexCnt; ++j) {
            cout << adjMatrix[i][j];
        }
        cout << endl;
    }
}

void
FromAdjacencyMatrixToEdgeList()
{
    int vertexCnt;
    cin >> vertexCnt;

    vector<priority_queue<int, vector<int>, greater<int>>> adjList(vertexCnt);
    char digit;
    int edgeCnt = 0;

    for (int i = 0; i < vertexCnt; ++i) {
        do {
            cin.get(digit);
        } while (isspace(digit));

        for (int j = 0; j < vertexCnt; ++j) {
            if (digit == '1') {
                if (i < j) {
                    adjList[i].push(j);
                    ++edgeCnt;
                }
            }

            cin.get(digit);
        }
    }

    cout << edgeCnt << endl;
    size_t vertexNum = 0;
    for (int i = 0; i < edgeCnt; ++i) {
        while (! adjList[vertexNum].size()) {
            ++vertexNum;
        }

        cout << vertexNum + 1 << " " << adjList[vertexNum].top() + 1 << endl;
        adjList[vertexNum].pop();
    }
}

int
main()
{
    // FromAdjacencyMatrixToAdjacencyList
    // FromEdgeListToAdjacencyList();
    // FromEdgeListToAdjacencyMatrix();
    // FromAdjacencyListToAdjacencyMatrix();
    FromAdjacencyMatrixToEdgeList();

    return 0;
}
