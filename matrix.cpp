//
// Created by HuanGege on 05/12/2016.
//

#include "main.h"



void Kmatrix::clear() {
    M.clear();
    this->rNum = 0;
    this->cNum = 0;
}

void Kmatrix::calMatrix(Graph &pg, Graph &dg, int t) {
    vector<set<int>> rem(pg.nodeNum(), set<int>());
    vector<set<int>> cad(pg.nodeNum(), set<int>());

    this->clear();

    //initialization

    rNum = pg.nodeNum();
    cNum = dg.nodeNum();
    pg.getREdges();
    dg.getREdges();

    for (int i = 0; i < pg.nodeNum(); i++) {
        M.push_back(vector<int>());
        for (int j = 0; j < dg.nodeNum(); j++) {
            M[i].push_back(0);
        }
    }

    for (int i = 0; i < pg.nodeNum(); i++) {
        for (int j = 0; j < dg.nodeNum(); j++) {
            if (pg.nodes[i] == dg.nodes[j]) {
                M[i][j] = t + 1;
                cad[i].insert(j);
            }
            else {
                M[i][j] = -1;
            }
        }
    }

    Bmatrix bm(pg, dg, *this);

    //match computation

    for (int count = 0; count <= t; count++) {
        for (int i = 0; i < pg.nodeNum(); i++) {
            for (int j : rem[i]) {
                if (M[i][j] == t + 1) {
                    cad[i].erase(j);
                    bm.update(pg, dg, cad, i, j, *this, t);
                    M[i][j] = count - 1;
                }
            }
            rem[i].clear();
        }

        for (int i = 0; i < pg.nodeNum(); i++) {
            for (pair<int, string> j : pg.edges[i]) {
                for (int v : cad[i]) {
                    if (bm.test(i, j.first, v)) {
                        rem[i].insert(v);
                    }
                }
            }
        }
    }

    set<int> remNotEmpty;

    for (int i = 0; i < pg.nodeNum(); i++) {
        if (!rem[i].empty())
            remNotEmpty.insert(i);
    }

    while (!remNotEmpty.empty()) {
        int u = *remNotEmpty.begin();
        remNotEmpty.erase(u);
        for (int v : rem[u]) {
            if (M[u][v] == t + 1) {
                cad[u].erase(v);
                bm.update(pg, dg, cad, u, v, *this, t);
                M[u][v] = t;
                for (pair<int, string> ui : pg.rEdges[u]) {
                    for (pair<int, string> vi : dg.rEdges[v]) {
                        if (M[ui.first][vi.first] == t + 1 && bm.test(ui.first, u, vi.first)) {
                            rem[ui.first].insert(vi.first);
                            remNotEmpty.insert(ui.first);
                        }
                    }
                }
            }
        }
        rem[u].clear();
    }

}

vector<vector<int>> Kmatrix::getKmatrix() {
    return M;
}

ostream& operator<<(ostream& os, Kmatrix &km) {
    vector<vector<int>> m = km.getKmatrix();

    for (int i = 0; i < km.rNum; i++) {
        for (int j = 0; j < km.cNum; j++)
            os << km.M[i][j] << "\t";
        os << endl;
    }
    return os;
}

void Kmatrix::write2File(string outputFile) {
    ofstream os(outputFile);

    if (!os.is_open())
        cout << outputFile <<  "open failed." << endl;

    os << *this << endl;

    os.close();
}

