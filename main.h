//
// Created by HuanGege on 04/12/2016.
//

#ifndef JAM_MAIN_H
#define JAM_MAIN_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <fstream>
#include <cmath>
#include <string.h>
#include <list>
#include <iomanip>
#include <cstdlib>
#include <set>
#include <map>
#include <cstdlib>
#include <time.h>

using namespace std;


/* classes
 *
 * */

struct Node {
    string id;
    int num;
    vector<string> labels;

    Node(string idValue = "", int numValue = 0, vector<string> labelsValue = {}):
            id(idValue), num(numValue), labels(labelsValue) {}

    bool operator==(Node &node);
    bool contains(string label);
};

struct Graph {
    vector<Node> nodes;
    map<string, int> nodeId2Num;
    // num num label
    vector<set<pair<int, string>>> edges;
    vector<set<pair<int, string>>> rEdges;

    int nodeNum() {
        return nodes.size();
    }
    int edgeNum();
    void findEdge(string label1, string label2, string edgeLabel);
    void getREdges();
    int insertNode(Node &node);
    int insertNode(string id, vector<string> labels);
    int insertEdge(string lid, string rid, string label);
    void ignoreNodeLabel();
    void ignoreEdgeLabel();
    // id \t labels(&)
    void readNodesFromFile(string inputFile);
    // id \t id \t label
    void readEdgesFromfile(string inputFile);

    //  write to file
    void writeToFile(string outputPath);
    void writetoFileUsingNum(string outputPath);

    virtual void printNodes(int n);
    void printEdges(int n);

    void graphCompress(Graph &dest, int n);
    virtual void clear();
    virtual ~Graph();
};

struct Pattern : public Graph {
    vector<int> weight;
    int T = -2;

    int getT();
    void readPatterNodesFromFile(string inputFile);
    void printNodes(int n);
    void inftyWeight();
    void clear();
    ~Pattern();
};

struct Kmatrix {
    vector<vector<int>> M;
    int rNum;
    int cNum;

    vector<vector<int>> getKmatrix();

    void calMatrix(Graph &pg, Graph &dg, int t);
    void clear();
    void write2File(string outputFile);
    ~Kmatrix() {
        clear();
    }
};

struct Bmatrix {
    vector<vector<vector<int>>> B;
    int xNum;
    int yNum;
    int zNum;

    Bmatrix(Graph &pg, Graph &dg, Kmatrix &km);
    bool test(int i, int j, int v);
    void update(Graph &pg, Graph &dg, vector<set<int>> &cad, int u, int v, Kmatrix &km, int t);
    void clear();
    ~Bmatrix() {
        clear();
    }
};

struct Lmatch {
    bool getMatch(Pattern &pg, Graph &dg, Graph &dest);
};

struct Gmatch {
    bool getMatch(Pattern &pg, Graph &dg, Graph &dest);
};

struct Exp {
    void exp0();
    void exp1Limited();
    void exp1Graph();
    void exp1NoNodelabel();
    void exp1NoEdgelabel();
    void exp2Limited();
    void exp2Graph();
    void exp2NoNodelabel();
    void exp2NoEdgelabel();
    void exp3Limited();
    void exp3Graph();
    void exp3NoNodelabel();
    void exp3NoEdgelabel();
    void expAll();
};

/*functions
 *
 * */

//nodeNum \t nodeid \t labels(&)
void readNodes(string inputFile, vector<Node> &nodes);
void writeNodesToFile(string outputFile, vector<Node> &nodes);

//nodeNum \t nodeNum
void writeEdgesToFile(string outputFile, map<int, set<int>> edges);
void readEdges(string inputFile, map<int, set<int>> &edges, vector<Node> &nodes);

//common operations
vector<string> split(string line, string s);
vector<string> splitBy(string line, string s);
map<int, set<int>> getRedges(map<int, set<int>> edges);
ostream& operator << (ostream &os, Node node);
ostream& operator<<(ostream& os, Kmatrix &km);
void readAmazonFile(string inputFile, Graph &graph);

#endif //JAM_MAIN_H

