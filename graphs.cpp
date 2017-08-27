//
// Created by HuanGege on 04/12/2016.
//
#include "main.h"


bool Node::operator==(Node &node) {
    if (find(this->labels.begin(), this->labels.end(), "*") != this->labels.end()
            || find(node.labels.begin(), node.labels.end(), "*") != node.labels.end())
        return true;

    for (auto i : this->labels) {
        for (auto j : node.labels) {
            if (i == j)
                return true;
        }
    }
    return false;
}

bool Node::contains(string label) {
    for (auto i : this->labels)
        if (i == label)
            return true;

    return false;
}

ostream& operator << (ostream &os, Node node) {
    os << node.id;
    if (node.labels.empty())
        return os;
    os << "\t";
    for (auto i : node.labels)
        os << "&" << i;
    return os;
}

map<int, set<int>> getRedges(map<int, set<int>> edges) {
    map<int, set<int>> redges;
    set<int> s;
    for (auto p : edges) {
        for (auto q : p.second) {
            if (redges.find(q) == redges.end())
                redges[q] = s;
            redges[q].insert(p.first);
        }
    }
    return redges;
};

int Pattern::getT() {
    if (this->T != -2)
        return T;

    T = 0;

    for (int i : weight)
        T = T < i ? i : T;

    return T;
}

void Graph::getREdges() {
    if (rEdges.empty()) {
        for (int i = 0; i < nodeNum(); i++)
            rEdges.push_back(set<pair<int, string>>());
    }

    for (int i = 0; i < nodeNum(); i++) {
        for (pair<int, string> p : edges[i]) {
            rEdges[p.first].insert(pair<int, string>(i, p.second));
        }
    }
}

void Graph::readNodesFromFile(string inputFile) {
    ifstream is(inputFile);
    string line;

    if (!is.is_open()) {
        cout << inputFile << "open failed" << endl;
        exit(100);
    }

    getline(is, line);

    while (!is.eof()) {
        vector<string> v = split(line, "\t");
        if (v.size() < 2) {
            getline(is, line);
            continue;
        }
        if (v.size() == 2)
            this->insertNode(v[0], split(v[1], "&"));
        else
            this->insertNode(v[1], split(v[2], "&"));
        getline(is, line);
    }
    is.close();
}

void Graph::readEdgesFromfile(string inputFile) {
    ifstream is(inputFile);
    string line;

    if (!is.is_open()) {
        cout << inputFile << "open failed." << endl;
        exit(100);
    }

    getline(is, line);

    while (!is.eof()) {
        vector<string> v = split(line, "\t");

        if (v.size() != 3) {
            getline(is, line);
            continue;
        }

        this->insertEdge(v[0], v[1], v[2]);

        getline(is, line);
    }

    is.close();
}

void Graph::printNodes(int n) {
    cout << "Nodes:" << endl;
    for (int i = 0; i < n && i < nodes.size(); i++)
        cout << nodes[i] << endl;

}

void Graph::printEdges(int n) {
    cout << "Edges:" << endl;
    for (int i = 0; i < this->nodeNum() && i < n; i++) {
        for (auto j : this->edges[i]) {
            cout << nodes[i].id << "\t" << nodes[j.first].id << "\t" << j.second << endl;
        }
    }
}

void Pattern::readPatterNodesFromFile(string inputFile) {
    ifstream is(inputFile);
    string line;

    if (!is.is_open()) {
        cout << inputFile << "open failed" << endl;
        exit(100);
    }

    getline(is, line);

    while (!is.eof()) {
        vector<string> v = split(line, "\t");
        if (v.size() < 3) {
            getline(is, line);
            continue;
        }

        this->insertNode(v[0], split(v[1], "&"));
        weight.push_back(atoi(v[2].c_str()));
        getline(is, line);
    }
    is.close();
}

void Pattern::printNodes(int n) {
    cout << "Nodes:" << endl;
    for (int i = 0; i < nodeNum() && i < n; i++) {
        cout << nodes[i] << "\t" << weight[i] << endl;
    }
}

void Graph::writeToFile(string outputPath) {
    string nodesPath = outputPath + "Nodes";
    string edgesPath = outputPath + "Edges";

    ofstream os(nodesPath);
    for (Node i : nodes) {
        os << i << endl;
    }
    os.close();

    os.open(edgesPath);
    for (int i = 0; i < nodeNum(); i++) {
        for (pair<int, string> p : edges[i]) {
            os << nodes[i].id << "\t"
            << nodes[p.first].id << "\t"
            << p.second << endl;
        }
    }
    os.close();
}

void Graph::writetoFileUsingNum(string outputPath) {
    string nodesPath = outputPath + "nNodes";
    string edgesPath = outputPath + "nEdges";

    ofstream os(nodesPath);
    for (int i = 0; i < this->nodeNum(); i++) {
        os << i << "\t" << nodes[i] << endl;
    }
    os.close();

    os.open(edgesPath);
    for (int i = 0; i < nodeNum(); i++) {
        for (pair<int, string> p : edges[i]) {
            os << nodes[i].num << "\t"
            << nodes[p.first].num << "\t"
            << p.second << endl;
        }
    }
    os.close();
}

int Graph::insertNode(Node &nd) {
    Node node(nd.id, nodes.size(), nd.labels);

    nodes.push_back(node);
    this->nodeId2Num[node.id] = node.num;
    edges.push_back(set<pair<int, string>>());
    return nodes.size() - 1;
}

int Graph::insertNode(string id, vector<string> labels) {
    Node node(id, nodes.size(), labels);

    nodes.push_back(node);
    this->nodeId2Num[node.id] = node.num;
    edges.push_back(set<pair<int, string>>());
    return nodes.size() - 1;
}

int Graph::insertEdge(string lid, string rid, string label) {
    auto l = nodeId2Num.find(lid);
    auto r = nodeId2Num.find(rid);

    if (l == nodeId2Num.end() || r == nodeId2Num.end())
        return -1;
    edges[l->second].insert(pair<int, string>(r->second, label));
    return 0;
}

void Graph::graphCompress(Graph &dest, int n) {
    dest.clear();

    set<string> nodeSet;

    for (int i = 0; i < n && i < this->nodeNum() && nodeSet.size() < n; i++) {
        nodeSet.insert(this->nodes[i].id);
        for (pair<int, string> e : this->edges[i]) {
            nodeSet.insert(this->nodes[e.first].id);
        }
    }

    for (Node i : this->nodes) {
        if (nodeSet.find(i.id) != nodeSet.end())
            dest.insertNode(i);
    }

    for (int i = 0; i < this->nodeNum(); i++) {
        for (pair<int, string> e : this->edges[i]) {
            string l = this->nodes[i].id;
            string r = this->nodes[e.first].id;
            string label = e.second;
            dest.insertEdge(l, r, label);
        }
    }
}

void Graph::clear() {
    nodes.clear();
    nodeId2Num.clear();
    edges.clear();
    rEdges.clear();
}

void Graph::findEdge(string label1, string label2, string edgeLabel) {
    for (int i = 0; i < nodeNum(); i++) {
        for (auto p : edges[i]) {
            if (nodes[i].contains(label1) && nodes[p.first].contains(label2) && p.second == edgeLabel)
                cout << nodes[i].id << "\t" << nodes[p.first].id << endl;
        }
    }
}

void Pattern::clear() {
    nodes.clear();
    nodeId2Num.clear();
    edges.clear();
    rEdges.clear();
    weight.clear();

}

Graph::~Graph() {
    this->clear();
}

Pattern::~Pattern() {
    this->clear();
}

int Graph::edgeNum() {
    int count = 0;

    for (int i = 0; i < nodeNum(); i++) {
        for (auto p : edges[i]) {
            count++;
        }
    }
    return count;
}

void Graph::ignoreNodeLabel() {
    for (int i = 0; i < this->nodeNum(); i++) {
        this->nodes[i].labels.clear();
        this->nodes[i].labels.push_back("*");
    }
}

void Graph::ignoreEdgeLabel() {
    for (int i = 0; i < this->nodeNum(); i++) {
        set<pair<int, string>> s;
        for (auto p : this->edges[i]) {
            s.insert(pair<int, string>(p.first, "*"));
        }
        this->edges[i] = s;
    }
}

void Pattern::inftyWeight() {
    for (int i = 0; i < this->nodeNum(); i++) {
        this->weight[i] = -1;
    }
}