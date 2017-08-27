//
// Created by HuanGege on 05/12/2016.
//

#include "main.h"

//asin \t group \t simAsin( ) \t category \t salesrank \t reviews
void readAmazonFile(string inputFile, Graph &graph) {
    ifstream is(inputFile);
    string line;

    if (!is.is_open()) {
        cout << inputFile << "open failed" << endl;
        exit(100);
    }

    getline(is, line);

    while (!is.eof()) {
        vector<string> v = splitBy(line, "\t");
        if (v.size() != 6) {
            if (v.size() != 5)
                cout << v.size() << endl;
            getline(is, line);
            continue;
        }
        graph.insertNode(v[0], {v[1]});

        getline(is, line);
    }
    is.close();

    is.open(inputFile);
    if (!is.is_open()) {
        cout << inputFile << "open failed" << endl;
        exit(100);
    }

    getline(is, line);

    while (!is.eof()) {
        vector<string> v = split(line, "\t");
        if (v.size() != 6) {
            getline(is, line);
            continue;
        }
        vector<string> egs = split(v[2], " ");

        for (int i = 0; i < egs.size(); i++) {
            graph.insertEdge(v[0], egs[i], to_string(i));
        }
        getline(is, line);
    }
    is.close();
}

void readNodes(string inputFile, vector<Node> &nodes) {
    ifstream is(inputFile);
    string line;

    if (!is.is_open()) {
        cout << inputFile << "open failed" << endl;
        exit(100);
    }

    getline(is, line);

    while (!line.empty()) {
        vector<string> v = split(line, "\t");
        if (v.size() != 3) {
            getline(is, line);
            continue;
        }

        nodes.push_back(Node(v[1], atoi(v[0].c_str()), split(v[2], "&")));
        getline(is, line);
    }
    is.close();
}

void readEdges(string inputFile, map<int, set<int>> &edges, vector<Node> &nodes) {
    ifstream is(inputFile);
    string line;

    if (!is.is_open()) {
        cout << inputFile << "open failed." << endl;
        exit(100);
    }

    getline(is, line);

    while (!line.empty()) {
        vector<string> v = split(line, "\t");

        if (v.size() != 2) {
            getline(is, line);
            continue;
        }

        int p = atoi(v[0].c_str());
        int q = atoi(v[1].c_str());

        if (p >= nodes.size() || q >= nodes.size()) {
            getline(is, line);
            continue;
        }

        if (edges.find(p) == edges.end()) {
            edges[p];
        }
        edges[p].insert(q);
        getline(is, line);
    }

    is.close();
}

