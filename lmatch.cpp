//
// Created by HuanGege on 05/12/2016.
//

#include "main.h"

bool Lmatch::getMatch(Pattern &pg, Graph &dg, Graph &dest) {
    Kmatrix km;

    km.calMatrix(pg, dg, pg.getT());

    set<int> nodes;

    vector<bool> nodeMatch(pg.nodeNum(), false);
    vector<vector<bool>> edgeMatch(pg.nodeNum(), vector<bool>(pg.nodeNum(), true));
    for (int i = 0; i < pg.nodeNum(); i++) {
        for (auto p : pg.edges[i])
            edgeMatch[i][p.first] = false;
    }

    for (int i = 0; i < pg.nodeNum(); i++)
        if (pg.weight[i] == -1)
            pg.weight[i] = pg.getT() + 1;

    for (int i = 0; i < pg.nodeNum(); i++) {
        for (int j = 0; j < dg.nodeNum(); j++) {
            if (km.M[i][j] >= pg.weight[i]) {
                nodeMatch[i] = true;
                nodes.insert(j);
            }
        }
    }

    for (int i : nodes) {
        dest.insertNode(dg.nodes[i]);
    }

    for (int i = 0; i < pg.nodeNum(); i++) {
        for (pair<int, string> p : pg.edges[i]) {
            for (int j = 0; j < dg.nodeNum(); j++) {
                for (pair<int, string> q : dg.edges[j]) {
                    if (km.M[i][j] >= pg.weight[i] && km.M[p.first][q.first] >= pg.weight[p.first]
                            && p.second == q.second) {
                        edgeMatch[i][p.first] = true;
                        dest.insertEdge(dg.nodes[j].id, dg.nodes[q.first].id, q.second);
                    }
                }
            }
        }
    }

    for (int i = 0; i < pg.nodeNum(); i++) {
        if (nodeMatch[i] == false) {
            cout << pg.nodes[i] << endl;
            return false;
        }
        for (int j = 0; j < pg.nodeNum(); j++) {
            if (edgeMatch[i][j] == false) {
                cout << pg.nodes[i] << " --->>> " << pg.nodes[j] << endl;
                return false;
            }
        }
    }
    return true;
}