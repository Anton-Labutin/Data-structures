//
//  main.cpp
//  Find Graph Components
//
//  Created by Лабутин Антон Александрович on 06.09.2020.
//  Copyright © 2020 Labutin Anton. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int
main(int argc, const char * argv[])
{
    int vertexCnt, edgeCnt;
    cin >> vertexCnt >> edgeCnt;

    vector<set<int>> vertexNeighbours(vertexCnt + 1);

    int v1, v2;
    for (int i = 0; i < edgeCnt; ++i) {
        cin >> v1 >> v2;
        vertexNeighbours[v1].insert(v2);
        vertexNeighbours[v2].insert(v1);
    }

    int currentComponent = 0;
    vector<int> vertexComponents(vertexCnt + 1, 0);
    for (size_t i = 0; i < vertexNeighbours.size(); ++i) {
        
    }

    return 0;
}
