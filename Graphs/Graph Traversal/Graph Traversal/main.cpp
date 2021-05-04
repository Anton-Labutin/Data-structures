//
//  main.cpp
//  Graph Traversal
//
//  Created by Лабутин Антон Александрович on 06.09.2020.
//  Copyright © 2020 Labutin Anton. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

void
dfs(int vertexCurrent, const vector<vector<int>>& adjList, vector<bool>& vertexUsed, vector<int>& vertexTraversed)
{
    vertexUsed[vertexCurrent] = true;
    vertexTraversed.push_back(vertexCurrent);

    for (const int& adjVertex : adjList[vertexCurrent]) {
        if (! vertexUsed[adjVertex]) {
            dfs(adjVertex, adjList, vertexUsed, vertexTraversed);
            vertexTraversed.push_back(vertexCurrent);
        }
    }
}

void
DFS(const vector<vector<int>>& adjList, int vertexStart, vector<int>& vertexTraversed)
{
    vector<bool> vertexUsed(adjList.size(), false);

    dfs(vertexStart, adjList, vertexUsed, vertexTraversed);
}

int
main()
{
    int vertexCnt, edgeCnt;
    cin >> vertexCnt >> edgeCnt;

    vector<vector<int>> adjList(vertexCnt + 1);
    int v1, v2;
    for (int i = 0; i < edgeCnt; ++i) {
        cin >> v1 >> v2;
        adjList[v1].push_back(v2);
        adjList[v2].push_back(v1);
    }

    int vertexStart;
    cin >> vertexStart;

    vector<int> vertexTraversed;
    DFS(adjList, vertexStart, vertexTraversed);

    cout << vertexTraversed.size() << endl;
    for (size_t i = 0; i < vertexTraversed.size(); ++i) {
        if (i) {
            cout << " ";
        }

        cout << vertexTraversed[i];
    }

    return 0;
}
