//
// Created by HuanGege on 19/12/2016.
//
#include "main.h"

void Exp::exp0() {
    string graphPath = "/Users/huangege/ClionProjects/Jam/resources/amazon/";
    string nodesPath = graphPath + "Nodes";
    string edgesPath = graphPath + "Edges";
    string patternPath = "/Users/huangege/ClionProjects/Jam/resources/patterns/";
    string resultPath = "/Users/huangege/ClionProjects/Jam/resources/result/";
    string statistics = "/Users/huangege/ClionProjects/Jam/resources/limitedSta";

    Graph dg;
    dg.readNodesFromFile(nodesPath);
    dg.readEdgesFromfile(edgesPath);

    cout << "Data graph: nodes(" << dg.nodeNum() << ")  edges(" << dg.edgeNum() << ")." << endl;

    clock_t start, finish;
    double  duration;
    int current = 10;
    ofstream os(statistics);
    vector<int> scale = {1000, 5000, 10000, 50000, 100000, 542684};
    int i = 0;

    while (1) {
        cout << "Input i: " << endl;
        cin >> i;
        if (i == -1) return;
        string patternPre = patternPath + "p";
        string pNodePath = patternPre +  to_string(i) + "/Nodes";
        string pEdgepath = patternPre +  to_string(i) + "/Edges";
        Pattern pg; //pattern graph
        Graph rg;   //result graph
        Lmatch lm;


        pg.readPatterNodesFromFile(pNodePath);
        pg.readEdgesFromfile(pEdgepath);

        start = clock();
        bool hasMatch = lm.getMatch(pg, dg, rg);
        finish = clock();
        duration = (double)(finish - start) / CLOCKS_PER_SEC;

        cout << "Time(" << duration << ") ";

        if (hasMatch) {
            cout << "Match size: " << "match nodes(" << rg.nodeNum()
            << ")  edges(" << rg.edgeNum() << ")." << endl;
            os << duration << "\t" << rg.nodeNum() << "\t" << rg.edgeNum() << endl;
        }
        else {
            cout << "No match found." << endl;
            os << duration << "\t" << "0\t0" << endl;
        }
    }
    os.close();
    return ;
}

void Exp::exp1Limited() {
    string graphPath = "/Users/huangege/ClionProjects/Jam/resources/amazon/";
    string nodesPath = graphPath + "Nodes";
    string edgesPath = graphPath + "Edges";
    string patternPath = "/Users/huangege/ClionProjects/Jam/resources/patterns/";
    string resultPath = "/Users/huangege/ClionProjects/Jam/resources/result/";
    string statistics = "/Users/huangege/ClionProjects/Jam/resources/limitedSta";

    Graph dg;
    dg.readNodesFromFile(nodesPath);
    dg.readEdgesFromfile(edgesPath);

    cout << "Data graph: nodes(" << dg.nodeNum() << ")  edges(" << dg.edgeNum() << ")." << endl;

    clock_t start, finish;
    double  duration;
    int current = 9;
    ofstream os(statistics);

    for (int i = 1; i <= current; i++) {
        string patternPre = patternPath + "p";
        string pNodePath = patternPre +  to_string(i) + "/Nodes";
        string pEdgepath = patternPre +  to_string(i) + "/Edges";
        Pattern pg; //pattern graph
        Graph rg;   //result graph
        Lmatch lm;


        pg.readPatterNodesFromFile(pNodePath);
        pg.readEdgesFromfile(pEdgepath);

        start = clock();
        bool hasMatch = lm.getMatch(pg, dg, rg);
        finish = clock();
        duration = (double)(finish - start) / CLOCKS_PER_SEC;

        cout << "Time(" << duration << ") ";

        if (hasMatch) {
            cout << "Match size: " << "match nodes(" << rg.nodeNum()
            << ")  edges(" << rg.edgeNum() << ")." << endl;
            os << duration << "\t" << rg.nodeNum() << "\t" << rg.edgeNum() << endl;
        }
        else {
            cout << "No match found." << endl;
            os << duration << "\t" << "0\t0" << endl;
        }
    }
    os.close();
}

void Exp::exp1Graph() {
    string graphPath = "/Users/huangege/ClionProjects/Jam/resources/amazon/";
    string nodesPath = graphPath + "Nodes";
    string edgesPath = graphPath + "Edges";
    string patternPath = "/Users/huangege/ClionProjects/Jam/resources/patterns/";
    string resultPath = "/Users/huangege/ClionProjects/Jam/resources/result/";
    string statistics = "/Users/huangege/ClionProjects/Jam/resources/graphSta";

    Graph dg;
    dg.readNodesFromFile(nodesPath);
    dg.readEdgesFromfile(edgesPath);
    dg.ignoreEdgeLabel();

    cout << "Data graph: nodes(" << dg.nodeNum() << ")  edges(" << dg.edgeNum() << ")." << endl;

    clock_t start, finish;
    double  duration;
    int current = 9;
    ofstream os(statistics);

    for (int i = 1; i <= current; i++) {
        string patternPre = patternPath + "p";
        string pNodePath = patternPre +  to_string(i) + "/Nodes";
        string pEdgepath = patternPre +  to_string(i) + "/Edges";
        Pattern pg; //pattern graph
        Graph rg;   //result graph
        Lmatch lm;

        //initialize pattern graph
        pg.readPatterNodesFromFile(pNodePath);
        pg.readEdgesFromfile(pEdgepath);
        pg.inftyWeight();
        pg.ignoreEdgeLabel();

        start = clock();
        bool hasMatch = lm.getMatch(pg, dg, rg);
        finish = clock();
        duration = (double)(finish - start) / CLOCKS_PER_SEC;

        cout << "Time(" << duration << ") ";

        if (hasMatch) {
            cout << "Match size: " << "match nodes(" << rg.nodeNum()
            << ")  edges(" << rg.edgeNum() << ")." << endl;
            os << duration << "\t" << rg.nodeNum() << "\t" << rg.edgeNum() << endl;
        }
        else {
            cout << "No match found." << endl;
            os << duration << "\t" << "0\t0" << endl;
        }
    }
    os.close();
}

void Exp::exp1NoNodelabel() {
    string graphPath = "/Users/huangege/ClionProjects/Jam/resources/amazon/";
    string nodesPath = graphPath + "Nodes";
    string edgesPath = graphPath + "Edges";
    string patternPath = "/Users/huangege/ClionProjects/Jam/resources/patterns/";
    string resultPath = "/Users/huangege/ClionProjects/Jam/resources/result/";
    string statistics = "/Users/huangege/ClionProjects/Jam/resources/noNodeLabelSta";

    Graph dg;
    dg.readNodesFromFile(nodesPath);
    dg.readEdgesFromfile(edgesPath);
    dg.ignoreNodeLabel();

    cout << "Data graph: nodes(" << dg.nodeNum() << ")  edges(" << dg.edgeNum() << ")." << endl;

    clock_t start, finish;
    double  duration;
    int current = 9;
    ofstream os(statistics);

    for (int i = 1; i <= current; i++) {
        string patternPre = patternPath + "p";
        string pNodePath = patternPre +  to_string(i) + "/Nodes";
        string pEdgepath = patternPre +  to_string(i) + "/Edges";
        Pattern pg; //pattern graph
        Graph rg;   //result graph
        Lmatch lm;


        pg.readPatterNodesFromFile(pNodePath);
        pg.readEdgesFromfile(pEdgepath);
        pg.ignoreNodeLabel();

        start = clock();
        bool hasMatch = lm.getMatch(pg, dg, rg);
        finish = clock();
        duration = (double)(finish - start) / CLOCKS_PER_SEC;

        cout << "Time(" << duration << ") ";

        if (hasMatch) {
            cout << "Match size: " << "match nodes(" << rg.nodeNum()
            << ")  edges(" << rg.edgeNum() << ")." << endl;
            os << duration << "\t" << rg.nodeNum() << "\t" << rg.edgeNum() << endl;
        }
        else {
            cout << "No match found." << endl;
            os << duration << "\t" << "0\t0" << endl;
        }
    }
    os.close();
}

void Exp::exp1NoEdgelabel() {
    string graphPath = "/Users/huangege/ClionProjects/Jam/resources/amazon/";
    string nodesPath = graphPath + "Nodes";
    string edgesPath = graphPath + "Edges";
    string patternPath = "/Users/huangege/ClionProjects/Jam/resources/patterns/";
    string resultPath = "/Users/huangege/ClionProjects/Jam/resources/result/";
    string statistics = "/Users/huangege/ClionProjects/Jam/resources/noEdgeLabelSta";

    Graph dg;
    dg.readNodesFromFile(nodesPath);
    dg.readEdgesFromfile(edgesPath);
    dg.ignoreEdgeLabel();

    cout << "Data graph: nodes(" << dg.nodeNum() << ")  edges(" << dg.edgeNum() << ")." << endl;

    clock_t start, finish;
    double  duration;
    int current = 9;
    ofstream os(statistics);

    for (int i = 1; i <= current; i++) {
        string patternPre = patternPath + "p";
        string pNodePath = patternPre +  to_string(i) + "/Nodes";
        string pEdgepath = patternPre +  to_string(i) + "/Edges";
        Pattern pg; //pattern graph
        Graph rg;   //result graph
        Lmatch lm;


        pg.readPatterNodesFromFile(pNodePath);
        pg.readEdgesFromfile(pEdgepath);
        pg.ignoreEdgeLabel();

        start = clock();
        bool hasMatch = lm.getMatch(pg, dg, rg);
        finish = clock();
        duration = (double)(finish - start) / CLOCKS_PER_SEC;

        cout << "Time(" << duration << ") ";

        if (hasMatch) {
            cout << "Match size: " << "match nodes(" << rg.nodeNum()
            << ")  edges(" << rg.edgeNum() << ")." << endl;
            os << duration << "\t" << rg.nodeNum() << "\t" << rg.edgeNum() << endl;
        }
        else {
            cout << "No match found." << endl;
            os << duration << "\t" << "0\t0" << endl;
        }
    }
    os.close();
}

void Exp::exp2Limited() {
    string graphPath = "/Users/huangege/ClionProjects/Jam/resources/amazon/";
    string nodesPath = graphPath + "Nodes";
    string edgesPath = graphPath + "Edges";
    string patternPath = "/Users/huangege/ClionProjects/Jam/resources/patterns/";
    string resultPath = "/Users/huangege/ClionProjects/Jam/resources/result/";
    string statistics = "/Users/huangege/ClionProjects/Jam/resources/limitedSta";

    Graph dg;
    dg.readNodesFromFile(nodesPath);
    dg.readEdgesFromfile(edgesPath);

    cout << "Data graph: nodes(" << dg.nodeNum() << ")  edges(" << dg.edgeNum() << ")." << endl;

    clock_t start, finish;
    double  duration;
    int current = 5;
    ofstream os(statistics);

    for (int i = 0; i <= current; i++) {
        string patternPre = patternPath + "t";
        string pNodePath = patternPre +  to_string(i) + "/Nodes";
        string pEdgepath = patternPre +  to_string(i) + "/Edges";
        Pattern pg; //pattern graph
        Graph rg;   //result graph
        Lmatch lm;


        pg.readPatterNodesFromFile(pNodePath);
        pg.readEdgesFromfile(pEdgepath);

        start = clock();
        bool hasMatch = lm.getMatch(pg, dg, rg);
        finish = clock();
        duration = (double)(finish - start) / CLOCKS_PER_SEC;

        cout << "Time(" << duration << ") ";

        if (hasMatch) {
            cout << "Match size: " << "match nodes(" << rg.nodeNum()
            << ")  edges(" << rg.edgeNum() << ")." << endl;
            os << duration << "\t" << rg.nodeNum() << "\t" << rg.edgeNum() << endl;
        }
        else {
            cout << "No match found." << endl;
            os << duration << "\t" << "0\t0" << endl;
        }
    }
    os.close();
}

void Exp::exp2Graph() {
    string graphPath = "/Users/huangege/ClionProjects/Jam/resources/amazon/";
    string nodesPath = graphPath + "Nodes";
    string edgesPath = graphPath + "Edges";
    string patternPath = "/Users/huangege/ClionProjects/Jam/resources/patterns/";
    string resultPath = "/Users/huangege/ClionProjects/Jam/resources/result/";
    string statistics = "/Users/huangege/ClionProjects/Jam/resources/graphSta";

    Graph dg;
    dg.readNodesFromFile(nodesPath);
    dg.readEdgesFromfile(edgesPath);
    dg.ignoreEdgeLabel();

    cout << "Data graph: nodes(" << dg.nodeNum() << ")  edges(" << dg.edgeNum() << ")." << endl;

    clock_t start, finish;
    double  duration;
    int current = 5;
    ofstream os(statistics);

    for (int i = 0; i <= current; i++) {
        string patternPre = patternPath + "t";
        string pNodePath = patternPre +  to_string(i) + "/Nodes";
        string pEdgepath = patternPre +  to_string(i) + "/Edges";
        Pattern pg; //pattern graph
        Graph rg;   //result graph
        Lmatch lm;

        //initialize pattern graph
        pg.readPatterNodesFromFile(pNodePath);
        pg.readEdgesFromfile(pEdgepath);
        pg.inftyWeight();
        pg.ignoreEdgeLabel();

        start = clock();
        bool hasMatch = lm.getMatch(pg, dg, rg);
        finish = clock();
        duration = (double)(finish - start) / CLOCKS_PER_SEC;

        cout << "Time(" << duration << ") ";

        if (hasMatch) {
            cout << "Match size: " << "match nodes(" << rg.nodeNum()
            << ")  edges(" << rg.edgeNum() << ")." << endl;
            os << duration << "\t" << rg.nodeNum() << "\t" << rg.edgeNum() << endl;
        }
        else {
            cout << "No match found." << endl;
            os << duration << "\t" << "0\t0" << endl;
        }
    }
    os.close();
}

void Exp::exp2NoNodelabel() {
    string graphPath = "/Users/huangege/ClionProjects/Jam/resources/amazon/";
    string nodesPath = graphPath + "Nodes";
    string edgesPath = graphPath + "Edges";
    string patternPath = "/Users/huangege/ClionProjects/Jam/resources/patterns/";
    string resultPath = "/Users/huangege/ClionProjects/Jam/resources/result/";
    string statistics = "/Users/huangege/ClionProjects/Jam/resources/noNodeLabelSta";

    Graph dg;
    dg.readNodesFromFile(nodesPath);
    dg.readEdgesFromfile(edgesPath);
    dg.ignoreNodeLabel();

    cout << "Data graph: nodes(" << dg.nodeNum() << ")  edges(" << dg.edgeNum() << ")." << endl;

    clock_t start, finish;
    double  duration;
    int current = 5;
    ofstream os(statistics);

    for (int i = 0; i <= current; i++) {
        string patternPre = patternPath + "t";
        string pNodePath = patternPre +  to_string(i) + "/Nodes";
        string pEdgepath = patternPre +  to_string(i) + "/Edges";
        Pattern pg; //pattern graph
        Graph rg;   //result graph
        Lmatch lm;


        pg.readPatterNodesFromFile(pNodePath);
        pg.readEdgesFromfile(pEdgepath);
        pg.ignoreNodeLabel();

        start = clock();
        bool hasMatch = lm.getMatch(pg, dg, rg);
        finish = clock();
        duration = (double)(finish - start) / CLOCKS_PER_SEC;

        cout << "Time(" << duration << ") ";

        if (hasMatch) {
            cout << "Match size: " << "match nodes(" << rg.nodeNum()
            << ")  edges(" << rg.edgeNum() << ")." << endl;
            os << duration << "\t" << rg.nodeNum() << "\t" << rg.edgeNum() << endl;
        }
        else {
            cout << "No match found." << endl;
            os << duration << "\t" << "0\t0" << endl;
        }
    }
    os.close();
}

void Exp::exp2NoEdgelabel() {
    string graphPath = "/Users/huangege/ClionProjects/Jam/resources/amazon/";
    string nodesPath = graphPath + "Nodes";
    string edgesPath = graphPath + "Edges";
    string patternPath = "/Users/huangege/ClionProjects/Jam/resources/patterns/";
    string resultPath = "/Users/huangege/ClionProjects/Jam/resources/result/";
    string statistics = "/Users/huangege/ClionProjects/Jam/resources/noEdgeLabelSta";

    Graph dg;
    dg.readNodesFromFile(nodesPath);
    dg.readEdgesFromfile(edgesPath);
    dg.ignoreEdgeLabel();

    cout << "Data graph: nodes(" << dg.nodeNum() << ")  edges(" << dg.edgeNum() << ")." << endl;

    clock_t start, finish;
    double  duration;
    int current = 5;
    ofstream os(statistics);

    for (int i = 0; i <= current; i++) {
        string patternPre = patternPath + "t";
        string pNodePath = patternPre +  to_string(i) + "/Nodes";
        string pEdgepath = patternPre +  to_string(i) + "/Edges";
        Pattern pg; //pattern graph
        Graph rg;   //result graph
        Lmatch lm;


        pg.readPatterNodesFromFile(pNodePath);
        pg.readEdgesFromfile(pEdgepath);
        pg.ignoreEdgeLabel();

        start = clock();
        bool hasMatch = lm.getMatch(pg, dg, rg);
        finish = clock();
        duration = (double)(finish - start) / CLOCKS_PER_SEC;

        cout << "Time(" << duration << ") ";

        if (hasMatch) {
            cout << "Match size: " << "match nodes(" << rg.nodeNum()
            << ")  edges(" << rg.edgeNum() << ")." << endl;
            os << duration << "\t" << rg.nodeNum() << "\t" << rg.edgeNum() << endl;
        }
        else {
            cout << "No match found." << endl;
            os << duration << "\t" << "0\t0" << endl;
        }
    }
    os.close();
}

void Exp::exp3Limited() {
    string graphPath = "/Users/huangege/ClionProjects/Jam/resources/amazon/";
    string nodesPath = graphPath + "Nodes";
    string edgesPath = graphPath + "Edges";
    string patternPath = "/Users/huangege/ClionProjects/Jam/resources/patterns/";
    string resultPath = "/Users/huangege/ClionProjects/Jam/resources/result/";
    string statistics = "/Users/huangege/ClionProjects/Jam/resources/limitedSta";

    Graph dg;
    dg.readNodesFromFile(nodesPath);
    dg.readEdgesFromfile(edgesPath);

    vector<int> scale = {1000, 5000, 10000, 50000, 100000, 542684};
    clock_t start, finish;
    double  duration;
    int current = 5;
    ofstream os(statistics);

    for (int i = 0; i <= current; i++) {
        string patternPre = patternPath + "q";
        string pNodePath = patternPre + "/Nodes";
        string pEdgepath = patternPre + "/Edges";
        Pattern pg; //pattern graph
        Graph rg;   //result graph
        Graph cg;   //compressed graph
        Lmatch lm;

        dg.graphCompress(cg, scale[i]);

        cout << "Data graph: nodes(" << cg.nodeNum() << ")  edges(" << cg.edgeNum() << ")." << endl;

        pg.readPatterNodesFromFile(pNodePath);
        pg.readEdgesFromfile(pEdgepath);

        start = clock();
        bool hasMatch = lm.getMatch(pg, cg, rg);
        finish = clock();
        duration = (double)(finish - start) / CLOCKS_PER_SEC;

        cout << "Time(" << duration << ") ";

        if (hasMatch) {
            cout << "Match size: " << "match nodes(" << rg.nodeNum()
            << ")  edges(" << rg.edgeNum() << ")." << endl;
            os << duration << "\t" << rg.nodeNum() << "\t" << rg.edgeNum() << endl;
        }
        else {
            cout << "No match found." << endl;
            os << duration << "\t" << "0\t0" << endl;
        }
    }
    os.close();
}

void Exp::exp3Graph() {
    string graphPath = "/Users/huangege/ClionProjects/Jam/resources/amazon/";
    string nodesPath = graphPath + "Nodes";
    string edgesPath = graphPath + "Edges";
    string patternPath = "/Users/huangege/ClionProjects/Jam/resources/patterns/";
    string resultPath = "/Users/huangege/ClionProjects/Jam/resources/result/";
    string statistics = "/Users/huangege/ClionProjects/Jam/resources/graphSta";

    Graph dg;
    dg.readNodesFromFile(nodesPath);
    dg.readEdgesFromfile(edgesPath);

    vector<int> scale = {1000, 5000, 10000, 50000, 100000, 542684};
    clock_t start, finish;
    double  duration;
    int current = 5;
    ofstream os(statistics);

    for (int i = 0; i <= current; i++) {
        string patternPre = patternPath + "q";
        string pNodePath = patternPre + "/Nodes";
        string pEdgepath = patternPre + "/Edges";
        Pattern pg; //pattern graph
        Graph rg;   //result graph
        Graph cg;   //compressed graph
        Lmatch lm;

        dg.graphCompress(cg, scale[i]);
        cg.ignoreEdgeLabel();

        cout << "Data graph: nodes(" << cg.nodeNum() << ")  edges(" << cg.edgeNum() << ")." << endl;

        dg.ignoreEdgeLabel();

        pg.readPatterNodesFromFile(pNodePath);
        pg.readEdgesFromfile(pEdgepath);
        pg.ignoreEdgeLabel();
        pg.inftyWeight();

        start = clock();
        bool hasMatch = lm.getMatch(pg, cg, rg);
        finish = clock();
        duration = (double)(finish - start) / CLOCKS_PER_SEC;

        cout << "Time(" << duration << ") ";

        if (hasMatch) {
            cout << "Match size: " << "match nodes(" << rg.nodeNum()
            << ")  edges(" << rg.edgeNum() << ")." << endl;
            os << duration << "\t" << rg.nodeNum() << "\t" << rg.edgeNum() << endl;
        }
        else {
            cout << "No match found." << endl;
            os << duration << "\t" << "0\t0" << endl;
        }
    }
    os.close();
}

void Exp::exp3NoNodelabel() {
    string graphPath = "/Users/huangege/ClionProjects/Jam/resources/amazon/";
    string nodesPath = graphPath + "Nodes";
    string edgesPath = graphPath + "Edges";
    string patternPath = "/Users/huangege/ClionProjects/Jam/resources/patterns/";
    string resultPath = "/Users/huangege/ClionProjects/Jam/resources/result/";
    string statistics = "/Users/huangege/ClionProjects/Jam/resources/noNodeLabelSta";

    Graph dg;
    dg.readNodesFromFile(nodesPath);
    dg.readEdgesFromfile(edgesPath);

    vector<int> scale = {1000, 5000, 10000, 50000, 100000, 542684};
    clock_t start, finish;
    double  duration;
    int current = 5;
    ofstream os(statistics);

    for (int i = 0; i <= current; i++) {
        string patternPre = patternPath + "q";
        string pNodePath = patternPre + "/Nodes";
        string pEdgepath = patternPre + "/Edges";
        Pattern pg; //pattern graph
        Graph rg;   //result graph
        Graph cg;   //compressed graph
        Lmatch lm;

        dg.graphCompress(cg, scale[i]);
        cg.ignoreNodeLabel();

        cout << "Data graph: nodes(" << cg.nodeNum() << ")  edges(" << cg.edgeNum() << ")." << endl;

        pg.readPatterNodesFromFile(pNodePath);
        pg.readEdgesFromfile(pEdgepath);
        pg.ignoreNodeLabel();

        start = clock();
        bool hasMatch = lm.getMatch(pg, cg, rg);
        finish = clock();
        duration = (double)(finish - start) / CLOCKS_PER_SEC;

        cout << "Time(" << duration << ") ";

        if (hasMatch) {
            cout << "Match size: " << "match nodes(" << rg.nodeNum()
            << ")  edges(" << rg.edgeNum() << ")." << endl;
            os << duration << "\t" << rg.nodeNum() << "\t" << rg.edgeNum() << endl;
        }
        else {
            cout << "No match found." << endl;
            os << duration << "\t" << "0\t0" << endl;
        }
    }
    os.close();
}

void Exp::exp3NoEdgelabel() {
    string graphPath = "/Users/huangege/ClionProjects/Jam/resources/amazon/";
    string nodesPath = graphPath + "Nodes";
    string edgesPath = graphPath + "Edges";
    string patternPath = "/Users/huangege/ClionProjects/Jam/resources/patterns/";
    string resultPath = "/Users/huangege/ClionProjects/Jam/resources/result/";
    string statistics = "/Users/huangege/ClionProjects/Jam/resources/noEdgeLabelSta";

    Graph dg;
    dg.readNodesFromFile(nodesPath);
    dg.readEdgesFromfile(edgesPath);

    vector<int> scale = {1000, 5000, 10000, 50000, 100000, 542684};
    clock_t start, finish;
    double  duration;
    int current = 5;
    ofstream os(statistics);

    for (int i = 0; i <= current; i++) {
        string patternPre = patternPath + "q";
        string pNodePath = patternPre + "/Nodes";
        string pEdgepath = patternPre + "/Edges";
        Pattern pg; //pattern graph
        Graph rg;   //result graph
        Graph cg;   //compressed graph
        Lmatch lm;

        dg.graphCompress(cg, scale[i]);
        cg.ignoreEdgeLabel();

        cout << "Data graph: nodes(" << cg.nodeNum() << ")  edges(" << cg.edgeNum() << ")." << endl;

        pg.readPatterNodesFromFile(pNodePath);
        pg.readEdgesFromfile(pEdgepath);
        pg.ignoreEdgeLabel();

        start = clock();
        bool hasMatch = lm.getMatch(pg, cg, rg);
        finish = clock();
        duration = (double)(finish - start) / CLOCKS_PER_SEC;

        cout << "Time(" << duration << ") ";

        if (hasMatch) {
            cout << "Match size: " << "match nodes(" << rg.nodeNum()
            << ")  edges(" << rg.edgeNum() << ")." << endl;
            os << duration << "\t" << rg.nodeNum() << "\t" << rg.edgeNum() << endl;
        }
        else {
            cout << "No match found." << endl;
            os << duration << "\t" << "0\t0" << endl;
        }
    }
    os.close();
}

void Exp::expAll() {
    string graphPath = "/Users/huangege/ClionProjects/Jam/resources/amazon/";
    string nodesPath = graphPath + "Nodes";
    string edgesPath = graphPath + "Edges";
    string patternPath = "/Users/huangege/ClionProjects/Jam/resources/patterns/";
    string resultPath = "/Users/huangege/ClionProjects/Jam/resources/result/";
    string statistics = "/Users/huangege/ClionProjects/Jam/resources/limitedSta";

    Graph dg;
    dg.readNodesFromFile(nodesPath);
    dg.readEdgesFromfile(edgesPath);

    cout << "Data graph: nodes(" << dg.nodeNum() << ")  edges(" << dg.edgeNum() << ")." << endl;

    clock_t start, finish;
    double  duration;
    int current = 10;
    ofstream os(statistics);
    int i = 0;

    while (1) {
        cout << "Input i: " << endl;
        cin >> i;
        if (i == -1) return;
        string patternPre = patternPath + "p";
        string pNodePath = patternPre +  to_string(i) + "/Nodes";
        string pEdgepath = patternPre +  to_string(i) + "/Edges";
        Pattern pg; //pattern graph
        Graph rg;   //result graph
        Lmatch lm;


        pg.readPatterNodesFromFile(pNodePath);
        pg.readEdgesFromfile(pEdgepath);

        start = clock();
        bool hasMatch = lm.getMatch(pg, dg, rg);
        finish = clock();
        duration = (double)(finish - start) / CLOCKS_PER_SEC;

        cout << "Time(" << duration << ") ";

        rg.writeToFile(resultPath);

        if (hasMatch) {
            cout << "Match size: " << "match nodes(" << rg.nodeNum()
            << ")  edges(" << rg.edgeNum() << ")." << endl;
            os << duration << "\t" << rg.nodeNum() << "\t" << rg.edgeNum() << endl;
        }
        else {
            cout << "No match found." << endl;
            os << duration << "\t" << "0\t0" << endl;
        }
    }
    os.close();
    return ;
}

