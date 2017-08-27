//
// Created by HuanGege on 05/12/2016.
//

#include "main.h"

Bmatrix::Bmatrix(Graph &pg, Graph &dg, Kmatrix &km) {
    xNum = pg.nodeNum();
    yNum = pg.nodeNum();
    zNum = dg.nodeNum();

    for (int i = 0; i < xNum; i++) {
        B.push_back(vector<vector<int>>());
        for (int j = 0; j < yNum; j++) {
            B[i].push_back(vector<int>());
            for (int k = 0; k < zNum; k++) {
                B[i][j].push_back(0);
            }
        }
    }

    for (int i = 0; i < pg.nodeNum(); i++) {
        for (pair<int, string> j : pg.edges[i]) {
            for (int v = 0; v < dg.nodeNum(); v++) {
                for (pair<int, string> vp : dg.edges[v]) {
                    if (pg.nodes[i] == dg.nodes[v]
                        && pg.nodes[j.first] == dg.nodes[vp.first]
                        && j.second == vp.second) {
                        B[i][j.first][v]++;
                    }
                }
            }
        }
    }
}

void Bmatrix::clear() {
    B.clear();
    xNum = yNum = zNum = 0;
}

bool Bmatrix::test(int i, int j, int v) {
    return B[i][j][v] == 0;
}

void Bmatrix::update(Graph &pg, Graph &dg, vector<set<int>> &cad, int u, int v, Kmatrix &km, int t) {
    for (pair<int, string> i : pg.rEdges[u]) {
        for (pair<int, string> j : dg.rEdges[v]) {
            if (km.M[i.first][j.first] == t + 1
                && i.second == j.second) {
                B[i.first][u][j.first]--;
            }
        }
    }
}